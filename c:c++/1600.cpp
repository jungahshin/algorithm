//말이 되고픈 원숭이
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int k, w, h;
int a[201][201] = {0, };
int dx[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
int dy[8] = {-1, -2, 1, 2, -2, -1, 2, 1};
int bx[4] = {0, 0, -1, 1};
int by[4] = {-1, 1, 0, 0};
int visited[201][201][31] = {0, };
int final = INT_MAX;

void play(int start_x, int start_y){//bfs
    //k를 어떻게 활용할 것인지가 관건!!-->일단 항상 말 이동으로 시도한다. 그리고 이동이 가능하면 말 이동 수를 센다.
    queue<pair<pair<int, int>, pair<int, int>>> horse;
    horse.push(make_pair(make_pair(start_x, start_y), make_pair(0, 0)));

    while(!horse.empty()){
        int x = horse.front().first.first;
        int y = horse.front().first.second;
        int horse_num = horse.front().second.first;
        int way_num = horse.front().second.second;
        horse.pop();
        visited[x][y][horse_num] = 1;

        if(final < way_num){
            continue;
        }

        //말의 위치가 (h-1, w-1)인지 여부 체크하기!
        if(x == (h-1) && y == (w-1)){//도착위치
            final = min(final, way_num);
            return;
        }

        if(horse_num < k){
            for(int i=0; i<8; i++){
                int final_x = x + dx[i];
                int final_y = y + dy[i];
                if(0 <= final_x && final_x < h && 0 <= final_y && final_y < w){
                    if(a[final_x][final_y] == 0){//평지이면서 방문한 적이 없으면 이동 가능
                        //큐에 같은 값이 있는 지 확인하기!
                        if(!visited[final_x][final_y][horse_num+1]){
                            visited[final_x][final_y][horse_num+1] = 1;
                            horse.push(make_pair(make_pair(final_x, final_y), make_pair(horse_num+1, way_num+1)));
                        }
                    }
                }
            }            
        }
        //말 이동으로 이동이 불가한 경우->인접한 곳으로 이동한다.
        for(int i=0; i<4; i++){
            int final_x = x + bx[i];
            int final_y = y + by[i];
            if(0 <= final_x && final_x < h && 0 <= final_y && final_y < w){
                if(a[final_x][final_y] == 0){//평지이면서 방문한 적이 없으면 이동 가능
                    if(!visited[final_x][final_y][horse_num]){
                        visited[final_x][final_y][horse_num] = 1;
                        horse.push(make_pair(make_pair(final_x, final_y), make_pair(horse_num, way_num+1)));
                    }
                }
            }
        }
    }
}

int main(){
    cin>>k;
    cin>>w>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }
    play(0, 0);
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}