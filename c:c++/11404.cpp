//플로이드(플로이드 와샬)
#include <iostream>
#include <climits>
using namespace std;
 
int n, m, S, E, C;
int dp[101][101] = {0, };
int bus[101][101] = {0, };
 
int main()
{
   cin>>n>>m;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           if(i==j){
               dp[i][j] = 0;
               continue;
           }
           dp[i][j] = INT_MAX;
       }
   }
   for(int i=0; i<m; i++){
       cin>>S>>E>>C;
       bus[S][E] = min(bus[S][E], C);
       dp[S][E] = min(dp[S][E], C);
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
 
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           if(dp[i][j]==INT_MAX){
               dp[i][j] = 0;
           }
           cout<<dp[i][j]<<" ";
       }
       cout<<"\n";
   }
 
   return 0;
}
