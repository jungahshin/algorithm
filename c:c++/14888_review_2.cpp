// 연산자 끼워넣기
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
 
int n, m, l;
vector<int> v;
vector<int> op;
char OP[4] = {'+', '-', '*', '/'};
int ans_min = INT_MAX;
int ans_max = -INT_MAX;
 
void cal()
{
   int total = v[0];
   for(int i=1; i<v.size(); i++){
       int a = v[i];
       int idx = op[i-1];
 
       if(OP[idx]=='+'){
           total += a;
       }else if(OP[idx]=='-'){
           total -= a;
       }else if(OP[idx]=='*'){
           total *= a;
       }else if(OP[idx]=='/'){
           total /= a;
       }
   }
 
   ans_min = min(ans_min, total);
   ans_max = max(ans_max, total);
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       v.push_back(m);
   }
 
   for(int i=0; i<4; i++){
       cin>>l;
       for(int j=0; j<l; j++){
           op.push_back(i);
       }
   }
 
   do{
       cal();
   }while(next_permutation(op.begin(), op.end()));
 
   cout<<ans_max<<"\n";
   cout<<ans_min<<"\n";
 
   return 0;
}