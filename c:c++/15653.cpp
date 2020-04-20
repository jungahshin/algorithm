//구슬 탈출4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
string s;
char bid[11][11];
int blue_x, blue_y, red_x, red_y;
int visited[11][11][11][11] = {0, };//red_x, red_y, blue_x, blue_y
//방향 0-상, 1-오, 2-아래, 3-왼
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int play(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(red_x, red_y), make_pair(blue_x, blue_y)));
    visited[red_x][red_y][blue_x][blue_y] = 1;

    int num = 0;//이동 수

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int bx = q.front().second.first;
            int by = q.front().second.second;
            q.pop();


            for(int j=0; j<4; j++){
                bool check_red = false;
                bool check_blue = false;
                int nx = x, ny = y, nbx = bx, nby = by;
                while(bid[nx+dx[j]][ny+dy[j]] == '.' || bid[nx+dx[j]][ny+dy[j]] == 'O'){
                    nx += dx[j];
                    ny += dy[j];
                    if(bid[nx][ny] == 'O'){
                        check_red = true;
                    }
                }
                while(bid[nbx+dx[j]][nby+dy[j]] == '.' || bid[nbx+dx[j]][nby+dy[j]] == 'O'){
                    nbx += dx[j];
                    nby += dy[j];
                    if(bid[nbx][nby] == 'O'){
                        check_blue = true;
                    }
                }

                if(check_red == false && check_blue == true){
                    continue;
                }

                if(nx == nbx && ny == nby){
                    if(check_red == true && check_blue == true){
                        continue;
                    }
                    if(abs(nx-x)+abs(ny-y)>abs(nbx-bx)+abs(nby-by)){//빨간색이 더 많이 움직인 경우->더 전으로 가야한다.
                        nx -= dx[j];
                        ny -= dy[j];
                    }else{
                        nbx -= dx[j];
                        nby -= dy[j];
                    }
                }

                if(check_red == true && check_blue == false){
                    return num+1;
                }

                if(!visited[nx][ny][nbx][nby]){
                    visited[nx][ny][nbx][nby] = 1;
                    q.push(make_pair(make_pair(nx, ny), make_pair(nbx, nby)));
                }
            }
        }
        num++;
    }
    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            bid[i][j] = s[j];
            if(s[j] == 'B'){
                blue_x = i;
                blue_y = j;
                bid[i][j] = '.';
            }else if(s[j] == 'R'){
                red_x = i;
                red_y = j;
                bid[i][j] = '.';
            }
        }
    }
    int final = play();
    cout<<final<<"\n";
    return 0;
}