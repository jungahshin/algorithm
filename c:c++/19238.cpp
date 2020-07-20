// 스타트 택시
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
 
int n, m, start_x, start_y, s_x, s_y, e_x, e_y;
int road[22][22] = {0, }; // 도로의 상태
long long oil = 0; // 연료
vector<pair<pair<int, int>, pair<int, int> > > customer;
map<int, int> check;// 이미 데려다 준 고객들을 map으로 표시해준다.
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check_final = true; // // 연료가 부족하거나 도착지점에 도착할 수 없음을 판별
 
// 태울 사람의 출발지에서 목적지까지의 거리
long long bfs2(int idx)
{
   //중간에 연료가 부족하거나 도착 지점에 도착할 수 없으면 -1 반환한다.
   int final = 0; // 출발지에서 도착지까지의 거리
   bool temp = false; // 연료가 부족하거나 도착지점에 도착할 수 없음을 판별
   queue<pair<pair<int, int>, int>> q;
   q.push(make_pair(make_pair(customer[idx].first.first, customer[idx].first.second), 0));
   int visited[22][22] = {0, };
 
   while(!q.empty()){
       int x = q.front().first.first;
       int y = q.front().first.second;
       int num = q.front().second;
       visited[x][y] = 1;
       q.pop();
 
       if(num>oil){
           break;
       }
 
       if(x==customer[idx].second.first && y==customer[idx].second.second){
           final = num;
           temp = true;
           break;
       }
 
       for(int i=0; i<4; i++){
           int nx = x+dx[i];
           int ny = y+dy[i];
           if(1<=nx && nx<=n && 1<=ny && ny<=n && !visited[nx][ny]){
               visited[nx][ny] = 1;
               if(road[nx][ny]==0){
                   q.push(make_pair(make_pair(nx, ny), num+1));
               }
           }
       }
   }
 
   if(temp == false){ // 도착지점에 도착하지 못하거나 연료가 부족한 경우
       return -1;
   }
  
   return final;
}
 
// 태울 사람 선정
void bfs()
{
   // 일단, 각 사람들까지의 최단 거리를 각각 구해보고 가장 최단 거리인 사람을 찾는다.
   vector<pair<int, int> > v; // 가장 최단 거리를 구하기 위해(거리, idx k값)
   for(int k=0; k<customer.size(); k++){
       if(check.count(k)==0){ // 나중에 최단 거리인 고객을 check[k] = 1로 표시해준다.
           queue<pair<pair<int, int>, int> > q;
           q.push(make_pair(make_pair(start_x, start_y), 0));
           int visited[22][22] = {0, };
 
           while(!q.empty()){
               int x = q.front().first.first;
               int y = q.front().first.second;
               int num = q.front().second;
               visited[x][y] = 1;
               q.pop();
 
               if(x==customer[k].first.first && y==customer[k].first.second){
                   v.push_back(make_pair(num, k));
                   break;
               }
 
               for(int i=0; i<4; i++){
                   int nx = x+dx[i];
                   int ny = y+dy[i];
                   if(1<=nx && nx<=n && 1<=ny && ny<=n && !visited[nx][ny]){
                       visited[nx][ny] = 1;
                       if(road[nx][ny]==0){
                           q.push(make_pair(make_pair(nx, ny), num+1));
                       }
                   }
               }
           }
       }
   }
 
   if(v.size()!=m){
       check_final = false;
       return;
   }
 
   sort(v.begin(), v.end());
 
   vector<pair<pair<int, int>, int> > v_temp;
   for(int i=0; i<v.size(); i++){
       if(v[0].first == v[i].first){ // 거리가 최단으로 같아면 행과 열을 확인한다.
           int idx = v[i].second;
           v_temp.push_back(make_pair(make_pair(customer[idx].first.first, customer[idx].first.second), idx));
       }
   }
 
   sort(v_temp.begin(), v_temp.end());
 
   //최단 거리 -> v[0].first // customer -> v_temp[0].second
   int short_num = v[0].first;
   int short_idx = v_temp[0].second;
 
   oil -= short_num;
 
   long long dist = bfs2(short_idx);
   if(dist==-1){ // 중간에 연료가 부족하거나, 도착할 수 없다.
       check_final = false;
   }else{
       m--;
       check[short_idx] = 1;
       oil = oil-dist+2*dist;
       //택시 출발 지점 바꿔주기
       start_x = customer[short_idx].second.first;
       start_y = customer[short_idx].second.second;
   }
}
 
int main()
{
   cin>>n>>m>>oil;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           cin>>road[i][j];
       }
   }
   cin>>start_x>>start_y;
   for(int i=0; i<m; i++){
       cin>>s_x>>s_y>>e_x>>e_y;
       customer.push_back(make_pair(make_pair(s_x, s_y), make_pair(e_x, e_y)));
   }
 
   while(1){
       check_final = true;
       bfs();
       if(m==0){ // 모든 승객을 다 태웠다.
           break;
       }
 
       if(check_final==false){ // 중간에 연료가 없거나 다 태울 수 없는 경우
           break;
       }
       // break;
   }
 
   if(check_final==false){
       cout<<"-1"<<"\n";
   }else{
       cout<<oil<<"\n";
   }
 
   return 0;
}

