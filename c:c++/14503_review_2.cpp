// 로봇 청소기
#include <iostream>
using namespace std;
 
int n, m, r, c, d;
int area[51][51] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[51][51] = {0, }; // 청소한 곳 표시
int ans = 0;
 
void change_dir()
{
   if(d==0){
       d = 3;
   }else if(d==3){
       d = 2;
   }else if(d==2){
       d = 1;
   }else if(d==1){
       d = 0;
   }
}
 
void clean()
{
   int start_x = r;
   int start_y = c;
   bool check = false;
   int num = 0;
 
   while(1){
 
       // 1. 현재 위치 청소
       if(check==false){
           num = 0;
           ans++;
           visited[start_x][start_y] = 1;
       }
 
       if(num==4){ // 4방향 모두 청소x->
           num = 0;
           // 한 칸 후진
           if(d==3){
               start_y += 1;
           }else if(d==0){
               start_x += 1;
           }else if(d==1){
               start_y -= 1;
           }else if(d==2){
               start_x -= 1;
           }
 
           if(0>start_x || start_x>=n || 0>start_y || start_y>=m || area[start_x][start_y]==1){
               break;
           }
       }
 
       int temp = d-1;
       if(temp==-1) temp = 3;
       int nx = start_x+dx[temp];
       int ny = start_y+dy[temp];
      
       // 2-a. 왼쪽에 청소를 안했으면 그 방향으로 회전 후, 1번 돌아가
       if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny] && area[nx][ny]==0){
           //2-a.
           change_dir();
           start_x = nx;
           start_y = ny;
           check = false;
           continue;
       }else{
           // 2-b.
           change_dir();
           check = true;
           num++;
           continue;
       }
   }
}
 
int main()
{
   cin>>n>>m;
   cin>>r>>c>>d;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cin>>area[i][j];
       }
   }
 
   clean();
 
   cout<<ans<<"\n";
}