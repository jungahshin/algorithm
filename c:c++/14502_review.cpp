//연구소시리즈 복습
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[9][9] = {0, };
int a_copy[9][9] = {0, };
queue<pair<int, int>> q;
vector<pair<int, int>> v;
vector<pair<int, int>> wall;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int safe = 0;
bool visited_[65];
int n,m;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
}

void spread(){//바이러스 퍼뜨리기
    int visited[9][9] = {0, };
    for(int i=0; i<v.size(); i++){//초기 바이러스 넣어주기
        q.push(make_pair(v[i].first, v[i].second));
    }

    while(!q.empty()){//바이러스가 다 없을 때까지
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = 1;

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
                visited[nx][ny] = 1;
                if(a_copy[nx][ny] == 0){//바이러스 전염
                    a_copy[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int temp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_copy[i][j] == 0){
                temp+=1;//안전영역
            }
        }
    }
    safe = max(safe, temp);
}

void put(){//copy해놓은 a_copy에 벽 위치 넣기
    copy();
    for(int i=0; i<wall.size(); i++){
        if(visited_[i] == true){
            a_copy[wall[i].first][wall[i].second] = 1;
        }
    }
    spread();
}

void make_wall(int idx, int num){//벽 3개 세우기 0->1로 바꾸기
    //벽 3개 세우기(wall)
    if(num == 3){
        put();
        return;
    }

    for(int i=idx; i<wall.size(); i++){
        if(visited_[i] == true) continue;
        visited_[i] = true;

        make_wall(i, num+1);
        visited_[i] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){//바이러스는 따로 벡터에 저장
                v.push_back(make_pair(i, j));
            }else if(a[i][j] == 0){//빈칸도 따로 저장->벽 세울때 쓰기
                wall.push_back(make_pair(i, j));
            }
        }
    }
    make_wall(0, 0);
    cout<<safe<<"\n";
    return 0;
}