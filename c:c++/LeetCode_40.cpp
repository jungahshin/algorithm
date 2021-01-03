class Solution {
public:
    vector<vector<int>> ans;
    map<int, int> m;
    
    void dfs(int sum, vector<int>& v, vector<int>& candidates, int target, int start){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(v);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            dfs(sum+candidates[i], v, candidates, target, i+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int i=0; i<candidates.size(); i++){
            if(m.count(candidates[i])!=0) continue;
            m[candidates[i]] = 1;
            vector<int> temp;
            temp.push_back(candidates[i]);
            dfs(candidates[i], temp, candidates, target, i+1);
        }
        
        return ans;
    }
};