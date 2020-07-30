// 차량 번호판1
#include <iostream>
using namespace std;
 
string s;
int total = 1;
 
int main()
{
   cin>>s;
   char temp;
   for(int i=0; i<s.size(); i++){
       if(i==0){
           if(s[i]=='c'){
               total *= 26;
           }else if(s[i]=='d'){
               total *= 10;
           }
           temp = s[i]; // 전에 어떤 값이었는지 저장
       }else{
           if(temp==s[i]){ // 전의 값과 일치한다.
               if(s[i]=='c'){
                   total *= 25;
               }else if(s[i]=='d'){
                   total *= 9;
               }
               temp = s[i];
           }else{ // 일치하지 않는다.
               if(s[i]=='c'){
                   total *= 26;
               }else if(s[i]=='d'){
                   total *= 10;
               }
               temp = s[i];
           }           
       }
   }
 
   cout<<total<<"\n";
   return 0;
}
