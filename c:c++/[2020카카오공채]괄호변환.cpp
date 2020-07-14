//2020 kakao blind recruitment 괄호변환
#include <iostream>
#include <stack>
using namespace std;
 
string p;
string ans;
bool check = false; // u가 올바른 문자열인지 판단하는 flag값
string final;
 
string go(string s){
   if(s==""){
       return s;
   }
   check = false;
   string final;
   string u;
   string v;
   stack<char> S;
   int idx;
   int open_num = 0;
   int close_num = 0;
   for(int i=0; i<s.size(); i++){
       if(s[i]=='('){
           S.push(s[i]);
           open_num++;
       }else if(s[i]==')'){
           if(S.empty()){
               check = false;
           }else{
               S.pop();
           }
           close_num++;
       }
       if(open_num==close_num){
           idx = i;
           break;
       }
   }
 
   if(S.empty()){ // 올바른 문자열이라는 것
       check = true;
   }else{
       check = false;
   }
 
   if(idx==s.size()-1 && check==true){
       return s;
   }
 
   for(int i=0; i<=idx; i++){
       u += s[i];
   }
   for(int i=idx+1; i<s.size(); i++){
       v += s[i];
   }
 
   //u가 올바른 문자열이라면
   if(check==true){
       final += u;
       final += go(v);
   }else{
       final += '(';
       final += go(v);
       final += ')';
       for(int i=1; i<u.size()-1; i++){
           if(u[i]=='('){
               final += ')';
           }else if(u[i]==')'){
               final += '(';
           }
       }
   }
 
   return final;
}
 
 
 
int main()
{
   cin>>p;
   if(p==""){
       ans = "";
   }else{
       //문자열을 균형잡힌 괄호 문자열 u, v로 분리
       //0~idx까지가 u문자열, 나머지가 v문자열이다.
       final = go(p);       
   }
   cout<<final<<"\n";
   return 0;
}
