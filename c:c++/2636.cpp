// 2636번.
#include <iostream>
#include <queue>
#include <cstring>
 
using namespace std;
 
int n, m;
int cheese[101][101] = {0, };
int visited[101][101] = {0, };
int sec = 0;
int final = 0; // 가장 마지막에 남은 치즈조각 수
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
// 외부의 공기들을 표시해주고 이와 인접한 치즈들을 0으로 만들어준다.
void bfs()
{
   queue<pair<int, int>> q;
   q.push(make_pair(0, 0));
 
   while(!q.empty()){
       int x = q.front().first;
       int y = q.front().second;
       visited[x][y] = 1;
       q.pop();
 
       for(int t=0; t<4; t++){
           int nx = x+dx[t];
           int ny = y+dy[t];
           if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
               if(cheese[nx][ny]==0){
                   visited[nx][ny] = 1;
                   q.push(make_pair(nx, ny));
               }
           }
       }
   }
 
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(visited[i][j]){
               for(int t=0; t<4; t++){
                   int nx = i+dx[t];
                   int ny = j+dy[t];
                   if(0<=nx && nx<n && 0<=ny && ny<m && cheese[nx][ny]==1){
                       cheese[nx][ny] = 0;
                   }
               }
           }
       }
   }
}
 
bool check()
{
   bool temp = false;
   int num = 0;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(cheese[i][j]==1){
               temp = true;
               num++;
           }
       }
   }
   if(num != 0){
       final = num;
   }
   return temp;
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cin>>cheese[i][j];
       }
   }
 
   while(1){
       if(!check()){ // 1이 아무것도 없을 경우
           break;
       }
 
       sec++;
 
       memset(visited, 0, sizeof(visited));
       bfs();
   }
 
   cout<<sec<<"\n";
   cout<<final<<"\n";
 
   return 0;
}

