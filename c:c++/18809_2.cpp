//Gaaaaaaaaaarden
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, g, r;
int garden[51][51] = {0, };
int possible = 0;
vector<pair<int, int>> v1;//첫 번째 조합
vector<pair<int, int>> v2;//두 번째 조합
queue<pair<pair<int, int>, int>> green;
queue<pair<pair<int, int>, int>> red;
int visited1[11] = {0, };
int visited2[11] = {0, };
int g_visited[51][51] = {0, };
int r_visited[51][51] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;

void go(){//bfs진행
    int flower = 0;
    int number[51][51] = {0, };//번호(1->초록, 2->빨강) 저장
    int time[51][51] = {0, };//최근 시간 저장
    //초록과 빨강 둘 다 동시에 진행
    while(!green.empty() || !red.empty()){
        int green_num = green.size();
        for(int i=0; i<green_num; i++){
            int x = green.front().first.first;
            int y = green.front().first.second;
            int num = green.front().second;
            g_visited[x][y] = 1;
            green.pop();

            if(number[x][y] == -1){
                continue;
            }

            for(int j=0; j<4; j++){
                int final_x = x+dx[j];
                int final_y = y+dy[j];
                if(0<=final_x && final_x<n && 0<=final_y && final_y<m && !g_visited[final_x][final_y]){
                    g_visited[final_x][final_y] = 1;
                    if(garden[final_x][final_y] == 1 || garden[final_x][final_y] == 2){
                        green.push(make_pair(make_pair(final_x, final_y), num+1));
                        number[final_x][final_y] = 1;
                        time[final_x][final_y] = num+1;
                    }
                }
            }
        }

        int red_num = red.size();
        for(int i=0; i<red_num; i++){
            int x = red.front().first.first;
            int y = red.front().first.second;
            int num = red.front().second;
            r_visited[x][y] = 1;
            red.pop();

            if(number[x][y] == -1){
                continue;
            }

            for(int j=0; j<4; j++){
                int final_x = x+dx[j];
                int final_y = y+dy[j];
                if(0<=final_x && final_x<n && 0<=final_y && final_y<m && !r_visited[final_x][final_y]){
                    r_visited[final_x][final_y] = 1;
                    if(garden[final_x][final_y] == 1 || garden[final_x][final_y] == 2){
                        red.push(make_pair(make_pair(final_x, final_y), num+1));
                        if(number[final_x][final_y] != 2 && time[final_x][final_y] == num+1){
                            flower++;
                            number[final_x][final_y] = -1;
                        }
                    }
                }
            }
        }
    }
    final = max(final, flower);
}

void choose2(int num, int idx, int final, int check){
    if(num == final){
        memset(g_visited, 0, sizeof(g_visited));
        memset(r_visited, 0, sizeof(r_visited));
        if(check == 1){
            for(int i=0; i<v2.size(); i++){
                if(visited2[i] == true){//red
                    red.push(make_pair(make_pair(v2[i].first, v2[i].second), 0));
                    r_visited[v2[i].first][v2[i].second] = 1;
                }else{
                    green.push(make_pair(make_pair(v2[i].first, v2[i].second), 0));
                    g_visited[v2[i].first][v2[i].second] = 1;
                }
            }            
        }else if(check == 2){
            for(int i=0; i<v2.size(); i++){
                if(visited2[i] == true){//green
                    green.push(make_pair(make_pair(v2[i].first, v2[i].second), 0));
                    g_visited[v2[i].first][v2[i].second] = 1;
                }else{
                    red.push(make_pair(make_pair(v2[i].first, v2[i].second), 0));
                    r_visited[v2[i].first][v2[i].second] = 1;
                }
            }  
        }
        go();
        return;
    }

    for(int i=idx; i<v2.size(); i++){
        if(visited2[i] == true) continue;
        visited2[i] = true;

        choose2(num+1, i, final, check);
        visited2[i] = false;
    }
}

void choose1(int num, int idx, int final, int check){
    if(num == final){
        v2.clear();
        if(check == 1){
            for(int i=0; i<v1.size(); i++){
                if(visited1[i] == true){
                    v2.push_back(make_pair(v1[i].first, v1[i].second));
                }
            }            
        }else if(check == 2){
            for(int i=0; i<v1.size(); i++){
                if(visited1[i] == false){
                    v2.push_back(make_pair(v1[i].first, v1[i].second));
                }
            }  
        }
        if(g>r){
            choose2(0, 0, r, 1);//visited한 곳이 red
        }else{
            choose2(0, 0, g, 2);//visited한 곳이 green
        }
        return;
    }

    for(int i=idx; i<v1.size(); i++){
        if(visited1[i] == true) continue;
        visited1[i] = true;

        choose1(num+1, i, final, check);
        visited1[i] = false;
    }
}

int main(){
    cin>>n>>m>>g>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>garden[i][j];
            if(garden[i][j] == 2){
                v1.push_back(make_pair(i, j));
                possible++;
            }
        }
    }
    if((possible-(g+r))>(g+r)){
        choose1(0, 0, g+r, 1);
    }else{
        choose1(0, 0, possible-(g+r), 2);
    }
    cout<<final<<"\n";
    return 0;
}