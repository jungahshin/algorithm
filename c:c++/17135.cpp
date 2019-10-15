//캐슬디펜스
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int a[16][16] = {0, };//행은 성을 위해 한 줄 더
int a_copy[16][16] = {0, };
int a_copy_1[16][16] = {0, };
vector<pair<int, int>> army;//적의 위치-->턴마다 업데이트 되어야 해
vector<pair<int, int>> army_copy;
vector<pair<int, int>> palace;
vector<pair<int, int>> bts;//궁수의 위치(3개)
vector<pair<int, int>> death;
vector<pair<int, int>> location;
bool visited[16];
int final = 0;
int n, m, d;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
}

void copy_army(){
    for(int i=0; i<army.size(); i++){
        army_copy.push_back(make_pair(army[i].first, army[i].second));
    }
}

bool check(){
    bool temp = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_copy[i][j] != 0){
                temp = false;
            }
        }
    }
    return temp;
}

void attack(){
    copy();
    copy_army();
    int kill = 0;
    while(!check()){//1의 값이 하나라도 있으면 계속 진행
        for(int i=0; i<bts.size(); i++){
            for(int j=0; j<army_copy.size(); j++){
                if(abs(bts[i].first - army_copy[j].first)+abs(bts[i].second-army_copy[j].second) <= d){
                    //거리와 열의 위치 넣어주기(death)
                    death.push_back(make_pair(abs(bts[i].first - army_copy[j].first)+abs(bts[i].second-army_copy[j].second), army_copy[j].second));
                    //행과 열 넣어주기(location)
                    location.push_back(make_pair(army_copy[j].first, army_copy[j].second));
                }
            }
            if(death.size() != 0){
                sort(death.begin(), death.end());
                //death[0].second-->열의 위치
                sort(location.begin(), location.end());
                //가장 끝에서 부터 열이 같은 location을 찾으면 break;
                for(int i=location.size()-1; i>=0; i--){
                    if(location[i].second == death[0].second){
                        if(a_copy[location[i].first][location[i].second] != 0){
                            a_copy[location[i].first][location[i].second] = 0;
                            kill += 1;
                            break;
                        }
                    }
                }
            }
            death.clear();
            location.clear();
        }
        //a_copy값들 다 바꾸기(이동)
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                a_copy_1[i+1][j] = a_copy[i][j];
            }
        }
        for(int j=0; j<m; j++){
            a_copy_1[0][j] = 0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a_copy[i][j] = a_copy_1[i][j];
            }
        }
        army_copy.clear();
        //새로운 적군의 위치 army에 넣기 (a_copy에 1로 남아있는 애들 넣어주기)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a_copy[i][j] == 1){//적군으로 남아있음
                    army_copy.push_back(make_pair(i, j));
                }
            }
        }
    }
    army_copy.clear();
    final = max(final, kill);
}

void put(){
    for(int i=0; i<palace.size(); i++){
        if(visited[i] == true){
            bts.push_back(make_pair(palace[i].first, palace[i].second));
        }
    }
    attack();
    bts.clear();
}

void choose(int idx, int num){
    if(num == 3){
        put();
        return;
    }
    for(int i=idx; i<palace.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        choose(i, num+1);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>m>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == 1){
                army.push_back(make_pair(i, j));
            }
        }
    }
    for(int i=0; i<m; i++){
        palace.push_back(make_pair(n, i));//궁수가 있을 수 있는 위치 넣기
    }
    choose(0, 0);

    cout<<final<<"\n";
    return 0;
}