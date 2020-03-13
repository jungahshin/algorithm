//수리공 항승
#include <iostream>
#include <algorithm>
using namespace std;

int a[1001] = {0, };
int visited[1001] = {0, };
int num = 0;
int n, l;

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            int temp = a[i]+l-1;
            for(int j=i+1; j<n; j++){
                if(a[j]>temp){
                    break;
                }else{
                    visited[j] = 1;
                }
            }
            num++;
        }
    }
    cout<<num<<"\n";
    return 0;
}