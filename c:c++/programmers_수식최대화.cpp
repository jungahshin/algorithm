#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> num;
    vector<char> exp, location; // 연산자 종류, 연산자 위치
    
    string s = "";
    for(int i=0; i<expression.size(); i++){
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            num.push_back(stoi(s));
            s = "";
            
            if(find(exp.begin(), exp.end(), expression[i]) == exp.end()){
                exp.push_back(expression[i]);
            }
            location.push_back(expression[i]);
        }else{
            s += expression[i];
        }
    }
    
    num.push_back(stoi(s));
    sort(exp.begin(), exp.end());
    
    do {
        // 매번 계산한 위치를 지우고 하는 작업이 필요하기 때문에 임시 벡터가 필요하다.
        vector<char> tmp_loc = location;
        vector<long long> tmp_num = num;
        
        for(int i=0; i<exp.size(); i++){
            for(int j=0; j<tmp_loc.size(); j++){
                if(exp[i]==tmp_loc[j]){
                    if(exp[i]=='+'){
                        tmp_num[j] = tmp_num[j]+tmp_num[j+1];
                    } else if(exp[i]=='-'){
                        tmp_num[j] = tmp_num[j]-tmp_num[j+1];
                    } else{
                        tmp_num[j] = tmp_num[j]*tmp_num[j+1];
                    }
                    
                    // 계산한 부분 지우기
                    tmp_num.erase(tmp_num.begin()+j+1);
                    tmp_loc.erase(tmp_loc.begin()+j);
                    j--;
                }
            }
        }
        
        // 최대값 갱신
        answer = max(answer, abs(tmp_num[0]));
        
    } while(next_permutation(exp.begin(), exp.end()));
    
    
    return answer;
}