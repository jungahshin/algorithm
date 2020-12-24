// 크레인 인형뽑기
#include <string>
#include <vector>
#include <stack>
#include <iostream>
 
using namespace std;
 
stack<int> s;
stack<int> map[31];
 
int solution(vector<vector<int>> board, vector<int> moves) {
   int answer = 0;
   for(int i=0; i<board.size(); i++){
       for(int j=board[i].size()-1; j>=0; j--){
           if(board[j][i]==0) continue;
           map[i].push(board[j][i]);
       }
   }
  
   for(int i=0; i<moves.size(); i++){
       int col = moves[i]-1;
       if(!map[col].empty()){
           int num = map[col].top();
           map[col].pop();
          
           if(!s.empty() && num==s.top()){
               s.pop();
               answer += 2;
           }else{
               s.push(num);
           }
       }
   }
  
  
   return answer;
}