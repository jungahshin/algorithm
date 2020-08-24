// 벽 부수고 이동하기 4
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
 
using namespace std;
 
int n, m;
string s;
int wall[1001][1001] = {0, };
int AREA[1001][1001]; // 영역의 idx
vector<int> AREA_NUM; // 영역의 크기
int final = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
 
void check()
{
   int visited[1001][1001] = {0, };
   queue<pair<pair<int, int>, int>> q;
   int idx = 0; // 인접 영역 번호매기기
 
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(!visited[i][j] && wall[i][j]==0){
               vector<pair<int, int>> temp;
               q.push(make_pair(make_pair(i, j), 1));
               int area = 1;
 
               while(!q.empty()){
                   int x = q.front().first.first;
                   int y = q.front().first.second;
                   int num = q.front().second;
                   visited[x][y] = 1;
                   temp.push_back(make_pair(x, y));
                   q.pop();
 
                   for(int k=0; k<4; k++){
                       int nx = x+dx[k];
                       int ny = y+dy[k];
                       if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
                           if(wall[nx][ny]==0){
                               area++;
                               visited[nx][ny] = 1;
                               q.push(make_pair(make_pair(nx, ny), num+1));
                           }
                       }
                   }
               }
 
               for(int k=0; k<temp.size(); k++){
                   AREA[temp[k].first][temp[k].second] = idx;
               }
               AREA_NUM.push_back(area);
               idx++;
           }
       }
   }
}
 
void count()
{
   for(int i=0; i<n; i++){
       string S;
       for(int j=0; j<m; j++){
           if(wall[i][j]==1){
               map<int, int> M;
               int num = 0;
 
               for(int k=0; k<4; k++){
                   int nx = i+dx[k];
                   int ny = j+dy[k];
 
                   if(0<=nx && nx<n && 0<=ny && ny<m){
                       if(wall[nx][ny]==0 && M.count(AREA[nx][ny])==0){
                           M[AREA[nx][ny]] = 1;
                           num += AREA_NUM[AREA[nx][ny]];
                       }
                   }
               }
 
               S += to_string((num+1)%10);
           }else{
               S += "0";
           }
       }
       cout<<S<<"\n";
   }
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       cin>>s;
       for(int j=0; j<s.size(); j++){
           wall[i][j] = s[j]-'0';
       }
   }
 
   memset(AREA, -1, sizeof(AREA));
   check();
   count();
 
   return 0;
}
