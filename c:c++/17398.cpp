// 통신망 분할 (union-find)
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int n, m, q, x, y, z;
 
vector<int> disconnect; // 끊을 곳
vector<pair<int, int>> v;
map<int, int> M;
int connect[100001] = {0, };
long long cost[100001] = {0, };
long long total = 0;
 
int find(int a){
   if(a==connect[a]){
       return a;
   }else{
       return connect[a] = find(connect[a]);
   }
}
 
 
int main()
{
   cin>>n>>m>>q;
   for(int i=1; i<=m; i++){
       cin>>x>>y;
       v.push_back(make_pair(x, y));
   }
   for(int i=0; i<q; i++){
       cin>>z;
       M[z] = 1;
       disconnect.push_back(z); // z번째 연결 요소를 끊는다.
   }
 
   for(int i=1; i<=n; i++){
       cost[i] = 1;
       connect[i] = i;
   }
 
   for(int i=0; i<v.size(); i++){
       if(M[i+1]==1){ // 끊어야 할 연결요소
           continue;
       }
       int a = find(v[i].first);
       int b = find(v[i].second);
 
       if(a!=b){
           // a->b
           connect[a] = b;
           cost[b] += cost[a];
       }
   }
 
   // 거꾸로 연결해준다.
   for(int i=disconnect.size()-1; i>=0; i--){
       int idx = disconnect[i]-1;
       int a = find(v[idx].first);
       int b = find(v[idx].second);
 
       if(a!=b){
           connect[a] = b;
           total += cost[a]*cost[b];
           cost[b] += cost[a];
       }
   }
 
   cout<<total<<"\n";
   return 0;
}
