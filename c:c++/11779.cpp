// 최소 비용구하기 2
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
 
using namespace std;
 
int n, m, from, to, cost, Start, End;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<pair<int, int> > v[1001];
int city[1001] = {0, }; // city[a] = b이면, a도시는 b에서 오는게 가장 최소 비용이다.
int dist[1001] = {0, };
int visited[1001] = {0, };
vector<int> final;
 
void go()
{
   dist[Start] = 0;
   pq.push(make_pair(0, Start));
 
   while(!pq.empty()){
       int x = pq.top().second;
       int num = pq.top().first;
       pq.pop();
 
       if(!visited[x]){
           visited[x] = 1;
           for(int i=0; i<v[x].size(); i++){
               if(dist[v[x][i].first]>num+v[x][i].second){
                   city[v[x][i].first] = x;
                   dist[v[x][i].first] = num+v[x][i].second;
                   pq.push(make_pair(dist[v[x][i].first], v[x][i].first));
               }
           }
       }
   }
}
 
void print_go(int C)
{
   if(C==Start){
       return;
   }
   final.push_back(city[C]);
 
   print_go(city[C]);
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
 
   go();
   cout<<dist[End]<<"\n";
 
   final.push_back(End);
   print_go(End);
   cout<<final.size()<<"\n";
   for(int i=final.size()-1; i>=0; i--){
       cout<<final[i]<<" ";
   }
   cout<<"\n";
   return 0;
}
