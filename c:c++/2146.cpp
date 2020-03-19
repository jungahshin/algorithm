//다리 만들기
#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int n;
int map[102][102] = {0, };
int visited_total[102][102] = {0, };//전체적으로 사용하는
int visited[102][102] = {0, };//내부에서 사용하는
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = INT_MAX;

void go(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited_total[i][j] && map[i][j] == 1){
                memset(visited, 0, sizeof(visited));
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                queue<pair<pair<int, int>, int>> temp;
                temp.push(make_pair(make_pair(i, j), 0));

                //visited_total 채워주기
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    visited_total[x][y] = 1;
                    visited[x][y] = 1;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int final_x = x+dx[k];
                        int final_y = y+dy[k];
                        if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited_total[final_x][final_y]){
                            if(map[final_x][final_y] == 1){
                                visited_total[final_x][final_y] = 1;
                                visited[final_x][final_y] = 1;
                                q.push(make_pair(final_x, final_y));
                                temp.push(make_pair(make_pair(final_x, final_y), 0));
                            }
                        }
                    }
                }

                while(!temp.empty()){
                    int x = temp.front().first.first;
                    int y = temp.front().first.second;
                    int num = temp.front().second;
                    visited[x][y] = 1;
                    temp.pop();

                    if(map[x][y] == 1 && num>0){
                        final = min(num, final);
                        break;
                    }

                    for(int k=0; k<4; k++){
                        int final_x = x+dx[k];
                        int final_y = y+dy[k];
                        if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                            visited[final_x][final_y] = 1;
                            if(map[final_x][final_y] == 0){
                                temp.push(make_pair(make_pair(final_x, final_y), num+1));
                            }
                            if(map[final_x][final_y] == 1 && num>0){
                                temp.push(make_pair(make_pair(final_x, final_y), num));
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    go();
    cout<<final<<"\n";
}