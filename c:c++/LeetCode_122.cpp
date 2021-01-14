class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 내려가는 구간은 절대 사지 않고
        // 올라가는 구간에서만 사고 판다.
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                ans += (prices[i]-prices[i-1]);
            }
        }
        
        return ans;
    }
};