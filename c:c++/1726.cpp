//로봇-->최소 명령
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m;
int start_x, start_y, start_dir, end_x, end_y, end_dir = 0;
int a[102][102] = {0, };
int visited[102][102][5] = {0, };//3번째 요소는 명령의 수행 횟수-->visited에 방문 횟수를 넣어준다.
int dir_visited[102][102][5] = {0, };//위치랑 방향으로 
int dx[4] = {0, 0, 1, -1};//동, 서, 남, 북
int dy[4] = {1, -1, 0, 0};
int final = INT_MAX;
 
void go(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    queue<int> q_check;
    q.push(make_pair(make_pair(start_x, start_y), make_pair(start_dir, 0)));//가는 k
    q_check.push(0);

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int num = q.front().second.second;
        int temp = q_check.front();//앞으로 전진하는 수
        q.pop();
        q_check.pop();
        visited[x][y][dir] = num;

        if(num > final){
            continue;
        }

        //도착지점에 왔는지 확인
        if(x == end_x && y == end_y && dir == end_dir){
            final = min(final, num);
            continue;
        }

        //그냥 동서남북으로 이동하기!
        if(temp == 0){
            int final_x = x + dx[(dir-1)];
            int final_y = y + dy[(dir-1)];
            if(1 <= final_x && final_x <= m && 1 <= final_y && final_y <= n){
                if(a[final_x][final_y] == 0 && visited[final_x][final_y][dir] != (num+1)){
                    visited[final_x][final_y][dir] = num+1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(dir, num+1)));//방향은 원래 그대로!
                    q_check.push(temp+1);
                }
            }
        }
        if(0 < temp && temp < 3){
            int final_x = x + dx[(dir-1)];
            int final_y = y + dy[(dir-1)];
            if(1 <= final_x && final_x <= m && 1 <= final_y && final_y <= n){
                if(a[final_x][final_y] == 0 && visited[final_x][final_y][dir] != num){//명령 횟수 그대로
                    visited[final_x][final_y][dir] = num;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(dir, num)));//방향은 원래 그대로!
                    q_check.push(temp+1);
                }
            }
        }
        if(temp == 3){//다시 시작!
            int final_x = x + dx[(dir-1)];
            int final_y = y + dy[(dir-1)];
            if(1 <= final_x && final_x <= m && 1 <= final_y && final_y <= n){
                if(a[final_x][final_y] == 0 && visited[final_x][final_y][dir] != (num+1)){
                    visited[final_x][final_y][dir] = num+1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(dir, num+1)));//방향은 원래 그대로!
                    q_check.push(1);
                }
            }            
        }

        //방향 회전하기!
        if(dir == 1){//동
            //왼(4)
            if(dir_visited[x][y][4] != (num+1)){
                dir_visited[x][y][4] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(4, num+1)));
                q_check.push(0);
            }
            //오(3)
            if(dir_visited[x][y][3] != (num+1)){
                dir_visited[x][y][3] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(3, num+1)));
                q_check.push(0);                
            }
        }else if(dir == 2){
            //왼(3)
            if(dir_visited[x][y][3] != (num+1)){
                dir_visited[x][y][3] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(3, num+1)));
                q_check.push(0);                
            }
            //오(4)
            if(dir_visited[x][y][4] != (num+1)){
                dir_visited[x][y][4] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(4, num+1)));
                q_check.push(0);                
            }
        }else if(dir == 3){
            //왼(1)
            if(dir_visited[x][y][1] != (num+1)){
                dir_visited[x][y][1] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(1, num+1)));
                q_check.push(0);                
            }
            //오(2)
            if(dir_visited[x][y][2] != (num+1)){
                dir_visited[x][y][2] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(2, num+1)));
                q_check.push(0);                
            }
        }else if(dir == 4){
            //왼(2)
            if(dir_visited[x][y][2] != (num+1)){
                dir_visited[x][y][2] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(2, num+1)));
                q_check.push(0);
            }
            //오(1)
            if(dir_visited[x][y][1] != (num+1)){
                dir_visited[x][y][1] = num+1;
                q.push(make_pair(make_pair(x, y), make_pair(1, num+1)));
                q_check.push(0);                
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    cin>>start_x>>start_y>>start_dir;
    cin>>end_x>>end_y>>end_dir;
    go();
    cout<<final<<"\n";
    return 0;
}