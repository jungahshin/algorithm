//괄호 추가하기
//연산자 우선순위가 전혀 없기 때문에 수식을 계산시 그냥 왼쪽부터 계산한다.
//단, 괄호안에는 연산자 1개만 있다.
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int n;
string a;
int bracket[20] = {0, };
vector<string> v;//최종 계산하는 숫자와 연산자들을 넣는 벡터
vector<char> temp;//임시로 괄호 안의 숫자와 연산자들을 넣는 벡터
int really_final = -(INT_MAX);


int cal_3(int num_1, char num_2, int num_3){//계산
    int temp = 0;
    if(num_2 == '+'){
        temp = num_1 + num_3;
    }else if(num_2 == '-'){
        temp = num_1 - num_3;
    }else if(num_2 == '*'){
        temp = num_1 * num_3;
    }
    return temp;
}


int cal_2(vector<char> c){//temp, v에 들어 있는 값들 계산
    int result = 0;
    if(c.size() > 1){
        for(int i=0; i<c.size(); i++){
            if(i == 0){
                int num_1 = c[i] - '0';//char를 string으로 바꾸고 int로 바꾼다.
                char num_2 = c[i+1];
                int num_3 = c[i+2] - '0';
                result = cal_3(num_1, num_2, num_3);
                i += 2;
            }else{
                char num_2 = c[i];
                int num_3 = c[i+1] - '0';
                result = cal_3(result, num_2, num_3);
                i += 1;
            }
        }
        return result;
    }else{
        return c[0] - '0';
    }
}

void go(){//계산하기
    v.clear();
    string final;
    bool check = false;
    for(int i=0; i<=n; i++){
        char num = a[i];
        if(bracket[i] == 1){//여는 괄호
            if(i != n){
                int temp_2 = 0;
                temp.clear();
                check = true;
                final += '(';
                final += a[i];
                temp.push_back(num);
            }else{
                final += '(';
            }
        }else if(bracket[i] == 2){//닫는 괄호 --> 벡터 안에 들어있는 값들을 계산해준다.
            if(i != n){
                check= false;
                final += ')';
                final += a[i];
                //v에 temp값들을 계산한 후의 값을 넣어준다.
                v.push_back(to_string(cal_2(temp)));
                //그리고 v에 a[i]값을 넣어준다.
                string str = "";
                str = num;
                v.push_back(str);
            }else{
                final += ')';
                //v에 temp값들을 계산한 후의 값을 넣어준다.
                v.push_back(to_string(cal_2(temp)));
            }
        }else{//괄호가 없어-->그냥 벡터에 넣어준다.
            if(i != n){
                final += a[i];
                if(check == true){//괄호 안의 값
                    temp.push_back(num);
                }else{
                    string str = "";
                    str = num;
                    v.push_back(str);
                }
            }
        }
    }
    int res = stoi(v[0]);
    for(int i=1; i<v.size(); i+=2){
        if(v[i] == "+"){
            res += stoi(v[i+1]);
        }else if(v[i] == "-"){
            res -= stoi(v[i+1]);
        }else if(v[i] == "*"){
            res *= stoi(v[i+1]);
        }
    }
    really_final = max(really_final, res);
}

void cal(int t, int k, int h){//괄호 여는 지 닫는 지 여부, idx시작하는 곳
    for(int i=k; i<n; i++){
        if(i%2 == 0){//짝수-->숫자이니까 닫거나 닫지 않는다.
            if(t == 1){
                if(i == n-1){
                    go();
                    return;
                }
                continue;
            }else{//닫을 차례-->h+3이면 무조건 닫는다.
                if(i == h+3 && i != n-1){
                    //무조건 닫는다.
                    bracket[i+1] = 2;
                    cal(1, i+1, i);
                    bracket[i+1] = 0;          
                }else if(i == h+3 && i == n-1){//n-1이면
                    bracket[i+1] = 2;
                    go();//계산한다.
                    bracket[i+1] = 0;
                    return;
                }
            }
        }else if(i%2 != 0){//홀수-->연산자 이니까 열거나 열지 않는다.
            if(t == 2){//닫을 차례
                if(i == n-1){
                    go();
                    return;
                }
                continue;
            }else{//열 차례
                //열거나 열지 않는다.
                if(i <= (n-4)){
                    for(int j=0; j<2; j++){
                        if(j == 0){//열지 않는다.
                            cal(1, i+1, i);
                        }else{//연다.
                            bracket[i+1] = 1;
                            cal(2, i+1, i);
                            bracket[i+1] = 0;
                        }
                    }                   
                }
            }
        }

    }
}

int main(){
    cin>>n;
    cin>>a;
    for(int i=0; i<2; i++){
        if(i == 0){
            cal(1, 0, 0);//1이라는 것은 괄호를 열 차례라는 것(맨 처음 괄호 추가x)
        }else{
            for(int j=0; j<20; j++){
                bracket[j] = 0;
            }
            bracket[0] = 1;
            cal(2, 0, -1);//괄호 닫을 차례
        }
    }
    cout<<really_final<<"\n";
}