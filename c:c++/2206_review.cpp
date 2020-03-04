//벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int map[1001][1001] = {0, };
int visited[1001][1001][2] = {0, };
string s;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = INT_MAX;
int n, m;

//(0, 0)에서 (n-1, m-1)로 도착하는 데에 최소경로
//BFS로 가면서 num이 0이면 벽 하나를 부수고 이동가능
//but, num이 이미 1이면 더 이상 벽은 못 부순다.

void play(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    visited[0][0][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second.first;//부순 벽의 개수
        int move = q.front().second.second;//총 이동 수
        q.pop();

        if(x==n-1 && y==m-1){//최종 도착지점
            final = min(final, move);
            break;
        }

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                if(map[final_x][final_y] == 1 && !visited[final_x][final_y][1]){//벽이다.
                    if(num == 0){
                        visited[final_x][final_y][1] = 1;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, move+1)));
                    }
                }else if(map[final_x][final_y] == 0 && !visited[final_x][final_y][num]){//빈 공간이면 그냥 간다.
                    visited[final_x][final_y][num] = 1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(num, move+1)));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j]-'0';
        }
    }
    play();
    if(final == INT_MAX){//최종 도착지점에 도착하지 못함
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}