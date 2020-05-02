#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
map<string, int> m;
vector<int> final;

vector<int> solution(string msg) {
    vector<int> answer;
    for(int i=1; i<=26; i++){
        string s = "";
        char alphabet = i+'A'-1;
        m[s+alphabet] = i;
    }
    int num = 27;
    for(int i=0; i<msg.size(); i++){
        string temp = "";
        int temp_num = 0;
        bool check = false;
        for(int j=i; j<msg.size(); j++){
            temp += msg[j];
            if(m.count(temp) == 0){
                //사전 추가
                m[temp] = num++;
                i = j-1;
                break;
            }else{
                temp_num = m[temp];
            }
            if(j == msg.size()-1){
                check = true;
            }
        }
        final.push_back(temp_num);
        if(check == true){
            break;
        }
    }
    answer = final;
    return answer;
}