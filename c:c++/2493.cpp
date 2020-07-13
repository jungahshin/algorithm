//탑(스택)
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int n, m;
stack<pair<int, int>> s; // 탑의 높이, 순서
vector<pair<int, int>> final;
map<int, int> M;
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       if(s.empty()){
           s.push(make_pair(m, i+1));
       }else{
           while(!s.empty()){
               if(s.top().first<m){
                   int temp = s.top().first;
                   int temp_idx = s.top().second;
                   s.pop();
 
                   if(!s.empty()){
                       final.push_back(make_pair(temp_idx, s.top().second));
                   }else{ // 0을 넣는다.
                       final.push_back(make_pair(temp_idx, 0));
                   }
               }else{
                   s.push(make_pair(m, i+1));
                   break;
               }
           }
           if(s.empty()){ // 이게 핵심포인트!!! -> 스택에 아무것도 남아있지 않아서 m을 넣지 않았는데 while문을 끝난경우 스택에 m을 넣어준다.
               s.push(make_pair(m, i+1));
           }
       }
   }
 
   // stack에 남아있는 것들 처리
   while(!s.empty()){
       int temp = s.top().first;
       int temp_idx = s.top().second;
       s.pop();
       if(!s.empty()){
           final.push_back(make_pair(temp_idx, s.top().second));
       }else{
           final.push_back(make_pair(temp_idx, 0));
       }
   }
 
   sort(final.begin(), final.end());
 
   for(int i=0; i<final.size(); i++){
       cout<<final[i].second<<"\n";
   }
 
   return 0;
}
