//괄호 추가하기(복습)
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int n;
string s;
int bracket[21] = {0, };//여는 괄호->1, 닫는 괄호->2
int final = -(INT_MAX);//마지막 최종 계산한 값(최대값 출력)

void go(){
    queue<char> q;
    if(bracket[0] == 1){
        q.push('(');
    }
    for(int i=0; i<n; i++){
        q.push(s[i]);
        if(bracket[i+1] == 1){//여는
            q.push('(');
        }else if(bracket[i+1] == 2){//닫는
            q.push(')');
        }
    }

    //이제 본격 계산해주기!!!
    int total_num = -(INT_MAX);
    int num = 0;
    vector<int> v_total;//숫자들만 들어있어
    vector<char> v_cal;//연산자만 들어있어
    while(!q.empty()){
        char temp = q.front();
        q.pop();
        if(temp == '('){
            num = 0;
            vector<char> v;
            char temp_2 = temp;
            while(1){
                temp_2 = q.front();
                if(temp_2 == ')'){
                    q.pop();
                    break;
                }
                v.push_back(temp_2);
                q.pop();
            }
            //v에 있는 값들 계산하기
            if(v[1] == '+'){
                num = (v[0]-'0')+(v[2]-'0');
            }else if(v[1] == '-'){
                num = (v[0]-'0')-(v[2]-'0');
            }else if(v[1] == '*'){
                num = (v[0]-'0')*(v[2]-'0');
            }
            v_total.push_back(num);
        }else{
            if(temp == '+' || temp == '-' || temp == '*'){
                v_cal.push_back(temp);
            }else{
                v_total.push_back(temp-'0');
            }
        }
    }

    int cal_1 = 0;
    int cal_2 = 0;
    cal_1 = v_total[0];
    for(int i=0; i<v_cal.size(); i++){
        // cal_1 = v_total[i];
        cal_2 = v_total[i+1];
        if(v_cal[i] == '+'){
            total_num = cal_1+cal_2;
            cal_1 = total_num;
        }else if(v_cal[i] == '*'){
            total_num = cal_1*cal_2;
            cal_1 = total_num;
        }else if(v_cal[i] == '-'){
            total_num = cal_1-cal_2;
            cal_1 = total_num;
        }
    }
    final = max(final, total_num);
}

void add(int x, int y, int z){
    for(int i=x; i<=n; i++){
        if(i%2 != 0){//홀수->닫는 타임
            if(i==1 || y==1){//idx가 1이거나 여는 타임이면
                if(i==n){
                    go();
                    return;
                }
                continue;
            }else{
                if(i==z+3 && y==2){//무조건 닫아야한다
                    bracket[i] = 2;
                    if(i==n){
                        go();//마지막 idx니까 계산한다.
                        bracket[i] = 0;
                        return;
                    }else{
                        add(i+1, 1, i);
                        bracket[i] = 0;
                    }
                }
            }
        }else if(i%2 == 0){//짝수->여는 타임
            if(i==(n-1) || y==2){
                continue;
            }else{//그냥 열거나 열지 않는다.
                //열지 않는다
                add(i+1, 1, i);
                //연다
                bracket[i] = 1;
                add(i+1, 2, i);
                bracket[i] = 0;
            }
        }
    }
}

int main(){
    cin>>n;
    cin>>s;
    if(n == 1){
        cout<<s<<"\n";
        return 0;
    }
    add(0, 1, 0);//아무 괄호도 없는 상태(이제 열어야하는)
    bracket[0] = 1;
    add(0, 2, 0);//여는 괄호를 하나 추가한 상태(이제 닫아야하는)
    cout<<final<<"\n";
    return 0;
}