//자물쇠와 열쇠(원래 문제의 조건대로 열쇠보다 자물쇠의 크기가 크거나 같다)
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//돌기와 돌기가 만나서는 안된다.

int map[21][21] = {0, };//키
int row, col;
int l_row, l_col;
vector<vector<int>> l;
bool check = false;
int temp_num = 0;
int lock_num = 0;
int final_lock = 0;

//끝점(row-1, col-1)->(row+1, col+1)
//(0, 0)~((keyd의row)-1+(lock의row-1)+(keyd의row)-1,(key의col)-1+(lock의 col-1)+(key의col)-1)은 0으로 초기화 하고
//((keyd의row)-1, (key의col)-1)~((keyd의row)-1+(lock의row-1), (key의col)-1+(lock의 col-1))은 기존 lock의 값으로..
void move(int a[21][21]){
    int large_lock[100][100] = {0, };
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            large_lock[i][j] = 2;
        }
    }
    int lock_row = 0;
    for(int i=row-1; i<=(row-1+l_row-1); i++){
        int lock_col = 0;
        for(int j=col-1; j<=(col-1+l_col-1); j++){
            large_lock[i][j] = l[lock_row][lock_col];
            lock_col++;
        }
        lock_row++;
    }

    for(int i=0; i<=(col-1+l_row-1); i++){
        for(int j=0; j<=(col-1+l_col-1); j++){
            //(i, j)~(i+row-1, j+col-1)까지
            int temp_row = 0;
            int temp_num = 0;
            int lock_num = 0;
            int total_num = 0;
            for(int k=i; k<=i+row-1; k++){
                int temp_col = 0;
                for(int t=j; t<=j+col-1; t++){
                    if(large_lock[k][t] != 2){
                        if((large_lock[k][t]+a[temp_row][temp_col]) == 1){
                            if(large_lock[k][t] == 0){
                                lock_num++;
                            }
                            temp_num++;
                        }
                        total_num++;
                    }
                    temp_col++;
                }
                temp_row++;
            }
            if(temp_num == total_num && lock_num == final_lock){
                check = true;
                break;
            }
        }
        if(check == true){
            break;
        }
    }
}

void rotation(int num, int a[21][21]){//90도 회전의 횟수
    int a_temp[21][21] = {0, };
    int temp = 0;
    while(1){
        temp++;
        if(temp>num){
            break;
        }
        int col_temp = row-1;//이것이 열이 된다.
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                a_temp[j][col_temp] = a[i][j];
            }
            col_temp--;
        }
        //행과 열의 수가 바뀐다.
        row = col;
        col = row;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                a[i][j] = a_temp[i][j];
            }
        }
    }
    //이제 이동
    move(a);
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    l = lock;
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key[i].size(); j++){
            map[i][j] = key[i][j];
        }
    }
    for(int i=0; i<lock.size(); i++){
        l_row = lock.size();
        for(int j=0; j<lock[i].size(); j++){
            l_col = lock[i].size();
            if(lock[i][j] == 0){
                final_lock++;
            }
        }
    }
    row = key.size();
    col = key[0].size();
    //회전->시계방향 회전x, 90, 180, 270 총 4가지 경우
    //이동->위, 아래, 오, 왼 총 4가지 경우
    
    //회전x
    //90도 회전
    //180도 회전
    //270도 회전
    for(int i=0; i<4; i++){
        rotation(i, map);
        if(check == true){
            break;
        }
    }
        
    return check;
}