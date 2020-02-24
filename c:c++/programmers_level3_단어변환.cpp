//단어 변환
#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;
int visited[51] = {0, };
int final = INT_MAX;
vector<string> words_final;
bool check_final = false;

void check(int size, string temp, string target, int num){
    // cout<<"temp"<<temp<<"\n";
    // cout<<"num"<<num<<"\n";
    if(temp == target){
        // cout<<"in"<<temp<<"\n";
        final = min(final, num);
        check_final = true;
        return;
    }

    for(int i=0; i<words_final.size(); i++){
        int temp_num = 0;
        if(!visited[i]){
            for(int j=0; j<size; j++){
                if(words_final[i][j] != temp[j]){
                    temp_num++;
                }
            }        
            if(temp_num == 1){//하나만 다르면 변환 가능!
                visited[i] = 1;
                check(size, words_final[i], target, num+1);
                visited[i] = 0;
            }            
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words_final = words;
    check(begin.size(), begin, target, 0);
    if(check_final == false){//불가능한 경우
        answer = 0;
    }else{
        answer = final;
    }
    return answer;
}