// 나무재테크
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int n, m, k, x, y, z;
int vitamin[11][11] = {0, }; // 땅이 가지고 있는 양분
int summer_vit[11][11] = {0, }; // 여름에 추가할 양분
int a[11][11] = {0, }; // 겨울에 추가할 양분
vector<int> tree[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
void Spring()
{
   memset(summer_vit, 0, sizeof(summer_vit));
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           if(tree[i][j].size()>0){
               sort(tree[i][j].begin(), tree[i][j].end());
               int idx = 0; // 죽을 나무의 인덱스 저장  
               bool check = false;
               for(int k=0; k<tree[i][j].size(); k++){
                   if(vitamin[i][j]>=tree[i][j][k]){
                       vitamin[i][j] -= tree[i][j][k];
                       tree[i][j][k]++;
                   }else{
                       if(check==false){
                           check = true;
                           idx = k;
                       }
                       summer_vit[i][j] += (tree[i][j][k]/2);
                   }
               }
 
               if(check==true){
                   tree[i][j].erase(tree[i][j].begin()+idx, tree[i][j].end());
               }
           }
       }
   }
}
 
void Summer()
{
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           vitamin[i][j] += summer_vit[i][j];
       }
   }
}
 
void Fall()
{
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           if(tree[i][j].size()>0){
               for(int k=0; k<tree[i][j].size(); k++){
                   if(tree[i][j][k]%5==0){
                       for(int t=0; t<8; t++){
                           int nx = i+dx[t];
                           int ny = j+dy[t];
 
                           if(1<=nx && nx<=n && 1<=ny && ny<=n){
                               tree[nx][ny].push_back(1);
                           }
                       }
                   }
               }
           }
       }
   }
}
 
void Winter()
{
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           vitamin[i][j] += a[i][j];
       }
   }
}
 
int main()
{
   cin>>n>>m>>k;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           cin>>a[i][j];
           vitamin[i][j] = 5;
       }
   }
 
   for(int i=0; i<m; i++){
       cin>>x>>y>>z;
       tree[x][y].push_back(z);
   }
 
   for(int i=0; i<k; i++){
       Spring();
       Summer();
       Fall();
       Winter(); 
   }
 
   int cnt = 0;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           cnt += tree[i][j].size();
       }
   }
 
   cout<<cnt<<"\n";
   return 0;
}