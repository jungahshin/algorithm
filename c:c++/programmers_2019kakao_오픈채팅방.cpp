#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> result;//uid, nick
vector<string> han;//문구
map<string, string> nick;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string temp;
        string final1 = "";
        string final2 = "";
        string final3 = "";
        int num = 0;
        while(ss >> temp){
            num++;
            bool change = false;
            if(num == 1){
                final1 = temp;
            }else if(num == 2){//유저 아이디
                final2 = temp;
            }else if(num == 3){//닉네임
                final3 = temp;
            }
        }
        if(final1 == "Enter"){
            nick[final2] = final3;
            result.push_back(final2);
            han.push_back("님이 들어왔습니다.");
        }else if(final1 == "Leave"){
            result.push_back(final2);
            han.push_back("님이 나갔습니다.");
        }else if(final1 == "Change"){
            nick[final2] = final3;
        }
    }
    
    for(int i=0; i<result.size(); i++){
        answer.push_back(nick[result[i]] + han[i]);
    }
    
    return answer;
}