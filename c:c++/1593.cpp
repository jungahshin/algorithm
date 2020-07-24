// 문자 해독
// 비트마스킹으로는 대문자, 소문자가 모두 있기 때문에 불가하다.
#include <iostream>
#include <map>
using namespace std;
 
int n, m;
string s1, s2;
map<char, int> M;
map<char, int> T;
int total = 0;
int visited[3000001] = {0, };
 
int main()
{
   cin>>n>>m;
   cin>>s1;
   int kind = 0;
   for(int i=0; i<s1.size(); i++){
       if(M.count(s1[i])==0){
           kind++;
           M[s1[i]] = 1;
           T[s1[i]] = 1;
       }else{
           T[s1[i]]++;
       }
   }
   cin>>s2;
 
   int num = 0;
   int Start = 0;
   int End = n-1;
 
   for(int i=0; i<n; i++){
       if(M[s2[i]]==1){ // s1에 있는 알파벳
           num++;
       }
       M[s2[i]]++;
   }
 
   while(1){
       // 확인
       if(num==kind){
           bool temp = true;
           for(int j=Start; j<=End; j++){
               if(M[s2[j]]!=(T[s2[j]]+1)){
                   temp = false;
                   break;
               }
           }
           if(temp==true){
              total++;
           }
       }
 
       End++;
       if(End<m){
           // i번째 애는 빼주고 진행
           if(M[s2[Start]]==2){
               M[s2[Start]]--;
               num--;
           }else if(M[s2[Start]]>2){
               M[s2[Start]]--;
           }
           Start++;
       }else{
           break;
       }
 
       if(M.count(s2[End])!=0){
           if(M[s2[End]]==1){ // s1에 있는 알파벳
               num++;
           }
           M[s2[End]]++;
       }
   }
 
   cout<<total<<"\n";
  
   return 0;
}
