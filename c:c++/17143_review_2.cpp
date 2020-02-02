//낚시왕 복습
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, m, r, c, s, d, z;
vector<pair<int, pair<int, int>>> sea[102][102];//((속력 이동방향), 크기)
int person = 0;//낚시왕의 열 위치(person의 값이 C+1이 되면 멈춘다)
int total = 0;//낚시왕이 잡은 상어크기의 합
int dx[4] = {-1, 1, 0, 0};//위, 아래, 오, 왼
int dy[4] = {0, 0, 1, -1};

void play(){
    while(person < C+1){
        //낚시왕 오른쪽 한 칸으로 이동
        person++;

        //낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
        for(int i=1; i<=R; i++){
            if(sea[i][person].size() > 0){//어차피 한 칸에는 한마리의 상어가 있는 가정 하에
                total += sea[i][person][0].first;
                sea[i][person].clear();
                break;
            }
        }

        //상어 이동
        //임시 벡터 생성
        vector<pair<int, pair<int, int>>> sea_temp[102][102];
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(sea[i][j].size() > 0){//상어가 있다면 이동시킨다.
                    int speed = sea[i][j][0].second.first;
                    int dir = sea[i][j][0].second.second;
                    int count_temp = 0;
                    if(dir == 1 || dir == 2){
                        count_temp = speed % ((R-1)*2);
                    }else if(dir == 3 || dir == 4){
                        count_temp = speed % ((C-1)*2);
                    }
                    int size = sea[i][j][0].first;
                    int x = i;
                    int y = j;
                    while(count_temp--){
                        int final_x = x+dx[dir-1];
                        int final_y = y+dy[dir-1];
                        if(1<=final_x && final_x<=R && 1<=final_y && final_y<=C){
                            x = final_x;
                            y = final_y;
                        }else{//경계선을 벗어난다.->방향을 바꾸고 한 칸 이동
                            if(dir == 1){//위->아래
                                dir = 2;
                            }else if(dir == 2){//아래->위
                                dir = 1;
                            }else if(dir == 3){//오->왼
                                dir = 4;
                            }else if(dir == 4){//왼->오
                                dir = 3;
                            }
                            x += dx[dir-1];
                            y += dy[dir-1];
                        } 
                    }

                    //최종 도착지점->(x, y) 최종 방향 dir, 속력과 크기는 그대로
                    sea_temp[x][y].push_back(make_pair(size, make_pair(speed, dir)));
                }
            }
        }

        //sea clear해주기
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                sea[i][j].clear();
            }
        }

        //같은 칸에 여러마리의 상어가 있을 경우 가장 큰 상어가 나머지를 다 잡아먹는다.(sea_temp로 판별)
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(sea_temp[i][j].size()>1){
                    int temp = sea_temp[i][j].size()-1;//마지막 idx
                    sort(sea_temp[i][j].begin(), sea_temp[i][j].end());//크기 순으로 정렬
                    int speed = sea_temp[i][j][temp].second.first;
                    int dir = sea_temp[i][j][temp].second.second;
                    int size = sea_temp[i][j][temp].first;
                    sea[i][j].push_back(make_pair(size, make_pair(speed, dir)));
                }else if(sea_temp[i][j].size() == 1){
                    sea[i][j].push_back(make_pair(sea_temp[i][j][0].first, make_pair(sea_temp[i][j][0].second.first, sea_temp[i][j][0].second.second)));
                }
            }
        }

        //sea_temp clear해주기
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                sea_temp[i][j].clear();
            }
        }
    }
}

int main(){
    cin>>R>>C>>m;
    for(int i=0; i<m; i++){
        cin>>r>>c>>s>>d>>z;
        sea[r][c].push_back(make_pair(z, make_pair(s, d)));
    }
    if(m == 0){
        cout<<"0"<<"\n";
        return 0;
    }
    play();
    cout<<total<<"\n";
    return 0;
}