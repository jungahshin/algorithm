//책 페이지
#include <iostream>
using namespace std;

int n;//최대 10자리(10억)
int final[11] = {0, };

void go(int num, int n){
    int temp = 1;
    for(int i=0; i<num-1; i++){
        temp *= 10;
    }
    for(int i=num; i>=1; i--){
        int check = n/temp;//몫-->계산하기
        final[check]++;
        n %= temp;
        temp /= 10;
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        if(i < 10){//한 자리 수(1로 나눔)
            go(1, i);
        }else if(i < 100){
            go(2, i);
        }else if(i < 1000){
            go(3, i);
        }else if(i < 10000){ 
            go(4, i);
        }else if(i < 100000){
            go(5, i);
        }else if(i < 1000000){
            go(6, i);
        }else if(i < 10000000){
            go(7, i);
        }else if(i < 100000000){
            go(8, i);
        }else if(i < 1000000000){//아홉 자리 수(100000000으로 나눔)
            go(9, i);
        }        
    }
    cout<<final[0]<<" "<<final[1]<<" "<<final[2]<<" "<<final[3]<<" "<<final[4]<<" "<<final[5]<<" "<<final[6]<<" "<<final[7]<<" "<<final[8]<<" "<<final[9]<<"\n";
}