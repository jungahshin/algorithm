//퇴사
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int n, t, p;
int final_max = 0;

bool check(int idx){
    bool temp = false;
    if(v[idx].first == 1 && idx == n-1){
        temp = true;
    }
    return temp;
}

void dfs(int idx, int final){
    if((idx+1)+(v[idx].first) <= n+1){
        final += v[idx].second;
    }
    if((idx+1)+(v[idx].first) >= n+1 || check(idx)){
        //최대값 저장하기
        final_max = max(final_max, final);
        return;
    }
    for(int j=idx+v[idx].first; j<n; j++){
        dfs(j, final);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t>>p;
        v.push_back(make_pair(t, p));
    }
    for(int i=0; i<v.size(); i++){
        dfs(i, 0);
    }
    cout<<final_max<<"\n";
}