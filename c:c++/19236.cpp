// 청소년 상어
#include <iostream>
using namespace std;
 
int a, b;
int sea[5][5] = {0, };
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
 
struct FISH{
   int x, y, dir;
   bool die;
};
 
void copy(int a[5][5], int b[5][5])
{
   for(int i=0; i<4; i++){
       for(int j=0; j<4; j++){
           a[i][j] = b[i][j];
       }
   }
}
 
void copy2(FISH a[17], FISH b[17])
{
   for(int i=1; i<=16; i++){
       a[i].x = b[i].x;
       a[i].y = b[i].y;
       a[i].dir = b[i].dir;
       a[i].die = b[i].die;
   }
}
 
// bottom-up방식으로 dfs구현
int dfs(int sea[5][5], FISH fish[17], int a, int b)
{
   int nsea[5][5] = {0, };
   FISH nfish[17];
   copy(nsea, sea);
   copy2(nfish, fish);
 
   // 번호(잡아먹을)
   int num = nsea[a][b];
 
   // 상어가 잡아 먹기
   nfish[num].die = 1;
 
   // 물고기 이동
   for(int i=1; i<=16; i++){
       if(nfish[i].die==1) continue;
 
       int x = nfish[i].x;
       int y = nfish[i].y;
       int dir = nfish[i].dir;
 
       int nx, ny;
       bool check = false;
       while(1){
           nx = x+dx[dir-1];
           ny = y+dy[dir-1];
           if(0<=nx && nx<4 && 0<=ny && ny<4){
               if(nx==a && ny==b){
                   dir++;
                   if(dir==9){
                       dir = 1;
                   }
               }else{
                   check = true;
                   break;
               }
           }else{
               dir++;
               if(dir==9){
                   dir = 1;
               }
           }
       }
 
       if(check==true){
           int next_num = nsea[nx][ny];
           int next_dir = nfish[next_num].dir;
           int now_num = i;
 
           nfish[next_num].x = x;
           nfish[next_num].y = y;
           nsea[nx][ny] = now_num;
          
 
           nfish[now_num].x = nx;
           nfish[now_num].y = ny;
           nfish[now_num].dir = dir;
           nsea[x][y] = next_num;
       }
 
   }
 
   int ans = 0;
 
   // 상어 이동
   int snx = a+dx[nfish[num].dir-1];
   int sny = b+dy[nfish[num].dir-1];
   while(0<=snx && snx<4 && 0<=sny && sny<4){
       if(nfish[nsea[snx][sny]].die==0){
           ans = max(ans, dfs(nsea, nfish, snx, sny));
       }
       snx += dx[nfish[num].dir-1];
       sny += dy[nfish[num].dir-1];
   }
  
   return ans+num;
}
 
int main()
{
   FISH fish[17];
   for(int i=0; i<4; i++){
       for(int j=0; j<4; j++){
           cin>>a>>b;
           fish[a].dir = b;
           fish[a].x = i;
           fish[a].y = j;
           fish[a].die = 0;
           sea[i][j] = a;
       }
   }
 
   int eat = sea[0][0];
   cout<<dfs(sea, fish, 0, 0)<<"\n";
 
   return 0;
}