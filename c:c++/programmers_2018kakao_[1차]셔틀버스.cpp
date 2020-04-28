#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int, int>> wait;

//같은 시간대에 인원이 남는 경우->딱 그 시간에 선다
//인원이 꽉차서 중간에 들어가야 하는 경우-> 가장 마지막 타임의 마지막 순서였던 사람의 시간 (분-1)
//23:59의 경우 거른다....

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    for(int i=0; i<timetable.size(); i++){
        string temp = "";
        string h = "";//시
        string m = "";//분
        int H, M;
        for(int j=0; j<timetable[i].size(); j++){
            if(timetable[i][j] == ':'){
                h = temp;
                temp = "";
            }else{
                temp += timetable[i][j];
                if(j == timetable[i].size()-1){
                    m = temp;
                }
            }
        }
        //h, m모두 int로 바꿔주고 넣기!!!!!
        stringstream ss1(h);
        ss1 >> H;
        stringstream ss2(m);
        ss2 >> M;
        wait.push_back(make_pair(H, M));
    }
    sort(wait.begin(), wait.end());
    //셔틀이 처음 시작하는 시간
    int start_h = 9;
    int start_m = 0;
    int final_h, final_m;
    int idx = 0;//wait벡터의 idx
    bool check = false;
    for(int i=0; i<n; i++){
        if(idx == wait.size()){//더 이상 기다리는 사람이 없어 시간만 흐른다.
            check = true;
            start_m += t;
            if(start_m >= 60){
                start_m -= 60;
                start_h += 1;
            }
            continue;
        }
        int temp_idx = idx;
        int temp = 0;//타는 사람 수
        for(int k=temp_idx; k<wait.size(); k++){
            if(wait[k].first<=start_h){
                if(wait[k].first == start_h){
                    if(wait[k].second>start_m){
                        continue;
                    }
                }
                temp++;
                final_h = wait[k].first;
                final_m = wait[k].second;
                idx++;
            }else{
                break;
            }
            if(temp == m){
                break;
            }
        }
        if(temp<m){
            check = true;
        }else{
            check = false;
        }
        
        if(i == n-1){
            break;
        }
        //맨 마지막에 다음 타임 시간 계산
        start_m += t;
        if(start_m >= 60){
            start_m -= 60;
            start_h += 1;
        }
    }
    if(check == true){//사람보다 차가 많이 다녀서 그냥 맨 마지막 타임에 타기
        string s1 = "";
        string s2 = "";
        if(start_h>=10){
            s1 = to_string(start_h);
        }else{
            s1 += '0';
            s1 += to_string(start_h);
        }
        if(start_m>=10){
            s2 = to_string(start_m);
        }else{
            s2 += '0';
            s2 += to_string(start_m);
        }
        answer += s1+':'+s2;
    }else{//사람들 중간에 껴서 타기-> 맨 마지막 타임 맨 마지막 사람(분-1)
        if(final_m == 0){
            final_h -= 1;
            final_m = 60;
        }
        string s1 = "";
        string s2 = "";
        if(final_h>=10){
            s1 = to_string(final_h);
        }else{
            s1 += '0';
            s1 += to_string(final_h);
        }
        if(final_m-1>=10){
            s2 = to_string(final_m-1);
        }else{
            s2 += '0';
            s2 += to_string(final_m-1);
        }
        answer += s1+':'+s2;
    }
    return answer;
}