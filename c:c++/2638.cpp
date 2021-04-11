#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
 
using namespace std;
 
int n, m;
int cheese[101][101] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool isInside[101][101];
 
void checkInsideOxygen()
{
    int visited[101][101] = {0, };
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;
        isInside[x][y] = false;
 
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
 
            if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
                if(cheese[nx][ny]==0){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }                    
        }
    }
}
 
bool isAllMelt()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cheese[i][j]==1){
                return false;
            }
        }
    }
 
    return true;
}
 
void melting()
{
    vector<pair<int, int>> tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cheese[i][j]==0) continue;
            int cnt = 0;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
 
                if(0<=nx && nx<n && 0<=ny && ny<m && !isInside[nx][ny] && cheese[nx][ny]==0){
                    cnt++;
                }
            }
 
            if(cnt>=2){
                tmp.push_back(make_pair(i, j));
            }
        }
    }
 
    for(int i=0; i<tmp.size(); i++){
        cheese[tmp[i].first][tmp[i].second] = 0;
    }
}
 
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>cheese[i][j];
        }
    }
 
    int sec = 0;
    while(!isAllMelt()){
        sec++;
        memset(isInside, true, sizeof(isInside));
        checkInsideOxygen();
        melting(); 
    }
    
    cout<<sec<<"\n";
    return 0;
}