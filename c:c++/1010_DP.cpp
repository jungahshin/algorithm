//다리 놓기
//조합의 성질 이용(nCr = n-1Cr-1 + n-1Cr)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int testcase, n, m;
long long DP[31][31] = {0, };
vector<long long> final;
long long sum = 0;

int go(int n, int m){
    if(n == 0){
        return 1;
    }
    if(n == m){
        return 1;
    }
    if(DP[m][n] != 0){//m개중에 n개 조합
        return DP[m][n];
    }

    DP[m][n] = go(n-1, m-1) + go(n, m-1);
    return DP[m][n];
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n>>m;
        memset(DP, 0, sizeof(DP));
        if(m-n > n){
            sum = go(n, m);
        }else{
            sum = go(m-n, m);
        }
        final.push_back(sum);
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}