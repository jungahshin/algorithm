// 치킨 배달
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int n, m;
int city[51][51] = {0, };
vector<pair<int, int>> chicken;
int visited[2500] = {0, };
vector<pair<int, int>> real_chick;
int ans = INT_MAX;
 
void cal()
{
   int total = 0;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           if(city[i][j]==1){
               int dist = INT_MAX;
               for(int k=0; k<real_chick.size(); k++){
                   int temp = abs(real_chick[k].first-i)+abs(real_chick[k].second-j);
                   dist = min(dist, temp);
               }
               total += dist;
           }
       }
   }
 
   ans = min(ans, total);
}
 
void choose(int idx, int num)
{
   if(num==m){
       real_chick.clear();
       for(int i=0; i<chicken.size(); i++){
           if(visited[i]==true){
               real_chick.push_back(make_pair(chicken[i].first, chicken[i].second));
           }
       }
       cal();
       return;
   }
 
   for(int i=idx; i<chicken.size(); i++){
       if(visited[i]==true) continue;
       visited[i] = true;
       choose(i, num+1);
       visited[i] = false;
   }
}
 
int main()
{
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cin>>city[i][j];
           if(city[i][j]==2){
               chicken.push_back(make_pair(i, j));
           }
       }
   }
 
   choose(0, 0);
 
   cout<<ans<<"\n";
   return 0;
}