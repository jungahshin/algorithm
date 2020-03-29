//새로운 게임2
#include <iostream>
#include <vector>
using namespace std;

int n, k;
int a, b, c;
int map[13][13] = {0, };
vector<pair<pair<int, int>, int>> horse;//말의 위치와 이동방향 저장
int num = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<int> v[13][13];//지도에 상태표시(말의 번호)

void white(int a, int b, int c, int d, int horse_num){
    //다음칸에 넣는다.
    int temp = 0;
    for(int j=0; j<v[a][b].size(); j++){
        if(v[a][b][j] == horse_num){
            temp = j;
            for(int k=j; k<v[a][b].size(); k++){
                v[c][d].push_back(v[a][b][k]);
                //말의 위치 수정
                horse[v[a][b][k]-1].first.first = c;
                horse[v[a][b][k]-1].first.second = d;
            }
        }
    }
    //원래칸에서 지운다.
    v[a][b].erase(v[a][b].begin()+temp, v[a][b].end());
}

void red(int a, int b, int c, int d, int horse_num){
    //다음칸에 넣는다.
    int temp = 0;
    for(int j=0; j<v[a][b].size(); j++){
        if(v[a][b][j] == horse_num){
            temp = j;
            for(int k=v[a][b].size()-1; k>=j; k--){
                v[c][d].push_back(v[a][b][k]);
                //말의 위치 수정
                horse[v[a][b][k]-1].first.first = c;
                horse[v[a][b][k]-1].first.second = d;
            }
        }
    }
    //원래칸에서 지운다.
    v[a][b].erase(v[a][b].begin()+temp, v[a][b].end());
}

void play(){
    while(1){//턴을 돈다.
        bool check = false;
        num++;
        if(num>1000){
            break;
        }
        for(int i=0; i<horse.size(); i++){
            int x = horse[i].first.first;
            int y = horse[i].first.second;
            int dir = horse[i].second;

            //이동할 칸
            int final_x = x+dx[dir-1];
            int final_y = y+dy[dir-1];

            if(1<=final_x && final_x<=n && 1<=final_y && final_y<=n){
                if(map[final_x][final_y] == 0){//흰색 칸
                    white(x, y, final_x, final_y, i+1);
                }else if(map[final_x][final_y] == 1){//빨간 칸
                    red(x, y, final_x, final_y, i+1);
                }else if(map[final_x][final_y] == 2){//파란 칸
                    //방향을 반대로 바꾼다.
                    if(dir == 1){
                        dir = 2;
                    }else if(dir == 2){
                        dir = 1;
                    }else if(dir == 3){
                        dir = 4;
                    }else if(dir == 4){
                        dir = 3;
                    }
                    //그 방향으로 한 칸 이동한다.
                    int f_x = x+dx[dir-1];
                    int f_y = y+dy[dir-1];
                    if(1<=f_x && f_x<=n && 1<=f_y && f_y<=n){
                        if(map[f_x][f_y] == 0){//흰색
                            white(x, y, f_x, f_y, i+1);
                        }else if(map[f_x][f_y] == 1){//빨간색
                            red(x, y, f_x, f_y, i+1);
                        }
                    }
                    horse[i].second = dir;
                }    
            }else{//범위 밖에 벗어난 경우
                //방향을 반대로 바꾼다.
                if(dir == 1){
                    dir = 2;
                }else if(dir == 2){
                    dir = 1;
                }else if(dir == 3){
                    dir = 4;
                }else if(dir == 4){
                    dir = 3;
                }

                //그 방향으로 한 칸 이동한다.
                int f_x = x+dx[dir-1];
                int f_y = y+dy[dir-1];
                if(1<=f_x && f_x<=n && 1<=f_y && f_y<=n){
                    if(map[f_x][f_y] == 0){//흰색
                        white(x, y, f_x, f_y, i+1);
                    }else if(map[f_x][f_y] == 1){//빨간색
                        red(x, y, f_x, f_y, i+1);
                    }
                }
                horse[i].second = dir;
            }
            
            //말이 4개 이상 쌓이면 끝난다.
            for(int k=1; k<=n; k++){
                for(int t=1; t<=n; t++){
                    if(v[k][t].size()>=4){
                        check = true;
                    }
                }
            }

            if(check == true){
                break;
            }
        }
        if(check == true){
            break;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>a>>b>>c;
        horse.push_back(make_pair(make_pair(a, b), c));
        v[a][b].push_back(i+1);
    }
    play();
    if(num > 1000){
        cout<<"-1"<<"\n";
    }else{
        cout<<num<<"\n";
    }
    return 0;
}