//소문난 칠공주
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

string s;
char classroom[6][6];
vector<pair<int, int>> dasom;
vector<pair<int, int>> all;
int visited[6][6] = {0, };
int visited_all[26] = {0, };
int final = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//이문제는 bfs로도, dfs로도 풀 수 없는 문제이다...!
//결국, 조합으로 25개의 경우 중에 7개를 뽑는 경우를 세고 각각의 경우가 1)이다솜파가 4명이상인지, 2)모두 인접하는지 판단하면 된다.

bool check(){//이다솜파가 4명이상인지 확인
    bool check_temp = false;
    int num_temp = 0;
    for(int i=0; i<dasom.size(); i++){
        if(classroom[dasom[i].first][dasom[i].second] == 'S'){
            num_temp++;
        }
    }
    if(num_temp >= 4){
        check_temp = true;
    }

    return check_temp;
}

//모두 인접하는지 확인하는 함수
bool bfs(){
    bool check_temp = false;
    queue<pair<int, int>> q;
    q.push(make_pair(dasom[0].first, dasom[0].second));
    int num_temp = 0;

    while(!q.empty()){
        num_temp++;
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;
        q.pop();

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<5 && 0<=final_y && final_y<5 && !visited[final_x][final_y]){
                bool temp = false;
                for(int j=0; j<dasom.size(); j++){
                    if((dasom[j].first == final_x) && (dasom[j].second == final_y)){
                        temp = true;
                        break;
                    }
                }
                if(temp == true){
                    visited[final_x][final_y] = 1;
                    q.push(make_pair(final_x, final_y));
                }
            }
        }
    }

    if(num_temp == 7){
        check_temp = true;
    }

    return check_temp;
}

void choose(int idx, int num){
    if(num == 7){
        dasom.clear();
        for(int i=0; i<all.size(); i++){
            if(visited_all[i] == true){
                dasom.push_back(make_pair(all[i].first, all[i].second));
            }
        }
        memset(visited, 0, sizeof(visited));
        if(check()){//이다솜파의 수가 4명이상이고 모두 인접한다면
            if(bfs()){
                final++;
            }
        }
        return;
    }

    for(int i=idx; i<all.size(); i++){
        if(visited_all[i]) continue;
        visited_all[i] = true;

        choose(i, num+1);
        visited_all[i] = false;
    }
}

int main(){
    for(int i=0; i<5; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            classroom[i][j] = s[j];
            all.push_back(make_pair(i, j));
        }
    }
    choose(0, 0);
    cout<<final<<"\n";
    return 0;
}