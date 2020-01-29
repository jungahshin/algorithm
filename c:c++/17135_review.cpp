//캐슬디펜스
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, d;
int a[16][16] = {0, };//0->빈칸, 1->적군, 2->궁수
int b[16][16] = {0, };
int visited[16] = {0, };
vector<pair<int, int>> v;
int final = 0;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            b[i][j] = a[i][j];
        }
    }
}

bool check(){//하나라도 적이 있으면 true반환
    bool temp = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(b[i][j] == 1){
                temp = true;
            }
        }
    }
    return temp;
}

void fight(){
    copy();
    int kill = 0;
    while(check()){
        //일단 궁수가 적을 공격한다
        vector<pair<int, int>> final_target;
        for(int k=0; k<v.size(); k++){
            vector<pair<int, pair<int, int>>> target;
            int x = v[k].first;
            int y = v[k].second;//궁수의 위치
            for(int i=0; i<n; i++){//적의 위치
                for(int j=0; j<m; j++){
                    if(b[i][j] == 1 && ((abs(x-i)+abs(y-j)) <= d)){
                        //공격가능
                        target.push_back(make_pair((abs(x-i)+abs(y-j)), make_pair(j, i)));
                    }
                }
            }
            if(target.size() > 0){
                sort(target.begin(), target.end());//열 기준 정렬(가장 왼쪽)   
                final_target.push_back(make_pair(target[0].second.second, target[0].second.first));
                target.clear();                
            }
        }

        for(int i=0; i<final_target.size(); i++){
            if(b[final_target[i].first][final_target[i].second] == 1){
                kill++;
                b[final_target[i].first][final_target[i].second] = 0; 
            }
        }
        final_target.clear();

        //적이 한 칸 아래로 이동한다.        
        int temp_[16][16] = {0, };
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                temp_[i+1][j] = b[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                b[i][j] = temp_[i][j];
            }
        }
    }
    final = max(final, kill);
}

//일단 궁수 3명의 위치를 잡는다.(조합 m개 자리중에 3개)
void choose(int num, int idx){
    if(num == 3){
        //궁수3명의 위치
        v.clear();
        for(int j=0; j<m; j++){
            if(visited[j] == true){
                v.push_back(make_pair(n, j));
            }
        }
        fight();
    }

    for(int i=idx; i<m; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        choose(num+1, i);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>m>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    choose(0, 0);
    fight();
    cout<<final<<"\n";
}