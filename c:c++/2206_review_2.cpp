//벽 부수고 이동
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a[1001][1001] = {0, };
int visited[1001][1001][2] = {0, };//위치와 벽을 한개 이미 부쉈는지 여부
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
string s;
bool check = false;
int final = 0;

void go(int start_x, int start_y){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(start_x, start_y), make_pair(0, 1)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second.first;
        int num = q.front().second.second;
        q.pop();
        visited[x][y][wall] = 1;

        if(x == n && y == m){//도착지점에 도착
            final = num;
            check = true;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(1<=nx && nx<=n && 1<=ny && ny<=m){
                if(a[nx][ny] == 1){//벽이면 일단 부숴
                    if(wall == 1){//이미 부쉈으면 패스
                        continue;
                    }
                    if(!visited[nx][ny][1]){
                        visited[nx][ny][1] = 1;
                        q.push(make_pair(make_pair(nx, ny), make_pair(1, num+1)));
                    }
                }else{
                    if(!visited[nx][ny][wall]){
                        visited[nx][ny][wall] = 1;
                        q.push(make_pair(make_pair(nx, ny), make_pair(wall, num+1)));
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            a[i][j+1] = s[j]-'0';
        }
    }
    go(1, 1);
    if(check == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}