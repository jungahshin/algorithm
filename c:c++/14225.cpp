// 부분 수열의 합
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int n, m;
vector<int> v;
vector<int> final;
int visited[21] = {0, };
map<int, int> check;
 
void choose(int idx, int num, int total)
{
   if(num==total){
       // 계산해서 벡터에 모든 부분 수열의 합 넣기
       int temp = 0;
       for(int i=0; i<v.size(); i++){
           if(visited[i]==true){
               temp += v[i];
           }
       }
       if(check.count(temp)==0){
           check[temp] = 1;
           final.push_back(temp);
       }
       return;
   }
 
   for(int i=idx; i<v.size(); i++){
       if(visited[i]==true) continue;
       visited[i] = true;
 
       choose(i, num+1, total);
       visited[i] = false;
   }
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       v.push_back(m);
   }
 
   for(int i=1; i<=v.size(); i++){
       choose(0, 0, i);
   }
 
   sort(final.begin(), final.end());
 
   int cmp = 1;
   for(int i=0; i<final.size(); i++){
       if(cmp!=final[i]){
           break;
       }
       cmp++;
   }
 
   cout<<cmp<<"\n";
   return 0;
}
