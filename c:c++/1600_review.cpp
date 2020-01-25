//말이 되고픈 원숭이
#include <iostream>
#include <queue>
using namespace std;

int chess[201][201] = {0, };
int visited[201][201][31] = {0, };//위치랑 말로 이동한 횟수
int num = 0;//이동한 수
int dir_x[4] = {0, 0, -1, 1};//그냥 이동
int dir_y[4] = {-1, 1, 0, 0};
int hor_x[8] = {-2, -1, -2, -1, 1, 2, 1, 2};//말로 이동
int hor_y[8] = {-1, -2, 1, 2, -2, -1, 2, 1};
int final = 0;
bool temp = false;
int w, h, k;

void play(){
    queue<pair<pair<int, int>, pair<int, int>>> q;//위치랑 총 이동한 수
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int horse_num = q.front().second.first;
        int normal_num = q.front().second.second;
        q.pop();
        visited[x][y][horse_num] = 1;

        if(x == h-1 && y == w-1){//도착지점에 왔다.
            temp = true;
            final = horse_num + normal_num;
            break;
        }

        //말로 이동
        if(horse_num < k){
            for(int i=0; i<8; i++){
                int final_x = x + hor_x[i];
                int final_y = y + hor_y[i];
                if(0<=final_x && final_x<h && 0<=final_y && final_y<w && !visited[final_x][final_y][horse_num+1]){
                    visited[final_x][final_y][horse_num+1] = 1;
                    if(chess[final_x][final_y] == 0){
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(horse_num+1, normal_num)));                        
                    }
                }
            }            
        }
        //그냥 이동
        for(int i=0; i<4; i++){
            int final_x = x + dir_x[i];
            int final_y = y + dir_y[i];
            if(0<=final_x && final_x<h && 0<=final_y && final_y<w && !visited[final_x][final_y][horse_num]){
                visited[final_x][final_y][horse_num] = 1;
                if(chess[final_x][final_y] == 0){
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(horse_num, normal_num+1)));
                }
            }
        }
    }
}

int main(){
    cin>>k;//말처럼 이동할 수 있는 수
    cin>>w>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>chess[i][j];
        }
    }
    play();
    if(temp == false){//도착지점에 도착하지 못했다.
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}