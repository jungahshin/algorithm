// 1206. [S/W 문제해결 기본] 1일차 - View
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int n, m;
int building[257][1002] = {0, };
vector<int> height;
int dy[4] = {-2, -1, 1, 2};
int total = 0;
 
void check()
{
   for(int j=0; j<height.size(); j++){ // 열
       // 위에서 부터 내려온다.
       int num = height[j];
       for(int k=num-1; k>=0; k--){ // 행
           int x = k;
           int y = j;
           int temp = 0;
           for(int t=0; t<4; t++){
               int nx = x;
               int ny = y+dy[t];
               if(0<=ny && ny<n && building[nx][ny]==0){
                   temp++;
               }
           }
           if(temp==4){
               total++;
           }
       }
   }
}
 
int main()
{
   for(int i=0; i<10; i++){
       memset(building, 0, sizeof(building));
       height.clear();
       total = 0;
       cin>>n;
       for(int j=0; j<n; j++){ // 열
           cin>>m;
           height.push_back(m);
           for(int k=0; k<m; k++){ // 행
               building[k][j] = 1;
           }
       }
 
       // check
       check();
 
       cout<<"#"<<i+1<<" "<<total<<"\n";
   }
 
   return 0;
}
