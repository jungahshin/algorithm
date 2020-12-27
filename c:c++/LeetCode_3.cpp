// 투포인터
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int Start=0, End = 0;
        map<char, int> m;
        int num = 0;
        while(Start<=End && End<s.size()){
            if(m.count(s[End])==0){
                num++;
                m[s[End]] = 1;
                End++;
            }else{
                num--;
                m.erase(s[Start]);
                Start++;
            }
            ans = max(ans, num);
        }
        return ans;
    }
};