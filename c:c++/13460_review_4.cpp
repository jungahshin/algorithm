// 구슬 탈출 2
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <climits>
#include <string>
 
using namespace std;
 
int n, m;
string s;
int map[11][11] = { 0, };
queue<tuple<int, int, int, int, int>> q;
int rx, ry, bx, by, endX, endY;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int ans = INT_MAX;
 
void bfs()
{
   q.push(make_tuple(rx, ry, bx, by, 0));
   int move = 0;
 
   while (1) {
       move++;
       if (move > 10) {
           break;
       }
 
       int size = q.size();
 
       for (int i = 0; i < size; i++) {
           int rx, ry, bx, by, cnt; // 현재 빨간 구슬과 파란 구슬의 위치
           tie(rx, ry, bx, by, cnt) = q.front();
 
           q.pop();
 
           for (int j = 0; j < 4; j++) {
               bool check_red = false;
               bool check_blue = false;
               int nrx = rx;
               int nry = ry;
               while (map[nrx+dx[j]][nry+dy[j]] != '#') {
                   nrx += dx[j];
                   nry += dy[j];
                   if (map[nrx][nry] == 'O') {
                       check_red = true;
                   }
               }
 
               int nbx = bx;
               int nby = by;
               while (map[nbx+dx[j]][nby+dy[j]] != '#') {
                   nbx += dx[j];
                   nby += dy[j];
                   if (map[nbx][nby] == 'O') {
                       check_blue = true;
                   }
               }
 
               if (check_blue == true) { // 파란 공이 빠지면 어쨋든 실패,,,,
                   continue;
               }
 
               if (check_red == true) { // 성공!
                   ans = cnt + 1;
                   return;
               }
 
               // 둘다 구멍에 빠지지 않았을 경우 위치 선정하기
               if (nrx == nbx && nry == nby) {
                   if ((abs(rx - nrx) + abs(ry - nry)) > (abs(bx - nbx) + abs(by - nby))) { // 빨간 구슬이 더 많이 움직임
                       nrx -= dx[j];
                       nry -= dy[j];
                   }
                   else {
                       nbx -= dx[j];
                       nby -= dy[j];
                   }
               }
 
               q.push(make_tuple(nrx, nry, nbx, nby, cnt + 1));
           }
       }
   }
}
 
int main()
{
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
       cin >> s;
       for (int j = 0; j < s.size(); j++) {
           map[i][j] = s[j];
           if (s[j] == 'R') {
               map[i][j] = '.';
               rx = i;
               ry = j;
           }
           else if (s[j] == 'B') {
               map[i][j] = '.';
               bx = i;
               by = j;
           }
           else if (s[j] == 'O') {
               endX = i;
               endY = j;
           }
       }
   }
 
   bfs();
 
   if (ans == INT_MAX) {
       cout << "-1" << "\n";
   }
   else {
       cout << ans << "\n";
   }
  
   return 0;
}