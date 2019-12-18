//잃어버린 괄호
//-, +부호가 있을 때에 가장 최소값을 구하는 것은 -부호가 나오면 바로 괄호를 치고 -부호가 다음에 나오면 괄호를 닫는다.
//즉, -부호가 분배법칙으로 인해 분해되어 -부호가 한 번 나오고 난 이후의 모든 숫자들을 빼주면 최소값이다.
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string str;
vector<long long> num;//숫자들 저장
vector<char> v;//연산자 저장

long long final = 0;

int main(){
    cin>>str;
    string temp = "";
    for(int i=0; i<=str.size(); i++){
        if(str[i] == '-' || str[i] == '+'){//연산자
            long long number = 0;
            number = stoll(temp);
            temp = "";
            num.push_back(number);
            v.push_back(str[i]);
        }else{//숫자
            temp += str[i];
        }
        if(i == str.size()-1){
            long long number = 0;
            number = stoll(temp);
            num.push_back(number);
        }
    }
    bool check = false;
    long long final = num[0];//index 1부터 계산한다
    for(int i=0; i<v.size(); i++){
        if(check == false){//-부호를 아직 만나지 않았다
            if(v[i] == '+'){
                final += num[i+1];
            }else{
                check = true;
                final -= num[i+1];
            }
        }else{
            final -= num[i+1];
        }
    }
    cout<<final<<"\n";
}