//전깃줄-2(LIS->요소추적하기)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
int n, a, b;
vector<pair<int, int>> v;
vector<int> LIS;//값, idx
vector<int> backtrace;
vector<int> ans;
map<int, int> m;
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>a>>b;
       v.push_back(make_pair(a, b));
   }
 
   sort(v.begin(), v.end());
 
   int idx = 0;
   for(int i=0; i<v.size(); i++){
       if(LIS.empty() || LIS.back()<v[i].second){
           LIS.push_back(v[i].second);
           backtrace.push_back(LIS.size()-1);
       }else{
           int idx = lower_bound(LIS.begin(), LIS.end(), v[i].second)-LIS.begin();
           backtrace.push_back(idx);
           LIS[idx] = v[i].second;
       }
   }
 
   int temp = LIS.size()-1;
   for(int i=backtrace.size()-1; i>=0; i--){
       if(backtrace[i]==temp){
           temp--;
           m[i] = 1;
       }
   }
 
   for(int i=0; i<v.size(); i++){
       if(m.count(i)==0){
           ans.push_back(v[i].first);
       }
   }
 
   sort(ans.begin(), ans.end());
 
   cout<<n-LIS.size()<<"\n";
   for(int i=0; i<ans.size(); i++){
       cout<<ans[i]<<"\n";
   }
 
   return 0;
}
