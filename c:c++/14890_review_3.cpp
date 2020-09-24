// 경사로
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int ans, n, l;
int area[101][101] = {0, };
 
void check()
{
   // 행 기준
   for(int i=0; i<n; i++){
       int visited[101] = {0, };
       bool check = true;
       for(int j=0; j<n-1; j++){
           // 내려감
           if((area[i][j]-area[i][j+1])==1){
               if((j+1+l)>n){
                   check = false;
                   break;
               }
 
               int num = 0;
               for(int k=j+1; k<j+1+l; k++){
                   if(area[i][j+1]==area[i][k] && !visited[k]){
                       visited[k] = 1;
                       num++;
                   }
               }
 
               if(num!=l){
                   check = false;
               }
           }else if((area[i][j]-area[i][j+1])==-1){ // 올라감
               if((j+1-l)<0){
                   check = false;
                   break;
               }
 
               int num = 0;
               for(int k=j+1-l; k<j+1; k++){
                   if(area[i][j]==area[i][k] && !visited[k]){
                       visited[k] = 1;
                       num++;
                   }
               }
 
               if(num!=l){
                   check = false;
               }
           }else if(abs(area[i][j]-area[i][j+1])>=2){
               check = false;
           }
       }
       if(check==false){
           ans--;
       }
   }
 
   // 열 기준
   for(int i=0; i<n; i++){
       int visited[101] = {0, };
       bool check = true;
       for(int j=0; j<n-1; j++){
           if((area[j][i]-area[j+1][i])==1){
               if((j+1+l)>n){
                   check = false;
                   break;
               }
 
               int num = 0;
               for(int k=j+1; k<j+1+l; k++){
                   if(area[j+1][i]==area[k][i] && !visited[k]){
                       visited[k] = 1;
                       num++;
                   }
               }
 
               if(num!=l){
                   check = false;
               }
           }else if((area[j][i]-area[j+1][i])==-1){
               if((j+1-l)<0){
                   check = false;
                   break;
               }
 
               int num = 0;
               for(int k=j+1-l; k<j+1; k++){
                   if(area[j][i]==area[k][i] && !visited[k]){
                       visited[k] = 1;
                       num++;
                   }
               }
 
               if(num!=l){
                   check = false;
               }
           }else if(abs(area[j][i]-area[j+1][i])>=2){
               check = false;
           }
       }
       if(check==false){
           ans--;
       }
   }
}
 
int main()
{
   cin>>n>>l;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cin>>area[i][j];
       }
   }
 
   ans = 2*n;
 
   check();
   cout<<ans<<"\n";
 
   return 0;
}