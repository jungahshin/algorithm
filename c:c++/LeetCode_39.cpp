class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int sum, vector<int>& v, vector<int>& candidates, int target, int start){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(v);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            v.push_back(candidates[i]);
            dfs(sum+candidates[i], v, candidates, target, i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i=0; i<candidates.size(); i++){
            vector<int> temp;
            temp.push_back(candidates[i]);
            dfs(candidates[i], temp, candidates, target, i);
        }
        
        return ans;
    }
};