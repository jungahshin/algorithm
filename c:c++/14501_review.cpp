//퇴사 복습
#include <iostream>
#include <vector>
using namespace std;

int n, a, b;
int DP[17] = {0, };
vector<pair<int, int>> v;
int total = 0;

int go(int idx, int final){
    int next_idx = idx+v[idx].first;
    if(next_idx<v.size()){
        for(int i=next_idx; i<v.size(); i++){
            DP[i] = max(DP[i], go(i, final+v[idx].second));
        }
    }else if(next_idx == v.size()){
        DP[next_idx] = max(DP[next_idx], final+v[idx].second);
    }
    return final;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    for(int i=0; i<v.size(); i++){
        DP[i] = max(DP[i], go(i, 0));
    }
    for(int i=0; i<=v.size(); i++){
        total = max(DP[i], total);
    }
    cout<<total<<"\n";
    return 0;
}