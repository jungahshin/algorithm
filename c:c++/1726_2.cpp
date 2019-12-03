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
int dx[4] = {0, 0, 1, -1};//동, 서, 남, 북
int dy[4] = {1, -1, 0, 0};
int final = INT_MAX;
 
void go(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(start_x, start_y), make_pair(start_dir, 0)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int num = q.front().second.second;
        q.pop();
        visited[x][y][dir] = 1;

        if(num > final){
            continue;
        }

        //도착지점에 왔는지 확인
        if(x == end_x && y == end_y && dir == end_dir){
            final = min(final, num);
            continue;
        }

        //k(1,2,3)만큼 이동하기!
        for(int i=1; i<=3; i++){//1, 2, 3만큼 이동
            int final_x = x + (dx[(dir-1)] * i);
            int final_y = y + (dy[(dir-1)] * i);

            if(visited[final_x][final_y][dir]){
                continue;
            }

            if(1 <= final_x && final_x <= m && 1 <= final_y && final_y <= n && a[final_x][final_y] == 0){
                visited[final_x][final_y][dir] = 1;
                q.push(make_pair(make_pair(final_x, final_y), make_pair(dir, num+1)));
            }else{//만족하지 못한다면 어차피 그 방향으로는 이동하지 못하니까 나온다.
                break;
            }
        }

        //방향 회전하기!
        if(dir == 1){//동
            //왼(4)
            if(!visited[x][y][4]){
                visited[x][y][4]= 1;
                q.push(make_pair(make_pair(x, y), make_pair(4, num+1)));
            }
            //오(3)
            if(!visited[x][y][3]){
                visited[x][y][3] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(3, num+1)));
            }
        }else if(dir == 2){
            //왼(3)
            if(!visited[x][y][3]){
                visited[x][y][3] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(3, num+1)));
            }
            //오(4)
            if(!visited[x][y][4]){
                visited[x][y][4] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(4, num+1)));
            }
        }else if(dir == 3){
            //왼(1)
            if(!visited[x][y][1]){
                visited[x][y][1] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(1, num+1)));
            }
            //오(2)
            if(!visited[x][y][2]){
                visited[x][y][2] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(2, num+1)));
            }
        }else if(dir == 4){
            //왼(2)
            if(!visited[x][y][2]){
                visited[x][y][2] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(2, num+1)));
            }
            //오(1)
            if(!visited[x][y][1]){
                visited[x][y][1] = 1;
                q.push(make_pair(make_pair(x, y), make_pair(1, num+1)));
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