#include <string>
#include <vector>
#include <iostream>

using namespace std;
int traffic[86400001] = {0, };//가장 최대가 24시니까

int go(string s){
    bool check = false;
    int num = 0;
    int total = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '.'){
            check = true;
        }else{
            if(check == true){
                num++;
                if(num == 1){//*100
                    total += (100*(s[i]-'0'));
                }else if(num == 2){
                    total += (10*(s[i]-'0'));
                }else if(num == 3){
                    total += (1*(s[i]-'0'));
                }
            }else{
                total += (1000*(s[i]-'0'));
            }
        }
    }
    return total;
}

int solution(vector<string> lines) {
    int answer = 0;
    for(int i=0; i<lines.size(); i++){
        //시작시간과 끝시간을 구하는 작업
        string temp = "";
        string s2 = "";//처리 시간
        bool check = false;
        for(int j=0; j<lines[i].size(); j++){
            if(lines[i][j] == ' '){
                check = true;
                temp = "";
            }else{
                if(check == true){
                    if(lines[i][j] == 's'){
                        s2 = temp;
                        break;
                    }
                    temp += lines[i][j];
                }
            }
        }
        int h = stoi(lines[i].substr(11, 2));
        int m = stoi(lines[i].substr(14, 2));
        int s = stoi(lines[i].substr(17, 2));
        int d = stoi(lines[i].substr(20, 3));
        int term = go(s2);
        //traffic[i]는 i~i+999까지 해당되는 트래픽들의 수를 넣는 것!
        //따라서 트래픽의 start지점의 -999부터 효력이 생긴다.
        int end = h*3600000+m*60000+s*1000+d;
        int start = end-term+1-999;
        if(start<0){
            start = 0;
        }
        if(end>86400000){
            end = 86400000;
        }
        
        for(int k=start; k<=end; k++){
            traffic[k]++;
        }
    }

    for(int i=0; i<=86400000; i++){
        answer = max(answer, traffic[i]);
    }
    return answer;
}