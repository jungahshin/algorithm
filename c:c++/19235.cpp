// 모노미노도미노
#include <iostream>
#include <cstring>
 
using namespace std;
 
int n, t, x, y;
int blue[5][7] = {0, };
int green[7][5] = {0, }; // 각 블록의 고유 번호를 저장
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int score = 0; // 총 점수
int total = 0; // 총 타일 수
 
int Green(int x, int y)
{
   int idx = 0;
   for(int i=x; i<6; i++){
       if(green[i][y]!=0){
           break;
       }
       idx = i;
   }
   return idx;
}
 
int Blue(int x, int y)
{
   int idx = 0;
   for(int i=y; i<6; i++){
       if(blue[x][i]!=0){
           break;
       }
       idx = i;
   }
   return idx;
}
 
void remove_green(int idx)
{
   for(int i=idx-1; i>=0; i--){
       for(int j=0; j<4; j++){
           if(green[i][j]!=0){
               int n = green[i][j];
               bool check = false;
               for(int k=0; k<4; k++){
                   int nx = i+dx[k];
                   int ny = j+dy[k];
                   if(0<=nx && nx<6 && 0<=ny && ny<4 && green[nx][ny]==n){
                       green[i][j] = 0;
                       green[nx][ny] = 0;
                       check = true;
                       if(i==nx){ // 행이 같다.(1*2)
                           int a = Green(i, j);
                           int b = Green(nx, ny);
                           if(a>=b){ // b
                               green[b][j] = n;
                               green[b][ny] = n;
                           }else{ // a
                               green[a][j] = n;
                               green[a][ny] = n;
                           }
                       }else if(j==ny){ // 열이 같다.(2*1)
                           int c = Green(i, j);
                           green[c][j] = n;
                           green[c-1][j] = n;
                       }
                       break;
                   }
               }
               if(check==false){ // 혼자밖에 없는 경우(짝궁x)
                   green[i][j] = 0;
                   int c = Green(i, j);
                   green[c][j] = n;
               }
           }
       }
   }
}
 
void remove_blue(int idx)
{
   for(int i=idx-1; i>=0; i--){
       for(int j=0; j<4; j++){
           if(blue[j][i]!=0){
               int n = blue[j][i];
               bool check = false;
               for(int k=0; k<4; k++){
                   int nx = j+dx[k];
                   int ny = i+dy[k];
                   if(0<=nx && nx<4 && 0<=ny && ny<6 && blue[nx][ny]==n){
                       blue[j][i] = 0;
                       blue[nx][ny] = 0;
                       check = true;
                       if(j==nx){ // 1*2
                           int c = Blue(j, i);
                           blue[j][c] = n;
                           blue[j][c-1] = n;
                       }else if(i==ny){ // 2*1
                           int a = Blue(j, i);
                           int b = Blue(nx, ny);
                           if(a>=b){ // b
                               blue[j][b] = n;
                               blue[nx][b] = n;
                           }else{ // a
                               blue[j][a] = n;
                               blue[nx][a] = n;
                           }
                       }
                       break;
                   }
               }
               if(check==false){ // 혼자밖에 없는 경우(짝궁x)
                   blue[j][i] = 0;
                   int c = Blue(j, i);
                   blue[j][c] = n;
               }
           }
       }
   }
}
 
void shift_green()
{
   int green_temp[7][5] = {0, };
   bool check_zero = false;
   bool check_one = false;
   for(int j=0; j<4; j++){
       if(green[0][j]!=0){
           check_zero = true;
           break;
       }
   }
   if(check_zero==true){ // 2행 shift
       for(int j=0; j<=3; j++){
           for(int k=0; k<4; k++){
               green_temp[j+2][k] = green[j][k];
           }
       }
       memset(green, 0, sizeof(green));
       for(int j=0; j<6; j++){
           for(int k=0; k<4; k++){
               green[j][k] = green_temp[j][k];
           }
       }
   }else{
       for(int j=0; j<4; j++){
           if(green[1][j]!=0){
               check_one = true;
               break;
           }
       }
       if(check_one==true){ // 1행 shift
           for(int j=1; j<=4; j++){
               for(int k=0; k<4; k++){
                   green_temp[j+1][k] = green[j][k];
               }
           }
           memset(green, 0, sizeof(green));
           for(int j=0; j<6; j++){
               for(int k=0; k<4; k++){
                   green[j][k] = green_temp[j][k];
               }
           }
       }
   }
}
 
void shift_blue()
{
   int blue_temp[5][7] = {0, };
   bool check_zero = false;
   bool check_one = false;
   for(int j=0; j<4; j++){
       if(blue[j][0]!=0){
           check_zero = true;
           break;
       }
   }
   if(check_zero==true){ // 2열 shift
       for(int j=0; j<4; j++){
           for(int k=0; k<=3; k++){
               blue_temp[j][k+2] = blue[j][k];
           }
       }
       memset(blue, 0, sizeof(blue));
       for(int j=0; j<4; j++){
           for(int k=0; k<6; k++){
               blue[j][k] = blue_temp[j][k];
           }
       }
   }else{
       for(int j=0; j<4; j++){
           if(blue[j][1]!=0){
               check_one = true;
               break;
           }
       }
       if(check_one==true){ // 1열 shift
           for(int j=0; j<4; j++){
               for(int k=1; k<=4; k++){
                   blue_temp[j][k+1] = blue[j][k];
               }
           }
           memset(blue, 0, sizeof(blue));
           for(int j=0; j<4; j++){
               for(int k=0; k<6; k++){
                   blue[j][k] = blue_temp[j][k];
               }
           }
       }
   }
}
 
int main()
{
   cin>>n;
   int num = 0; // 블록들의 고유 번호
   for(int i=0; i<n; i++){
       num++;
       cin>>t>>x>>y;
       if(t==1){
           // 초
           int c = Green(0, y);
           green[c][y] = num;
           // 파
           int d = Blue(x, 0);
           blue[x][d] = num;
       }else if(t==2){
           // 초(0, y), (0, y+1) -> 둘 중 최소 행으로
           int a = Green(0, y);
           int b = Green(0, y+1);
           if(a>=b){ // b
               green[b][y] = num;
               green[b][y+1] = num;
           }else{ // a
               green[a][y] = num;
               green[a][y+1] = num;
           }
           // 파(x, 0), (x, 1) -> (x, 1)만 넣으면 됨
           int c = Blue(x, 1);
           blue[x][c] = num;
           blue[x][c-1] = num;
       }else if(t==3){
           // 초(0, y), (1, y) -> (1, y)만 넣으면 됨
           int c = Green(1, y);
           green[c][y] = num;
           green[c-1][y] = num;
 
           // 파(x, 0), (x+1, 0) -> 둘 중 최소 열로
           int a = Blue(x, 0);
           int b = Blue(x+1, 0);
           if(a>=b){ // b
               blue[x][b] = num;
               blue[x+1][b] = num;
           }else{ // a
               blue[x][a] = num;
               blue[x+1][a] = num;
           }
       }
 
       // 행이나 열이 가득차있는지 확인
       // 초
       while(1){
           bool check = false;
           int idx = 0;
           for(int j=5; j>=0; j--){ // 행
               int temp = 0;
               for(int k=0; k<4; k++){ //열
                   if(green[j][k]!=0) temp++;
               }
               if(temp==4){
                   if(check==false){
                       idx = j;
                   }
                   check = true;
                   score++;
                   for(int k=0; k<4; k++){
                       green[j][k] = 0;
                   }
               }
           }
           if(check==false){
               break;
           }else{
               remove_green(6);
           }
       }
 
       //파
       while(1){
           bool check = false;
           int idx = 0;
           for(int j=5; j>=0; j--){ // 열
               int temp = 0;
               for(int k=0; k<4; k++){ // 행
                   if(blue[k][j]!=0) temp++;
               }
               if(temp==4){
                   if(check==false){
                       idx = j;
                   }
                   check = true;
                   score++;
                   for(int k=0; k<4; k++){
                       blue[k][j] = 0;
                   }
               }
           }
           if(check==false){
               break;
           }else{
               remove_blue(6);
           }
       }
 
       // 최종적으로 특별한 칸에 있게 되면 또 처리해준다.(노가다 예상)
       // 초
       shift_green();
      
       // 파
       shift_blue();
   }
  
   for(int j=0; j<4; j++){
       for(int k=0; k<6; k++){
           if(blue[j][k]!=0){
               total++;
           }
       }
   }
 
   for(int j=0; j<6; j++){
       for(int k=0; k<4; k++){
           if(green[j][k]!=0){
               total++;
           }
       }
   }
  
   cout<<score<<"\n";
   cout<<total<<"\n";  
 
   return 0;
}