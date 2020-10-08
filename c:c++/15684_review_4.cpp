// 사다리 조작
#include <iostream>
#include <climits>
 
using namespace std;
 
int n, m, h, a, b;
int ladder[31][11] = {0, }; // (a, b)의 형태 a가로선과 b, b+1세로선 연결하는 것
int ans = INT_MAX;
 
bool check()
{
   for(int i=1; i<=n; i++){
       int temp = i;
       for(int j=1; j<=h; j++){
           if(ladder[j][temp]==1){
               temp++;
           }else if(ladder[j][temp-1]==1){
               temp--;
           }
       }
       if(temp!=i){
           return false;
       }
   }
   return true;
}
 
void play(int k, int num)
{
   if(num>3){
       return;
   }
 
   if(check()==true){ // i가 i로 갔을 경우
       ans = min(ans, num);
      
       return;
   }
 
   for(int i=k; i<=h; i++){
       for(int j=1; j<n; j++){ // n번째 사다리에는 그을 수 없다.
           if(ladder[i][j]==1) continue;
           if(ladder[i][j-1]==1) continue;
           if(ladder[i][j+1]==1) continue;
 
           ladder[i][j] = 1;
           play(i, num+1);
           ladder[i][j] = 0;
       }
   }
}
 
int main()
{
   cin>>n>>m>>h;
   for(int i=0; i<m; i++){
       cin>>a>>b;
       ladder[a][b] = 1;
   }
 
   play(1, 0);
 
   if(ans==INT_MAX){
       cout<<"-1"<<"\n";
   }else{
       cout<<ans<<"\n";
   }
 
   return 0;
}