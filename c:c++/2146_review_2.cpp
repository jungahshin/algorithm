#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;
 
int n;
int map[101][101] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int check[101][101] = { 0, }; // 영역 표시하기
 
int connectArea(vector<pair<int ,int>> &v, int num)
{
    int visited[101][101] = { 0, };
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < v.size(); i++) {
        q.push(make_tuple(v[i].first, v[i].second, 1));
    }
    
    while (!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();
        visited[x][y] = true;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && check[nx][ny]!=num) {
                if (map[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push(make_tuple(nx, ny, cnt + 1));
                }
                else {
                    return cnt;
                }
            }
        }
    }
 
    return 0;
}
 
int makeBridge()
{
    int num = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]==0) continue;
            if (check[i][j] != 0) continue;
            int visited[101][101] = { 0, };
            num++;
            queue<pair<int, int>> q;
            vector<pair<int, int>> edge;
            q.push(make_pair(i, j));
 
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                visited[x][y] = true;
                check[x][y] = num;
 
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        if (map[nx][ny] == 0) {
                            edge.push_back(make_pair(nx, ny));
                        }
                        if (map[nx][ny] == 1) {
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
            
            ans = min(ans, connectArea(edge, num));
        }
    }
 
    return ans;
}
 
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
 
    cout<<makeBridge()<<"\n";
    return 0;
}