class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1){
            return 1;
        }
        
        int ans = 0;
        int idx1 = 0, idx2 = 0, idx3 = 0;
        vector<int> v;
        v.push_back(1);
        n--;
        
        while(n--){
            int num = min(v[idx1]*2, min(v[idx2]*3, v[idx3]*5));
            ans = num;
            v.push_back(num);
            if(v.back()==v[idx1]*2) idx1++;
            if(v.back()==v[idx2]*3) idx2++;
            if(v.back()==v[idx3]*5) idx3++;
        }
        
        return ans;
    }
};