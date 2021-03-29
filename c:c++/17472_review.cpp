#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>
using namespace std;
 
int n, m;
int connect[7] = { 0, };
int map[11][11] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int check[11][11] = { 0, }; // 영역 표시하기
vector<pair<int, int>> edge[7];
int areaNum = 0;
vector<int> seq; // 다리를 만드는 순서
 
int find(int i)
{
    if (i == connect[i]) {
        return i;
    }
 
    return connect[i] = find(connect[i]);
}
 
int makeBridge()
{
    int ans = 0; // 총 다리의 길이
 
    // from -> to 를 잇는 다리 건설
    for (int i = 0; i < seq.size(); i++) {
        int from = seq[i];
        queue<tuple<int, int, int, int>> q;
        for (int k = 0; k < edge[from].size(); k++) {
            for (int t = 0; t < 4; t++) {
                q.push(make_tuple(edge[from][k].first, edge[from][k].second, 0, t));
            }
        }
 
        while (!q.empty()) {
            int x, y, cnt, dir;
            tie(x, y, cnt, dir) = q.front();
            q.pop();
 
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] != from) {
                if (map[nx][ny] == 0) {
                    q.push(make_tuple(nx, ny, cnt + 1, dir));
                }
                else {
                     //from -> to 다리를 이을 수 있으면 잇는다.
                    int to = check[nx][ny];
                    int a = find(from);
                    int b = find(to);
                    if (a==b || cnt<2) continue;
                    connect[a] = b;
                    ans += cnt;
                }
            }
        }
    }
 
    return ans;
}
 
void makeArea()
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) continue;
            if (check[i][j] != 0) continue;
            int visited[11][11] = { 0, };
            areaNum++;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
 
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                visited[x][y] = true;
                check[x][y] = areaNum;
 
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        if (map[nx][ny] == 0) {
                            edge[check[x][y]].push_back(make_pair(x, y));
                        }
                        if (map[nx][ny] == 1) {
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
}
 
bool isAllConnect()
{
    for (int i = 1; i < areaNum; i++) {
        if (find(i) != find(i + 1)) return false;
    }
 
    return true;
}
 
int main()
{
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    int ans = INT_MAX;
    bool isPossible = false; // 모든 섬을 연결하는 것이 가능한지
                             
    // 영역 표시
    makeArea();
 
    // Brute Force로 최단 다리 구하기
    for (int i = 1; i <= areaNum; i++) {
        seq.push_back(i);
    }
    do {
        for (int i = 1; i <= areaNum; i++) {
            connect[i] = i;
        }
        int num = makeBridge();
        if (isAllConnect()) {
            isPossible = true;
            ans = min(ans, num);
        }
    } while (next_permutation(seq.begin(), seq.end()));
 
    if (isPossible) {
        cout << ans << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
 
    return 0;
}