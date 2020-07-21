// 괄호의 값
#include <iostream>
#include <stack>
using namespace std;
 
string s;
int visited[31] = {0, };
int total = 0;
bool check = false;
stack<int> S;
 
int dfs(int idx)
{
   int final = 0;
   int total_temp = 0;
   for(int i=idx; i<s.size(); i++){
       if(!visited[i]){
           visited[i] = 1;
           if(s[i]=='[' || s[i]=='('){ // 곱해준다.
               S.push(s[i]);
               check = false;
               final = 0;
               int num = dfs(i+1);
               if(final==0){
                   final = 1;
               }
               final *= num;
               total_temp += final;
           }
 
           if(s[i]==')'){
               if(S.size()==0){
                   check = false;
                   return -1;
               }
               if(S.top()=='('){
                   S.pop();
               }else{
                   check = false;
                   return -1;
               }
               check = true;
               if(total_temp==0){
                   total_temp = 1;
               }
               total_temp *= 2;
               return total_temp;
           }
           if(s[i]==']'){
               if(S.size()==0){
                   check = false;
                   return -1;
               }
               if(S.top()=='['){
                   S.pop();
               }else{
                   check = false;
                   return -1;
               }
               check = true;
               if(total_temp==0){
                   total_temp = 1;
               }
               total_temp *= 3;
               return total_temp;
           }         
       }
   }
 
   return total_temp;
}
 
int main()
{
   cin>>s;
 
   int final = 0;
   for(int i=0; i<s.size(); i++){
       if(!visited[i]){
           visited[i] = 1;
           if(s[i]=='[' || s[i]=='('){
               S.push(s[i]);
               check = false;
               final = 0;
               int num = dfs(i+1);
               if(num==-1){
                   break;
               }
               if(final==0){
                   final = 1;
               }
               final *= num;
               total += final;
           }
           if(s[i]==')'){
               if(S.size()==0){
                   check = false;
                   break;
               }
               if(S.top()=='('){
                   S.pop();
               }else{
                   check = false;
                   break;
               }
               check = true;
               if(total==0){
                   total = 1;
               }
               total *= 2;
           }
           if(s[i]==']'){
               if(S.size()==0){
                   check = false;
                   break;
               }
               if(S.top()=='['){
                   S.pop();
               }else{
                   check = false;
                   break;
               }
               check = true;
               if(total==0){
                   total = 1;
               }
               total *= 3;
           }         
       }
   }
 
   if(check == false || total<0 || S.size()!=0){
       cout<<"0"<<"\n";
   }else{
       cout<<total<<"\n";
   }
  
 
   return 0;
}
