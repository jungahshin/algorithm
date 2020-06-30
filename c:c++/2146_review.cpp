//다리 만들기
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int n;
int earth[101][101] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int final = INT_MAX;

void bfs()
{
    int visited[101][101] = {0, };
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(earth[i][j] == 1 && !visited[i][j]){
                //먼저 1인 부분의 섬을 다 칠해주기
                queue<pair<int, int>> q;
                queue<pair<pair<int, int>, int>> sea;
                sea.push(make_pair(make_pair(i, j), 0));
                q.push(make_pair(i, j));
                int visited2[101][101] = {0, };

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    visited[x][y] = 1;
                    visited2[x][y] = 1;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny]){
                            if(earth[nx][ny] == 1){
                                visited[nx][ny] = 1;
                                visited2[nx][ny] = 1;
                                sea.push(make_pair(make_pair(nx, ny), 0));
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }

                while(!sea.empty()){
                    int x = sea.front().first.first;
                    int y = sea.front().first.second;
                    int num = sea.front().second;
                    sea.pop();

                    if(earth[x][y] == 1 && num>0){
                        final = min(final, num-1);
                        break;
                    }
                    
                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(0<=nx && nx<n && 0<=ny && ny<n && !visited2[nx][ny]){
                            if(earth[nx][ny] == 0 || earth[nx][ny] == 1){
                                visited2[nx][ny] = 1;
                                sea.push(make_pair(make_pair(nx, ny), num+1));
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>earth[i][j];
        }
    }
    bfs();
    cout<<final<<"\n";
    return 0;
}