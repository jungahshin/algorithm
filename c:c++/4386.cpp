// 별자리 만들기(MST->kruskal)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int n;
double x, y;
int connect[101] = {0, };
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> v;
double answer = 0;
 
int find(int a){
   if(a==connect[a]){
       return a;
   }
      
   return connect[a] = find(connect[a]);
}
 
double cal(double x1, double y1, double x2, double y2)
{
   return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>x>>y;
       stars.push_back(make_pair(x, y));
   }
 
   // 두 점 사이의 거리를 저장한다.
   for(int i=0; i<stars.size(); i++){
       for(int j=i+1; j<stars.size(); j++){
           double cost = cal(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
           v.push_back(make_pair(cost, make_pair(i, j)));
       }
   }
 
   for(int i=0; i<n; i++){
       connect[i] = i;
   }
 
   sort(v.begin(), v.end());
 
   for(int i=0; i<v.size(); i++){
       int x = v[i].second.first;
       int y = v[i].second.second;
       double cost = v[i].first;
 
       int a = find(x);
       int b = find(y);
 
       if(a!=b){
           connect[a] = b;
           answer += cost;
       }
   }
 
   cout.precision(3);
   cout<<answer<<"\n";
   return 0;
}