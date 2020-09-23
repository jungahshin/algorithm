// 가장 긴 증가하는 부분 수열 2,3
#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector<int> v;
vector<int> LIS;
 
int main()
{
   cin>>n;
   v.resize(n);
   for(int i=0; i<n; i++){
       cin>>v[i];
   }
 
   for(int i=0; i<v.size(); i++){
       if(LIS.empty() || LIS.back()<v[i]){
           LIS.push_back(v[i]);
       }else{
           LIS[lower_bound(LIS.begin(), LIS.end(), v[i])-LIS.begin()] = v[i];
       }
   }
 
   cout<<LIS.size()<<"\n";
   return 0;
}