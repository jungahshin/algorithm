#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<pair<int, int>> v;//각 로그들의 시작시간과 끝 시간을 저장

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

int main(vector<string> lines) {
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
        int end = h*3600000+m*60000+s*1000+d;
        int start = end-term+1;
        if(start<0){
            v.push_back(make_pair(0, end));
        }else{
            v.push_back(make_pair(start, end));
        }
    }
    
    int a = v[0].first;//맨 처음 시작 시간
    while(1){
        int total_num = 0;
        if(a>v[v.size()-1].second){
            break;
        }
        for(int i=0; i<v.size(); i++){
            if((a<=v[i].first && v[i].first<=a+999) || (v[i].first<=a && a+999<=v[i].second) || (a<=v[i].second && v[i].second<=a+999)){
                total_num++;
            }
        }
        answer = max(answer, total_num);
        a ++;
    }
    
    return answer;
}