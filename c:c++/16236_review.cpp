//아기상어 복습
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, t;
int a[21][21] = {0, };
vector<pair<pair<int, int>, int>> shark;
vector<pair<int, pair<int, int>>> can_eat;//먹을 수 있는 물고기 위치 저장
vector<pair<pair<int, int>, int>> same;
int time_final = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void check(){//dist, 위치까지 같이 저장해줘야한다!!(먹을 수 있는 물고기 위치랑 거리까지!)
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(shark[0].first.first, shark[0].first.second)));
    can_eat.clear();
    int visited[21][21] = {0, };
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        visited[x][y] = 1;

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny]){
                visited[nx][ny] = 1;
                if(a[nx][ny] == 0 || a[nx][ny] == shark[0].second){//지나갈 수 있다.
                    q.push(make_pair(dist+1, make_pair(nx, ny)));
                }else if(a[nx][ny] < shark[0].second){//먹을 수 있고 지나갈 수 있다.
                    can_eat.push_back(make_pair(dist+1, make_pair(nx, ny)));
                    q.push(make_pair(dist+1, make_pair(nx, ny)));
                }
            }
        }
    }
}

void eat(){
    int num = 0;
    while(1){
        //상어와의 위치를 재기
        check();
        if(can_eat.size() == 0){//더이상 먹을 수 있는 물고기가 없다.
            break;
        }
        same.clear();
        //거리로 정렬
        sort(can_eat.begin(), can_eat.end());
        for(int i=0; i<can_eat.size(); i++){
            if(can_eat[0].first == can_eat[i].first){
                same.push_back(make_pair(make_pair(can_eat[i].second.first, can_eat[i].second.second), can_eat[i].first));
            }
        }
        //행,열 정렬
        sort(same.begin(), same.end());//가장 왼쪽[0]을 먹는다.
        //그 위치의 a배열 0값으로 만들고
        a[same[0].first.first][same[0].first.second] = 0;
        //시간은 잡아먹은 물고기와의 거리만큼 지난다.
        time_final += same[0].second;
        //아기상어의 위치가 잡아먹은 물고기의 위치가 된다.
        shark[0].first.first = same[0].first.first;
        shark[0].first.second = same[0].first.second;
        // 물고기 먹은 개수
        num++;
        //num이 자신의 크기만큼 되면, 자신의 크기 +1해주고 num=0으로 초기화해준다.
        if(num == shark[0].second){
            shark[0].second++;
            num = 0;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> t;
            if(t == 9){//아기 상어
                shark.push_back(make_pair(make_pair(i, j), 2));
            }else{
                a[i][j] = t;
            }
        }
    }
    eat();
    cout<<time_final<<"\n";
}