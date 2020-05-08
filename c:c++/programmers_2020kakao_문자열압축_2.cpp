#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;
vector<string> v;//자른 단위를 벡터에 저장 후 처리.
int answer = INT_MAX;

void cal(){//v벡터에 있는 단위들 중복체크 후 최종 문자열 생성하고 길이 체크
    int num = 1;
    string final = "";
    for(int i=1; i<v.size(); i++){
        if(v[i] == v[i-1]){
            num++;
            if(i == v.size()-1){
                final += to_string(num);
                final += v[i-1]; 
            }
        }else{
            if(num == 1){
                final += v[i-1];
                num = 1;
            }else{
                final += to_string(num);
                final += v[i-1];     
                num = 1;
            }
            if(i == v.size()-1){
                final += v[i];
            }
        }
    }
    if(v.size()==1){
        final += v[0];
    }
    int temp_num = final.size();
    answer = min(answer, temp_num);
}

void go(int num, string s){//문자열s를 num단위로 압축,,
    int temp = 0;
    int total = 0;//몇 개의 단위가 축적되는지 센다.
    string temp_s = "";
    for(int i=0; i<s.size(); i++){
        temp++;
        temp_s += s[i];
        if(temp == num){
            //앞의 문자와 동일한지 비교...
            v.push_back(temp_s);
            temp = 0;
            temp_s = "";
            total++;
        }else if(i == s.size()-1){
            v.push_back(temp_s);
        }
    }
    cal();
}

int solution(string s) {
    //원래 문자열의 길이 만큼 쭉 완탐으로 압축 진행
    for(int i=1; i<=s.size(); i++){
        v.clear();
        go(i, s);
    }
    return answer;
}