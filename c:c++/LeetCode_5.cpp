// BruteForce
class Solution {
public:
    string longestPalindrome(string s) {
        string S = "";
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            // 홀수 팰린드롬
            int Start = i, End = i;
            // 짝수 팰린드롬
            int Start2 = i, End2 = i;
            
            // 홀수 팰린드롬
            while(Start>0 && End<s.size()-1){
                Start--;
                End++;
                if(s[Start]!=s[End]){
                    Start++;
                    End--;
                    // check = true;
                    break;
                }
            }
 
            // 짝수 팰린드롬
            Start2 = i, End2 = i;
            End2++;
            if(End2<s.size()){
                if(s[Start2]==s[End2]){
                    while(Start2>0 && End2<s.size()-1){
                        Start2--;
                        End2++;
                        if(s[Start2]!=s[End2]){
                            Start2++;
                            End2--;
                            break;
                        }
                    }
                }else{
                    Start2 = i;
                    End2 = i;
                }
            }
 
            // 최종 계산
            int temp = End-Start+1;
            int temp2 = End2-Start2+1;
            
            if(temp<temp2){
                if(ans<temp2){
                    ans = temp2;
                    S = s.substr(Start2, temp2);
                }
            }else{
                if(ans<temp){
                    ans = temp;
                    S = s.substr(Start, temp);
                }
            }
        }
        return S;
    }
};