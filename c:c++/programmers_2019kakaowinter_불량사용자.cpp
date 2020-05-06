#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
int answer = 0;
map<int, int> m;

bool go(string banned, string user){//일치하는지 여부 판단
    bool temp = true;
    if(banned.size() != user.size()){
        temp = false;
        return temp;
    }
    for(int i=0; i<banned.size(); i++){
        if(banned[i] == '*'){
            continue;
        }
        if(banned[i] != user[i]){
            temp = false;
        }
    }
    return temp;
}

void dfs(int idx, int size, int num, vector<int> v[9]){//banner_id의 idx, size, 방문 비트마스크, v
    if(size == idx){
        if(m.count(num) == 0){
            answer++;
            m[num] = 1;
        }
        return;
    }
    
    for(int i=0; i<v[idx].size(); i++){
        if((num & (1<<v[idx][i])) != 0){//이미 방문했다.
            continue;
        }
        int temp = (num | (1<<v[idx][i]));
        dfs(idx+1, size, temp, v);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    vector<int> v[9];
    for(int i=0; i<banned_id.size(); i++){
        for(int j=0; j<user_id.size(); j++){
            if(go(banned_id[i], user_id[j]) == true){
                v[i].push_back(j);
            }
        }    
    }
    dfs(0, banned_id.size(), 0, v);
    return answer;
}