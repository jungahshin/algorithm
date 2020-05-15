//후위 표기식
#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> s;
string final = "";

int main(){
    cin>>str;
    for(int i=0; i<str.size(); i++){
        int c = str[i];
        if('A'<= c && c<='Z'){//피연산자
            final += c;
        }else{
            switch(c){
                case '(':
                    s.push(c);
                    break;

                case '*':
                case '/':
                    while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                        final += s.top();
                        s.pop();
                    }
                    s.push(c);
                    break;
                //+와 -는 '('를 만나지 않는 이상 다 pop해준다.
                case '+':
                case '-':
                    while(!s.empty() && s.top() != '('){
                        final += s.top();
                        s.pop();
                    }
                    s.push(c);
                    break;
                //')'가 나오면 이것과 짝궁인 '('가 나올 때까지 pop해준다.
                case ')':
                    while(!s.empty() && s.top() != '('){
                        final += s.top();
                        s.pop();
                    }
                    s.pop();//'('도 마저 pop해준다.
                    break;
            }
        }
    }
    while(!s.empty()){
        final += s.top();
        s.pop();
    }
    cout<<final<<"\n";
    return 0;
}