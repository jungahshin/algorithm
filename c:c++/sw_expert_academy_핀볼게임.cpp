// 5650. [모의 SW 역량테스트] 핀볼 게임
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int testcase, n;
int pinball[101][101] = {0, };
vector<pair<int, int>> start;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int total = 0;//최종 점수
vector<pair<int, int>> wormwhole[6];
int final = 0;

int change(int dir){//방향만 반대로 바꿔준다.
    if(dir == 0){
        dir = 2;
    }else if(dir == 2){
        dir = 0;
    }else if(dir == 1){
        dir = 3;
    }else if(dir == 3){
        dir = 1;
    }
    return dir;
}

int play(int temp, int start_x, int start_y){//시작지점과 방향
    total = 0;
    int dir = temp;
    int x = start_x;
    int y = start_y;
    while(1){
        int nx = dx[dir]+x;
        int ny = dy[dir]+y;
        if(0<=nx && nx<n && 0<=ny && ny<n){
            if(pinball[nx][ny] == 0){//빈공간
                x = nx;
                y = ny;
            }else if(1<=pinball[nx][ny] && pinball[nx][ny]<=5){//블록
                total++;
                if(dir == 0){
                    if(pinball[nx][ny] == 2){
                        dir = 1;
                    }else if(pinball[nx][ny] == 3){
                        dir = 3;
                    }else{//방향만 반대로 바뀐다.
                        dir = change(dir);
                    }
                }else if(dir == 1){
                    if(pinball[nx][ny] == 3){
                        dir = 2;
                    }else if(pinball[nx][ny] == 4){
                        dir = 0;
                    }else{
                        dir = change(dir);
                    }
                }else if(dir == 2){
                    if(pinball[nx][ny] == 1){
                        dir = 1;
                    }else if(pinball[nx][ny] == 4){
                        dir = 3;
                    }else{
                        dir = change(dir);
                    }
                }else if(dir == 3){
                    if(pinball[nx][ny] == 1){
                        dir = 0;
                    }else if(pinball[nx][ny] == 2){
                        dir = 2;
                    }else{
                        dir = change(dir);
                    }
                }
                x = nx;
                y = ny;
            }else if(pinball[nx][ny] == -1){//블랙홀
                break;
            }else if(6<=pinball[nx][ny] && pinball[nx][ny]<=10){//웜홀
                for(int k=0; k<wormwhole[pinball[nx][ny]-6].size(); k++){
                    if(wormwhole[pinball[nx][ny]-6][k].first != nx || wormwhole[pinball[nx][ny]-6][k].second != ny){//자기 자신이 아닌 같은 번호의 다른 웜홀
                        x = wormwhole[pinball[nx][ny]-6][k].first;
                        y = wormwhole[pinball[nx][ny]-6][k].second;
                        break;
                    }
                }
            }
        }else{//벽에 부딪힌다. -> 방향만 바꾼다.
            x = nx;
            y = ny;
            total++;
            dir = change(dir);
        }
        if(x == start_x && y == start_y){//출발지점으로 돌아옴.
            break;
        }
    }
    return total;
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        //초기화
        memset(pinball, 0, sizeof(pinball));
        final = 0;
        start.clear();
        for(int k=0; k<5; k++){
            if(wormwhole[k].size()>0){
                wormwhole[k].clear();
            }
        }
        cin>>n;
        for(int k=0; k<n; k++){
            for(int t=0; t<n; t++){
                cin>>pinball[k][t];
                if(pinball[k][t] == 0){//출발할 수 있는 지점
                    start.push_back(make_pair(k, t));
                }else if(6<=pinball[k][t] && pinball[k][t]<=10){//웜홀 쌍으로 저장하기
                    wormwhole[pinball[k][t]-6].push_back(make_pair(k, t));
                }
            }
        }
        for(int k=0; k<start.size(); k++){
            for(int t=0; t<4; t++){//모든 방향에서 시작해보기..!
                final = max(final, play(t, start[k].first, start[k].second));
            }
        }
        cout<<"#"<<i+1<<" "<<final<<"\n";
    }
    return 0;
}