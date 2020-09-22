// 퇴사
#include <iostream>
#include <vector>
using namespace std;
 
int n, t, p;
vector<pair<int, int>> v;
int final = 0;
 
void dfs(int start, int total)
{
   final = max(final, total);
 
   for(int i=start; i<v.size(); i++){
       int day = i+1;
       int cost = v[i].second;
       int end = day+v[i].first-1;
       if(end>=n+1) continue;
       dfs(end, total+cost);
   }
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>t>>p;
       v.push_back(make_pair(t, p));
   }
 
   for(int i=0; i<v.size(); i++){
       // i+1이 day
       int day = i+1;
       int cost = v[i].second;
       int end = day+v[i].first-1;
       if(end>=n+1) continue;
       dfs(end, cost);
   }
 
   cout<<final<<"\n";
   return 0;
}