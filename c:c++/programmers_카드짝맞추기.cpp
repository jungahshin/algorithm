// 다익스트라(최단거리) + 백트래킹(Brute Force)
// 같은 카드도 어떤 것을 먼저 뒤집느냐
// 어떤 카드 종류를 먼저 뒤집느냐에 따라 결과가 달라질 수 있음
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
 
using namespace std;
 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
 
bool isDone(vector<vector<int>> &board){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(board[i][j]!=0){
                return false;
            }
        }
    }
    
    return true;
}
 
bool inRange(int x, int y){
    if(x<0 || y<0 || x>=4 || y>=4){
        return false;
    }
    
    return true;
}
 
// 다익스트라(최단거리)
int dijkstra(vector<vector<int>> &board, int x, int y, int ex, int ey){
    priority_queue<pair<int, pair<int, int>>> pq;
    int dist[4][4] = {0, };
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            dist[i][j] = INT_MAX;
        }
    }
    
    dist[x][y] = 0;
    pq.push(make_pair(0, make_pair(x, y)));
    
    while(!pq.empty()){
        int distance = -pq.top().first;
        int x1 = pq.top().second.first;
        int y1 = pq.top().second.second;
        pq.pop();
        
        if(x1==ex && y1 ==ey){
            return distance;
        }
        
        for(int i=0; i<4; i++){
            int cnt = 0;
            int nx = x1, ny = y1;
            
            while(inRange(nx+dx[i], ny+dy[i])){
                cnt++;
                nx += dx[i], ny += dy[i];
                
                if(board[nx][ny]!=0) break;
                                
                if(dist[nx][ny]>distance+cnt){
                    dist[nx][ny] = distance+cnt;
                    pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
                }
            }
            
            if(dist[nx][ny]>distance+1){
                dist[nx][ny] = distance+1;
                pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
            }
        }
    }
}
 
// 백트래킹(Brute Force)
int brute(vector<vector<int>> &board, int r, int c){
    if(isDone(board)) return 0;
    int ans = INT_MAX;
    
    for(int i=1; i<=6; i++){
        vector<pair<int, int>> point;
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                if(board[j][k]==i){
                    point.push_back(make_pair(j, k));
                }
            }
        }
        
        if(point.empty()) continue;
        
        // 첫번째 카드를 먼저 뒤집어
        int cal1 = dijkstra(board, r, c, point[0].first, point[0].second)+
            dijkstra(board, point[0].first, point[0].second, point[1].first, point[1].second) + 2;
        
        // 두번째 카드를 먼저 뒤집어
        int cal2 = dijkstra(board, r, c, point[1].first, point[1].second)+
            dijkstra(board, point[1].first, point[1].second, point[0].first, point[0].second) + 2;
        
        board[point[0].first][point[0].second] = 0;
        board[point[1].first][point[1].second] = 0;
        
        ans = min(ans, min(cal1+brute(board, point[1].first, point[1].second), cal2+brute(board, point[0].first, point[0].second)));
        
        board[point[0].first][point[0].second] = i;
        board[point[1].first][point[1].second] = i;
    }
    
    return ans;
}
 
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    
    answer = brute(board, r, c);
    
    return answer;
}