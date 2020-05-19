//로봇청소기
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int w, h, start_x, start_y;
int visited[21][21][1<<11] = {0, };
string s;
int room[21][21] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;
bool check = false;

int clean(int a, int b, int all){
    int total = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(a, b), 0));
    visited[a][b][0] = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int bit = q.front().second;
        q.pop();

        if(all == bit){
            check = true;
            total = visited[x][y][bit];
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<h && 0<=ny && ny<w && room[nx][ny] != -1){
                if(room[nx][ny] == 0){
                    if(!visited[nx][ny][bit]){
                        visited[nx][ny][bit] = visited[x][y][bit]+1;
                        q.push(make_pair(make_pair(nx, ny), bit));
                    }
                }
                if(room[nx][ny]>0){//더럽다.
                    int temp = bit | (1<<(room[nx][ny]-1));
                    if(!visited[nx][ny][temp]){
                        visited[nx][ny][temp] = visited[x][y][bit]+1;
                        q.push(make_pair(make_pair(nx, ny), temp));
                    }
                }
            }
        }
    }

    return total;
}

int main(){
    while(1){
        memset(visited, 0, sizeof(visited));
        memset(room, 0, sizeof(room));
        final = 0;
        check = false;
        cin>>w>>h;
        if(w==0 && h==0){
            break;
        }
        int num = 0;
        for(int i=0; i<h; i++){
            cin>>s;
            for(int j=0; j<s.size(); j++){
                // room[i][j] = s[j];
                if(s[j] == 'o'){//시작위치
                    start_x = i;
                    start_y = j;

                }else if(s[j] == '*'){
                    num++;
                    room[i][j] = num;
                }else if(s[j] == 'x'){
                    room[i][j] = -1;
                }
            }
        }
        int all = 0;
        for(int i=1; i<=num; i++){
            all = all | (1<<(i-1));
        }
        final = clean(start_x, start_y, all);
        if(check == false){
            cout<<"-1"<<"\n";
        }else{
            cout<<final<<"\n";
        }
    }
    return 0;
}
