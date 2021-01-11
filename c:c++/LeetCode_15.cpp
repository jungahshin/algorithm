class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int low = i+1;
            int high = nums.size()-1;
            
            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if(sum<0){
                    low++;
                }else if(sum>0){
                    high--;
                }else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);
 
                    while(low+1<nums.size() && nums[low+1]==nums[low]){
                        low++;
                    }
 
                    while(high-1>=0 && nums[high-1]==nums[high]){
                        high--;
                    }
 
                    // 위에 while문은 같은 것의 끝을 가르키고 있는 것이니 새로운 값이 나오도록 한 번 더 이동해준다.
                    high--;
                    low++;
                }                
            }
        }
        
        return ans;
    }
};