class Solution {
public:
    int dp[101][101] = {0, };
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1){
            return 0;
        }
                
        bool check = false;
        bool check2 = false;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    if(i==0){
                        check = true; 
                    }
                    if(j==0){
                        check2 = true;
                    }
                    continue;
                }
                if(check==true && i==0) continue;
                if(check2==true && j==0) continue;
                dp[i][j] = 1;
            }
        }
        
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1) continue;
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};