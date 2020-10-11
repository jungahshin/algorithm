// 어른 상어
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, m, k, a, b, c;
pair<int, int> shark[21][21]; // 상어의 번호와 남은 시간
int dir[401] = {0, }; // 상어마다 현재의 방향
int die[401] = {0, };
pair<int, int> loc[401]; // 상어마다 현재 위치
vector<int> pri[401][5]; // 상어번호,방향에 따른 우선순위 저장
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0;
 
void move()
{
   vector<pair<int, int>> v[21][21]; // 각 칸에 상어의 번호, 방향 저장 후 한꺼번에 setting
   for(int i=1; i<=m; i++){
       if(die[i]) continue;
       int x = loc[i].first;
       int y = loc[i].second;
 
       // 우선순위에 따라 이동할 칸 정하기
       bool check = false;
       for(int j=0; j<pri[i][dir[i]].size(); j++){
           int ndir = pri[i][dir[i]][j];
           int nx = x+dx[ndir-1];
           int ny = y+dy[ndir-1];
           if(0<=nx && nx<n && 0<=ny && ny<n){
               if(shark[nx][ny].first==0){ // 빈칸이면
                   check = true;
                   // setting
                   v[nx][ny].push_back(make_pair(i, ndir));
                   break;
               }
           }
       }
 
       if(check==false){ // 빈칸이 없어서 다시 우선순위로 자신의 자취를 찾아
           for(int j=0; j<pri[i][dir[i]].size(); j++){
               int ndir = pri[i][dir[i]][j];
               int nx = x+dx[ndir-1];
               int ny = y+dy[ndir-1];
               if(0<=nx && nx<n && 0<=ny && ny<n){
                   if(shark[nx][ny].first==i){ // 자신의 자취를 찾으면
                       // setting
                       v[nx][ny].push_back(make_pair(i, ndir));
                       break;
                   }
               }
           }
       }
   }
 
   // 시간 감소
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           if(shark[i][j].second>0){
               shark[i][j].second--;
               if(shark[i][j].second==0){
                   shark[i][j].first = 0;
               }
           }
       }
   }
 
   // setting
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           if(v[i][j].size()>0){
               sort(v[i][j].begin(), v[i][j].end());
               int shark_num = v[i][j][0].first;
               int shark_dir = v[i][j][0].second;
               dir[shark_num] = shark_dir;
               shark[i][j] = make_pair(shark_num, k);
               loc[shark_num] = make_pair(i, j);
               if(v[i][j].size()>1){
                   for(int k=1; k<v[i][j].size(); k++){
                       die[v[i][j][k].first] = 1;
                   }
               }
           }
       }
   }
}
 
bool check()
{
   int num = 0;
   if(die[1]){
       return false;
   }
 
   for(int i=1; i<=m; i++){
       if(!die[i]) num++;
   }
 
   if(num==1){
       return true;
   }
 
   return false;
}
 
void play()
{
   int sec = 0;
   while(1){
       sec++;
       if(sec>1000){
           ans = -1;
           break;
       }
 
       // 상어 이동
       move();
 
       if(check()){
           ans = sec;
           break;
       }
   }
}
 
int main()
{
   cin>>n>>m>>k;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cin>>a;
           if(a!=0){
               shark[i][j] = make_pair(a, k);
               loc[a] = make_pair(i, j);
           }else{
               shark[i][j] = make_pair(0, 0);
           }
       }
   }
 
   for(int i=1; i<=m; i++){
       cin>>b;
       dir[i] = b;
   }
 
   for(int i=1; i<=m; i++){
       for(int j=1; j<=4; j++){
           for(int k=0; k<4; k++){
               cin>>c;
               pri[i][j].push_back(c);
           }
       }
   }
 
   play();
 
   cout<<ans<<"\n";
   return 0;
}