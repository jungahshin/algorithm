//좋은 수열
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int n;
string final;
bool real = false;
map<string, int> m;

//일단, 수를 만들어놓고 그 7자리수가 좋은 수열인지 아닌지 판별한다.

bool check(string s){
    //문자열의 길이만큼 연속된 부분수열이 있는지 판별
    bool temp = true;
    for(int i=0; i<s.size(); i++){
        int idx = i;
        for(int j=1; j<=s.size(); j++){
            int size = j;
            for(int k=i; k<s.size(); k++){//돌면서 size만큼 연속된 문자를 비교
                if(k+size*2-1<s.size()){
                    int a = k;
                    int b = k+size;
                    string temp_a = "";
                    string temp_b = "";
                    for(int t=0; t<size; t++){
                        temp_a += s[a+t];
                    }
                    for(int t=0; t<size; t++){
                        temp_b += s[b+t];
                    }
                    if(temp_a == temp_b){//좋지 않은 수열
                        temp = false;
                        break;
                    }
                }
            }
            if(temp == false){
                break;
            }
        }
        if(temp == false){
            break;
        }
    }
    return temp;
}

void go(string s, int num){
    if(final != ""){
        return;
    }
    if(check(s) == true){//좋은 수열이면...!
        if(num == n){
            final = s;
            return;
        }
    }else{
        return;
        if(num == n){
            return;
        }
    }
    for(int i=1; i<=3; i++){
        go(s+to_string(i), num+1);
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=3; i++){
        go(to_string(i), 1);
    }
    cout<<final<<"\n";
}