//나이트 이동
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int testcase, n, start_x, start_y, end_x, end_y;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int visited[301][301] = {0, };
int final = 0;

void bfs(int start_x, int start_y)
{
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(start_x, start_y), 0));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        q.pop();

        if(x == end_x && y == end_y){
            final = num;
            break;
        }

        for(int i=0; i<8; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push(make_pair(make_pair(nx, ny), num+1));
            }
        }        
    }
    
}

int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        memset(visited, 0, sizeof(visited));
        cin>>n;
        cin>>start_x>>start_y;
        cin>>end_x>>end_y;        
        bfs(start_x, start_y);
        cout<<final<<"\n";
    }

    return 0;
}