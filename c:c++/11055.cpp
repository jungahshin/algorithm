//가장 큰 증가 부분 수열
#include <iostream>
using namespace std;

int n;
int a[1002] = {0, };
int DP[1002] = {0, };
int final = 0;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    DP[1] = a[1];
    //첫 번째 요소를 건너띄나, 안띄나(idx, 지금까지 총 합)
    for(int i=1; i<=n; i++){
        int temp = 0;
        for(int j=0; j<i; j++){
            if(a[i] > a[j]){
                temp = max(temp, DP[j]);
            }
        }
        DP[i] = temp+a[i];
        final = max(DP[i], final);
    }    
    cout<<final<<"\n";
}