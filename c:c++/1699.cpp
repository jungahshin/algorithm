//제곱수의 합
//310-320사이정도의 제곱수를 요한다.
#include <iostream>
using namespace std;

int n;
int num;
int DP[100001] = {0, };

//DP[n]은 n이라는 수에서 필요한 가장 작은 제곱 항의 수

void go(){
    for(int i=1; i<=n; i++){
        DP[i] = i;
        //n보다 작은 제곱수를 구한다.
        for(int j=1; j*j <= i; j++){
            DP[i] = min(DP[i], DP[i-j*j]+1);
        }
    }
}
//dp[n-a*a]

int main(){
    cin>>n;
    go();
    cout<<DP[n]<<"\n";
}