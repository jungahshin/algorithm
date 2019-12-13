//연구소
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a[9][9] = {0, };
int a_copy[9][9] = {0, };
vector<pair<int, int>> virus;
vector<pair<int, int>> none;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[70] = {0, };
int visited_virus[9][9] = {0, };
int final = 0;

void spread(){//모든 바이러스 번지기
    queue<pair<int, int>> q;
    for(int i=0; i<virus.size(); i++){
        q.push(make_pair(virus[i].first, virus[i].second));
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited_virus[x][y] = 1;

        for(int j=0; j<4; j++){
            int final_x = dx[j] + x;
            int final_y = dy[j] + y;
            if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                if(a_copy[final_x][final_y] == 0 && !visited_virus[final_x][final_y]){
                    visited_virus[final_x][final_y] = 1;
                    a_copy[final_x][final_y] = 2;
                    q.push(make_pair(final_x, final_y));
                }
            }
        }
    }
    
    //0의 개수 세기
    int num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_copy[i][j] == 0){
                num++;
            }
        }
    }
    
    final = max(final, num);
}

void copy(){//새롭게 none벡터에 visited가 1인 위치를 a_copy에서 1로 만들어주기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    for(int i=0; i<none.size(); i++){
        if(visited[i] == true){
            a_copy[(none[i].first)][(none[i].second)] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited_virus[i][j] = 0;
        }
    }    
    spread();
}

void wall(int num, int index){//벽 3개 세우기(none 벡터에 있는 것들 중에 3개 선택->조합)
    if(num == 3){
        copy();
        return;
    }

    for(int i=index; i<none.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        wall(num+1, i);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){//바이러스
                virus.push_back(make_pair(i, j));
            }else if(a[i][j] == 0){//빈 공간
                none.push_back(make_pair(i, j));
            }
        }
    }
    wall(0, 0);
    cout<<final<<"\n";
}