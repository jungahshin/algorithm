// 바이러스
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int n, k, m, a;
vector<int> v[101];
bool final = false;
 
vector<int> getPi(vector<int> p){//실패 함수 작성
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
 
vector<int> kmp(vector<int> s, vector<int> p){
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
   cin>>n>>k;
   for(int i=0; i<n; i++){
       cin>>m;
       for(int j=0; j<m; j++){
           cin>>a;
           v[i].push_back(a);
       }
   }
 
   // 0번째 문자열에서 k길이 만큼의 문자열을 뽑는다.
   for(int i=0; i<v[0].size()-k; i++){
       vector<int> cmp;
       for(int j=0; j<k; j++){
           cmp.push_back(v[0][i+j]);
       }
       //나머지 1번째 문자열이랑 계속 비교한다.
       // 원래
       bool check = true;
       for(int j=1; j<n; j++){
           vector<int> temp;
           for(int k=0; k<v[j].size(); k++){
               temp.push_back(v[j][k]);
           }
           auto matched = kmp(temp, cmp); // 큰거 작은거
           if((int)matched.size()==0){ // 일치하지 않는다.
               // 정방향으로는 일치하지 않으니 반대로 뒤집어서도 해본다.
               reverse(temp.begin(), temp.end());
               auto matched2 = kmp(temp, cmp);
               // 다시 제자리로
               reverse(temp.begin(), temp.end());
               if((int)matched2.size()==0){
                   check = false;
                   break;
               }
           }
       }
       if(check == true){ // 일치한다.
           final = true;
           break;
       }
   }
 
   if(final == true){
       cout<<"YES"<<"\n";
   }else{
       cout<<"NO"<<"\n";
   }
 
   return 0;
}
