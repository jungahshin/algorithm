// 괄호
#include <iostream>
#include <stack>
using namespace std;
 
int n;
stack<char> S;
string s;
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>s;
       bool check = true;
       for(int j=0; j<s.size(); j++){
           if(s[j]=='('){
               S.push(s[j]);
           }else{
               if(S.size()==0){
                   check = false;
                   break;
               }else{
                   if(S.top()=='('){
                       S.pop();
                   }else{
                       check = false;
                       break;
                   }                   
               }
           }
       }
      
       if(check==true){
           if(S.size()!=0){
               check = false;
           }           
       }
 
       if(check==true){
           cout<<"YES"<<"\n";
       }else{
           cout<<"NO"<<"\n";
       }
 
       while(!S.empty()){
           S.pop();
       }
   }
 
   return 0;
}