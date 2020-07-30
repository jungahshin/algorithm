// 십자가 찾기
#include <iostream>
#include <vector>
using namespace std;
 
int n, m, temp;
char cross[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<pair<int, int>, int>> final;
int visited[101][101] = {0, };
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cin>>cross[i][j];
       }
   }
 
   temp = min(n, m);
 
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(cross[i][j]=='*'){
               // 십자가 중심부의 *가 맞는지 확인
               int num = 0;
               vector<pair<int, int>> v;
               v.push_back(make_pair(i, j));
               for(int k=1; k<=(temp/2); k++){ // 최대 (temp/2)만큼 확장될 수 있다.
                   // k만큼 확장
                   bool check = true;
                   for(int t=0; t<4; t++){
                       int nx = i+(dx[t]*k);
                       int ny = j+(dy[t]*k);
                       if(0<=nx && nx<n && 0<=ny && ny<m && cross[nx][ny]=='*'){
                           v.push_back(make_pair(nx, ny));
                       }else{
                           check = false;
                           break;
                       }
                      
                   }
                   if(check==false){ // 확장 실패
                       break;
                   }
                   num++;
               }
 
               // num만큼의 크기를 가지는 십자가
               if(num>0){
                   final.push_back(make_pair(make_pair(i, j), num));
                   for(int t=0; t<v.size(); t++){
                       visited[v[t].first][v[t].second] = 1;
                   }
               }
           }
       }
   }
 
   bool check = true;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(cross[i][j]=='*' && !visited[i][j]){
               check = false;
           }
       }
   }
 
   if(check==false){
       cout<<"-1"<<"\n";
   }else{
       if(final.size()==0){
           cout<<"-1"<<"\n";
       }else{
           cout<<final.size()<<"\n";
           for(int i=0; i<final.size(); i++){
               cout<<final[i].first.first+1<<" "<<final[i].first.second+1<<" "<<final[i].second<<"\n";
           }           
       }
   }
 
   return 0;
}  
