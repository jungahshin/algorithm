//돌 게임3
#include <iostream>
using namespace std;
 
int n;
int dp[1002] = {0, };
 
int main()
{
   cin>>n;
   dp[1] = 1;
   dp[2] = 0;
   dp[3] = 1;
   dp[4] = 1;
 
   for(int i=5; i<=n; i++){
       if(min({dp[i-1], dp[i-3], dp[i-4]}) == 0){
           dp[i] = 1;
       }else{
           dp[i] = 0;
       }
   }
 
   if(dp[n] == 1){
       cout<<"SK"<<"\n";
   }else{
       cout<<"CY"<<"\n";
   }
   return 0;
}
