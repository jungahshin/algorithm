// 제국
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
int n, m;
string s;
vector<string> nation;
int connect[502] = {0, };
map<string, int> M;
vector<string> final;
 
int find(int a){
  if(a==connect[a]){
      return a;
  }else{
      return connect[a] = find(connect[a]);
  }
}
 
void war(string a, string b) // a가 b를 이겼다.
{
   int x = find(M[a]);
   int y = find(M[b]);
 
   if(x!=y){ // 다른 왕국끼리 싸움 y->x
       connect[y] = x;
   }else{ // 같은 왕국 안에서의 싸움
       connect[M[a]] = M[a];
       connect[x] = M[a];
   }
}
 
int main()
{
   cin>>n>>m;
   cin.ignore();
   for(int i=0; i<n; i++){
       getline(cin, s);
       stringstream ss(s);
       string temp;
       while(ss >> temp){ }
       nation.push_back(temp);
       M[temp] = i;
       connect[i] = i;
   }
 
   for(int i=0; i<m; i++){
       getline(cin, s);
       string a, b;
       int win = s[s.size()-1]-'0';
       int idx = 11;
       while(s[idx]!=','){
           a += s[idx++];
       }
       idx += 12;
       while(s[idx]!=','){
           b += s[idx++];
       }
 
       if(win==1){
           war(a, b);
       }else if(win==2){
           war(b, a);
       }
   }
 
   map<int, int> check;
   for(int i=0; i<n; i++){
       int temp = find(i);
       if(check.count(temp)==0){
           check[temp] = 1;
           final.push_back(nation[temp]);
       }
   }
 
   sort(final.begin(), final.end());
 
   cout<<final.size()<<"\n";
   for(int i=0; i<final.size(); i++){
       cout<<"Kingdom of "<<final[i]<<"\n";
   }
 
   return 0;
}
