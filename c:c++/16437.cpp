// 양 구출 작전(트리)
// leaf->root 구조로 순회
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
 
vector<vector<int>> connect;
vector<char> kind;
vector<ll> num;
int n, a, p;
char t;
 
ll go(int island)
{  
   ll sum = 0;
   for(int i=0; i<connect[island].size(); i++){
       sum += go(connect[island][i]);
   }
 
   if(kind[island] == 'S'){
       return sum+num[island];
   }else{
       if(sum-num[island]>=0){
           return sum-num[island];
       }else{
           return 0;
       }
   }
}
 
int main()
{
   cin>>n;
   connect.resize(n+1);
   kind.resize(n+1);
   num.resize(n+1);
   // i번 섬의 정보
   for(int i=2; i<=n; i++){
       cin>>t>>a>>p;
       kind[i] = t;
       num[i] = a;
       connect[p].push_back(i);     
   }
 
   cout<<go(1)<<"\n";
   return 0;
}
