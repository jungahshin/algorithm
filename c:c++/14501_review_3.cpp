// 퇴사
#include <iostream>
#include <vector>
 
using namespace std;
 
int n, days, cost;
vector<pair<int, int>> v;
int ans = 0;
 
void dfs(int day, int total)
{
    if(day>v.size()) return;
    ans = max(ans, total);
 
    for(int i=day; i<v.size(); i++){
        int days = v[i].first;
        int cost = v[i].second;
 
        dfs(i+days, total+cost);
    }
}
 
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>days>>cost;
        v.push_back(make_pair(days, cost));
    }
 
    for(int i=0; i<v.size(); i++){
        int days = v[i].first;
        int cost = v[i].second;
        
        dfs(i+days, cost);
    }
 
    cout<<ans<<"\n";
    return 0;
}