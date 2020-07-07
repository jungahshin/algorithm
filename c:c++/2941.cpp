//크로아티아 알파벳
#include <iostream>
using namespace std;
 
string s;
int num = 0;
int visited[101] = {0, };
string S[7] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
 
int main()
{
   cin>>s;
 
   if(s.size()>=3){
       for(int i=0; i<s.size()-2; i++){
           string temp;
           temp += s[i];
           temp += s[i+1];
           temp += s[i+2];
           if(temp == "dz="){
               visited[i] = 1;
               visited[i+1] = 1;
               visited[i+2] = 1;
               num++;
           }
       }       
   }
 
   if(s.size()>=2){
       for(int k=0; k<7; k++){
           for(int i=0; i<s.size()-1; i++){
               string temp;
               if(!visited[i]){
                   temp += s[i];
                   temp += s[i+1];
                   if(temp == S[k]){
                       visited[i] = 1;
                       visited[i+1] = 1;
                       num++;
                   }               
               }
           }       
       }       
   }
 
   for(int i=0; i<s.size(); i++){
       if(!visited[i]){
           visited[i] = 1;
           num++;
       }
   }
 
 
   cout<<num<<"\n";
   return 0;
}
