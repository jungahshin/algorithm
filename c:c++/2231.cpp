//분해합
//생성자의 최소는 분해합에 - 분해합자리수 *9
#include <iostream>
#include <climits>
using namespace std;

int n;
int final = INT_MAX;

void go(int start, int size){
    for(int i=start; i<n; i++){//이 중에 i를 더하고 각 자리수를 더한 것이 n이 되면 탈출
        int temp = i;
        int final_temp = i;
        int size_temp = size;
        while(final_temp != 0){
            temp += final_temp/size_temp;
            final_temp %= size_temp;
            size_temp /= 10;
        }
        if(temp == n){
            final = min(final, i);
        }
    }
}

int main(){
    cin>>n;
    if(n >= 1000000){//7자리
        go(n-(9*7), 1000000);
    }else if(n >= 100000){//6자리
        go(n-(9*6), 100000);
    }else if(n >= 10000){//5자리
        go(n-(9*5), 10000);
    }else if(n >= 1000){//4자리
        go(n-(9*4), 1000);
    }else if(n >= 100){//3자리
        go(n-(9*3), 100);
    }else if(n >= 10){//2자리
        go(0, 10);
    }else{//한 자리
        go(0, 1);
    }
    if(final == INT_MAX){
        cout<<"0"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}