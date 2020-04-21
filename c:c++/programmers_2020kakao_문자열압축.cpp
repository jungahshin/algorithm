#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;
vector<string> v;

int solution(string s) {
    if(s.size() == 1){
        return 1;
    }
    int answer = INT_MAX;
    for(int i=1; i<s.size(); i++){//문자열을 압축할 수 있는 방법만큼 수행
        int num = 0;
        string temp1 = "";
        for(int j=0; j<s.size(); j++){//문자 전체를 돌면서 압축 실행
            num++;
            temp1 += s[j];
            if(num == i){
                num = 0;
                v.push_back(temp1);
                temp1 = "";
            }else{
                if(j == s.size()-1){
                    v.push_back(temp1);
                }
            }
        }
        int temp_num = 1;
        int final = 0;
        bool check = false;
        for(int j=0; j<v.size()-1; j++){
            if(v[j] == v[j+1]){
                check = true;
                temp_num++;
                if(j == v.size()-2){
                    final += v[j].size();
                    if(temp_num<10){
                        final += 1;
                    }else if(temp_num<100){
                        final += 2;
                    }else if(temp_num<1000){
                        final += 3;
                    }
                }
            }else{
                if(check == true){//그 전까지 같았다.
                    final += v[j].size();
                    if(temp_num<10){
                        final += 1;
                    }else if(temp_num<100){
                        final += 2;
                    }else if(temp_num<1000){
                        final += 3;
                    }
                    if(j == v.size()-2){
                        final += v[j+1].size();
                    }
                }else{
                    //그냥 더해
                    final += v[j].size();
                    if(j == v.size()-2){
                        //맨 마지막 문자까지 더해주기
                        final += v[j+1].size();
                    }
                }
                check = false;
                temp_num = 1;
            }
        }
        v.clear();
        answer = min(final, answer);
    }
    return answer;
}