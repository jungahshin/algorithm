//주사위 굴리기
#include <iostream>
#include <vector>
using namespace std;

int v1[4] = {1, 3, 6, 4};
int v2[4] = {1, 5, 6, 2};//0->맨위, 3->맨밑
int num[6] = {0, };//주사위에 쓰여진 수
int map[21][21] = {0, };
vector<int> move_;//이동하는 방향 저장 벡터
int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};
vector<int> final;//이동할 때마다 맨 위에 적혀 있는 수 넣기
int x, y, n, m, k, dir;

void go(){
    for(int i=0; i<move_.size(); i++){
        int dir = move_[i];//이동 방향
        int final_x = dir_x[dir-1] + x;
        int final_y = dir_y[dir-1] + y;
        if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
            x = final_x;
            y = final_y;
            if(dir == 1){//동
                int temp[4] = {0, };
                temp[0] = v1[3];
                for(int j=0; j<3; j++){
                    temp[j+1] = v1[j];
                }
                for(int j=0; j<4; j++){
                    v1[j] = temp[j];
                }
                //v2도 update
                v2[0] = v1[0];
                v2[2] = v1[2];
                if(map[final_x][final_y] == 0){//주사위의 바닥면에 쓰여진 수를 지도에 복사
                    //지도에 복사
                    map[final_x][final_y] = num[(v1[2]-1)];
                }else{//지도에 쓰여진 수가 주사위의 바닥면에 복사되고 지도의 수는 0이 된다.
                    //주사위에 복사
                    num[(v1[2]-1)] = map[final_x][final_y];
                    map[final_x][final_y] = 0;
                }
                //주사위 맨 위의 수 저장
                final.push_back(num[(v1[0]-1)]);
            }else if(dir == 2){//서
                int temp[4] = {0, };
                temp[3] = v1[0];
                for(int j=1; j<4; j++){
                    temp[j-1] = v1[j];
                }
                for(int j=0; j<4; j++){
                    v1[j] = temp[j];
                }
                //v2도 update
                v2[0] = v1[0];
                v2[2] = v1[2];
                if(map[final_x][final_y] == 0){//주사위의 바닥면에 쓰여진 수를 지도에 복사
                    //지도에 복사
                    map[final_x][final_y] = num[(v1[2]-1)];
                }else{//지도에 쓰여진 수가 주사위의 바닥면에 복사되고 지도의 수는 0이 된다.
                    //주사위에 복사
                    num[(v1[2]-1)] = map[final_x][final_y];
                    map[final_x][final_y] = 0;
                }
                //주사위 맨 위의 수 저장
                final.push_back(num[(v1[0]-1)]);
            }else if(dir == 3){//북
                int temp[4] = {0, };
                temp[3] = v2[0];
                for(int j=1; j<4; j++){
                    temp[j-1] = v2[j];
                }
                for(int j=0; j<4; j++){
                    v2[j] = temp[j];
                }
                //v1도 update
                v1[0] = v2[0];
                v1[2] = v2[2];
                if(map[final_x][final_y] == 0){//주사위의 바닥면에 쓰여진 수를 지도에 복사
                    //지도에 복사
                    map[final_x][final_y] = num[(v2[2]-1)];
                }else{//지도에 쓰여진 수가 주사위의 바닥면에 복사되고 지도의 수는 0이 된다.
                    //주사위에 복사
                    num[(v2[2]-1)] = map[final_x][final_y];
                    map[final_x][final_y] = 0;
                }
                //주사위 맨 위의 수 저장
                final.push_back(num[(v2[0]-1)]);
            }else if(dir == 4){//남
                int temp[4] = {0, };
                temp[0] = v2[3];
                for(int j=0; j<3; j++){
                    temp[j+1] = v2[j];
                }
                for(int j=0; j<4; j++){
                    v2[j] = temp[j];
                }
                //v1도 update
                v1[0] = v2[0];
                v1[2] = v2[2];
                if(map[final_x][final_y] == 0){//주사위의 바닥면에 쓰여진 수를 지도에 복사
                    //지도에 복사
                    map[final_x][final_y] = num[(v2[2]-1)];
                }else{//지도에 쓰여진 수가 주사위의 바닥면에 복사되고 지도의 수는 0이 된다.
                    //주사위에 복사
                    num[(v2[2]-1)] = map[final_x][final_y];
                    map[final_x][final_y] = 0;
                }
                //주사위 맨 위의 수 저장
                final.push_back(num[(v2[0]-1)]);
            }            
        }
    }
}

//동, 서 상태 따로 저장하는 벡터, 남, 북 상태 따로 저장하는 벡터
//전체 주사위 1~6자리에 있는 숫자 저장하는 벡터-->계속 update해주기
int main(){
    cin>>n>>m>>x>>y>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>dir;
        move_.push_back(dir);
    }
    go();
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}