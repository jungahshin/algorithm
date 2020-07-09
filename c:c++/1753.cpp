//최단경로
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
 
using namespace std;
 
int V, E, K, from, to, w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<pair<int, int> > v[20001];
int dist[20001] = {0, };
int visited[20001] = {0, };
 
void go()//다익스트라
{
   dist[K] = 0;//자기 자신은 0
   pq.push(make_pair(0, K));
 
   while(!pq.empty()){
       int x = pq.top().second;
       int value = pq.top().first;
       pq.pop();
      
       if(!visited[x]){//출발
           visited[x] = 1;
           for(int i=0; i<v[x].size(); i++){
               if(dist[v[x][i].first]>value+v[x][i].second){
                   dist[v[x][i].first] = value+v[x][i].second;
                   pq.push(make_pair(dist[v[x][i].first], v[x][i].first));
               }
           }
       }
   }
}
 
int main()
{
   cin>>V>>E;//정점, 간선
   cin>>K;
   for(int i=0; i<E; i++){
       cin>>from>>to>>w;
       v[from].push_back(make_pair(to, w));
   }
 
   for(int i=1; i<=V; i++){
       dist[i] = INT_MAX;
   }
 
   go();
   for(int i=1; i<=V; i++){
       if(dist[i] == INT_MAX){//갈 방법이 없다.
           cout<<"INF"<<"\n";
       }else{
           cout<<dist[i]<<"\n";
       }
   }
 
   return 0;
}
