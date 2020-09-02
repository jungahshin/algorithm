// 낚시왕
#include <iostream>
#include <vector>
#include <cstring>
 
using namespace std;
 
int R, C, M, r, c, s, d, z;
pair<pair<int, int>, int> river[101][101]; // 속력, 이동방향, 크기 저장
int final = 0; // 낚시왕이 잡은 상어 크기의 합
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
void shark_catch(int c)
{
   for(int i=1; i<=R; i++){
       if(river[i][c].second>0){ // 가장 가까운 상어를 잡는다.
           final += river[i][c].second;
           river[i][c] = make_pair(make_pair(0, 0), 0);
           break;
       }
   }
}
 
void shark_move()
{
   pair<pair<int, int>, int> temp[101][101];
   for(int i=1; i<=R; i++){
       for(int j=1; j<=C; j++){
           if(river[i][j].second>0){
               int speed = river[i][j].first.first;
               int dir = river[i][j].first.second;
               int size = river[i][j].second;
               int nx = i;
               int ny = j;
               if(dir==1 || dir==2){
                   speed = speed%(2*R-2);
               }else if(dir==3 || dir==4){
                   speed = speed%(2*C-2);
               }
               for(int k=0; k<speed; k++){
                   if(dir==1 && nx==1){
                       dir = 2;
                       nx = 2;
                   }else if(dir==2 && nx==R){
                       dir = 1;
                       nx = R-1;
                   }else if(dir==3 && ny==C){
                       dir = 4;
                       ny = C-1;
                   }else if(dir==4 && ny==1){
                       dir = 3;
                       ny = 2;
                   }else{
                       nx += dx[dir-1];
                       ny += dy[dir-1];
                   }
               }
              
               // 이미 다른 상어가 있다.
               if(temp[nx][ny].second>0){
                   if(temp[nx][ny].second<size){
                       temp[nx][ny] = make_pair(make_pair(speed, dir), size);
                   }
               }else{
                   temp[nx][ny] = make_pair(make_pair(speed, dir), size);
               }
           }
       }
   }
 
   // temp->river
   memset(river, 0, sizeof(river));
   for(int i=1; i<=R; i++){
       for(int j=1; j<=C; j++){
           if(temp[i][j].second>0){
               river[i][j] = make_pair(make_pair(temp[i][j].first.first, temp[i][j].first.second), temp[i][j].second);
           }
       }
   }
}
 
int main()
{
   cin>>R>>C>>M;
   for(int i=0; i<M; i++){
       cin>>r>>c>>s>>d>>z;
       river[r][c] = make_pair(make_pair(s, d), z);
   }
 
   // 낚시왕 이동
   for(int i=1; i<=C; i++){
       // 상어잡기
       shark_catch(i);
       // 상어이동
       shark_move();
   }
 
   cout<<final<<"\n";
}