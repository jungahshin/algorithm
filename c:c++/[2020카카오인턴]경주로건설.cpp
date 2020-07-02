//2020 카카오인턴 #4번(bfs)
//경주로 건설
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int n;
int board[26][26] = {0, };
int move_num, dir, dir_num;
int answer = INT_MAX;
int visited[26][26][5][700] = {0, };//위치, 방향
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, tuple<int, int, int>>> q;//위치, (이동거리, 방향, 방향 전환 수)

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    //초기 2방향 가능(오, 아래)
    q.push(make_pair(make_pair(0, 0), make_tuple(0, 1, 0)));
    q.push(make_pair(make_pair(0, 0), make_tuple(0, 2, 0)));
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        tie(move_num, dir, dir_num) = q.front().second;
        visited[x][y][dir][dir_num] = 1;
        q.pop();
                
        if(x==n-1 && y==n-1){
            int total = move_num*100+dir_num*500;
            answer = min(answer, total);
        }
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(board[nx][ny] == 0){
                    if(dir == i){//전과 같은 방향
                        if(!visited[nx][ny][i][dir_num]){
                           visited[nx][ny][i][dir_num] = 1;
                            q.push(make_pair(make_pair(nx, ny), make_tuple(move_num+1, i, dir_num))); 
                        }
                    }else{//전과 다른 방향
                        if(!visited[nx][ny][i][dir_num+1]){
                            visited[nx][ny][i][dir_num+1] = 1;
                            q.push(make_pair(make_pair(nx, ny), make_tuple(move_num+1, i, dir_num+1)));
                        }
                    }
                }
            }
        }
    }
    
    cout<<answer<<"\n";
    return 0;
}