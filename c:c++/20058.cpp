#include <iostream>
#include <queue>
#include <cmath>
 
using namespace std;
 
int n, q, N;
int ice[65][65] = {0, };
int divide[1001] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int total = 0;
 
void rotate(int x, int y, int num)
{
    queue<int> q;
    for(int i=x; i<x+num; i++){
        for(int j=y; j<y+num; j++){
            q.push(ice[i][j]);
        }
    }
 
    for(int i=(y+num-1); i>=(y); i--){
        for(int j=x; j<(x+num); j++){
            int temp = q.front();
            q.pop();
            ice[j][i] = temp;
        }
    }
}
 
void bfs()
{
    int temp[65][65] = {0, };
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = ice[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(temp[i][j]==0) continue;
            int cnt = 0;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(0<=nx && nx<N && 0<=ny && ny<N && temp[nx][ny]!=0){
                    cnt++;
                }
            }
            if(cnt<3){
                if(ice[i][j]==0) continue;
                ice[i][j]--;
                total--;
            }
        }
    }
}
 
int area()
{
    int visited[65][65] = {0, };
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] || ice[i][j]==0) continue;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int cnt = 0;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y] = 1;
                cnt++;
                q.pop();
 
                for(int k=0; k<4; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(0<=nx && nx<N && 0<=ny && ny<N && !visited[nx][ny]){
                        if(ice[nx][ny]!=0){
                            visited[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
 
            ans = max(ans, cnt); 
        }
    }
 
    return ans;
}
 
int main()
{
    cin>>n>>q;
    N = pow(2, n);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>ice[i][j];
            total += ice[i][j];
        }
    }
 
    for(int i=0; i<q; i++){
        cin>>divide[i];
    }
 
    for(int i=0; i<q; i++){ // 총 q번 파이어스톰 시전
        int cnt = 0;
        int num = pow(2, divide[i]);
        
        // 회전
        for(int j=0; j<N; j+=num){
            for(int k=0; k<N; k+=num){
                rotate(j, k, num);
            }
        }
 
        // 3개 이상 인접하지 않은 곳 얼음 -1
        bfs();
    }
 
    cout<<total<<"\n";
    cout<<area()<<"\n";
 
    return 0;
}