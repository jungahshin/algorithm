// 새로운 게임 2
#include <iostream>
#include <vector>
 
using namespace std;
 
int n, k, r, c, d;
int color[13][13] = {0, };
vector<pair<pair<int, int>, int>> horse;
vector<int> board[13][13];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
bool total_check = false;
 
void move(int x, int y, int nx, int ny, int num, int kind)
{
   vector<int> temp;
   bool check = false;
   int idx = 0;
   for(int i=0; i<board[x][y].size(); i++){
       if(board[x][y][i]==num){
           check = true;
           idx = i;
       }
 
       if(check==true){
           temp.push_back(board[x][y][i]);
       }
   }
 
   board[x][y].erase(board[x][y].begin()+idx, board[x][y].end());
 
   if(kind==0){ // 흰색일 경우 -> 정방향
       for(int i=0; i<temp.size(); i++){
           board[nx][ny].push_back(temp[i]);
           horse[temp[i]].first.first = nx;
           horse[temp[i]].first.second = ny;
       }
   }else if(kind==1){ // 빨간색 -> 역방향
       for(int i=temp.size()-1; i>=0; i--){
           board[nx][ny].push_back(temp[i]);
           horse[temp[i]].first.first = nx;
           horse[temp[i]].first.second = ny;
       }
   }
}
 
void play()
{  
   int cnt = 0;
   while(1){
       cnt++;
       if(cnt>1000){
           total_check = true;
           break;
       }
 
       bool check = false;
 
       for(int i=0; i<horse.size(); i++){
           int x = horse[i].first.first;
           int y = horse[i].first.second;
           int dir = horse[i].second;
 
           int nx = x+dx[dir-1];
           int ny = y+dy[dir-1];
 
           if(1<=nx && nx<=n && 1<=ny && ny<=n){
               // 빨간, 흰색 원래 규칙대로 이동
               if(color[nx][ny]==0){
                   move(x, y, nx, ny, i, 0);
               }else if(color[nx][ny]==1){
                   move(x, y, nx, ny, i, 1);
               }else if(color[nx][ny]==2){
                   // 방향을 바꾸고 이동해본다.
                   if(dir==1){
                       dir = 2;
                   }else if(dir==2){
                       dir = 1;
                   }else if(dir==3){
                       dir = 4;
                   }else if(dir==4){
                       dir = 3;
                   }
 
                   int rx = x+dx[dir-1];
                   int ry = y+dy[dir-1];
 
                   horse[i].second = dir;
 
                   if(1<=rx && rx<=n && 1<=ry && ry<=n){
                       // 빨간, 흰색 원래 규칙대로 이동
                       if(color[rx][ry]==0){
                           move(x, y, rx, ry, i, 0);
                       }else if(color[rx][ry]==1){
                           move(x, y, rx, ry, i, 1);
                       }
                   }
               }
           }else{
               // 방향을 바꾸고 이동해본다.
               if(dir==1){
                   dir = 2;
               }else if(dir==2){
                   dir = 1;
               }else if(dir==3){
                   dir = 4;
               }else if(dir==4){
                   dir = 3;
               }
 
               int rx = x+dx[dir-1];
               int ry = y+dy[dir-1];
 
               horse[i].second = dir;
 
               if(1<=rx && rx<=n && 1<=ry && ry<=n){
                   // 빨간, 흰색 원래 규칙대로 이동
                   if(color[rx][ry]==0){
                       move(x, y, rx, ry, i, 0);
                   }else if(color[rx][ry]==1){
                       move(x, y, rx, ry, i, 1);
                   }
               }
           }
 
           // 말을 하나씩 옮기고 검사한다.
           for(int i=1; i<=n; i++){
               for(int j=1; j<=n; j++){
                   if(board[i][j].size()>=4){
                       check = true;
                       break;
                   }
               }
               if(check==true){
                   break;
               }
           }
           if(check==true){
               break;
           }
       }
 
       if(check==true){
           ans = cnt;
           break;
       }
 
   }
}
 
int main()
{
   cin>>n>>k;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           cin>>color[i][j];
       }
   }
 
   for(int i=0; i<k; i++){
       cin>>r>>c>>d;
       horse.push_back(make_pair(make_pair(r, c), d));
       board[r][c].push_back(i);
   }
 
   play();
 
   if(total_check==true){
       cout<<"-1"<<"\n";
   }else{
       cout<<ans<<"\n";
   }
 
   return 0;
}