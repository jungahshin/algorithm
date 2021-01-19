class Solution {
public:
    stack<char> S;
    bool check = true;
    
    bool isValid(string s) {
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){ // 열린 괄호
                S.push(s[i]);
            }else{ // 닫힌 괄호
                if(S.empty()){
                    check = false;
                    break;
                }
                
                if(s[i]==')'){
                    if(S.top()!='('){
                        check = false;
                        break;
                    }
                    S.pop();
                }else if(s[i]=='}'){
                    if(S.top()!='{'){
                        check = false;
                        break;
                    }
                    S.pop();
                }else{
                    if(S.top()!='['){
                        check = false;
                        break;
                    }
                    S.pop();
                }
            }
        }
        
        if(!S.empty()){
            check = false;
        }
        
        return check;
    }
};