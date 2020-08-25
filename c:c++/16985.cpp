// Maaaaaaaaaze
#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
 
int maze[6][6][6] = {0, };
int seq[6] = {0, };
int final = INT_MAX;
int dh[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
 
int bfs(int nmaze [6][6][6])
{
   queue<pair<pair<int, int>, pair<int, int>>> q;
   int Visited[6][6][6] = {0, };
   q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
   while (!q.empty()) {
       int height = q.front().first.first;
       int x = q.front().first.second;
       int y = q.front().second.first;
       int cnt = q.front().second.second;
       Visited[height][x][y] = 1;
       q.pop();
 
       if(height==4 && x==4 && y==4){
           return cnt;
       }
 
       for(int k=0; k<6; k++){
           int nh = height+dh[k];
           int nx = x+dx[k];
           int ny = y+dy[k];
           if(0<=nh && nh<5 && 0<=nx && nx<5 && 0<=ny && ny<6 && !Visited[nh][nx][ny] && nmaze[nh][nx][ny]==1){
               Visited[nh][nx][ny] = 1;
               q.push(make_pair(make_pair(nh, nx), make_pair(ny, cnt+1)));
           }
       }
   }
 
   return -1;
}
 
void rotate(int height, int nmaze [6][6][6], int maze [6][6][6])
{
   if(height==5){
       if(nmaze[0][0][0]==1 && nmaze[4][4][4]==1){
           int temp = bfs(nmaze);
           if(temp != -1){
               final = min(final, temp);
           }
       }
       return;
   }
 
   // 반시계방향으로 회전하는 수
   for(int num=1; num<=4; num++){
       for(int i=0; i<5; i++){
           for(int j=0; j<5; j++){
               if(maze[height][i][j]==1){
                   if(num==1){
                       nmaze[height][j][4 - i] = 1;
                   }else if(num==2){
                       nmaze[height][4 - i][4 - j] = 1;
                   }else if(num==3){
                       nmaze[height][4 - j][i] = 1;
                   }else{
                       nmaze[height][i][j] = 1;
                   }
               }
           }
       }
 
       rotate(height+1, nmaze, maze);
       for(int i=0; i<5; i++){
           for(int j=0; j<5; j++){
               nmaze[height][i][j] = 0;
           }
       }
   }
}
 
void stacked(int cnt, int visited[6])
{
   if(cnt==5){
       int nmaze[6][6][6] = {0, };
       for(int h=0; h<5; h++){
           int idx = seq[h];
           for(int i=0; i<5; i++){
               for(int j=0; j<5; j++){
                   nmaze[h][i][j] = maze[idx][i][j];
               }
           }
       }
 
       int temp [6][6][6] = {0, };
       rotate(0, temp, nmaze);
       return;
   }
 
   for(int i=0; i<5; i++){
       if(visited[i]==true) continue;
       visited[i] = true;
       seq[i] = cnt;
       stacked(cnt+1, visited);
       visited[i] = false;
       seq[i] = 0;
   }
   return;
}
 
int main()
{
   for(int h=0; h<5; h++){
       for(int i=0; i<5; i++){
           for(int j=0; j<5; j++){
               cin>>maze[h][i][j];
           }
       }
   }
 
   // 판을 쌓는다.
   int visited[6] = {0, };
   stacked(0, visited);
   if(final==INT_MAX){
       cout<<"-1"<<"\n";
   }else{
       cout<<final<<"\n";
   }
 
   return 0;
}
