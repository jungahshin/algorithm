//연구소3 복습
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int n, m;
int lab[51][51] = {0, };
vector<pair<int, int>> virus;//바이러스를 놓을 수 있는 위치
vector<pair<int, int>> real_virus;//퍼뜨릴 바이러스 위치
int visited[11] = {0, };
int visited_spread[51][51] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = INT_MAX;
int zero = 0;
int max_final = 0;
int zero_num = 0;

//0-빈칸, 1-벽, 2-바이러스
//바이러스 최대 10개

void spread(){
    zero_num = zero;
    max_final = 0;
    memset(visited_spread, 0, sizeof(visited_spread));
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<real_virus.size(); i++){
        q.push(make_pair(make_pair(real_virus[i].first, real_virus[i].second), 0));
    }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int sec = q.front().second;
        visited_spread[x][y] = 1;
        q.pop();

        max_final = max(max_final, sec);

        if(lab[x][y] == 0){
            zero_num--;
        }

        if(zero_num == 0){
            break;
        }

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited_spread[final_x][final_y]){
                if(lab[final_x][final_y] == 0 || lab[final_x][final_y] == 2){
                    visited_spread[final_x][final_y] = 1;
                    q.push(make_pair(make_pair(final_x, final_y), sec+1));
                }
            }
        }
    }
}

void choose(int idx, int num){
    if(num == m){
        real_virus.clear();
        for(int i=0; i<virus.size(); i++){
            if(visited[i] == true){
                real_virus.push_back(make_pair(virus[i].first, virus[i].second));
            }
        }
        spread();
        if(zero_num == 0){//다 번졌다.
            final = min(final, max_final);
        }
        return;
    }

    for(int i=idx; i<virus.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        choose(i, num+1);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>lab[i][j];
            if(lab[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }else if(lab[i][j] == 0){
                zero++;
            }
        }
    }
    choose(0, 0);
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}