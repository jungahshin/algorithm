//2*n 타일링-->점화식 규칙 이용,,
#include <iostream>
using namespace std;

int n;
int num[1001] = {0, };

int go(int n){
    if(num[n] != 0){
        return num[n];
    }else{
        if(n == 1){
            num[1] = 1;
            return 1;
        }else if(n == 2){
            num[2] = 2;
            return 2;
        }else{
            num[n] = go(n-1) + go(n-2);
            return num[n] %= 10007;
        }
    }
}

int main(){
    cin>>n;
    int final = go(n);
    //직사각형을 채우는 방법의 수를 10,007으로 나눈 나머지를 출력
    final %= 10007;
    cout<<final<<"\n";
}