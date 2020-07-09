//거의 최단경로(다익스트라)
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
 
using namespace std;
 
int n, m, Start, End, u, v, p;
vector<pair<int, int>> V[501];
int visited[501] = {0, };
int dist[501] = {0, };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<int> shortest[501];//최단 경로를 저장
 
void dijkstra()
{
   dist[Start] = 0;
   pq.push(make_pair(0, Start));
 
   while(!pq.empty()){
       int x = pq.top().second;
       int value = pq.top().first;
       pq.pop();
 
       if(!visited[x]){
           visited[x] = 1;
           for(int i=0; i<V[x].size(); i++){
               if(V[x][i].second==-1){
                   continue;
               }
               if(dist[V[x][i].first]>value+V[x][i].second){
                   dist[V[x][i].first] = value+V[x][i].second;
                   pq.push(make_pair(dist[V[x][i].first], V[x][i].first));
                   shortest[V[x][i].first].clear();
                   shortest[V[x][i].first].push_back(x);
               }else if(dist[V[x][i].first]==value+V[x][i].second){
                   shortest[V[x][i].first].push_back(x);
               }
           }
       }
   }
}
 
void del(int End)//최단 거리의 도로들을 다 없애준다.
{
   for(int j=0; j<shortest[End].size(); j++){
       //End도착, temp출발
       int temp = shortest[End][j];
       for(int k=0; k<V[temp].size(); k++){
           if(V[temp][k].first == End){
               V[temp][k].second = -1;
           }
       }
       del(temp);
   }
}
 
int main()
{
   while(1){
       memset(visited, 0, sizeof(visited));
       for(int i=0; i<n; i++){
           shortest[i].clear();
       }
       for(int i=0; i<n; i++){
           V[i].clear();
       }
 
       cin>>n>>m;
       if(n==0 && m==0){
           break;
       }
       cin>>Start>>End;
       for(int i=0; i<m; i++){
           cin>>u>>v>>p;
           V[u].push_back(make_pair(v, p));
       }
 
       for(int i=0; i<n; i++){
           dist[i] = INT_MAX;
       }
 
       dijkstra();
       del(End);
      
       //다시 다익스트라돌린다.
       memset(visited, 0, sizeof(visited));
       for(int i=0; i<n; i++){
           shortest[i].clear();
       }
       for(int i=0; i<n; i++){
           dist[i] = INT_MAX;
       }
 
       dijkstra();
       if(dist[End] == INT_MAX){
           cout<<"-1"<<"\n";
       }else{
           cout<<dist[End]<<"\n";
       }
   }
   return 0;
}
