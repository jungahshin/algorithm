// 미로 탐색
#include <iostream>
#include <queue>
using namespace std;
 
int n, m;
string s;
int miro[101][101] = {0, };
int visited[101][101] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int final = 0;
 
void bfs()
{
   queue<pair<pair<int, int>, int>> q;
   q.push(make_pair(make_pair(0, 0), 1));
 
   while(!q.empty()){
       int x = q.front().first.first;
       int y = q.front().first.second;
       int num = q.front().second;
       visited[x][y] = 1;
       q.pop();
 
       if(x==n-1 && y==m-1){ // 도착
           final = num;
           break;
       }
 
       for(int i=0; i<4; i++){
           int nx = x+dx[i];
           int ny = y+dy[i];
           if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
               if(miro[nx][ny]==1){
                   visited[nx][ny] = 1;
                   q.push(make_pair(make_pair(nx, ny), num+1));
               }
           }
       }
   }
 
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       cin>>s;
       for(int j=0; j<s.size(); j++){
           miro[i][j] = s[j]-'0';
       }
   }
 
   bfs();
   cout<<final<<"\n";
   return 0;
}
