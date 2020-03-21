//초콜릿 자르기(DP)
//DP이지만 너무 쉽게 수학 문제로 풀리는..^^
#include <iostream>
using namespace std;

int n, m;
int DP[302] = {0, };
//항상 (col-1)+(DP[row]*col)의 식이 성립한다

int main(){
    cin>>n>>m;
    for(int i=1; i<=300; i++){
        DP[i] = i-1;
    }
    int final = (m-1) + (DP[n]*m);
    cout<<final<<"\n";
}