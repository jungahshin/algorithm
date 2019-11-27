//1로 만들기(DP)
#include <iostream>
#include <climits>
using namespace std;

int n;
int num[1000001];//특정 숫자가 1이 되는 데에 최소 연산 횟수 저장

int go(int x){
    cout<<"x"<<x<<"\n";
    if(x == 1){
        cout<<"도달"<<"\n";
        return 0;
    }
    if(num[x] != INT_MAX){
        return num[x];
    }else{
        for(int i=0; i<3; i++){
            if((x % 3) == 0){
                cout<<"3 in"<<"\n";
                num[x] = min(num[x], go(x/3)+1);
                cout<<"num3"<<num[x]<<"\n";
            }
            if((x % 2) == 0){//2번 연산
                cout<<"2 in"<<"\n";
                num[x] = min(num[x], go(x/2)+1);
                cout<<"num2"<<num[x]<<"\n";
            }
            cout<<"1 in"<<"\n";
            num[x] = min(num[x], go(x-1)+1);
            cout<<"num1"<<num[x]<<"\n";
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
    // cout<<num[2]<<"\n";
}