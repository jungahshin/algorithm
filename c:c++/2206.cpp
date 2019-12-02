//벽 부수고 이동하기-->최단 경로는 무조건 bfs!!!
//bfs
//입력값이 붙어있다....ㅎㅎ(scanf사용하기)
//visited는 3차원 배열로 구분해주기
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, m;
string s;
int map[1111][1111];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[1111][1111][2] = {0, };
int final = INT_MAX;//최단 경로 수

void go(int a, int b, int map[][1111]){//최단 경로를 찾아 이동하기-->부수면서 확인하기!!!!
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(a, b), make_pair(1, 0)));//위치와 경로 수, 부순 벽의 수를 저장하기!
    
    while(!q.empty()){//(n-1, m-1)까지 도착할 떄까지의 최단 경로 구하기!
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second.first;
        int break_wall = q.front().second.second;
        q.pop();
        visited[x][y][break_wall] = 1;

        //도착 지점인지 확인하기 --> 최단 경로인지 확인하기
        if((x == (n-1)) && (y == (m-1))){
            final = min(final, num);
            return;
        }

        for(int i=0; i<4; i++){
            int final_x = x + dx[i];
            int final_y = y + dy[i];
            if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                if(map[final_x][final_y] == 0 && !visited[final_x][final_y][break_wall]){
                    if(break_wall == 0){
                        visited[final_x][final_y][break_wall] = 1;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, 0)));                        
                    }else if(break_wall == 1){
                        visited[final_x][final_y][break_wall] = 1;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, 1)));  
                    }
                }
                if(map[final_x][final_y] == 1 && !visited[final_x][final_y][break_wall] && break_wall == 0){//벽을 부순다.
                    visited[final_x][final_y][1] = 1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, 1)));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    go(0, 0, map);//벽을 안 부셨을 때의 최단경로
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}