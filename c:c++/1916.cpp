//최소비용 구하기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
int from, to, w, n, m, Start, End;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int visited[1001] = {0, };
vector<pair<int, int>> v[1001];
int cost[1001] = {0, };
 
void go()
{
   cost[Start] = 0;
   pq.push(make_pair(0, Start));//최소 비용, 도시
 
   while(!pq.empty()){
       int city = pq.top().second;
       int value = pq.top().first;
       pq.pop();
 
       if(!visited[city]){
           visited[city] = 1;
           for(int i=0; i<v[city].size(); i++){
               if(cost[v[city][i].first] > value+v[city][i].second){
                   cost[v[city][i].first] = value+v[city][i].second;
                   pq.push(make_pair(cost[v[city][i].first], v[city][i].first));
               }
           }
       }
   }
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<m; i++){
       cin>>from>>to>>w;
       v[from].push_back(make_pair(to, w));
   }
   cin>>Start>>End;
 
   for(int i=1; i<=n; i++){
       cost[i] = INT_MAX;
   }
 
   go();
   cout<<cost[End]<<"\n";
   return 0;
}
