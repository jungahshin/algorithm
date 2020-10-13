// 2048(easy)
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n;
int game[21][21] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int ans = 0;
 
void move(int dir, int temp[21][21]) {
   if(dir==0){ // 왼쪽
       for (int i = 0; i < n; i++) {
           vector<int> v;
           for (int j = 0; j < n; j++) {
               if (temp[i][j] != 0) {
                   v.push_back(temp[i][j]);
                   temp[i][j] = 0;
               }
           }
           int idx = 0;
           for (int j = 0; j < v.size(); j++) {
               temp[i][idx++] = v[j];
           }
       }
   }
   else if (dir == 1) { // 오른쪽
       for (int i = 0; i < n; i++) {
           vector<int> v;
           for (int j = n-1; j>=0; j--) {
               if (temp[i][j] != 0) {
                   v.push_back(temp[i][j]);
                   temp[i][j] = 0;
               }
           }
           int idx = n-1;
           for (int j = 0; j < v.size(); j++) {
               temp[i][idx--] = v[j];
           }
       }
   }
   else if (dir == 2) { // 위쪽
       for (int i = 0; i < n; i++) { // 열
           vector<int> v;
           for (int j = 0; j < n; j++) { // 행
               if (temp[j][i] != 0) {
                   v.push_back(temp[j][i]);
                   temp[j][i] = 0;
               }
           }
           int idx = 0;
           for (int j = 0; j < v.size(); j++) {
               temp[idx++][i] = v[j];
           }
       }
   }
   else if (dir == 3) { // 아래쪽
       for (int i = 0; i < n; i++) { // 열
           vector<int> v;
           for (int j = n-1; j>=0; j--) { // 행
               if (temp[j][i] != 0) {
                   v.push_back(temp[j][i]);
                   temp[j][i] = 0;
               }
           }
           int idx = n-1;
           for (int j = 0; j < v.size(); j++) {
               temp[idx--][i] = v[j];
           }
       }
   }
}
 
void copy(int a[21][21], int b[21][21]) {
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           a[i][j] = b[i][j];
       }
   }
}
 
int final(int a[21][21])
{
   int temp = 0;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           temp = max(temp, a[i][j]);
       }
   }
 
   return temp;
}
 
void cal(int dir, int a[21][21], int b[21][21])
{
   if (dir == 0) { // 왼
       for (int j = 0; j < n; j++) {
           for (int k = 0; k < n - 1; k++) {
               if (b[j][k] == b[j][k + 1]) {
                   a[j][k] = b[j][k] * 2;
                   b[j][k + 1] = 0;
                   b[j][k] = 0;
               }
           }
           for (int k = 0; k < n; k++) {
               if (b[j][k] != 0) {
                   a[j][k] = b[j][k];
               }
           }
       }
   }
   else if (dir == 1) { // 오
       for (int j = 0; j < n; j++) {
           for (int k = n-1; k>=1; k--) {
               if (b[j][k] == b[j][k-1]) {
                   a[j][k] = b[j][k] * 2;
                   b[j][k-1] = 0;
                   b[j][k] = 0;
               }
           }
           for (int k = n-1; k>=0; k--) {
               if (b[j][k] != 0) {
                   a[j][k] = b[j][k];
               }
           }
       }
   }
   else if (dir == 2) { // 위
       for (int j = 0; j < n; j++) {
           for (int k = 0; k < n - 1; k++) {
               if (b[k][j] == b[k+1][j]) {
                   a[k][j] = b[k][j] * 2;
                   b[k+1][j] = 0;
                   b[k][j] = 0;
               }
           }
           for (int k = 0; k < n; k++) {
               if (b[k][j] != 0) {
                   a[k][j] = b[k][j];
               }
           }
       }
   }
   else if (dir == 3) { // 아래
       for (int j = 0; j < n; j++) {
           for (int k = n - 1; k >= 1; k--) {
               if (b[k][j] == b[k-1][j]) {
                   a[k][j] = b[k][j] * 2;
                   b[k-1][j] = 0;
                   b[k][j] = 0;
               }
           }
           for (int k = n - 1; k >= 0; k--) {
               if (b[k][j] != 0) {
                   a[k][j] = b[k][j];
               }
           }
       }
   }
}
 
void play(int cnt, int game[21][21])
{
   if (cnt == 5) {
       ans = max(ans, final(game)); // 최대값 계산
       return;
   }
 
   int temp[21][21] = { 0, };
 
   for (int i = 0; i < 4; i++) {
       copy(temp, game);
       // 그 방향으로 쭉 밀기
       move(i, temp);
       // 계산하기 -> 이것도 방향대로..처리
       int temp2[21][21] = { 0, };
       cal(i, temp2, temp);
 
       // 그 방향으로 쭉 밀기
       move(i, temp2);
       play(cnt + 1, temp2);
   }
}
 
int main()
{
   cin >> n;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           cin >> game[i][j];
       }
   }
  
   play(0, game);
 
   cout << ans << "\n";
   return 0;
}