class Solution {
public:
    char map[1001][1001];
    string convert(string s, int numRows) {
        map[0][0] = s[0];
        int idx = 1;
        int row = 0, col = 0;
        bool check = false;
        int maxCol = 0;
        string ans = "";
        
        if(numRows==1){
            return s;
        }
    
        while(idx<s.size()){
            // 밑으로 이동
            for(int i=0; i<numRows-1; i++){
                if(idx>s.size()-1){
                    check = true;
                    break;
                }      
                row++;
                map[row][col] = s[idx];
                idx++;
            }
            if(check==true){
                break;
            }
            // 대각선 이동
            for(int i=0; i<numRows-1; i++){
                if(idx>s.size()-1){
                    check = true;
                    break;
                } 
                row--;
                col++;
                map[row][col] = s[idx];
                idx++;
                maxCol = max(col, maxCol);
            }
        }
        
// 출력하기
        for(int i=0; i<numRows; i++){
            for(int j=0; j<=maxCol; j++){
                if(map[i][j]!=NULL){
                    ans += map[i][j];
                }
            }
        }
        
        return ans;
    }
};