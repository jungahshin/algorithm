#include <iostream>
#include <vector>
using namespace std;

int n;
long DP[101][11] = {0, };
int final = 0;

//DP[N][L]에서 N->길이, L->마지막 숫자
//(L = 0일 때) DP[N][L] = DP[N-1][L+1]
//(L=1~8)DP[N][L] = DP[N-1][L-1]+DP[N-1][L+1]
//(L = 9일 때) DP[N][L] = DP[N-1][L-1]
int main(){
    cin>>n;
    //길이가 1일때는 무조건 모두 마지막 숫자가 어떤 것이던 간에 1개의 경우가 생긴다.
    for(int i=1; i<10; i++){
        DP[1][i] = 1;
    }
    //길이가 2~n일 경우에는 위의 점화식을 적용시킬 수 있다.
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j == 0){
                DP[i][j] = DP[i-1][j+1] % 1000000000;
            }
            if(j>=1 && j<=8){
                DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
            }
            if(j == 9){
                DP[i][j] = DP[i-1][j-1] % 1000000000;
            }            
        }
    }
    //최종 계산
    for(int i=0; i<10; i++){
        final = (final +DP[n][i]) % 1000000000;
    }
    cout<<final % 1000000000<<"\n";
}