// 점프
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int n, x, y;
int game[101][101] = {0, };
int dx[4] = {1, 0};
int dy[4] = {0, 1};
long long dp[101][101] = {0, };
 
long long go(int X, int Y)
{
   if(X==n && Y==n){
       return 1;
   }
 
   if(dp[X][Y]==-1){
       dp[X][Y] = 0;
       for(int i=0; i<2; i++){
           int nx = X+game[X][Y]*dx[i];
           int ny = Y+game[X][Y]*dy[i];
           if(1<=nx && nx<=n && 1<=ny && ny<=n){
               dp[X][Y] += go(nx, ny);
           }
       }       
   }
 
   return dp[X][Y];
}
 
int main()
{
   memset(dp, -1, sizeof(dp));
   cin>>n;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           cin>>game[i][j];
       }
   }
 
   //top-down 방식
   x = 1;
   y = 1;
   dp[x][y] = 0;
   for(int i=0; i<2; i++){
       int nx = x+game[x][y]*dx[i];
       int ny = y+game[x][y]*dy[i];
       if(1<=nx && nx<=n && 1<=ny && ny<=n){
           dp[x][y] += go(nx, ny);
       }
   }
 
   cout<<dp[1][1]<<"\n";
 
   return 0;
}
