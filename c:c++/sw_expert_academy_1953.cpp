// 1953. [모의 SW 역량테스트] 탈주범 검거
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
 
using namespace std;
 
int n, m, r, c, l, testcase;
int map[51][51] = {0, };
int visited[51][51] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> structure[8];
int ans = 0;
 
void setting()
{
   structure[1].push_back(0);
   structure[1].push_back(1);
   structure[1].push_back(2);
   structure[1].push_back(3);
 
   structure[2].push_back(0);
   structure[2].push_back(2);
 
   structure[3].push_back(1);
   structure[3].push_back(3);
 
   structure[4].push_back(0);
   structure[4].push_back(1);
 
   structure[5].push_back(1);
   structure[5].push_back(2);
 
   structure[6].push_back(2);
   structure[6].push_back(3);
 
   structure[7].push_back(0);
   structure[7].push_back(3);
}
 
bool check(int dir, int num)
{
   int temp_dir;
   if(dir==0){
       temp_dir = 2;
   }else if(dir==1){
       temp_dir = 3;
   }else if(dir==2){
       temp_dir = 0;
   }else if(dir==3){
       temp_dir = 1;
   }
 
   for(int i=0; i<structure[num].size(); i++){
       if(structure[num][i]==temp_dir) return true;
   }
 
   return false;
}
 
int bfs()
{
   queue<pair<int, pair<int, int>>> q;
   q.push(make_pair(1, make_pair(r, c)));
   visited[r][c] = 1;
   int num = 1;
 
   while(!q.empty()){
       int x = q.front().second.first;
       int y = q.front().second.second;
       int sec = q.front().first;
       int struct_num = map[x][y];
       q.pop();
 
       if(sec>=l){
           break;
       }
 
       for(int i=0; i<structure[struct_num].size(); i++){
           int dir = structure[struct_num][i];
           int nx = x+dx[dir];
           int ny = y+dy[dir];
           if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
               if(map[nx][ny]>0 && check(dir, map[nx][ny])){
                   visited[nx][ny] = 1;
                   num++;
                   q.push(make_pair(sec+1, make_pair(nx, ny)));
               }
           }
       }
   }
 
   return num;
}
 
int main()
{
   cin>>testcase;
   setting();
   for(int i=0; i<testcase; i++){
       ans = 0;
       memset(visited, 0, sizeof(visited));
       memset(map, 0, sizeof(map));
       cin>>n>>m>>r>>c>>l;
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               cin>>map[i][j];
           }
       }
 
       ans = bfs();
       cout<<"#"<<i+1<<" "<<ans<<"\n";
   }
 
   return 0;
}