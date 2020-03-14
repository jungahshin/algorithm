//동물원(DP, 탑다운)
#include <iostream>
#define mod 9901
using namespace std;

int n;
int DP[100001][3] = {0, };

//아무것도 없을 경우
//왼쪽에 있을 경우
//오른쪽에 있을 경우

int main(){
    cin>>n;
    DP[0][0] = DP[0][1] = DP[0][2] = 1;
    for(int i=1; i<n; i++){
        DP[i][0] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2]) % mod;//아무것도 없을 경우 모든 경우가 가능하다.
        DP[i][1] = (DP[i-1][0] + DP[i-1][2]) % mod; //왼쪽에 있을 경우, 아무것도 없거나 오른쪽에 있어야한다.
        DP[i][2] = (DP[i-1][0] + DP[i-1][1]) % mod; //오른쪽에 있을 경우, 아무것도 없거나 왼쪽에 있어야한다.
    }
    cout<<(DP[n-1][0]+DP[n-1][1]+DP[n-1][2])%mod<<"\n";
}