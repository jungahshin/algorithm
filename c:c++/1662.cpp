//압축
#include <iostream>
#include <stack>
 
using namespace std;
 
string s;
int visited[51] = {0, };
 
int go(int start, int end)
{
   int result = 0;
 
   for(int i=start; i<end; i++){
       if(s[i]=='('){
           int temp = s[i-1]-'0';
           result += (temp*go(i+1, visited[i])-1);
           i = visited[i];
           continue;
       }
       result++;
   }
  
   return result;
}
 
int main()
{
   cin>>s;
  
   //괄호 쌍 인덱스를 저장해준다.
   stack<char> S;
   for(int i=0; i<s.size(); i++){
       if(s[i]=='('){
           S.push(i);
       }else if(s[i]==')'){
           visited[S.top()] = i;
           S.pop();
       }
   }
 
   cout<<go(0, s.size())<<"\n";
   return 0;
}
