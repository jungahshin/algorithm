//포도주 시식
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[10001] = {0, };
int num[10001][4] = {0, };//index와 횟수(0, 1, 2)
int final = 0;

int go(int index, int drink){//+a[index]
    if(index == n-1){
        if(drink == 0){
            return 0;
        }else{
            return a[index];
        }
    }
    if(num[index][drink] != 0){
        return num[index][drink];
    }else{
        if(drink == 0){//1(마시거나), 0(마시지 않거나)
            num[index][drink] = max(num[index][drink], go(index+1, 0));
            num[index][drink] = max(num[index][drink], go(index+1, 1));
        }else if(drink == 1){//2(마시거나), 0(마시지 않거나)
            num[index][drink] = max(num[index][drink], go(index+1, 0)+a[index]);
            num[index][drink] = max(num[index][drink], go(index+1, 2)+a[index]);
        }else if(drink == 2){//무조건 0(마시지 못해)
            num[index][drink] = max(num[index][drink], go(index+1, 0)+a[index]);
        }
        return num[index][drink];
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    final = max(final, go(0, 0));//첫 번째를 마시지 않거나
    final = max(final, go(0, 1));//마시거나
    cout<<final<<"\n";
}