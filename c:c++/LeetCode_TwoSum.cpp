class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++){
            int temp = target-nums[i];
            if(m.count(temp)==0) continue;
            if(i==m[temp]) continue;
            ans.push_back(i);
            ans.push_back(m[temp]);
            
            break;
        }
        
        return ans;
    }
};