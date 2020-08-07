// 운동
#include <iostream>
#include <climits>
using namespace std;
 
int v, e, a, b, c;
int dp[401][401] = {0, };
int road[401][401] = {0, };
int total = INT_MAX;
 
int main()
{
   cin>>v>>e;
   for(int i=1; i<=v; i++){
       for(int j=1; j<=v; j++){
           dp[i][j] = INT_MAX;
       }  
   }
   for(int i=0; i<e; i++){
       cin>>a>>b>>c;
       dp[a][b] = min(dp[a][b], c);
   }
 
   // 거쳐가는 점
   for(int i=1; i<=v; i++){
       // 출발 점
       for(int j=1; j<=v; j++){
           // 도착 점
           for(int k=1; k<=v; k++){
               if(dp[j][i]!=INT_MAX && dp[i][k]!=INT_MAX){
                   if(dp[j][i]+dp[i][k]<dp[j][k]){
                       dp[j][k] = dp[j][i]+dp[i][k];
                   }
               }
           }
       }
   }
 
   for(int i=1; i<=v; i++){
       for(int j=1; j<=v; j++){
           if(i==j){
               total = min(total, dp[i][j]);
           }
       }
   }
 
   if(total==INT_MAX){
       cout<<"-1"<<"\n";
   }else{
       cout<<total<<"\n";
   }
 
   return 0;
}
