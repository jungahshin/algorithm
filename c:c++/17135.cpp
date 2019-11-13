//캐슬디펜스
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int a[20][20] = {0, };
int a_copy[20][20] = {0, };
int a_temp[20][20] = {0, };
int visited[20] = {0, };
vector<pair<int, int>> v;//궁수들 위치 저장
int n, m, d;
int final = 0;

bool check(){//적이 남아있는지 확인
    bool attack = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_temp[i][j] == 1){
                attack = true;
            }
        }
    }
    return attack;
}

void copy(){//a를 새로운 곳에 복사하고 그것으로 게임 진행 a->a_temp
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_temp[i][j] = a[i][j];
        }
    }
}

int play(){//본격적인 게임 시작!
    int kill_num = 0;
    int really_temp = 0;
    copy();
    while(check()){//적이 아직 남아있으면 게임 계속 진행
        really_temp++;
        vector<pair<int, int>> kill;//적의 위치를 저장했다가 한 턴마다 죽인다.
        kill.clear();
        for(int i=0; i<v.size(); i++){//각 궁수들 마다 진행
            vector<pair<int, pair<int, int>>> temp;//거리가 d이하인 적수들 모두 저장
            temp.clear();
            for(int j=0; j<n; j++){
                for(int h=0; h<m; h++){
                    if(a_temp[j][h] == 1){//적수가 있으면
                        if(abs(v[i].first-j)+ abs(v[i].second-h) <= d){//거리가 d이하이면-->temp에 저장
                            temp.push_back(make_pair(abs(v[i].first-j)+ abs(v[i].second-h), make_pair(h, j)));//거리, 위치(열, 행)-->열이 우선!!!
                        }
                    }
                }
            }
            //가장 거리가 짧고, 가장 왼쪽에 있는 적을 죽인다.
            sort(temp.begin(), temp.end());
            if(temp.size() > 0){
                kill.push_back(make_pair(temp[0].second.second, temp[0].second.first));
            }
        }
        if(kill.size() > 0){
            for(int i=0; i<kill.size(); i++){//적을 죽인다.
                if(a_temp[kill[i].first][kill[i].second] == 1){
                    a_temp[kill[i].first][kill[i].second] = 0;
                    kill_num++;
                }
            }            
        }
        //적들이 행+1 이동한다.
        for(int i=0; i<=n-2; i++){
            for(int j=0; j<m; j++){
                a_copy[i+1][j] = a_temp[i][j];
            }
        }
        for(int j=0; j<m; j++){
            a_copy[0][j] = 0;
        }
        //a_copy를 a로 다 옮긴다.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a_temp[i][j] = a_copy[i][j];
            }
        }
    }
    return kill_num;
}

void put(){
    for(int i=0; i<m; i++){//미리 0으로 초기화
        a[n][i] = 0;
    }
    v.clear();
    for(int i=0; i<m; i++){
        if(visited[i] == 1){
            a[n][i] = 1;
            v.push_back(make_pair(n, i));
        }
    }
    //최대값 계산
    final = max(final, play());
}

void combin(int idx, int num){//조합 진행(3명)
    if(num == 3){
        put();
        return;
    }

    for(int i=idx; i<m; i++){//열 기준
        if(visited[i] == 1) continue;
        visited[i] = 1;

        combin(i, num+1);
        visited[i] = 0;
    }
}

int main(){
    cin>>n>>m>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    combin(0, 0);
    cout<<final<<"\n";
}