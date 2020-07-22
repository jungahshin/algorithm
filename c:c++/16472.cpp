// 고냥이
#include <iostream>
#include <map>
using namespace std;
 
int n;
string s;
map<char, int> kind;
int final = 0; // 최대 구간 길이
 
int main()
{
   cin>>n;
   cin>>s;
 
   int num = 0; // 종류
   int Start = 0;
   int End = 0;
 
   if(s.size()<=n){
       cout<<s.size()<<"\n";
   }else{
       while(Start<=End && End<s.size()){
           if(num<=n){ // End를 늘린다.
               if(Start<=End && End<s.size()){
                   if(kind.count(s[End])==0){
                       kind[s[End]] = 1;
                       num++;
                   }else{
                       kind[s[End]]++;
                   }
                   End++;
                   if(End==s.size()-1 && n>=num){
                       final = max(final, End-Start+1);
                   }
               }
           }else if(num>n){ // Start를 늘린다.
               if(Start<=End && End<s.size()){
                   kind[s[Start]]--;
                   if(kind[s[Start]]==0){
                       kind.erase(s[Start]);
                       num--;
                   }
                   Start++;
               }
           }
 
           if(num==n){
               // Start~End-1까지의 구간길이를 저장한다.
               final = max(final, End-Start);
           }
       }     
       cout<<final<<"\n"; 
   }
 
   return 0;
}
