//이친수->DP
#include <iostream>
using namespace std;

long long final = 0;
int n;
long long zero, one = 0;

void go(int temp){
    int num = temp;
    while(num != n){
        long long one_next, zero_next = 0;
        one_next = one*1 + zero*1;
        zero_next = one*1 + zero*2;
        num += 2;
        one = one_next;
        zero = zero_next;
    }
    final = one + zero;
}

int main(){
    cin>>n;
    if(n % 2 == 0){//짝수
        one = 0;
        zero = 1;
        go(2);
    }else{//홀수
        one = 1;
        zero = 0;
        go(1);
    }
    cout<<final<<"\n";
}