//연속 합
#include <iostream>
using namespace std;

int a[100001] = {0, };
int n, final = -1001;

int MAX(int a, int b){
    return a>b ? a:b;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=1; i<n; i++){
        a[i] = MAX(a[i], a[i]+a[i-1]);
    }

    for(int i=0; i<n; i++){
        final = max(final, a[i]);
    }

    cout<<final<<"\n";
}