//동전 0
#include <iostream>
#include <algorithm>
using namespace std;

int n, price;
int a[11] = {0, };
int num = 0;

void go(){
    for(int i=n-1; i>=0; i--){
        if(a[i] <= price){//i부터 차례대로 점점 내려간다
            for(int k=i; k>=0; k--){
                if(a[k] <= price){
                    num += (price / a[k]);
                    price %= a[k];                    
                }
            }
            break;
        }
    }
}

int main(){
    cin>>n>>price;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    go();
    cout<<num<<"\n";
}