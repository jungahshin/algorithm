//타일채우기
#include <iostream>
using namespace std;

int DP[31] = {0, };
int n;

//홀수는 경우의 수가 없다
//짝수의 경우, DP[i] = DP[i-2]*(2의 고유한 경우의 수) + DP[i-4]*(4의 고유한 경우의 수) +DP[i-6]*(6의 고유한 경우의 수).....+2(i번째의 고유한 경우의 수)

int main(){
    cin>>n;
    if(n%2 != 0){
        cout<<"0"<<"\n";
        return 0;
    }
    DP[2] = 3;
    DP[4] = 11;
    if(n==2 || n==4){
        cout<<DP[n]<<"\n";
        return 0;
    }
    for(int i=6; i<=n; i+=2){
        DP[i] = DP[i-2]*3;
        for(int j=i-4; j>=2; j-=2){
            DP[i] += DP[j]*2;
        }
        DP[i] += 2;//그 단계의 고유한 경우
    }
    cout<<DP[n]<<"\n";
}