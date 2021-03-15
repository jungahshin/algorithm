#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
long long check[360001] = {0, };
 
int time_to_sec(string s){
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));
    int Time = hour*3600+min*60+sec;
    
    return Time;
}
 
string sec_to_time(int n){
    string ret="";
     int s = n%60; n/=60;
    int m = n%60; n/=60;
    int h = n;
 
    if(h<10) ret+="0";
    ret+=to_string(h);
    ret+=":";
 
    if(m<10) ret+="0";
    ret+=to_string(m);
    ret+=":";
 
    if(s<10) ret+="0";
    ret+=to_string(s);
 
    return ret;
}
 
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int Terminate = time_to_sec(play_time); // 광고 끝나는 시간
    
    if(play_time==adv_time){
        return sec_to_time(0);
    }
    
    for(int i=0; i<logs.size(); i++){
        string T = logs[i];
        int STime = time_to_sec(T.substr(0, 8));
        int ETime = time_to_sec(T.substr(9, 8));
        check[STime]++;
        check[ETime]--;
    }
    
    // 재생수 계산
    for(int i=1; i<=Terminate; i++){
        check[i] += check[i-1];
    }
    
    // 누적재생수 계산
    for(int i=0; i<=Terminate; i++){
        check[i] += check[i-1];
    }
    
    int StartTime = 0;
    long long Max = 0;
    int term = time_to_sec(adv_time);
    for(int i=0; i<=Terminate; i++){
        int mid = i;
        long long Emid = mid+term;
        if(Emid>Terminate){
            Emid = Terminate;
        }
        if((check[Emid]-check[mid])>Max){
            Max = check[Emid]-check[mid];
            StartTime = mid+1;
        }
    }
    
    answer = sec_to_time(StartTime);
    
    return answer;
}