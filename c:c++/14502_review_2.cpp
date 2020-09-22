// 연구소
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int n, m;
int lab[9][9] = {0, };
int visited[70] = {0, };
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = 0;
 
void spread()
{
   queue<pair<int, int>> q;
   int visited_virus[9][9] = {0, };
 
   for(int i=0; i<virus.size(); i++){
       q.push(make_pair(virus[i].first, virus[i].second));
   }
 
   while(!q.empty()){
       int x = q.front().first;
       int y = q.front().second;
       visited_virus[x][y] = 1;
       q.pop();
 
       for(int i=0; i<4; i++){
           int nx = x+dx[i];
           int ny = y+dy[i];
           if(0<=nx && nx<n && 0<=ny && ny<m && !visited_virus[nx][ny]){
               visited_virus[nx][ny] = 1;
               if(lab[nx][ny]==0){
                   q.push(make_pair(nx, ny));
               }
           }
       }
   }
 
   int num = 0;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(!visited_virus[i][j] && lab[i][j]==0){
               num++;
           }
       }
   }
 
   ans = max(ans, num);
}
 
void choose(int idx, int num)
{
   if(num==3){
       // 새로 벽 세우기
       for(int i=0; i<wall.size(); i++){
           if(visited[i]==true){
               lab[wall[i].first][wall[i].second] = 1;
           }
       }
 
       // 바이러스 퍼뜨리기
       spread();
 
       // 벽 허물기
       for(int i=0; i<wall.size(); i++){
           if(visited[i]==true){
               lab[wall[i].first][wall[i].second] = 0;
           }
       }
 
       return;
   }
 
   for(int i=idx; i<wall.size(); i++){
       if(visited[i]==true) continue;
       visited[i] = true;
       choose(i, num+1);
       visited[i] = false;
   }
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cin>>lab[i][j];
           if(lab[i][j]==0){ // 바이러스
               wall.push_back(make_pair(i, j));
           }else if(lab[i][j]==2){
               virus.push_back(make_pair(i, j));
           }
       }
   }
 
   choose(0, 0);
 
   cout<<ans<<"\n";
   return 0;
}