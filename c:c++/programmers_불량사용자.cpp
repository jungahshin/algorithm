// 불량 사용자
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int visited[500] = {0, }; // user_id 방문 여부


bool check(string u_str, string b_str)
{
    if(u_str.size()!=b_str.size()){
        return false;
    }

    int idx = 0;
    bool check = true;
    
    while(idx<u_str.size()){
        if(b_str[idx]=='*'){
            idx++;
            continue;
        }
        if(b_str[idx]!=u_str[idx]){
            check = false;
        }
        idx++;
    }

    return check;
}

void dfs(int idx, int size, int bitmask, vector<int> v[9])
{
    if(idx==size){
        if(visited[bitmask]==0){
            visited[bitmask] = 1;
            answer++;
        }
        return;
    }

    for(int i=0; i<v[idx].size(); i++){
        if((bitmask & (1<<v[idx][i]))!=0){ // 이미 사용한 사용자이다.
            continue;
        }
        int temp = (bitmask | (1<<v[idx][i]));
        dfs(idx+1, size, temp, v);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> v[9];

    for(int i=0; i<user_id.size(); i++){
        for(int j=0; j<banned_id.size(); j++){
            if(!check(user_id[i], banned_id[j])) continue;
            v[j].push_back(i);
        }
    }

    dfs(0, banned_id.size(), 0, v);
    return answer;
}