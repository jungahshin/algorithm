class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int map[21][21] = {0, };
        int x = 0, y = 0, num = 0;
        int visited[21][21] = {0, };
        int idx = 0; // 방향 설정
        vector<vector<int>> ans;
        
        while(num<n*n){
            num++;
            map[x][y] = num;
            visited[x][y] = 1;
            int nx = x+dx[idx];
            int ny = y+dy[idx];
            if(0>nx || nx>=n || 0>ny || ny>=n || visited[nx][ny]){
                idx = (idx+1)%4;
                nx = x+dx[idx];
                ny = y+dy[idx];
            }
            x = nx;
            y = ny;
        }
        
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                temp.push_back(map[i][j]);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};