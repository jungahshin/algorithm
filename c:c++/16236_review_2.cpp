//아기상어(복습)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[21][21] = {0, };
int shark_x, shark_y, shark_size = 0;
int num = 0;//잡아먹은 물고기 수
int final_time = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[21][21] = {0, };
vector<pair<int, pair<int, int>>> fish;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    //행, 다음 열 순으로 정렬
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void go(){
    while(1){
        memset(visited, 0, sizeof(visited));
        fish.clear();
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(shark_x, shark_y), 0));
        bool check = false;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time_ = q.front().second;//지나간 칸 수(=걸린 시간)
            visited[x][y] = 1;
            q.pop();

            if(a[x][y] < shark_size && a[x][y] != 0){//먹을 수 있다. -> vector에 모아둔다.
                check = true;
                //벡터에 위치와 이동 시간 모두 저장한다->sort
                //그 중에 가장 앞에 있는 물고기를 먹는다 ->num++ && a배열에서 위치 값을 0으로 && 상어의 위치를 그 위치로 update && break!!
                fish.push_back(make_pair(time_, make_pair(x, y)));
            }

            for(int i=0; i<4; i++){
                int final_x = x+dx[i];
                int final_y = y+dy[i];
                if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                    visited[final_x][final_y] = 1;
                    if(a[final_x][final_y] <= shark_size){//자기와 같거나 작은 곳에만 지나갈 수 있다.
                        q.push(make_pair(make_pair(final_x, final_y), time_+1));
                    }
                }
            }
        }        
        if(check == false){//한 마리도 먹을 수 있는 물고기가 없는 경우...
            break;
        }
        //일단 시간순으로 정렬
        sort(fish.begin(), fish.end()); 
        vector<pair<int, int>> temp;
        int time_temp = fish[0].first;
        for(int k=0; k<fish.size(); k++){
            if(fish[0].first == fish[k].first){
                temp.push_back(make_pair(fish[k].second.first, fish[k].second.second));
            }
        }
        //temp를 정렬한다.
        sort(temp.begin(), temp.end(), compare);
        //잡아먹은 물고기 수++
        num++;
        if(num == shark_size){
            shark_size++;
            num = 0;
        }
        //이동 시간 증가+
        final_time += time_temp;
        a[temp[0].first][temp[0].second] = 0;
        shark_x = temp[0].first;
        shark_y = temp[0].second;
        temp.clear();
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j] == 9){
                a[i][j] = 0;
                shark_x = i;
                shark_y = j;
            }
        }
    }
    shark_size = 2;//초기 아기상어 크기
    go();
    cout<<final_time<<"\n";
}
