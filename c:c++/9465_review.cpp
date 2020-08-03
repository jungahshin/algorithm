// 스티커
#include <iostream>
#include <cstring>
using namespace std;
 
int testcase, n, final = 0;
int sticker[3][100002] = {0, };
int dp[3][100002] = {0, };
 
int main()
{
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       memset(dp, 0, sizeof(dp));
       memset(sticker, 0, sizeof(sticker));
       final = 0;
       cin>>n;
       // 0행
       for(int j=1; j<=n; j++){
           cin>>sticker[0][j];
       }
       // 1행
       for(int j=1; j<=n; j++){
           cin>>sticker[1][j];
       }
 
       dp[0][0] = dp[1][0] = 0;
       dp[0][1] = sticker[0][1];
       dp[1][1] = sticker[1][1];
 
       for(int j=2; j<=n; j++){
           dp[0][j] = max(dp[1][j-1], dp[1][j-2])+sticker[0][j];
           dp[1][j] = max(dp[0][j-1], dp[0][j-2])+sticker[1][j];
       }
 
       final = max(dp[0][n], dp[1][n]);
       cout<<final<<"\n";
   }
}
