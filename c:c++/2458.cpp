// 키 순서(플로이드 와샬)
#include <iostream>
#include <climits>
 
using namespace std;
 
int n, m, a, b;
int total = 0;
int dp[501][501] = {0, };
 
int main()
{
   cin>>n>>m;
   // 초기화
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           dp[i][j] = INT_MAX;
       }
   }
   for(int i=0; i<m; i++){
       cin>>a>>b;
       dp[a][b] = 1;
   }
   // 거쳐가는 점
   for(int i=1; i<=n; i++){
       // 출발 점
       for(int j=1; j<=n; j++){
           // 도착 점
           for(int k=1; k<=n; k++){
               if(dp[j][i]!=INT_MAX && dp[i][k]!=INT_MAX){
                   if(dp[j][i]+dp[i][k]<dp[j][k]){
                       dp[j][k] = dp[j][i]+dp[i][k];
                   }                   
               }
           }
       }
   }
 
   // 기준점
   for(int i=1; i<=n; i++){
       int num = 0;
       for(int j=1; j<=n; j++){
           if(i!=j){
               if(dp[i][j]!=INT_MAX || dp[j][i]!=INT_MAX){
                   num++;
               }
           }
       }
       if(num==n-1){
           total++;
       }
   }
 
   cout<<total<<"\n";
 
   return 0;
}
