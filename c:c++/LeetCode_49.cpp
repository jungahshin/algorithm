class Solution {
public:
    map<string, int> m;
    vector<vector<string>> ans;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ans.resize(strs.size());
        int idx = 0;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(m.count(temp)==0){
                m[temp] = idx++;
                ans[m[temp]].push_back(strs[i]);
            }else{
                ans[m[temp]].push_back(strs[i]);
            }
        }
        
        for(int i=0; i<ans.size(); i++){
            if(ans[i].size()==0){
                ans.erase(ans.begin()+i, ans.end());
            }
        }
        return ans;
    }
};