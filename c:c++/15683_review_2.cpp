// 감시
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
 
using namespace std;
 
int n, m;
int workspace[9][9] = {0, };
int workcopy[9][9] = {0, };
vector<pair<int, int>> cctv;
int cnt = 0; // cctv의 개수
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = INT_MAX;
int zero_num = 0;
 
void copy(int temp[9][9])
{
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           workcopy[i][j] = temp[i][j];
       }
   }
}
 
void cal(int x, int y, int dir)
{
   int nx = x;
   int ny = y;
   while(1){
       nx += dx[dir];
       ny += dy[dir];
       if(0<=nx && nx<n && 0<=ny && ny<m){
           if(workcopy[nx][ny]==6){
               break;
           }else{
               if(workcopy[nx][ny]==0){
                   workcopy[nx][ny] = -1;
               }
           }
       }else{
           break;
       }
   }
}
 
void dfs(int work[9][9], int k)
{
   int temp[9][9] = {0, };
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           temp[i][j] = work[i][j];
       }
   }
 
   for(int i=k; i<cctv.size(); i++){
       int x = cctv[i].first;
       int y = cctv[i].second;
       if(work[x][y]==1){ // 4개
           // right
           copy(temp);
           cal(x, y, 1);
           dfs(workcopy, i+1);
 
           // left
           copy(temp);
           cal(x, y, 0);
           dfs(workcopy, i+1);
 
           // up
           copy(temp);
           cal(x, y, 2);
           dfs(workcopy, i+1);
 
           // down
           copy(temp);
           cal(x, y, 3);
           dfs(workcopy, i+1);
       }else if(work[x][y]==2){ // 2개
           // left&right
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 1);
           dfs(workcopy, i+1);
 
           // up&down
           copy(temp);
           cal(x, y, 2);
           cal(x, y, 3);
           dfs(workcopy, i+1);
       }else if(work[x][y]==3){ // 4개
           // left&up
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 2);
           dfs(workcopy, i+1);
 
           // up&right
           copy(temp);
           cal(x, y, 1);
           cal(x, y, 2);
           dfs(workcopy, i+1);
 
           // right&down
           copy(temp);
           cal(x, y, 1);
           cal(x, y, 3);
           dfs(workcopy, i+1);
 
           // left&down
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 3);
           dfs(workcopy, i+1);
       }else if(work[x][y]==4){ // 4개
           // left&up&right
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 1);
           cal(x, y, 2);
           dfs(workcopy, i+1);
 
           // up&right&down
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 1);
           cal(x, y, 3);
           dfs(workcopy, i+1);
 
           // right&left&down
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 2);
           cal(x, y, 3);
           dfs(workcopy, i+1);
 
           // up&right&down
           copy(temp);
           cal(x, y, 3);
           cal(x, y, 1);
           cal(x, y, 2);
           dfs(workcopy, i+1);
       }else if(work[x][y]==5){ // 1개
           // up&right&left&down
           copy(temp);
           cal(x, y, 0);
           cal(x, y, 1);
           cal(x, y, 2);
           cal(x, y, 3);
           dfs(workcopy, i+1);
       }
   }
 
   int num = 0;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(workcopy[i][j]==0){
               num++;
           }
       }
   }
   ans = min(ans, num);
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cin>>workspace[i][j];
           if(1<=workspace[i][j] && workspace[i][j]<=5){
               cnt++;
               cctv.push_back(make_pair(i, j));
           }else if(workspace[i][j]==0){
               zero_num++;
           }
       }
   }
 
   if(cctv.size()==0){
       cout<<zero_num<<"\n";
       return 0;
   }
 
   dfs(workspace, 0);
 
   cout<<ans<<"\n";
   return 0;
}