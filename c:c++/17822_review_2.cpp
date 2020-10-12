// 원판 돌리기
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
 
int n, m, t, x, d, k;
vector<tuple<int, int, int>> v;
int r[51][51] = { 0, }; // 원판에 적힌 초기 수
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
 
bool bfs() // 인접한 수 제거하기
{
   bool check = false;
 
   // setting(0번째 idx에 m번째 idx넣어주기)
   for (int i=1; i <= n; i++) {
       r[i][0] = r[i][m];
   }
 
   int visited[51][51] = { 0, };
   int map[51][51] = { 0, };
  
   for (int i = 1; i <= n; i++) {
       for (int j = 0; j <= m; j++) {
           if (r[i][j] == 0 || visited[i][j]) continue;
           vector<pair<int, int>> temp;
           queue<pair<int, int>> q;
           q.push(make_pair(i, j));
 
           int num = r[i][j];
 
           while (!q.empty()) {
               int x = q.front().first;
               int y = q.front().second;
               temp.push_back(make_pair(x, y));
               visited[x][y] = 1;
               q.pop();
 
               for (int a = 0; a < 4; a++) {
                   int nx = x + dx[a];
                   int ny = y + dy[a];
                   if (1 <= nx && nx <= n && 0 <= ny && ny <= m && !visited[nx][ny]) {
                       if (r[nx][ny] == num) {
                           visited[nx][ny] = 1;
                           q.push(make_pair(nx, ny));
                       }
                   }
               }
           }
 
           if (temp.size() > 1) {
               check = true;
               for (int a = 0; a < temp.size(); a++) {
                   map[temp[a].first][temp[a].second] = -1;
               }
           }
       }
   }
 
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= m; j++) {
           if (map[i][j] == -1) {
               r[i][j] = 0;
           }
       }
   }
 
   for (int i = 1; i <= n; i++) {
       if (map[i][0] == -1) {
           r[i][m] = 0;
       }
   }
 
   return check;
}
 
void move()
{
   for (int i = 0; i < t; i++) { // T번 회전 진행
       int x, d, k;
       tie(x, d, k) = v[i];
       k %= m; // 열만큼 나눈 나머지값만 하면 된다.
       for (int a = 1; a <= n; a++) {
           if (a%x != 0) continue;
           for (int c = 0; c < k; c++) {
               int temp[51] = { 0, }; // 열만 따로 저장
               if (d == 0) { // 시계방향
                   temp[1] = r[a][m];
                   for (int b = 1; b <= m - 1; b++) {
                       temp[b + 1] = r[a][b];
                   }
               }
               else if (d == 1) { // 반시계 방향
                   temp[m] = r[a][1];
                   for (int b = 2; b <= m; b++) {
                       temp[b-1] = r[a][b];
                   }
               }
 
               // temp->r배열로 옮겨주기
               for (int b = 1; b <= m; b++) {
                   r[a][b] = temp[b];
               }
           }
       }
       if (!bfs()) { // 인접한 값이 없다. -> 평균 구하기
           int total = 0;
           int cnt = 0;
 
           for (int a = 1; a <= n; a++) {
               for (int b = 1; b <= m; b++) {
                   total += r[a][b];
                   if (r[a][b] != 0) {
                       cnt++;
                   }
               }
           }
 
           double avg = (double)total / cnt;
 
           for (int a = 1; a <= n; a++) {
               for (int b = 1; b <= m; b++) {
                   if (r[a][b] == 0) continue;
                   if (r[a][b] < avg) {
                       r[a][b]++;
                   }
                   else if (r[a][b] > avg) {
                       r[a][b]--;
                   }
               }
           }
       }
   }
}
 
int main()
{
   cin >> n >> m >> t;
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= m; j++) {
           cin >> r[i][j];
       }
   }
 
   for (int i = 0; i < t; i++) {
       cin >> x >> d >> k;
       v.push_back(make_tuple(x, d, k));
   }
 
   move();
 
   int ans = 0;
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= m; j++) {
           ans += r[i][j];
       }
   }
 
   cout << ans << "\n";
   return 0;
}