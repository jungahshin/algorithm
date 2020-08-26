// 1학년
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int n, m;
vector<int> v;
long long dp[21][102] = {0, }; // 가능한 개수
 
long long go(int sum, int idx)
{
   if(sum>20 || sum<0){
       return 0;
   }
 
   if(idx==n-2){
       if(sum==v[n-1]){
           return 1;
       }else{
           return 0;
       }
   }
 
   long long &num = dp[sum][idx];
 
   if(num!=-1){
       return dp[sum][idx];
   }
 
   num = 0;
 
   // 더할 경우와 뺄 경우의 수를 모두 더해준다.
   return num += (go(sum+v[idx+1], idx+1)+go(sum-v[idx+1], idx+1));
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       v.push_back(m);
   }
 
   memset(dp, -1, sizeof(dp));
 
   cout<<go(v[0], 0)<<"\n";
 
   return 0;
}
