class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}; // 위, 아래, 왼, 오
    int dy[4] = {0, 0, -1, 1};
    int visited[201][201] = {0, };
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]!=0 || visited[i][j]) continue;
                int x = i;
                int y = j;
                
                for(int k=0; k<4; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    while(0<=nx && nx<n && 0<=ny && ny<m){
                        if(!visited[nx][ny] && matrix[nx][ny]!=0){
                            visited[nx][ny] = 1;
                            matrix[nx][ny] = 0;
                        }
                        nx += dx[k];
                        ny += dy[k];  
                    }
                }
            }
        }
    }
};