//계단 오르기
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int stairs[301] = {0, };
int num[301] = {0, };

void go_up(){
    num[1] = stairs[1];
    num[2] = stairs[2] + stairs[1];
    num[3] = max(stairs[3] + stairs[1], stairs[3] + stairs[2]);

    for(int i=4; i<=n; i++){
        num[i] = max(stairs[i] + stairs[i-1] + num[i-3], stairs[i] + num[i-2]);
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>stairs[i];
    }
    go_up();
    cout<<num[n]<<"\n";
}