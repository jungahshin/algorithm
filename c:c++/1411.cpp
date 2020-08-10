// 비슷한 단어
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
 
int n;
string s;
vector<string> S;
int final = 0;
vector<string> total;
int v[30] = {0, };
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>s;
       S.push_back(s);
   }
 
   for(int i=0; i<S.size(); i++){
       int counter = 0;
       memset(v, 0, sizeof(v));
 
       map<int, int> m;
       string temp = S[i];
       string t;
       for(int j=0; j<temp.size(); j++){
           if(m.count(temp[j]-'a')==0){
               m[temp[j]-'a'] = 1;
               counter++;
               v[temp[j]-'a'] = counter;
               t += to_string(counter);
           }else{
               t += to_string(v[temp[j]-'a']);
           }
       }
 
       total.push_back(t);
   }
 
   for(int i=0; i<total.size(); i++){
       for(int j=i+1; j<total.size(); j++){
           if(total[i]==total[j]){
               final++;
           }
       }
   }
 
   cout<<final<<"\n";
   return 0;
}
