#include <string>
#include <vector>
#include <queue>
#include <iostream>
 
using namespace std;
 
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int map[101][101] = {0, };
    long long dp[101][101] = {0, };
    int visited[101][101] = {0, };
    int dirX[2] = {0, 1};
    int dirY[2] = {1, 0};
    
    for(int i=0; i<puddles.size(); i++){
        // 물에 잠긴곳 -1로 표시
        map[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    dp[1][1] = 1;
     
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        visited[y][x] = 1;
        q.pop();
        
        if(y==m && x==n){
            break;
        }
        
        for(int i=0; i<2; i++){
            int ny = y+dirY[i];
            int nx = x+dirX[i];
            if(1<=ny && ny<=m && 1<=nx && nx<=n){
                if(map[ny][nx]==-1) continue;
                dp[ny][nx] += (dp[y][x]%1000000007);
                // 더해주는 건 다 더해주고, 큐에 넣는 것은 한 번만!
                if(visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    answer = dp[m][n]%1000000007;
    
    return answer;
}