//연구소3 복습
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int n, m;
int a[51][51] = {0, };
int a_copy[51][51] = {0, };
vector<pair<int, int>> virus;
int c_visited[11] = {0, };//choice의 visited
int visited[51][51] = {0, };
queue<pair<pair<int, int>, int>> a_virus;//활성 바이러스 위치
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = INT_MAX;
bool final_check = false;
int virus_num = 0;
int zero = 0;
int zero_copy = 0;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    zero_copy = zero;
}

void spread(){
    //a_virus 큐에 있는 활성 바이러스를 이제 퍼뜨린다.
    int temp = 0;
    copy();
    memset(visited, 0, sizeof(visited));
    while(!a_virus.empty()){
        int x = a_virus.front().first.first;
        int y = a_virus.front().first.second;
        int cnt = a_virus.front().second;
        a_virus.pop();
        visited[x][y] = 1;
        //모든 칸이 빈칸인지 확인...
        if(zero_copy == 0){
            final_check = true;
            final = min(final, temp);
            break;
        }

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                visited[final_x][final_y] = 1;
                if(a_copy[final_x][final_y] == 0 || a_copy[final_x][final_y] == -1){
                    if(a_copy[final_x][final_y] == 0){
                        zero_copy--;
                    }
                    a_copy[final_x][final_y] = cnt+1;
                    temp = max(temp, cnt+1);
                    a_virus.push(make_pair(make_pair(final_x, final_y), cnt+1));
                }
            }
        }
    }
}

//바이러스 위치 m개 선택하기
void choice(int idx, int num){
    if(num == m){
        while(!a_virus.empty()){
            a_virus.pop();
        }
        for(int i=0; i<virus_num; i++){
            if(c_visited[i] == true){
                a_virus.push(make_pair(make_pair(virus[i].first, virus[i].second), 0));
            }
        }
        spread();
        return;
    }

    for(int i=idx; i<virus_num; i++){
        if(c_visited[i] == true) continue;
        c_visited[i] = true;

        choice(i, num+1);
        c_visited[i] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){//활성 바이러스
                virus_num++;
                virus.push_back(make_pair(i, j));
                a[i][j] = -1;
            }else if(a[i][j] == 1){//벽
                a[i][j] = -2;
            }else if(a[i][j] == 0){
                zero++;
            }
        }
    }
    if(virus_num == 0){
        cout<<"0"<<"\n";
        return 0;
    }
    choice(0, 0);
    if(final_check == true){
        cout<<final<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
    return 0;
}