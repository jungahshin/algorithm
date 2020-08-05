// 괄호 추가하기
#include <iostream>
#include <vector>
#include <stack>
#include<climits>
using namespace std;
 
int n;
string s;
int final = INT_MIN;
 
int cal(int a, int b, char oper)
{
   int result = a;
   if(oper=='+'){
       result += b;
   }else if(oper=='*'){
       result *= b;
   }else{
       result -= b;
   }
 
   return result;
}
 
 
void dfs(int idx, int total){
   if(idx>s.size()-1){ // 종료
       // 최대값 갱신
       final = max(final, total);
       return;
   }
 
   char oper;
   if(idx==0){
       oper = '+';
   }else{
       oper = s[idx-1];
   }
 
   // 괄호 추가하기
   if(idx+2<s.size()){
       int temp = cal(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
       dfs(idx+4, cal(total, temp, oper));
   }
 
   // 괄호 추가 안한다.
   dfs(idx+2, cal(total, s[idx]-'0', oper));
}
 
int main()
{
   cin>>n;
   cin>>s;
 
   dfs(0, 0);
   cout<<final<<"\n";
   return 0;
}
