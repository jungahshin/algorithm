// 등차수열 변환
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int n, m;
vector<int> v;
int final = INT_MAX;
 
void dfs(int before, int idx, int num, int diff) // 이전 값, 수행할 idx, 지금까지의 횟수, 차이
{
   if(idx>=n){ // 끝(n이 1, 2일 경우 idx2인 경우가 존재하지 않기 때문에 '>='로 해야 한다.)
       final = min(final, num);
       return;
   }
 
   int ndiff = (v[idx]-1) - before;
   if(ndiff==diff){
       dfs(v[idx]-1, idx+1, num+1, ndiff);
   }
 
   ndiff = (v[idx] - before);
   if(ndiff==diff){
       dfs(v[idx], idx+1, num, ndiff);
   }
 
   ndiff = (v[idx]+1) - before;
   if(ndiff==diff){
       dfs(v[idx]+1, idx+1, num+1, ndiff);
   }
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       v.push_back(m);
   }
 
   int dif = (v[1]+1) - (v[0]-1);
   dfs(v[1]+1, 2, 2, dif);
 
   dif = (v[1]+1) - (v[0]);
   dfs(v[1]+1, 2, 1, dif);
 
   dif = (v[1]+1) - (v[0]+1);
   dfs(v[1]+1, 2, 2, dif);
 
   dif = v[1] - (v[0]-1);
   dfs(v[1], 2, 1, dif);
 
   dif = v[1] - v[0];
   dfs(v[1], 2, 0, dif);
 
   dif = v[1] - (v[0]+1);
   dfs(v[1], 2, 1, dif);
 
   dif = (v[1]-1) - (v[0]-1);
   dfs(v[1]-1, 2, 2, dif);
 
   dif = (v[1]-1) - (v[0]);
   dfs(v[1]-1, 2, 1, dif);
 
   dif = (v[1]-1) - (v[0]+1);
   dfs(v[1]-1, 2, 2, dif);
 
   if(final == INT_MAX){
       cout<<"-1"<<"\n";
   }else{
       cout<<final<<"\n";
   }
  
   return 0;
}
