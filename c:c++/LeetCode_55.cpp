class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 현재 위치에서 최대 이동거리만큼 더한 값(i+nums[i])이 마지막 위치(lastPos)까지 도달할 수 있는 지를 판단!
        int lastPos = nums.size()-1; 
        for(int i=nums.size()-1; i>=0; i--){
            if(i+nums[i]>=lastPos){ // 현재 위치가 lastPos까지 도달할 수 있기 때문에 현재위치가 lastPos가 된다.
                lastPos = i;
            }
        }
        
        if(lastPos==0){
            return true;
        }
        
        return false;
    }
};