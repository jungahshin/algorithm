#include <climits>
 
class Solution {
public:
    int reverse(int x) {
        bool isMinus = false;
        string s = "";
        
        if(x<0){
            isMinus = true;
            long long temp = x;
            s = to_string(-temp);
        }else{
            s = to_string(x);
        }
                
        string temp = "";
        for(int i=s.size()-1; i>=0; i--){
            temp += s[i];
        }
                
        long long final = stoll(temp);
        
        if(final>INT_MAX || final<INT_MIN){
            return 0;
        }
        
        if(isMinus==true){
            final = -final;
        }
        
        return final;
    }
};