// 반복되는지 살펴보기..visit 처리
class Solution {
public:
    map<int, int> m;
    bool isHappy(int n) {
        do{
            string s = to_string(n);
            int num = 0;
            for(int i=0; i<s.size(); i++){
                num += (s[i]-'0')*(s[i]-'0');
            }
            if(m.count(num)==0){
                m[num] = 1;
            }else{
                return false;
            }
            if(num==1){
                return true;
            }
            n = num;
        }while(n<INT_MAX);
        
        return true;
    }
};