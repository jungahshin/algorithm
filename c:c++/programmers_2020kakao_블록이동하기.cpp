#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int visited[101][101][3] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int a[101][101] = {0, };

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = board[i-1][j-1];
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q;//위치(x, y), 방향, 걸린 시간
    q.push(make_pair(make_pair(1, 1), make_pair(1, 0)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int num = q.front().second.second;
        visited[x][y][dir] = 1;
        q.pop();
        
        if(dir == 0){//세로
            //그냥 이동
            int sx = x+1;
            int sy = y;
            
            if((x == n && y == n) || (sx == n && sy == n)){
                answer = num;
                break;
            }
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                int snx = sx+dx[i];
                int sny = sy+dy[i];
                if(1<=nx && nx<=n && 1<=ny && ny<=n && 1<=snx && snx<=n && 1<=sny && sny<=n && !visited[nx][ny][dir]){
                    if(a[nx][ny] == 0 && a[snx][sny] == 0){
                        visited[nx][ny][dir] = 1;
                        q.push(make_pair(make_pair(nx, ny), make_pair(dir, num+1)));
                    }
                    
                }
            }

            //회전
            //1)위를 축
            //시계
            if(1<=x && x<=n && 1<=x+1 && x+1<=n && 1<=y && y<=n && 1<=y-1 && y-1<=n){
                if(a[x][y] == 0 && a[x][y-1] == 0 && a[x+1][y-1] == 0 && a[x+1][y] == 0){
                    if(!visited[x][y-1][1]){
                        visited[x][y-1][1] = 1;
                        q.push(make_pair(make_pair(x, y-1), make_pair(1, num+1)));
                    }
                }                
            }
            //반시계
            if(1<=x && x<=n && 1<=y && y<=n && 1<=x+1 && x+1<=n && 1<=y+1 && y+1<=n){
                if(a[x][y] == 0 && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0){
                    if(!visited[x][y][1]){
                        visited[x][y][1] = 1;
                        q.push(make_pair(make_pair(x, y), make_pair(1, num+1)));                       
                    }
                }                
            }

            //2)아래를 축
            //시계
            if(1<=x && x<=n && 1<=y && y<=n && 1<=x+1 && x+1<=n && 1<=y+1 && y+1<=n){
                if(a[x][y] == 0 && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0){
                    if(!visited[x+1][y][1]){
                        visited[x+1][y][1] = 1;
                        q.push(make_pair(make_pair(x+1, y), make_pair(1, num+1)));
                    }
                }                
            }
            //반시계
            if(1<=x && x<=n && 1<=x+1 && x+1<=n && 1<=y && y<=n && 1<=y-1 && y-1<=n){
                if(a[x][y] == 0 && a[x][y-1] == 0 && a[x+1][y-1] == 0 && a[x+1][y] == 0){
                    if(!visited[x+1][y-1][1]){
                        visited[x+1][y-1][1] = 1;
                        q.push(make_pair(make_pair(x+1, y-1), make_pair(1, num+1)));
                    }
                }                
            }
        }else if(dir == 1){//가로
            //그냥 이동
            int sx = x;
            int sy = y+1;
            
            if((x == n && y == n) || (sx == n && sy == n)){
                answer = num;
                break;
            }
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                int snx = sx+dx[i];
                int sny = sy+dy[i];
                if(1<=nx && nx<=n && 1<=ny && ny<=n && 1<=snx && snx<=n && 1<=sny && sny<=n && !visited[nx][ny][dir]){
                    if(a[nx][ny] == 0 && a[snx][sny] == 0){
                        visited[nx][ny][dir] = 1;
                        q.push(make_pair(make_pair(nx, ny), make_pair(dir, num+1)));
                    }
                    
                }
            }

            //회전            
            //1)왼쪽 축
            //시계
            if(1<=x && x<=n && 1<=y && y<=n && 1<=x+1 && x+1<=n && 1<=y+1 && y+1<=n){
                if(a[x][y] == 0 && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0){
                    if(!visited[x][y][0]){
                        visited[x][y][0] = 1;
                        q.push(make_pair(make_pair(x, y), make_pair(0, num+1)));                       
                    }
                }                
            }
            //반시계
            if(1<=x && x<=n && 1<=y && y<=n && 1<=y+1 && y+1<=n && 1<=x-1 && x-1<=n){
               if(a[x][y] == 0 && a[x][y+1] == 0 && a[x-1][y] == 0 && a[x-1][y+1] == 0){
                    if(!visited[x-1][y][0]){
                        visited[x-1][y][0] = 1;
                        q.push(make_pair(make_pair(x-1, y), make_pair(0, num+1)));
                    }
                }                
            }
 
            //2)오른쪽 축
            //시계
            if(1<=x && x<=n && 1<=y && y<=n && 1<=y+1 && y+1<=n && 1<=x-1 && x-1<=n){
                if(a[x][y] == 0 && a[x][y+1] == 0 && a[x-1][y] == 0 && a[x-1][y+1] == 0){
                    if(!visited[x-1][y+1][0]){
                        visited[x-1][y+1][0] = 1;
                        q.push(make_pair(make_pair(x-1, y+1), make_pair(0, num+1)));
                    }
                }                
            }
            //반시계
            if(1<=x && x<=n && 1<=y && y<=n && 1<=x+1 && x+1<=n && 1<=y+1 && y+1<=n){
                if(a[x][y] == 0 && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0){
                    if(!visited[x][y+1][0]){
                        visited[x][y+1][0] = 1;
                        q.push(make_pair(make_pair(x, y+1), make_pair(0, num+1)));
                    }
                }                
            }
        }
    }
    return answer;
}