// 팰린드롬 수
#include <iostream>
using namespace std;
 
string s;
 
int main()
{
   while(1){
       cin>>s;
       if(s=="0"){
           break;
       }
       int idx = 0;
       bool check = true;
       while(1){
           int nidx = (s.size()-1-idx);
           if(idx>=nidx){
               break;
           }
           if(s[idx]!=s[nidx]){
               check = false;
               break;
           }
           idx++;
       }
       if(check==true){
           cout<<"yes"<<"\n";
       }else{
           cout<<"no"<<"\n";
       }
   }
 
   return 0;
}