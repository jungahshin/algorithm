//아기 상어 복습
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int sea[21][21] = {0, };
int visited[21][21] = {0, };
int shark_x, shark_y, shark_size;//아기상어 위치
int final = 0;//최종 시간
vector<pair<int, pair<int, int>>> fish;//먹을 수 있는 물고기 위치
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void go(){
    int num = 0;//아기상어가 먹은 물고기 수
    int sec = 0;//시간(초)
    queue<pair<pair<int, int>, int>> q;//위치와 시간
    while(1){
        fish.clear();
        memset(visited, 0, sizeof(visited));
        q.push(make_pair(make_pair(shark_x, shark_y), 0));
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time_ = q.front().second;
            visited[x][y] = 1;
            q.pop();

            for(int i=0; i<4; i++){
                int final_x = x+dx[i];
                int final_y = y+dy[i];
                if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                    visited[final_x][final_y] = 1;
                    if(sea[final_x][final_y] == shark_size || sea[final_x][final_y] == 0){//지나간다.
                        q.push(make_pair(make_pair(final_x, final_y), time_+1));
                    }
                    if(sea[final_x][final_y]<shark_size && sea[final_x][final_y] != 0){//먹는다.
                        fish.push_back(make_pair(time_+1, make_pair(final_x, final_y)));
                    }
                }
            }
        }
        //먹을 수 있는 물고기 수가 없다면 바로 끝
        if(fish.size() == 0){
            final = sec;
            break;
        }
        //먹을 수 있는 물고기가 있다.
        vector<pair<int, int>> temp;
        sort(fish.begin(), fish.end());//칸 순으로
        for(int i=0; i<fish.size(); i++){
            if(fish[0].first == fish[i].first){
                temp.push_back(make_pair(fish[i].second.first, fish[i].second.second));
            }
        }
        sort(temp.begin(), temp.end());
        int fish_x = temp[0].first;
        int fish_y = temp[0].second;
        int fish_sec = fish[0].first;

        //먹은 물고기 없애기
        sea[fish_x][fish_y] = 0;
        //아기상어 위치 update
        shark_x = fish_x;
        shark_y = fish_y;
        num++;
        if(num == shark_size){
            shark_size++;
            num = 0;
        }

        sec += fish_sec;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>sea[i][j];
            if(sea[i][j] == 9){
                shark_x = i;
                shark_y = j;
                shark_size = 2;
                sea[shark_x][shark_y] = 0;
            }
        }
    }
    go();
    cout<<final<<"\n";
    return 0;
}