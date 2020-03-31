#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<vector<string>> relation_;
vector<vector<int>> nope;//후보키인 것들 모음->뒤에 조합 걸러내기 위해
vector<int> final;//단일 후보키가 아닌 컬럼
vector<int> combin;//조합
int row = 0;
int column = 0;
int visited[10] = {0, };
int answer = 0;

void go(){
    map<string, int> check;
    bool temp = true;
    for(int i=0; i<row; i++){
        string s = "";
        for(int j=0; j<combin.size(); j++){
            s += relation_[i][combin[j]];
        }  
        if(check.count(s) == 0){
            check[s] = 1;
        }else{//이미 있다.(후보키가 될 수 없다.)
            temp = false;
            break;
        }
    }
    vector<int> really_temp;
    if(temp == true){//후보키 가능
        for(int j=0; j<combin.size(); j++){
            really_temp.push_back(combin[j]);
        }  
        nope.push_back(really_temp);
        answer++;
    }
}

void choose(int idx, int num, int final_num){
    if(final_num == num){
        combin.clear();
        bool check = true;
        for(int t=0; t<final.size(); t++){
            if(visited[t] == true){
                combin.push_back(final[t]);
            }
        }
        for(int j=0; j<nope.size(); j++){
            int temp = nope[j].size();
            int temp_num = 0;
            for(int t=0; t<nope[j].size(); t++){
                for(int r=0; r<combin.size(); r++){
                    if(nope[j][t] == combin[r]){
                        temp_num++;
                    }
                }
            }
            if(temp_num == temp){//못해
                check = false;
                break;
            }
        }
        if(check == true){//가능
            go();            
        }
        return;
    }
    
    for(int i=idx; i<final.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        
        choose(i, num+1, final_num);
        visited[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    relation_ = relation;
    row = relation.size();
    column = relation[0].size();
    
    for(int i=0; i<column; i++){//열마다 단일 후보키인지 확인
        map<string, int> check;
        bool temp = true;
        for(int j=0; j<row; j++){
            if(check.count(relation[j][i]) == 0){
                check[relation[j][i]] = 1;
            }else{//동일한 값이 들어왔다.->단일 후보키가 아니다.
                temp = false;
                break;
            }
        }
        if(temp == false){//단일 후보키가 아니다.
            final.push_back(i);
        }else{//후보키 가능
            answer++;
        }
    }
        
    for(int i=1; i<final.size(); i++){//열
        choose(0, 0, i+1);
    }
    
    return answer;
}