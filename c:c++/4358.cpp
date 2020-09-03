// 생태학
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
 
string s;
map<string, int> m;
vector<string> v;
int total = 0; // 전체 나무의 수
 
int main()
{
   while(1){
       getline(cin, s);
       if(s.length()==0){
           break;
       }
       total++;
       if(m.count(s)==0){
           v.push_back(s);
           m[s] = 1;
       }else{
           m[s]++;
       }       
   }
 
   sort(v.begin(), v.end());
   for(int i=0; i<v.size(); i++){
       cout<<v[i]<<" ";
       printf("%.4f\n", (m[v[i]]/(double)total)*100);
   }
  
   return 0;
}