// 스타트 택시
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int n, m, taxi_x, taxi_y, s_x, s_y, e_x, e_y;
long long oil;
int start[22][22] = {0, }; // 각 승객들의 출발 위치에 따른 번호
int map[22][22] = {0, };
vector<pair<pair<int, int>, pair<int, int>>> customer;
int done[402] = {0, }; // 이미 태운 승객
bool check2 = false;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
 
int bfs(int sx, int sy, int ex, int ey)
{
   int visited[21][21] = {0, };
   queue<pair<int, pair<int, int>>> q;
   q.push(make_pair(0, make_pair(sx, sy)));
 
   while(!q.empty()){
       int x = q.front().second.first;
       int y = q.front().second.second;
       int num = q.front().first;
       visited[x][y] = 1;
       q.pop();
 
       if(x==ex && y==ey){
           return num;
       }
 
       for(int i=0; i<4; i++){
           int nx = x+dx[i];
           int ny = y+dy[i];
           if(1<=nx && nx<=n && 1<=ny && ny<=n && !visited[nx][ny]){
               visited[nx][ny] = 1;
               if(map[nx][ny]==0){
                   q.push(make_pair(num+1, make_pair(nx, ny)));
               }
           }
       }
   }
 
   return -1;
}
 
bool choose()
{
   vector<pair<int, pair<int, int>>> temp;
   for(int i=0; i<customer.size(); i++){
       if(done[i]) continue;
       int start_x = customer[i].first.first;
       int start_y = customer[i].first.second;
 
       int dist = bfs(taxi_x, taxi_y, start_x, start_y);
       if(dist==-1){
           return false;
       }
       temp.push_back(make_pair(dist, make_pair(start_x, start_y)));
   }
 
   sort(temp.begin(), temp.end());
 
   int x = temp[0].second.first;
   int y = temp[0].second.second;
   int cus_num = start[x][y];
   int nx = customer[cus_num].second.first;
   int ny = customer[cus_num].second.second;
 
   int a = bfs(taxi_x, taxi_y, x, y);
   if(a==-1){
       return false;
   }
   int b = bfs(x, y, nx, ny);
   if(b==-1){
       return false;
   }
 
   int total_dist = a+b;
 
   if(oil<total_dist){
       return false;
   }
 
   oil -= total_dist;
   oil += (b*2);
   done[cus_num] = 1;
   taxi_x = nx;
   taxi_y = ny;
   m--;
 
   return true;
}
 
void drive()
{
   while(1){
       if(oil<=0){
           check2 = true;
           break;
       }
 
       if(m==0){
           break;
       }
 
       // 태울 승객 정하기
       if(!choose()){ // 운행도중 연료가 부족하거나 손님한테 갈 수 없는 경우(장애물)
           check2 = true;
           break;
       }
   }
}
 
int main()
{
   cin>>n>>m>>oil;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           cin>>map[i][j];
       }
   }
 
   cin>>taxi_x>>taxi_y;
   for(int i=0; i<m; i++){
       cin>>s_x>>s_y>>e_x>>e_y;
       customer.push_back(make_pair(make_pair(s_x, s_y), make_pair(e_x, e_y)));
       start[s_x][s_y] = i;
   }
 
   drive();
 
   if(check2==true){ // 중간에 업무가 중단된 경우
       cout<<"-1"<<"\n";
   }else{
       cout<<oil<<"\n";
   }
 
   return 0;
}