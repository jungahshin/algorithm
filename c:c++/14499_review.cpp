//주사위 굴리기(복습)
#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k, z;
int dice[21][21] = {0, };
vector<int> MOVE;
int num[7] = {0, };//주사위에 써있는 숫자 윗면은 idx1번
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int X, Y;

int east_west(int dir){//위, 오, 밑, 왼 순서
    int temp[5] = {0, };
    temp[0] = num[0];
    temp[1] = num[2];
    temp[2] = num[5];
    temp[3] = num[3];
    int temp2[5] = {0, };
    if(dir == 1){//동->오른쪽
        for(int i=0; i<3; i++){
            temp2[i+1] = temp[i];
        }
        temp2[0] = temp[3];
    }else if(dir == 2){//서->왼쪽
        for(int i=1; i<4; i++){
            temp2[i-1] = temp[i];
        }
        temp2[3] = temp[0];
    }
    //temp2의 값을 num에 넘겨주기
    num[0] = temp2[0];
    num[2] = temp2[1];
    num[5] = temp2[2];
    num[3] = temp2[3];
    return num[5];
}

int north_south(int dir){//뒤, 위, 앞, 밑 순서
    int temp[5] = {0, };
    temp[0] = num[1];
    temp[1] = num[0];
    temp[2] = num[4];
    temp[3] = num[5];
    int temp2[5] = {0, };
    if(dir == 3){//북->왼쪽
        for(int i=1; i<4; i++){
            temp2[i-1] = temp[i];
        }
        temp2[3] = temp[0];
    }else if(dir == 4){//남->오른쪽
        for(int i=0; i<3; i++){
            temp2[i+1] = temp[i];
        }
        temp2[0] = temp[3];
    }
    num[1] = temp2[0];
    num[0] = temp2[1];
    num[4] = temp2[2];
    num[5] = temp2[3];
    return num[5];
}

void play(){
    for(int i=0; i<MOVE.size(); i++){
        int dir = MOVE[i];//움직이는 방향
        int nx = X+dx[dir-1];
        int ny = Y+dy[dir-1];
        if(0<=nx && nx<n && 0<=ny && ny<m){
            int dice_num = 0;
            if(dir == 1){//동->오른쪽
                dice_num = east_west(1);
            }else if(dir == 2){//서->왼쪽
                dice_num = east_west(2);
            }else if(dir == 3){//북->왼쪽
                dice_num = north_south(3);
            }else if(dir == 4){//남->오른쪽
                dice_num = north_south(4);
            }
            if(dice[nx][ny] == 0){
                dice[nx][ny] = dice_num;
            }else{
                num[5] = dice[nx][ny];
                dice[nx][ny] = 0;
            }
            cout<<num[0]<<"\n";
            X = nx;
            Y = ny;
        }
    }
}

int main(){
    cin>>n>>m>>x>>y>>k;
    X = x;
    Y = y;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>dice[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>z;
        MOVE.push_back(z);
    }
    play();
}