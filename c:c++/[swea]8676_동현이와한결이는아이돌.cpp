// 8676. 동현이와 한결이는 아이돌
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
int testcase;
string s;
int dp[7] = {0, };
vector<int> final;
const int MAX = 1000000007;
 
int main()
{
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       memset(dp, 0, sizeof(dp));
       cin>>s;
       for(int j=0; j<s.size(); j++){
           if(s[j]=='S'){
               dp[0] = (dp[0]+1)%MAX;
               dp[3] = (dp[2]+dp[3])%MAX;
           }else if(s[j]=='A'){
               dp[1] = (dp[0]+dp[1])%MAX;
           }else if(s[j]=='M'){
               dp[2] = (dp[1]+dp[2])%MAX;
           }else if(s[j]=='U'){
               dp[4] = (dp[3]+dp[4])%MAX;
           }else if(s[j]=='N'){
               dp[5] = (dp[4]+dp[5])%MAX;
           }else if(s[j]=='G'){
               dp[6] = (dp[5]+dp[6])%MAX;
           }
       }
 
       final.push_back(dp[6]);
   }
 
   for(int i=0; i<final.size(); i++){
       cout<<"#"<<i+1<<" "<<final[i]<<"\n";
   }
}
