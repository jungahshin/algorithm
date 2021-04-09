// 합분해
#include <iostream>
using namespace std;
 
int n, k;
long long dp[201][201] = {0, }; // (합, 갯수)
 
int main()
{
    cin>>n>>k;
    
    // 1개 선택했을 때
    for(int i=0; i<=n; i++){
        dp[1][i] = 1;
    }
 
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += (dp[i-1][j-k]%1000000000);
            }
        }
    }
    
    cout<<dp[k][n]%1000000000<<"\n";
 
    return 0;
}