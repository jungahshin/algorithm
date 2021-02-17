class Solution {
public:
    vector<vector<string>> ans;
    
    bool check(int Start, int End, string s){
        int half = (End+1-Start)/2; // 양쪽을 비교할 횟수
        for(int i=0; i<half; i++){
            if(s[Start+i]!=s[End-i]) return false;
        }
        return true;
    }
 
    void dfs(int idx, string s, vector<string> &v){
        if(idx==s.size()){
            ans.push_back(v);
            return;
        }
 
        int size = s.size();
        for(int i=idx; i<s.size(); i++){
            if(check(idx, i, s)){
                v.push_back(s.substr(idx, i-idx+1));
                dfs(i+1, s, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int size = s.size();
        vector<string> v;
        for(int i=0; i<s.size(); i++){
            if(check(0, i, s)){
                v.push_back(s.substr(0, i+1));
                dfs(i+1, s, v);
                v.pop_back();
            }
        }
        
        return ans;
    }
};