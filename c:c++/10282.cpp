// 해킹(다익스트라)
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
 
int testcase, n, d, c, a, b, s;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
 
vector<pair<int, int>> v[10001];
int day[10001] = {0, };
int visited[10001] = {0, };
int final = 0;
int num = 0;
 
void go(){
   day[c] = 0;
   pq.push(make_pair(0, c));
 
   while(!pq.empty()){
       int value = pq.top().first;
       int x = pq.top().second;
       pq.pop();
 
       final = max(final, day[x]);
 
       if(!visited[x]){
           num++;
           visited[x] = 1;
           for(int i=0; i<v[x].size(); i++){
               if(day[v[x][i].first]>value+v[x][i].second){
                   day[v[x][i].first] = value+v[x][i].second;
                   pq.push(make_pair(day[v[x][i].first], v[x][i].first));
               }
           }
       }
   }
}
 
int main()
{
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       final = 0;
       num = 0;
       memset(visited, 0, sizeof(visited));
       cin>>n>>d>>c; // 해킹된 c에서 출발
       for(int j=1; j<=n; j++){
           day[j] = INT_MAX;
       }
 
       for(int j=1; j<=n; j++){
           if(v[j].size()>0){
               v[j].clear();
           }
       }
       for(int j=0; j<d; j++){
           cin>>a>>b>>s;
           v[b].push_back(make_pair(a, s)); // a가 b에 의존하기 때문에 b가 감염되면 a를 감염시킨다.
       }
 
       go();
 
       cout<<num<<" "<<final<<"\n";
   }
}
