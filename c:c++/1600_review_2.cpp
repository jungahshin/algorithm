//말이 되고픈 원숭이 복습
#include <iostream>
#include <queue>
using namespace std;

int w, h, k;
int chess[201][201] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int hor_dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hor_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int visited[201][201][31] = {0, };
int total_num = 0;//총 움직인 동작 수
bool check = false;
// int horse_num = 0;//말의 방법으로 움직인 동작 수

//k번으로만 말의 방법으로 이동하고 최소한의 동작으로 도착하기(최소는 무조건 bfs)
void play(){
    queue<pair<pair<int, int>, pair<int,int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second.first;//그냥 움직인
        int hor_num = q.front().second.second;//말로 움직인
        q.pop();
        visited[x][y][hor_num] = 1;

        //도착지점에 도착!
        if(x == h-1 && y == w-1){
            total_num = num+hor_num;
            check = true;
            break;
        }

        //말의 방법으로 움직인다.
        if(hor_num<k){
            for(int i=0; i<8; i++){
                int final_x = hor_dx[i]+x;
                int final_y = hor_dy[i]+y;
                if(0<=final_x && final_x<h && 0<=final_y && final_y<w){
                    if(chess[final_x][final_y] == 0 && !visited[final_x][final_y][hor_num+1]){
                        visited[final_x][final_y][hor_num+1] = 1;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(num, hor_num+1)));
                    }
                }
            }
        }
        //그냥 움직인다.
        for(int i=0; i<4; i++){
            int final_x = dx[i]+x;
            int final_y = dy[i]+y;
            if(0<=final_x && final_x<h && 0<=final_y && final_y<w && !visited[final_x][final_y][hor_num]){
                if(chess[final_x][final_y] == 0){
                    visited[final_x][final_y][hor_num] = 1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, hor_num)));
                }
            }
        }
    }
}

int main(){
    cin>>k;//k번 이동할 수 있다(말의 이동방법으로..)
    cin>>w>>h;//열과 행
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>chess[i][j];
        }
    }
    play();
    if(check == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<total_num<<"\n";
    }
}