class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int Start = 0, End = 0;
        vector<int> ans;
        bool check = false;
        
        if(nums.size()==1){
            if(nums[0]==target){
                check = true;
            }
        }
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                check = true;
                Start = mid, End = mid;
                while(End<nums.size()-1 && nums[End]==nums[End+1]){
                    End++;
                }
                while(Start>0 && nums[Start]==nums[Start-1]){
                    Start--;
                }
                break;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        if(check==true){
            ans.push_back(Start);
            ans.push_back(End);            
        }else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
 
        return ans;
    }
};