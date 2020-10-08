// 5653. [모의 SW 역량테스트] 줄기세포배양
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int testcase, n, m, k;
int cell[370][370] = {0, };
int activate[370][370] = {0, };
int disabled[370][370] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int total = 0;
vector<pair<int, int>> v;
queue<pair<int, pair<int, int>>> q;
vector<pair<int, int>> temp;
int check[370][370] = {0, };
 
void spread()
{
   int sec = 0;
   while(1){
       v.clear();
       temp.clear();
       memset(check, 0, sizeof(check));
       sec++;
       if(sec>k){
           for(int i=0; i<370; i++){
               for(int j=0; j<370; j++){
                   if(disabled[i][j]>0 || activate[i][j]>0) total++;
               }
           }
           break;
       }
 
       for(int i=0; i<370; i++){
           for(int j=0; j<370; j++){
               if(disabled[i][j]>0) disabled[i][j]--;
               if(disabled[i][j]==0){ // 활성화 시작
                   v.push_back(make_pair(i, j));
                   disabled[i][j] = -1;
               }
               if(activate[i][j]>0){
                   q.push(make_pair(cell[i][j], make_pair(i, j)));
                   activate[i][j]--;
               }
           }
       }
 
       while(!q.empty()){
           int x = q.front().second.first;
           int y = q.front().second.second;
           int num = q.front().first;
           q.pop();
  
           for(int i=0; i<4; i++){
               int nx = x+dx[i];
               int ny = y+dy[i];
               if(cell[nx][ny]==0){
                   if(check[nx][ny]<num){
                       temp.push_back(make_pair(nx, ny));
                       check[nx][ny] = num;
                   }
               }
           }
       }
 
       for(int i=0; i<temp.size(); i++){
           cell[temp[i].first][temp[i].second] = check[temp[i].first][temp[i].second];
           disabled[temp[i].first][temp[i].second] = check[temp[i].first][temp[i].second];
       }
 
       for(int i=0; i<v.size(); i++){
           activate[v[i].first][v[i].second] = cell[v[i].first][v[i].second];
       }
   }
}
 
int main()
{
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       cin>>n>>m>>k;
       memset(disabled, -1, sizeof(disabled));
       memset(cell, 0, sizeof(cell));
       memset(activate, 0, sizeof(activate));
       total = 0;
       for(int j=180; j<180+n; j++){
           for(int k=180; k<180+m; k++){
               cin>>cell[j][k];
               disabled[j][k] = cell[j][k];
           }
       }
       spread();
       cout<<"#"<<i+1<<" "<<total<<"\n";
   }
 
   return 0;
}