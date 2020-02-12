//이항계수 2
//nCk = n-1Ck-1 + n-1Ck라는 성질을 가지고 있음
//nCn = nC0 = 1
#include <iostream>
using namespace std;

int n, k;
long DP[1001][1001] = {0, };
int final = 0;

long go(int a, int b){
    if(DP[a][b] != 0){
        return DP[a][b];
    }

    DP[a][b] = (go(a-1, b-1) + go(a-1, b))%10007;
    return DP[a][b];
}

int main(){
    cin>>n>>k;
    for(int i=0; i<=n; i++){
        DP[i][0] = 1;
        DP[i][i] = 1;
    }
    if(k>=(n-k)){//nCn-k로 진행
        final = go(n, n-k);
    }else{//nCk로 진행
        final = go(n, k);
    }
    cout<<final%10007<<"\n";
}