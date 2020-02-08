//새로운 게임2 복습
#include <iostream>
#include <vector>
using namespace std;

int chess[13][13] = {0, };//체스판의 색깔 저장
vector<pair<int, int>> temp[13][13];//말의 번호랑 이동방향 저장
int n, k, a, b, c;
vector<pair<pair<int, int>, int>> horse;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool final = false;
int num = 0;

bool check(){
    bool check_temp = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(temp[i][j].size()>=4){
                check_temp = true;
            }
        }
    }
    return check_temp;
}

void play(){
    while(num<1000){
        num++;
        for(int i=0; i<horse.size(); i++){//말이 모두 움직이는 것이 하나의 turn
            int x = horse[i].first.first;
            int y = horse[i].first.second;
            int dir = horse[i].second;
            //이동할 위치
            int final_x = dx[dir-1]+x;
            int final_y = dy[dir-1]+y;
            
            if(1<=final_x && final_x<=n && 1<=final_y && final_y<=n){
                if(chess[final_x][final_y] == 0){//흰색->a+ a위에 있는 말들 모두가 이동할 위치에 있는 말들 위로 모두 올라간다.
                    for(int k=0; k<temp[x][y].size(); k++){//원래 있는 위치에 말들
                        if(temp[x][y][k].first == i){//말의 번호
                            //다음에 갈 곳의 위치에 옮긴다.
                            for(int t=k; t<temp[x][y].size(); t++){
                                temp[final_x][final_y].push_back(make_pair(temp[x][y][t].first, temp[x][y][t].second));
                                //horse vector의 정보도 바꿔준다.
                                horse[(temp[x][y][t].first)].first.first = final_x;
                                horse[(temp[x][y][t].first)].first.second = final_y;
                            }

                            //원래 위치에서 삭제
                            temp[x][y].erase(temp[x][y].begin()+k, temp[x][y].end());
                            break;
                        }
                    }
                }else if(chess[final_x][final_y] == 1){//빨간색->
                    for(int k=0; k<temp[x][y].size(); k++){//원래 있는 위치에 말들
                        if(temp[x][y][k].first == i){//말의 번호
                            //다음에 갈 곳의 위치에 옮긴다.
                            for(int t=temp[x][y].size()-1; t>=k; t--){
                                temp[final_x][final_y].push_back(make_pair(temp[x][y][t].first, temp[x][y][t].second));
                                //horse vector의 정보도 바꿔준다.
                                horse[(temp[x][y][t].first)].first.first = final_x;
                                horse[(temp[x][y][t].first)].first.second = final_y;
                            }

                            //원래 위치에서 삭제
                            temp[x][y].erase(temp[x][y].begin()+k, temp[x][y].end());
                            break;
                        }
                    }
                }else if(chess[final_x][final_y] == 2){//파란색
                    //일단 이동방향을 바꾼다
                    if(dir == 1){
                        dir = 2;
                    }else if(dir == 2){
                        dir = 1;
                    }else if(dir == 3){
                        dir = 4;
                    }else if(dir == 4){
                        dir = 3; 
                    } 

                    horse[i].second = dir;

                    //이동하려는 칸이 파란색이거나 체스판을 벗어나는지 확인 -> 아니면 이동, 맞으면 그냥 가만히
                    int next_x = dx[dir-1]+x;
                    int next_y = dy[dir-1]+y;
                    if(1<=next_x && next_x<=n && 1<=next_y && next_y<=n){
                        if(chess[next_x][next_y] == 0){//흰색
                            for(int k=0; k<temp[x][y].size(); k++){//원래 있는 위치에 말들
                                if(temp[x][y][k].first == i){//말의 번호
                                    temp[x][y][k].second = dir;
                                    //다음에 갈 곳의 위치에 옮긴다.
                                    for(int t=k; t<temp[x][y].size(); t++){
                                        temp[next_x][next_y].push_back(make_pair(temp[x][y][t].first, temp[x][y][t].second));
                                        //horse vector의 정보도 바꿔준다.
                                        horse[(temp[x][y][t].first)].first.first = next_x;
                                        horse[(temp[x][y][t].first)].first.second = next_y;
                                    }

                                    //원래 위치에서 삭제
                                    temp[x][y].erase(temp[x][y].begin()+k, temp[x][y].end());
                                    break;
                                }
                            }
                        }else if(chess[next_x][next_y] == 1){//빨간색
                            for(int k=0; k<temp[x][y].size(); k++){//원래 있는 위치에 말들
                                if(temp[x][y][k].first == i){//말의 번호
                                    temp[x][y][k].second = dir;
                                    //다음에 갈 곳의 위치에 옮긴다.
                                    for(int t=temp[x][y].size()-1; t>=k; t--){
                                        temp[next_x][next_y].push_back(make_pair(temp[x][y][t].first, temp[x][y][t].second));
                                        //horse vector의 정보도 바꿔준다.
                                        horse[(temp[x][y][t].first)].first.first = next_x;
                                        horse[(temp[x][y][t].first)].first.second = next_y;
                                    }

                                    //원래 위치에서 삭제
                                    temp[x][y].erase(temp[x][y].begin()+k, temp[x][y].end());
                                    break;
                                }
                            }
                        }
                    }
                }
            }else{//체스판을 벗어난다.
                //일단 이동방향을 바꾼다
                if(dir == 1){
                    dir = 2;
                }else if(dir == 2){
                    dir = 1;
                }else if(dir == 3){
                    dir = 4;
                }else if(dir == 4){
                    dir = 3; 
                } 

                horse[i].second = dir;

                //이동하려는 칸이 파란색이거나 체스판을 벗어나는지 확인 -> 아니면 이동, 맞으면 그냥 가만히
                int next_x = dx[dir-1]+x;
                int next_y = dy[dir-1]+y;
                if(1<=next_x && next_x<=n && 1<=next_y && next_y<=n){
                    if(chess[next_x][next_y] == 0){//흰색
                        for(int k=0; k<temp[x][y].size(); k++){//원래 있는 위치에 말들
                            if(temp[x][y][k].first == i){//말의 번호
                                temp[x][y][k].second = dir;
                                //다음에 갈 곳의 위치에 옮긴다.
                                for(int t=k; t<temp[x][y].size(); t++){
                                    temp[next_x][next_y].push_back(make_pair(temp[x][y][t].first, temp[x][y][t].second));
                                    //horse vector의 정보도 바꿔준다.
                                    horse[(temp[x][y][t].first)].first.first = next_x;
                                    horse[(temp[x][y][t].first)].first.second = next_y;
                                }

                                //원래 위치에서 삭제
                                temp[x][y].erase(temp[x][y].begin()+k, temp[x][y].end());
                                break;
                            }
                        }
                    }else if(chess[next_x][next_y] == 1){//빨간색
                        for(int k=0; k<temp[x][y].size(); k++){//원래 있는 위치에 말들
                            if(temp[x][y][k].first == i){//말의 번호
                                temp[x][y][k].second = dir;
                                //다음에 갈 곳의 위치에 옮긴다.
                                for(int t=temp[x][y].size()-1; t>=k; t--){
                                    temp[next_x][next_y].push_back(make_pair(temp[x][y][t].first, temp[x][y][t].second));
                                    //horse vector의 정보도 바꿔준다.
                                    horse[(temp[x][y][t].first)].first.first = next_x;
                                    horse[(temp[x][y][t].first)].first.second = next_y;
                                }

                                //원래 위치에서 삭제
                                temp[x][y].erase(temp[x][y].begin()+k, temp[x][y].end());
                                break;
                            }
                        }
                    }
                }
            }
            //말이 4개 이상 쌓이면 게임 종료!!->말이 모두 이동하고 마지막에 체크해주기
            if(check()){
                final = true;
                return;
            }
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>chess[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>a>>b>>c;
        horse.push_back(make_pair(make_pair(a, b),c));//위치(a, b)와 방향 c(1->오, 2->왼, 3->위, 4->아래)
        temp[a][b].push_back(make_pair(i, c));//말의 번호(0~k-1)랑 방향 저장
    }
    play();
    if(final == true){
        cout<<num<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
}