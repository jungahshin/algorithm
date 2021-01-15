class Solution {
public:
    vector<string> ans;
    int N;
    void dfs(int open, int close, string s){
        if(open==N){
            for(int i=0; i<close; i++){
                s += ')';
            }
            ans.push_back(s);
            return;
        }
        
        dfs(open+1, close+1, s+'(');
        if(close>0){
            dfs(open, close-1, s+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        N = n;
        dfs(0, 0, "");
        
        return ans;
    }
};