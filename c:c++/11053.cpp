//가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<int> v;
int DP[1002] = {0, };
int idx = 0;
int final = 0;

void go(){
    while(1){
        idx++;
        if(idx > n){
            return;
        }
        int temp = 0;
        for(int i=0; i<idx; i++){
            if(v[idx-1] > v[i]){
                temp = max(temp, DP[i+1]);
            }
        }
        DP[idx] = temp + 1;        
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        v.push_back(t);
    }
    DP[0] = 0;
    go();
    for(int i=0; i<=n; i++){
        final = max(final, DP[i]);
    }
    cout<<final<<"\n";
}