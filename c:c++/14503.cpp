//로봇청소기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, r, c, d;
int a[51][51] = {0, };//0-빈칸, 1-벽, 청소 후 -2
queue<pair<pair<int, int>, int>> q;//로봇의 위치(r, c), 방향(d) 저장
int num = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void clean(){
    while(!q.empty()){//로봇이 청소할 수 있으면
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;//방향
        q.pop();
        if(a[x][y] == 0){
            num++;//1번. 현재 위치 청소
            a[x][y] = 2;
        }

        //2-a번
        if(dir == 0){//북이면 서(3), 열 -1
            int final_x = x + dx[2];
            int final_y = y + dy[2];
            if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                if(a[final_x][final_y] == 0){//청소 하지 않은 공간
                    //그 방향으로 회전하고 +1 전진 & 1번 부터 다시 진행
                    q.push(make_pair(make_pair(final_x, final_y), 3));
                    continue;
                }else{//이미 청소를 했거나, 벽이면
                    //일단, 모든 방향이 청소를 했거나, 벽인지 살펴보기-->그렇다면, 방향 유지한 채, 한 칸 후진 후 2번으로
                    int temp = 0;
                    for(int i=0; i<4; i++){
                        int next_x = x + dx[i];
                        int next_y = y + dy[i];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] != 0){
                                temp++;
                            }                            
                        }
                    }
                    if(temp == 4){//모든 방향이 청소를 했거나, 벽이다.(행 +1)
                        int next_x = x + dx[3];
                        int next_y = y + dy[3];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] == 1){//뒤쪽 방향이 벽이면 그냥 프로그램 끝!!!
                                return;
                            }else{//한 칸 후진
                                q.push(make_pair(make_pair(next_x, next_y), dir));
                                continue;
                            }
                        }
                    }else{
                        //아니면
                        //그 방향으로 회전
                        q.push(make_pair(make_pair(x, y), 3));            
                        continue;            
                    }
                }
            }

        }else if(dir == 1){//동이면 북(0), 행 -1
            int final_x = x + dx[0];
            int final_y = y + dy[0];
            if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                if(a[final_x][final_y] == 0){//청소 하지 않은 공간
                    //그 방향으로 회전하고 +1 전진 & 1번 부터 다시 진행
                    q.push(make_pair(make_pair(final_x, final_y), 0));
                    continue;
                }else{//이미 청소를 했거나, 벽이면
                    //일단, 모든 방향이 청소를 했거나, 벽인지 살펴보기-->그렇다면, 방향 유지한 채, 한 칸 후진 후 2번으로
                    int temp = 0;
                    for(int i=0; i<4; i++){
                        int next_x = x + dx[i];
                        int next_y = y + dy[i];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] != 0){
                                temp++;
                            }                            
                        }
                    }
                    if(temp == 4){//모든 방향이 청소를 했거나, 벽이다.(열  -1)
                        int next_x = x + dx[2];
                        int next_y = y + dy[2];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] == 1){//뒤쪽 방향이 벽이면 그냥 프로그램 끝!!!
                                return;
                            }else{//한 칸 후진
                                q.push(make_pair(make_pair(next_x, next_y), dir));
                                continue;
                            }
                        }
                    }else{
                        //아니면
                        //그 방향으로 회전
                        q.push(make_pair(make_pair(x, y), 0));                    
                        continue;
                    }               
                }
            }
        }else if(dir == 2){//남이면 동(1), 열 +1
            int final_x = x + dx[1];
            int final_y = y + dy[1];
            if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                if(a[final_x][final_y] == 0){//청소 하지 않은 공간
                    //그 방향으로 회전하고 +1 전진 & 1번 부터 다시 진행
                    q.push(make_pair(make_pair(final_x, final_y), 1));
                    continue;
                }else{//이미 청소를 했거나, 벽이면
                    //일단, 모든 방향이 청소를 했거나, 벽인지 살펴보기-->그렇다면, 방향 유지한 채, 한 칸 후진 후 2번으로
                    int temp = 0;
                    for(int i=0; i<4; i++){
                        int next_x = x + dx[i];
                        int next_y = y + dy[i];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] != 0){
                                temp++;
                            }                            
                        }
                    }
                    if(temp == 4){//모든 방향이 청소를 했거나, 벽이다.(행 -1)
                        int next_x = x + dx[0];
                        int next_y = y + dy[0];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] == 1){//뒤쪽 방향이 벽이면 그냥 프로그램 끝!!!
                                return;
                            }else{//한 칸 후진
                                q.push(make_pair(make_pair(next_x, next_y), dir));
                                continue;

                            }
                        }
                    }else{
                        //아니면
                        //그 방향으로 회전
                        q.push(make_pair(make_pair(x, y), 1));
                        continue;
                    } 
                }
            }
        }else if(dir == 3){//서면 남(2), 행 +1
            int final_x = x + dx[3];
            int final_y = y + dy[3];
            if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                if(a[final_x][final_y] == 0){//청소 하지 않은 공간
                    //그 방향으로 회전하고 +1 전진 & 1번 부터 다시 진행
                    q.push(make_pair(make_pair(final_x, final_y), 2));
                    continue;
                }else{//이미 청소를 했거나, 벽이면
                    //일단, 모든 방향이 청소를 했거나, 벽인지 살펴보기-->그렇다면, 방향 유지한 채, 한 칸 후진 후 2번으로
                    int temp = 0;
                    for(int i=0; i<4; i++){
                        int next_x = x + dx[i];
                        int next_y = y + dy[i];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] != 0){
                                temp++;
                            }                            
                        }
                    }
                    if(temp == 4){//모든 방향이 청소를 했거나, 벽이다.(열 +1)
                        int next_x = x + dx[1];
                        int next_y = y + dy[1];
                        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                            if(a[next_x][next_y] == 1){//뒤쪽 방향이 벽이면 그냥 프로그램 끝!!!
                                return;
                            }else{//한 칸 후진
                                q.push(make_pair(make_pair(next_x, next_y), dir));
                                continue;
                            }
                        }
                    }else{
                        //아니면
                        //그 방향으로 회전
                        q.push(make_pair(make_pair(x, y), 2));
                        continue;
                    } 
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    cin>>r>>c>>d;//로봇 청소기 위치
    q.push(make_pair(make_pair(r, c), d));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    clean();
    cout<<num<<"\n";
}