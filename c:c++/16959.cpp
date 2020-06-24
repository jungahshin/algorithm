//체스판 여행1
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, x, y, sec, num, horse;
int chess[11][11] = {0, };
map<int, pair<int, int> > m;//숫자의 위치(x, y)저장
int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[8] = {1, -1, -1, 1, 2, 2, -2, -2};//나이트의 이동
int rx[4] = {-1, -1, 1, 1};//비숍의 이동
int ry[4] = {-1, 1, -1, 1};
int tx[4] = {-1, 1, 0, 0};//룩의 이동
int ty[4] = {0, 0, -1, 1};
int visited[11][11][101][4] = {0, };
int final = 0;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>chess[i][j];
            m[chess[i][j]] = make_pair(i, j);
        }
    }

    queue <tuple<int,int,int,int,int> > q;

    q.push(make_tuple(m[1].first, m[1].second, 0, 2, 1));//나이트(위치, 걸린 시간, 숫자, 말의 종류)
    q.push(make_tuple(m[1].first, m[1].second, 0, 2, 2));//비숍
    q.push(make_tuple(m[1].first, m[1].second, 0, 2, 3));//룩

    while(!q.empty()){
        tie(x, y, sec, num, horse) = q.front();
        q.pop();

        int next_x = m[num].first;
        int next_y = m[num].second;

        //도착
        if(num == n*n+1){
            final = sec;
            break;
        }

        //말이 나이트
        if(horse == 1){
            for(int i=0; i<8; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(0<=nx && nx<n && 0<=ny && ny<n){
                    if(visited[nx][ny][num][horse] == true) continue;
                    visited[nx][ny][num][horse] = true;

                    if(nx == next_x && ny == next_y){
                        q.push(make_tuple(nx, ny, sec+1, num+1, horse));
                    }else{
                        q.push(make_tuple(nx, ny, sec+1, num, horse));
                    }
                }
            }
        }

        //말이 비숍
        else if(horse == 2){
            for(int i=0; i<4; i++){
                int nx = x;
                int ny = y;
                while(0<=nx && nx<n && 0<=ny && ny<n){
                    nx += rx[i];
                    ny += ry[i];

                    if(0<=nx && nx<n && 0<=ny && ny<n){
                        if(visited[nx][ny][num][horse] == true) continue;
                        visited[nx][ny][num][horse] = true;

                        if(nx == next_x && ny == next_y){
                            q.push(make_tuple(nx, ny, sec+1, num+1, horse));
                        }else{
                            q.push(make_tuple(nx, ny, sec+1, num, horse));
                        }                        
                    }
                }
            }
        }

        //말이 룩
        else if(horse == 3){
            for(int i=0; i<4; i++){
                int nx = x;
                int ny = y;
                while(0<=nx && nx<n && 0<=ny && ny<n){
                    nx += tx[i];
                    ny += ty[i];

                    if(0<=nx && nx<n && 0<=ny && ny<n){
                        if(visited[nx][ny][num][horse] == true) continue;
                        visited[nx][ny][num][horse] = true;

                        if(nx == next_x && ny == next_y){
                            q.push(make_tuple(nx, ny, sec+1, num+1, horse));
                        }else{
                            q.push(make_tuple(nx, ny, sec+1, num, horse));
                        }                        
                    }
                }
            }
        }

        //말 바꿈
        for(int i=1; i<=3; i++){
            if(i == horse) continue;
            if(visited[x][y][num][i] == true) continue;

            visited[x][y][num][i] = 1;
            q.push(make_tuple(x, y, sec+1, num, i));
        }
    }


    cout<<final<<"\n";
    return 0;
}