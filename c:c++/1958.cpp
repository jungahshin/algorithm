//LCS3(3차원 lcs)
#include <iostream>
using namespace std;
 
string s1, s2, s3;
int dp[104][104][104] = {0, };
 
int main()
{
   cin>>s1;
   cin>>s2;
   cin>>s3;
 
   string temp;
   for(int i=0; i<s1.size(); i++){
       for(int j=0; j<s2.size(); j++){
           for(int k=0; k<s3.size(); k++){
               if(s1[i]==s2[j] && s2[j]==s3[k]){
                   // temp += s1[i];
                   dp[i+1][j+1][k+1] = dp[i][j][k]+1;
               }else{
                   dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j+1][k+1]);
                   dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i+1][j][k+1]);
                   dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i+1][j+1][k]);
               }
           }
       }
   }
   cout<<dp[s1.size()][s2.size()][s3.size()]<<"\n";
   return 0;
}
