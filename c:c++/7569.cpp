//토마토(3차원.ver)
#include <iostream>
#include <queue>
using namespace std;

int m, n, h;
queue<pair<pair<int, int>, pair<int, int>>> q;
int tomato[101][101][101] = {0, };//행, 열, 높이
int visited[101][101][101] = {0, };
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int total = 0;//안 읽은 토마토
int final = 0;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int height = q.front().second.first;
        int num = q.front().second.second;
        visited[x][y][height] = 1;
        q.pop();

        for(int i=0; i<6; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nh = height+dh[i];
            if(0<=nx && nx<n && 0<=ny && ny<m && 0<=nh && nh<h && !visited[nx][ny][nh]){
                if(tomato[nx][ny][nh] == 0){
                    visited[nx][ny][nh] = 1;
                    tomato[nx][ny][nh] = 1;
                    q.push(make_pair(make_pair(nx, ny), make_pair(nh, num+1)));
                    total--;
                }
            }
        }

        if(total == 0){//다 익었다.
            final = num+1;
            break;
        }
    }
}

int main(){
    cin>>m>>n>>h;
    for(int i=0; i<h; i++){
        for(int k=0; k<n; k++){
            for(int t=0; t<m; t++){
                cin>>tomato[k][t][i];
                if(tomato[k][t][i] == 1){
                    q.push(make_pair(make_pair(k, t), make_pair(i, 0)));
                }
                else if(tomato[k][t][i] == 0){
                    total++;
                }
            }
        }
    }
    if(total == 0){
        cout<<"0"<<"\n";
        return 0;
    }
    bfs();
    if(total == 0){
        cout<<final<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
    return 0;
}