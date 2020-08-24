// 피보나치 수 5
#include <iostream>
#include <cstring>
 
using namespace std;
 
int n;
int dp[22] = {0, };
 
int go(int N)
{
   if(dp[N]!=-1){
       return dp[N];
   }
  
   dp[N] = go(N-1)+go(N-2);
   return dp[N];
}
 
int main()
{
   memset(dp, -1, sizeof(dp));
   cin>>n;
   dp[0] = 0;
   dp[1] = 1;
   if(n>=2){
       dp[n] = go(n-1)+go(n-2);
   }
  
   cout<<dp[n]<<"\n";
}
