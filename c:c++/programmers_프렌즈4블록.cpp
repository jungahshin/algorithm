#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
 
using namespace std;
 
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int num = n*m;
    
    while(num!=0){
        num = 0;
        int check[31][31] = {0, };
        for(int i=0; i<=m-2; i++){
            for(int j=0; j<=n-2; j++){
                if(board[i][j] != '.' && board[i][j] == board[i][j+1] && board[i][j+1] == board[i+1][j] && board[i+1][j] == board[i+1][j+1]){
                    check[i][j] = 1;
                    check[i+1][j] = 1;
                    check[i][j+1] = 1;
                    check[i+1][j+1] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++){ // 열
            queue<char> q;
            for(int j=m-1; j>=0; j--){ // 행
                if(check[j][i]==1){
                    num++;
                    continue;
                }
                q.push(board[j][i]);
            }
            
            for(int j=m-1; j>=0; j--){
                if(!q.empty()){
                    char c = q.front();
                    q.pop();
                    board[j][i] = c;
                    continue;
                }
                board[j][i] = '.';
            }
        }
        
        answer += num;
    }
 
    
    return answer;
}