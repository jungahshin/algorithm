class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size()==0){
            return ans;
        }
        sort(strs.begin(), strs.end());
        string s = strs[0];
        string temp = "";
        
        if(strs.size()==1){
            return s;
        }
        
        for(int i=0; i<s.size(); i++){
            temp += s[i];
            for(int j=1; j<strs.size(); j++){
                if(temp!=strs[j].substr(0, i+1)){
                    return ans;
                }
            }
            
            ans = temp;
        }
        
        return ans;
    }
};