//탈출(복습)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
char forest[51][51] = {0, };
int start_x, start_y, end_x, end_y = 0;//고슴도치의 출발 위치, 비버의 굴 도착 위치
queue<pair<int, int>> q;//물의 위치->매분 물이 번진다.
queue<pair<int, int>> G;//고슴도치의 위치
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {-1, 1, 0, 0};
int visited[51][51] = {0, };
int visited_[51][51] = {0, };
bool temp = false;
int time_ = 0;

//고슴도치의 위치에서 비버의 굴로 도착하는 최소시간 구하기, 이동할 수 없을 시 "KAKTUS"출력
void go(){
    //물을 먼저 번지고 그리고 고슴도치가 그 외의 돌, 물을 제외한 빈 공간으로 이동한다.
    //반드시 while 탈출 기준은 고슴도치!!!
    while(!G.empty()){
        time_++;

        //매 분
        //물이 번진다.
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visited[x][y] = 1;

            //한 번 물이 사방면으로 번진다.
            for(int i=0; i<4; i++){
                int final_x = dir_x[i] + x;
                int final_y = dir_y[i] + y;
                if(0<=final_x && final_x<R && 0<=final_y && final_y<C && !visited[final_x][final_y]){
                    if(forest[final_x][final_y] == '.'){
                        visited[final_x][final_y] = 1;
                        forest[final_x][final_y] = '*';
                        q.push(make_pair(final_x, final_y));
                    }
                }
            }            
        }

        //고슴도치가 이동한다.
        int size = G.size();
        for(int k=0; k<size; k++){
            if(temp == true){
                break;
            }
            int x = G.front().first;
            int y = G.front().second;
            visited_[x][y] = 1;
            G.pop();

            for(int i=0; i<4; i++){
                int final_x = dir_x[i] + x;
                int final_y = dir_y[i] + y;
                if(0<=final_x && final_x<R && 0<=final_y && final_y<C && !visited_[final_x][final_y]){
                    visited_[final_x][final_y] = 1;
                    if(forest[final_x][final_y] == '.'){
                        G.push(make_pair(final_x, final_y));
                    }else if(forest[final_x][final_y] == 'D'){
                        temp = true;//도착!!
                        break;
                    }
                }                
            }
        }            
        if(temp == true){
            break;
        }
    }        
}

int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>forest[i][j];
            if(forest[i][j] == 'S'){//고슴도치의 위치
                start_x = i;
                start_y = j;
                G.push(make_pair(i, j));
            }
            if(forest[i][j] == 'D'){//비버의 굴 위치
                end_x = i;
                end_y = j;
            }
            if(forest[i][j] == '*'){//물이 있는 위치
                q.push(make_pair(i, j));
            }
        }
    }
    forest[start_x][start_y] = '.';//고슴도치의 시작위치에 S를 .으로 바꿔준다.
    go();
    if(temp == true){
        cout<<time_<<"\n";
    }else{
        cout<<"KAKTUS"<<"\n";
    }
    return 0;
}
