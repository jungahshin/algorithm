class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[502][502] = {0, };
        
        for(int i=1; i<=n; i++){
            dp[i][0] = i;
        }
        
        for(int j=1; j<=m; j++){
            dp[0][j] = j;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{ // insert, delete, replace
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                }
            }
        }
        
        return dp[n][m];
    }
};