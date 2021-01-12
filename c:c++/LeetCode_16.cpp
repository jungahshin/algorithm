class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            int low = i+1;
            int high = nums.size()-1;
            
            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if(abs(sum-target)<abs(diff)){
                    diff = sum-target;
                }
                
                if(sum>target){
                    high--;
                }else{
                    low++;
                }
            }
        }
        
        return diff+target;
    }
};