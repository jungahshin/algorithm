#include <iostream>
#include <queue>
 
using namespace std;
 
int n;
int map[501][501] = {0, };
int dp[501][501] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0;
 
void pandaSearch()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int visited[501][501] = {0, };
 
            while(!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y] = 1;
                q.pop();
 
                for(int k=0; k<4; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny]){
                        if(map[nx][ny]<=map[x][y]) continue;
                        if(dp[nx][ny]<dp[x][y]+1){
                            visited[nx][ny] = 1;
                            dp[nx][ny] = dp[x][y]+1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        } 
    }
}
 
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
 
    pandaSearch();
 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
 
    cout<<ans+1<<"\n";
 
    return 0;
}