class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = 0;
        bool check = false;
        for(int i=0; i<nums.size(); i++){
            idx = i;
            
            if(target==nums[i] || target<nums[i]){
                check = true;
                break;
            }
        }
        
        if(check==false){
            idx++;
        }
        
        return idx;
    }
};