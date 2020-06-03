//평범한 배낭(knapsack 알고리즘...)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, k, a, b;
int dp[105][100005] = {0, };
int w[100005] = {0, };
int v[1005] = {0, };

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        w[i] = a;
        v[i] = b;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j<w[i]){//넣을 수 없어
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }

    //-1로 초기화 시켰기 때문에 +1해줘야한다.
    cout<<dp[n][k]+1<<"\n";
    return 0;
}