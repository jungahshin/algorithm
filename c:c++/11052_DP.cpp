//카드 구매하기
//1개당 얼마인지를 계산을 해서 개당 가격이 가장 높은 것*그 개수만큼
//전체 n개에서 위의 갯수만큼을 뺀 나머지 갯수 >= 해당 개수이고 그 다음으로 개당 가격이 높은 것
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001] = {0, };
int DP[1001] = {0, };
int n;

void go(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            DP[i] = max(DP[i] , DP[i-j] + a[j]);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    go();
    cout<<DP[n]<<"\n";
}