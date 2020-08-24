// 보석 도둑
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int n, k, m, v;
pair<int, int> jewelry[300001];
int bag[300001] = {0, };
priority_queue<int> pq;
long long final = 0;
 
int main()
{
   cin>>n>>k;
   for(int i=0; i<n; i++){
       cin>>jewelry[i].first>>jewelry[i].second;
   }
 
   for(int i=0; i<k; i++){
       cin>>bag[i];
   }
 
   sort(jewelry, jewelry+n);
   sort(bag, bag+k);
 
   int idx = 0;
 
   // 가방을 기준으로(무게)
   for(int i=0; i<k; i++){
       while(idx<n && jewelry[idx].first<=bag[i]){
           pq.push(jewelry[idx++].second);
       }
 
       if(!pq.empty()){
           final += pq.top(); // root에 있는 값을 더해준다.
           pq.pop();
       }
   }
 
   cout<<final<<"\n";
   return 0;
}
