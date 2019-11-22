//움직이는 미로 탈출
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char chess[10][10];
vector<pair<int, int>> wall;
bool final_check;
int dx[9] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
int dy[9] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};
int visited[10][10] = {0, };

bool check(int x, int y, char a[][10]){//벽의 위치 중 하나가 캐릭터의 위치와 일치-->더 이상 이동 불가
    bool temp = false;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(a[i][j] == '#' && i == x && j == y){
                temp = true;
            }
        }
    }
    return temp;
}

bool check_2(int x, int y){//현재 캐릭터의 위치가 가장 오른 쪽 윗칸인지(0, 7)
    bool temp = false;
    if(x == 0 && y == 7){
        temp = true;
    }
    return temp;
}

bool check_3(){//wall[i].first == 7인 것이 있으면 계속 while문 돈다.
    bool temp = false;
    for(int i=0; i<wall.size(); i++){
        if(wall[i].first == 7){
            temp = true;
        }
    }
    return temp;
}

void play(int x, int y, char a[][10]){//움직이는 미로 탈출 시작
    char a_copy[10][10];

    for(int i=0; i<10; i++){//함수 안에서 a_copy를 초기화 해주는 것이 포인트!!!
        for(int j=0; j<10; j++){
            a_copy[i][j] = '.';
        }
    }

    if(final_check == true){
        return;
    }

    if(check(x, y, a)){//만약에 벽이 캐릭터가 있는 곳으로 이동하면-->캐릭터는 더 이상 이동할 수 없다->끝
        final_check = false;//실패
        return;
    }

    if(check_2(x, y)){//현재 캐릭터의 위치가 가장 오른쪽 맨 윗 칸일때
        final_check = true;//성공
        return;
    }

    for(int i=0; i<9; i++){
        int final_x = x + dx[i];
        int final_y = y + dy[i];
        if(0 <= final_x && final_x < 8 && 0 <= final_y && final_y < 8 && !visited[final_x][final_y] && a[final_x][final_y] == '.'){
            visited[final_x][final_y] = 1;
            //벽 이동
            //move
            for(int k=0; k<7; k++){
                for(int h=0; h<8; h++){
                    a_copy[k+1][h] = a[k][h];
                }
            }
            for(int k=0; k<8; k++){
                a_copy[0][k] = '.';
            }
        
            play(final_x, final_y, a_copy);
            visited[final_x][final_y] = 0;
        }
    }
}

int main(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>chess[i][j];
            if(chess[i][j] == '#'){//벽이면 위치를 따로 저장해 놓는다.
                wall.push_back(make_pair(i, j));
            }
        }
    }

    play(7, 0, chess);

    if(final_check == false){
        cout<<"0"<<"\n";
    }else if(final_check == true){
        cout<<"1"<<"\n";
    }
}