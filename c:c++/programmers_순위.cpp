#include <string>
#include <vector>
#include <climits>
#include <iostream>
 
using namespace std;
 
int dp[102][102] = {0, }; // i가 j를 이기면 1, 지면 -1, 모르면 0
 
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0; i<results.size(); i++){
        int win = results[i][0];
        int lose = results[i][1];
        
        dp[win][lose] = 1;
        dp[lose][win] = -1;
    }
    
    // 시작 점
    for(int i=1; i<=n; i++){
        // 거쳐가는 점
        for(int j=1; j<=n; j++){
            // 끝점
            for(int k=1; k<=n; k++){
                if(dp[i][j]==1 && dp[j][k]==1){
                    dp[i][k] = 1;
                    dp[k][i] = -1;
                }
                if(dp[i][j]==-1 && dp[j][k]==-1){
                    dp[i][k] = -1;
                    dp[k][i] = 1;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int num = 0;
        for(int j=1; j<=n; j++){
            if(dp[i][j]==0){
                num++;
            }
        }
        if(num==1){
            answer++;
        }
    }
    
    return answer;
}