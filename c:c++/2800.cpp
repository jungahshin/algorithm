//괄호 제거
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
string s;
vector<pair<int, int>> match;//괄호의 쌍의 idx저장
map<int, int> m;//쌍의 idx 저장
map<int, int> check;//열었는지 여부
vector<string> final;
map<string, int> dual;//중복체크
 
void dfs(int idx, string temp)
{
   if(idx == s.size()-1){
       final.push_back(temp);
       return;
   }
 
   string S = temp;
   for(int i=idx+1; i<s.size(); i++){
       if(s[i]=='(' && m.count(i)!=0){//여는 괄호가 있는 부분
           //연다
           check[m[i]] = 1;//닫는 괄호 표시
           dfs(i, S+s[i]);
           check[m[i]] = 0;
           dfs(i, S);
       }
       if(s[i]==')' && check[i]==1){//여는 괄호의 짝은 닫아준다.
           S += s[i];
       }
       if(s[i]!='(' && s[i]!=')'){//숫자
           S += s[i];
       }
       if(i==s.size()-1){
           if(dual.count(S) == 0 && S!=s){
               final.push_back(S);
               dual[S] =  1;
           }
       }
   }
 
 
}
 
int main()
{
   cin>>s;
   stack<pair<char, int>> v;
   for(int i=0; i<s.size(); i++){
       if(s[i] == '('){
           v.push(make_pair('(', i));
       }else if(s[i] == ')'){
           v.push(make_pair(')', i));
           int close_num = v.top().second;
           v.pop();
           int open_num = v.top().second;
           v.pop();
           match.push_back(make_pair(open_num, close_num));
           m[open_num] = close_num;
       }
   }
 
   string temp;
   int num = 0;
   for(int i=0; i<s.size(); i++){
       if(s[i]=='(' && m.count(i)!=0){//여는 괄호가 있는 부분
           //연다
           check[m[i]] = 1;//닫는 괄호 표시
           dfs(i, temp+s[i]);
           //열지 않는다.
           check[m[i]] = 0;
           dfs(i, temp);
       }
       if(s[i]==')' && check[i]==1){//여는 괄호의 짝은 닫아준다.
           temp += s[i];
       }
       if(s[i]!='(' && s[i]!=')'){//숫자
           temp += s[i];
       }
       if(i==s.size()-1){
           if(dual.count(temp)==0 && temp!=s){
               final.push_back(temp);
               dual[temp] = 1;
           }
       }
   }
 
   sort(final.begin(), final.end());
 
   for(int i=0; i<final.size(); i++){
       cout<<final[i]<<"\n";
   }
}
