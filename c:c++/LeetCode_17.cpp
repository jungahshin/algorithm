lass Solution {
public:
    vector<string> ans;
    vector<char> phone[11];
    
    void dfs(string digits, int idx, string temp){        
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<phone[digits[idx]-'0'].size(); i++){
            dfs(digits, idx+1, temp+phone[digits[idx]-'0'][i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return ans;
        }
        
        int idx = 0;
        
        for(int i=2; i<=9; i++){
            if(i==7 || i==9){ // 4개
                for(int j=0; j<4; j++){
                    char c = idx+'a';
                    phone[i].push_back(c);
                    idx++;
                }
            }else{ // 3개
                for(int j=0; j<3; j++){
                    char c = idx+'a';
                    phone[i].push_back(c);
                    idx++;
                }
            }
        }
        
        dfs(digits, 0, "");
        
        return ans;
    }
};