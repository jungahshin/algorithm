//2020 카카오인턴 #2번(문자열처리)
//수식 최대화
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
 
string s;
long long total = 0;
vector<char> op;
vector<char> OP;
vector<long long> num;
vector<long long> V;
char C[3] = {'+', '-', '*'};
 
long long cal(long long a, long long b, char c)
{
   long long num;
   if(c=='+'){
       num = a+b;
   }else if(c=='-'){
       num = a-b;
   }else if(c=='*'){
       num = a*b;
   }
   return num;
}
 
long long solution(string s) {
   map<char, int> m;
   int kind = 1;
   string temp;
   for(int i=0; i<s.size(); i++){
       if(s[i]=='-' || s[i]=='*' || s[i]=='+'){
           num.push_back(stoi(temp));
           temp = "";
           if(m.count(s[i])==0){
               op.push_back(s[i]);
               m[s[i]] = kind++;
           }
           OP.push_back(s[i]);
       }else{
           temp += s[i];
           if(i==s.size()-1){
               num.push_back(stoi(temp));
           }
       }
   }
 
   V.push_back(0);
   V.push_back(1);
   V.push_back(2);
  
   do{
       vector<char> OP_temp;
       for(int i=0; i<OP.size(); i++){
           OP_temp.push_back(OP[i]);
       }
       vector<long long> NUM_temp;
       for(int i=0; i<num.size(); i++){
           NUM_temp.push_back(num[i]);
       }
 
       int idx = 0;
       while(1){
           stack<char> op_temp;
           stack<long long> num_temp;
           num_temp.push(NUM_temp[0]);
 
           if(OP_temp.size()==0 && NUM_temp.size()==1){
               break;
           }
 
           for(int i=0; i<OP_temp.size(); i++){
               num_temp.push(NUM_temp[i+1]);
               op_temp.push(OP_temp[i]);
 
               //원하는 연산자가 나왔을 때에
               if(OP_temp[i]==C[V[idx]]){
                   long long b = num_temp.top();
                   num_temp.pop();
                   long long a = num_temp.top();
                   num_temp.pop();
                   char c = op_temp.top();
                   op_temp.pop();
 
                   long long final = cal(a, b, c);
                   num_temp.push(final);
               }
           }
           idx++;
           //stack_op에 남아있는 애들을 OP_temp에 넣어준다.
           OP_temp.clear();
           vector<char> v1;
           while(!op_temp.empty()){
               v1.push_back(op_temp.top());
               op_temp.pop();
           }
           for(int k=v1.size()-1; k>=0; k--){
               OP_temp.push_back(v1[k]);
           }
           //stack_num에 남아 있는 애들을 num에 넣어준다.
           NUM_temp.clear();
           vector<long long> v2;
           while(!num_temp.empty()){
               v2.push_back(num_temp.top());
               num_temp.pop();
           }
           for(int k=v2.size()-1; k>=0; k--){
               NUM_temp.push_back(v2[k]);
           }
       }
       if(total<abs(NUM_temp[0])){
           total = abs(NUM_temp[0]);
       }
       // total = max(total, abs(NUM_temp[0]));
   }while(next_permutation(V.begin(), V.end()));
  
   return total;
}
