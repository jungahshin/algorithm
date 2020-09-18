// 구슬 탈출2
#include <iostream>
#include <queue>
using namespace std;
 
int n, m, r_x, r_y, b_x, b_y, out_x, out_y;
string s;
char marble[11][11];
int visited[11][11][11][11]; // 빨간공, 파란공 위치
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
 
int bfs()
{
   queue<pair<pair<int, int>, pair<int, int>>> q;
   q.push(make_pair(make_pair(r_x, r_y), make_pair(b_x, b_y)));
   visited[r_x][r_y][b_x][b_y] = 1;
 
   int num = 0;
 
   while(!q.empty()){
       int size = q.size();
       for(int i=0; i<size; i++){
           int rx = q.front().first.first;
           int ry = q.front().first.second;
           int bx = q.front().second.first;
           int by = q.front().second.second;
           q.pop();
           visited[rx][ry][bx][by] = 1;           
 
           for(int j=0; j<4; j++){
               bool red = false; // 탈출구에 왔는지 여부
               bool blue = false;
               int nrx = rx, nry = ry, nbx = bx, nby = by;
 
               while(marble[nrx+dx[j]][nry+dy[j]]=='.' || marble[nrx+dx[j]][nry+dy[j]]=='O'){
                   nrx += dx[j];
                   nry += dy[j];
                   if(marble[nrx][nry]=='O'){
                       red = true;
                   }
               }
 
               while(marble[nbx+dx[j]][nby+dy[j]]=='.' || marble[nbx+dx[j]][nby+dy[j]]=='O'){
                   nbx += dx[j];
                   nby += dy[j];
                   if(marble[nbx][nby]=='O'){
                       blue = true;
                   }
               }
 
               if(blue==true){ // 파랑이 빠지면 노노
                   continue;
               }
 
               if(red==true){ // 빨강만 빠지면 굿
                   return num+1;
               }
 
               if(nrx==nbx && nry==nby){ // 파랑 빨강 자리가 똑같다면
                   if(abs(rx-nrx)+abs(ry-nry) > abs(bx-nbx)+abs(by-nby)){ // 빨강 이동거리가 더 크면, 더 이전 자리
                       nrx -= dx[j];
                       nry -= dy[j];
                   }else{
                       nbx -= dx[j];
                       nby -= dy[j];
                   }
               }
 
               if(!visited[nrx][nry][nbx][nby]){
                   visited[nrx][nry][nbx][nby] = 1;
                   q.push(make_pair(make_pair(nrx, nry), make_pair(nbx, nby)));
               }
           }
       }
       num++;
       if(num==10){
           break;
       }
   }
   return -1;
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       cin>>s;
       for(int j=0; j<s.size(); j++){
           marble[i][j] = s[j];
           if(s[j]=='R'){
               marble[i][j] = '.';
               r_x = i;
               r_y = j;
           }else if(s[j]=='B'){
               marble[i][j] = '.';
               b_x = i;
               b_y = j;
           }else if(s[j]=='O'){
               out_x = i;
               out_y = j;
           }
       }
   }
 
   cout<<bfs()<<"\n";
 
   return 0;
}