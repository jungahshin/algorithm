// 가장 긴 증가하는 부분 수열 4
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, m;
vector<int> v;
vector<int> LIS;
vector<int> backtrace;
vector<int> ans;
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       v.push_back(m);
   }
 
   for(int i=0; i<v.size(); i++){
       if(LIS.empty() || LIS.back()<v[i]){
           LIS.push_back(v[i]);
           backtrace.push_back(LIS.size()-1);
       }else{
           int idx = lower_bound(LIS.begin(), LIS.end(), v[i])-LIS.begin();
           backtrace.push_back(idx);
           LIS[idx] = v[i];
       }
   }
 
   int temp = LIS.size()-1;
   for(int i=backtrace.size()-1; i>=0; i--){
       if(backtrace[i]==temp){
           temp--;
           ans.push_back(v[i]);
       }
   }
 
   sort(ans.begin(), ans.end());
 
   cout<<ans.size()<<"\n";
   for(int i=0; i<ans.size(); i++){
       if(i==ans.size()-1){
           cout<<ans[i]<<"\n";
       }else{
           cout<<ans[i]<<" ";
       }
   }
  
   return 0;
}