//파일 합치기

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int n, testcase;
int book[502] = {0, };
int sum[502] = {0, };//i~j까지의 합 저장
int DP[502][502] = {0, };

//가장 중요한 점화식(dp[i][j] = min(dp[i][k]+dp[k+1][j])+(i~j까지의 합))

void go(){
    for(int j=2; j<=n; j++){
        for(int i=j-1; i>=0; i--){
            DP[i][j] = INT_MAX;
            //k의 존재 이유는 단순히 DP[i][j]의 최소값을 찾기위한 수단...
            for(int k=i; k<j; k++){
                DP[i][j] = min(DP[i][j], DP[i][k]+DP[k+1][j]);
            }
            //i~j까지의 합을 더한다.
            DP[i][j] += (sum[j]-sum[i-1]);
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        memset(sum, 0, sizeof(sum));
        memset(DP, 0, sizeof(DP));
        cin>>n;
        for(int j=1; j<=n; j++){
            cin>>book[j];
            if(j>1){
                sum[j] = sum[j-1]+book[j];
            }else if(j==1){
                sum[1] = book[1];
            }
        }
        go();
        cout<<DP[1][n]<<"\n";
    }
}