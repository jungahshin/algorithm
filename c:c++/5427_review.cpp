// 불
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
 
int w, h, testcase, start_x, start_y;
char building[1001][1001];
string s;
queue<pair<int, int>> fire;
queue<pair<pair<int, int>, int>> sang;
int visited_f[1001][1001] = {0, };
int visited_s[1001][1001] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int final = 0;
bool check = false;
 
void move()
{
   while(!sang.empty()){
       //불이 먼저 이동하고
       int size = fire.size();
       cout<<"불"<<"\n";
       while(size--){
           int x = fire.front().first;
           int y = fire.front().second;
           visited_f[x][y] = 1;
           fire.pop();
 
           cout<<"x"<<x<<"y"<<y<<"\n";
 
           for(int i=0; i<4; i++){
               int nx = x+dx[i];
               int ny = y+dy[i];
               if(0<=nx && nx<h && 0<=ny && ny<w && !visited_f[nx][ny]){
                   visited_f[nx][ny] = 1;
                   if(building[nx][ny]=='.'){
                       building[nx][ny] = '*';
                       fire.push(make_pair(nx, ny));
                   }
               }
           }
       }
 
       //남은 칸에 상근이가 이동한다.
       int size_s = sang.size();
       cout<<"상근"<<"\n";
       while(size_s--){
           int x = sang.front().first.first;
           int y = sang.front().first.second;
           int num = sang.front().second;
           visited_s[x][y] = 1;
           sang.pop();
 
           cout<<"x"<<x<<"y"<<y<<"num"<<num<<"\n";
 
           if(x==0 || x==h-1 || y==0 || y==w-1){ // 가장 자리
               final = num;
               check = true;
               break;
           }
 
           for(int i=0; i<4; i++){
               int nx = x+dx[i];
               int ny = y+dy[i];
               if(0<=nx && nx<h && 0<=ny && ny<w && !visited_s[nx][ny]){
                   visited_s[nx][ny] = 1;
                   if(building[nx][ny]=='.'){
                       sang.push(make_pair(make_pair(nx, ny), num+1));
                   }
               }
           }
       }
       if(check == true){
           break;
       }       
   }
}
 
int main()
{
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       final = 0;
       check = false;
       memset(visited_f, 0, sizeof(visited_f));
       memset(visited_s, 0, sizeof(visited_s));
       while(!sang.empty()){
           sang.pop();
       }
       while(!fire.empty()){
           fire.pop();
       }
       cin>>w>>h;
       for(int k=0; k<h; k++){
           cin>>s;
           for(int t=0; t<s.size(); t++){
               building[k][t] = s[t];
               if(s[t]=='@'){
                   building[k][t] = '.';
                   sang.push(make_pair(make_pair(k, t), 0));
               }else if(s[t]=='*'){
                   fire.push(make_pair(k, t));
               }
           }
       }
 
       move();
       cout<<"ANS"<<"\n";
       if(check == true){
           cout<<final+1<<"\n";
       }else{
           cout<<"IMPOSSIBLE"<<"\n";
       }
   }
}
