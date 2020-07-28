// 청소년 상어
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int a, b;
vector<int> sea[5][5]; // 0->번호, 1->방향
map<int, pair<int, int>> location; // 물고기 번호에 따른 위치
int alive[17] = {0, };
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int total = 0;
  
void move_fish(int shark_x, int shark_y)
{
   for(int i=1; i<=16; i++){
       if(alive[i]==1){
           continue;
       }
       // 살아있다면
       int x = location[i].first;
       int y = location[i].second;
 
       int num = sea[x][y][0];
       int dir = sea[x][y][1];
       bool check = false;
 
       int final_x, final_y; // 바꿀 위치
 
       while(1){ // 교환 가능할 때까지 방향 바꾼다.
           check = false;
           int nx = x+dx[dir-1];
           int ny = y+dy[dir-1];
 
           if(0<=nx && nx<4 && 0<=ny && ny<4){
               if(shark_x==nx && shark_y==ny){ // 상어가 있다.
                   check = false;
               }else{ // 위치 교환 가능
                   check = true;
               }
           }else{ // 벗어난다.
               check = false;
           }
           if(check==true){
               final_x = nx;
               final_y = ny;
               break;
           }
 
           // 방향을 45도 반시계 방향 회전
           dir++;
           if(dir==9){
               dir = 1;
           }
       }
  
       // (x, y)와 (final_x, final_y)가 서로 위치 교환
       if(sea[final_x][final_y].size()>0){
           int final_num = sea[final_x][final_y][0];
           int final_dir = sea[final_x][final_y][1];
           location[num] = make_pair(final_x, final_y);
           location[final_num] = make_pair(x, y);
           sea[x][y].clear();
           sea[final_x][final_y].clear();
           sea[x][y].push_back(final_num);
           sea[x][y].push_back(final_dir);
           sea[final_x][final_y].push_back(num);
           sea[final_x][final_y].push_back(dir);
       }else{
           location[num] = make_pair(final_x, final_y);
           sea[x][y].clear();
           sea[final_x][final_y].push_back(num);
           sea[final_x][final_y].push_back(dir);
       }
   }
}
 
void dfs(int shark_x, int shark_y, int shark_dir, int total_eat)
{
   total = max(total, total_eat);
  
   // 초기화
   vector<int> Sea[5][5];
   map<int, pair<int, int>> Location;
   int Alive[17] = {0, };

   for(int i=0; i<4; i++){
       for(int j=0; j<4; j++){
           if(Sea[i][j].size()>0){
               Sea[i][j].clear();
           }
           if(sea[i][j].size()>0){
                Sea[i][j].push_back(sea[i][j][0]);
                Sea[i][j].push_back(sea[i][j][1]);
           }
       }
   }
 
   for(int i=1; i<=16; i++){
       Location[i] = make_pair(location[i].first, location[i].second);
   }
 
   for(int i=1; i<=16; i++){
       Alive[i] = alive[i];
   }
 
   // 물고기 이동
   move_fish(shark_x, shark_y);
 
   // 상어 이동 (nx, ny)로 이동
   for(int i=1; i<=3; i++){
       int nx = shark_x + dx[shark_dir-1]*i;
       int ny = shark_y + dy[shark_dir-1]*i;
       if(0<=nx && nx<4 && 0<=ny && ny<4){
           if(sea[nx][ny].size()>0 && alive[sea[nx][ny][0]]==0){
               int num = sea[nx][ny][0];
               int dir = sea[nx][ny][1];
               alive[num] = 1;
               sea[nx][ny].clear();
               dfs(nx, ny, dir, total_eat+num);
               alive[num] = 0;
               sea[nx][ny].push_back(num);
               sea[nx][ny].push_back(dir);
           }
       }
       else{
           break;
       }       
   }
 
   // 되돌아가기
   for(int i=0; i<4; i++){
       for(int j=0; j<4; j++){
           if(sea[i][j].size()>0){
               sea[i][j].clear();
           }
           if(Sea[i][j].size()>0){
                sea[i][j].push_back(Sea[i][j][0]);
                sea[i][j].push_back(Sea[i][j][1]);
           }
       }
   }
  
   for(int i=1; i<=16; i++){
       location[i] = make_pair(Location[i].first, Location[i].second);
   }
  
   for(int i=1; i<=16; i++){
       alive[i] = Alive[i];
   }
}
 
 
int main()
{
   for(int i=0; i<4; i++){
       for(int j=0; j<4; j++){
           cin>>a>>b;
           sea[i][j].push_back(a);
           sea[i][j].push_back(b);
           location[a] = make_pair(i, j);
       }
   }

   alive[sea[0][0][0]] = 1; // 먹혔다.
   sea[0][0].clear();
   dfs(0, 0, sea[0][0][1], sea[0][0][0]);
  
   cout<<total<<"\n";
   return 0;
}
