//1로 만들기(DP)
#include <iostream>
#include <climits>
using namespace std;

int n;
int num[1000001];//특정 숫자가 1이 되는 데에 최소 연산 횟수 저장

int go(int x){
    if(x == 1){
        return 0;
    }
    if(num[x] != INT_MAX){
        return num[x];
    }else{
        for(int i=0; i<3; i++){
            if((x % 3) == 0){
                num[x] = min(num[x], go(x/3)+1);
            }
            if((x % 2) == 0){//2번 연산
                num[x] = min(num[x], go(x/2)+1);
            }
            num[x] = min(num[x], go(x-1)+1);
        }
    }
    return num[x];
}

int main(){
    cin>>n;
    for(int i=0; i<1000001; i++){
        num[i] = INT_MAX;
    }
    int temp = go(n);
    cout<<temp<<"\n";
}