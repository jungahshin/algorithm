//역사(플로이드 와샬)
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
 
int n, k, a, b, s, c, d;
int connect[401][401] = {0, };
int dp[401][401] = {0, };
vector<pair<int, int>> v;
 
int main()
{
   cin>>n>>k;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           dp[i][j] = INT_MAX;
       }
   }
 
   for(int i=0; i<k; i++){
       cin>>a>>b;
       connect[a][b] = 1; // 비용은 그냥 1로 친다.
       dp[a][b] = connect[a][b];
   }
   cin>>s;
   for(int i=0; i<s; i++){
       cin>>c>>d;
       v.push_back(make_pair(c, d));
   }
 
   // 거쳐가는 점
   for(int i=1; i<=n; i++){
       // 시작점
       for(int j=1; j<=n; j++){
           // 끝 점
           for(int k=1; k<=n; k++){
               if(dp[j][i]!=INT_MAX && dp[i][k]!=INT_MAX){
                   if(dp[j][i]+dp[i][k]<dp[j][k]){
                       dp[j][k] = dp[j][i]+dp[i][k];
                   }                   
               }
           }
       }
   }
 
   for(int i=0; i<v.size(); i++){
       int A = v[i].first;
       int B = v[i].second;
 
       if(dp[A][B]!=INT_MAX){
           cout<<"-1"<<"\n";
       }else if(dp[B][A]!=INT_MAX){
           cout<<"1"<<"\n";
       }else{
           cout<<"0"<<"\n";
       }
   }
 
   return 0;
}
