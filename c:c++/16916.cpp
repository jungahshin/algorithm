//부분 문자열
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string s, p;
 
vector<int> getPi(string p){//실패 함수 작성
   int m = (int)p.size(), j=0;
   vector<int> pi(m, 0);
   for(int i = 1; i< m ; i++){
       while(j > 0 && p[i] !=  p[j])
           j = pi[j-1];
       if(p[i] == p[j])
           pi[i] = ++j;
   }
   return pi;
}
 
vector<int> kmp(string s, string p){
   vector<int> ans;
   auto pi = getPi(p);
   int n = (int)s.size(), m = (int)p.size(), j =0;
   for(int i = 0 ; i < n ; i++){
       while(j>0 && s[i] != p[j])
           j = pi[j-1];
       if(s[i] == p[j]){
           if(j==m-1){
               ans.push_back(i-m+1);
               j = pi[j];
           }else{
               j++;
           }
       }
   }
   return ans;
}
 
int main()
{
   cin>>s>>p;
   auto matched = kmp(s,p);
   if((int)matched.size()>0){
       cout<<"1"<<"\n";
   }else{
       cout<<"0"<<"\n";
   }
 
   return 0;
}
