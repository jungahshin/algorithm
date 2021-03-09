#include <string>
#include <vector>
#include <climits>
#include <iostream>
 
using namespace std;
 
int dp[201][201] = {0, };
 
int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = 1e9;
    
    // 왜 INT_MAX로 하면 안되는거지??? 에러생김...ㅎㅎ
    // 두 개를 더하면 int범위를 초과하게 되기 때문에...쓰레기값이 들어간다..!!
    // 따라서, 적당한 큰 값을 넣어주는 것이 중요하다.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = 20000000;
        }
    }
    
    for(int i=1; i<=n; i++){
        dp[i][i] = 0;
    }
    
    for(int i=0; i<fares.size(); i++){
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
                
        dp[to][from] = cost;
        dp[from][to] = cost;
    }
    
    // 거쳐가는 점
    for(int i=1; i<=n; i++){
        // 출발점
        for(int j=1; j<=n; j++){
            // 도착점
            for(int k=1; k<=n; k++){
                dp[j][k] = min(dp[j][k], dp[j][i]+dp[i][k]);
                // dp[i][k] = min(dp[i][k], dp[i][j]+dp[j][k]);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        answer = min(answer, dp[s][i]+dp[i][a]+dp[i][b]);
    }
    
    return answer;
}