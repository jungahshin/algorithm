// 연구소 3
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
 
using namespace std;
 
int n, m;
int lab[51][51] = {0, };
int visited[11] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int>> virus;
vector<pair<int, int>> active;
int cnt = 0; // 빈칸의 총 수
bool check = false;
int ans = INT_MAX;
 
void bfs()
{
   int total = 0;
   int temp = 0;
   int visited2[51][51] = {0, };
   queue<tuple<int, int, int>> q;
   for(int i=0; i<active.size(); i++){
       q.push(make_tuple(0, active[i].first, active[i].second));
       visited2[active[i].first][active[i].second] = -1;
   }
 
   while(!q.empty()){
       int x, y, sec;
       tie(sec, x, y) = q.front();
       q.pop();
 
       if(cnt==total){
           check = true;
           ans = min(ans, temp);
           break;
       }
 
       for(int i=0; i<4; i++){
           int nx = x+dx[i];
           int ny = y+dy[i];
           if(0<=nx && nx<n && 0<=ny && ny<n && visited2[nx][ny]==0){
               if(lab[nx][ny]!=1){
                   if(lab[nx][ny]==0) total++;
                   visited2[nx][ny] = sec+1;
                   temp = max(temp, sec+1);
                   q.push(make_tuple(sec+1, nx, ny));
               }
           }
       }
   }
}
 
void choose(int num, int idx)
{
   if(num==m){
       active.clear();
       for(int i=0; i<virus.size(); i++){
           if(visited[i]==true){
               active.push_back(make_pair(virus[i].first, virus[i].second));
           }
       }
       bfs();
       return;
   }
 
   for(int i=idx; i<virus.size(); i++){
       if(visited[i]==true) continue;
       visited[i] = true;
 
       choose(num+1, i);
       visited[i] = false;
   }
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cin>>lab[i][j];
           if(lab[i][j]==2){
               virus.push_back(make_pair(i, j));
           }else if(lab[i][j]==0){
               cnt++;
           }
       }
   }
 
   choose(0, 0);
 
   if(check==false){
       cout<<"-1"<<"\n";
   }else{
      cout<<ans<<"\n";
   }
  
   return 0;
}