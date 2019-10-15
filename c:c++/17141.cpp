//연구소 시리즈 복습
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int a[51][51] = {0, };
int a_copy[51][51] = {0, };
vector<pair<int, int>> v;
queue<pair<pair<int, int>, int>> q;
bool visited[11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
// vector<int> min_time;
int final = INT_MAX;
int n,m;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_copy[i][j] = a[i][j];
        }
    }
}

void spread(){//바이러스 퍼짐
    int visited[51][51] = {0, };
    int temp = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        visited[x][y] = 1;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny]){
                visited[nx][ny] = 1;
                if(a_copy[nx][ny] == 0){
                    a_copy[nx][ny] = 2;
                    q.push(make_pair(make_pair(nx, ny), time+1));
                }
            }
        }
        temp = max(temp, time);
    }
    //0의 개수세기-->0이 없으면 min_time벡터에 넣고, 최종적으로 min_time에 들어 있는 것이 없으면 어떠한 조합으로도 다 퍼뜨릴 수 없다는 것->-1출력
    int temp_ = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a_copy[i][j] == 0){
                temp_++;
            }
        }
    }
    if(temp_ == 0){//min_time에 넣기
        final = min(final, temp);
    }
}

void put(){
    copy();

    for(int i=0; i<v.size(); i++){
        if(visited[i] == true){
            //2값을 넣기
            a_copy[v[i].first][v[i].second] = 2;//진짜 바이러스
            q.push(make_pair(make_pair(v[i].first, v[i].second), 0));
        }else if(visited[i] == false){
            //0값을 넣기
            a_copy[v[i].first][v[i].second] = 0;//벽으로 만든다.
        }
    }
    spread();
}

void choose(int idx, int num){
    if(num == m){
        //위치에 바이러스 넣기
        put();
        return;
    }
    for(int i=idx; i<v.size(); i++){
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
            cin>>a[i][j];
            if(a[i][j] == 2){
                v.push_back(make_pair(i,j));
            }
        }
    }
    choose(0, 0);
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}