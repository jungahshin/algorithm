// 최소 비용구하기 2
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
 
int n, m, from, to, cost, Start, End;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> v[1001];
int visited[1001] = {0, }; // 방문 여부 표시
int dist[1001] = {0, }; // 도시마다 최단 경로 저장
int city[1001] = {0, }; // 거쳐가는 도시 저장, city[a] = b이면 a로 오는 최단경로가 b에서 오는 것이다.
vector<int> final; // 최단 경로를 저장하는
 
void shortest()
{
   dist[Start] = 0;
   pq.push(make_pair(0, Start));
 
   while(!pq.empty()){
       int num = pq.top().first;
       int x = pq.top().second;
       pq.pop();
 
       if(!visited[x]){
           visited[x] = 1;
           for (int i=0; i<v[x].size(); i++){
               if(dist[v[x][i].first]>num+v[x][i].second){
                   city[v[x][i].first] = x;
                   dist[v[x][i].first] = num+v[x][i].second;
                   pq.push(make_pair(dist[v[x][i].first], v[x][i].first));
               }
           }
       }
   }
}
 
void print_shortest(int C)
{
   if(C==Start){
       return;
   }
 
   final.push_back(city[C]);
   print_shortest(city[C]);
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<m; i++){
       cin>>from>>to>>cost;
       v[from].push_back(make_pair(to, cost));
   }
   cin>>Start>>End;
 
   for(int i=1; i<=n; i++){
       dist[i] = INT_MAX;
   }
 
   shortest();
   final.push_back(End);
   print_shortest(End);
 
   cout<<dist[End]<<"\n";
   cout<<final.size()<<"\n";
   for(int i=final.size()-1; i>=0; i--){
       cout<<final[i]<<"\n";
   }
 
   return 0;
}