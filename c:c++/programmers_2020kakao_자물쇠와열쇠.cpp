//자물쇠와 열쇠(자물쇠와 열쇠가 같은 크기라는 가정)
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

//돌기와 돌기가 만나서는 안된다.

int map[21][21] = {0, };//키
int row, col;
int l_row, l_col;
int l_row_start, l_row_end, l_col_start, l_col_end;
int k_row_start, k_row_end, k_col_start, k_col_end;
vector<vector<int>> l;
vector<int> temp_key;
vector<int> temp_lock;
bool check = false;
int temp_num = 0;
int lock_num = 0;
int final_lock = 0;

//key 오른쪽이동->col_end--, 왼쪽이동->col_start++, 위로이동->row_start++, 아래이동->row_end--
//lock 오른->col_start++, 왼이동->col_end--, 위로->row_end--, 아래->row_start++
void move(int a[21][21]){
    for(int i=0; i<row; i++){//0~(row-1)만큼 이동 가능
        for(int j=0; j<col; j++){
            //i증가, j감소(아래, 왼)
            temp_key.clear();
            temp_lock.clear();
            //key
            for(int z=k_row_start; z<=(k_row_end-i); z++){
                for(int w=(k_col_start+j); w<=k_col_end; w++){
                    temp_key.push_back(a[z][w]);
                }
            }
            //lock
            for(int z=(l_row_start+i); z<=l_row_end; z++){
                for(int w=l_col_start; w<=(l_col_end-j); w++){
                    temp_lock.push_back(l[z][w]);
                }
            }
            //일치하는지 확인
            temp_num = 0;
            lock_num = 0;
            for(int k=0; k<temp_lock.size(); k++){
                if((temp_key[k]+temp_lock[k]) == 1){
                    if(temp_lock[k] == 0){//들어간 부분
                        lock_num++;
                    }
                    temp_num++;
                }
            }
            if((temp_num == temp_key.size()) && (lock_num == final_lock)){
                check = true;
            }
            if(check == true){
                break;
            }
            
            //i증가, j증가(아래, 오)
            temp_key.clear();
            temp_lock.clear();
            //key
            for(int z=k_row_start; z<=(k_row_end-i); z++){
                for(int w=k_col_start; w<=(k_col_end-j); w++){
                    temp_key.push_back(a[z][w]);
                }
            }
            //lock
            for(int z=(l_row_start+i); z<=l_row_end; z++){
                for(int w=(l_col_start+j); w<=l_col_end; w++){
                    temp_lock.push_back(l[z][w]);
                }
            }
            //일치하는지 확인
            temp_num = 0;
            lock_num = 0;
            for(int k=0; k<temp_lock.size(); k++){
                if((temp_key[k]+temp_lock[k]) == 1){
                    if(temp_lock[k] == 0){//들어간 부분
                        lock_num++;
                    }
                    temp_num++;
                }
            }
            if((temp_num == temp_key.size()) && (lock_num == final_lock)){
                check = true;
            }
            if(check == true){
                break;
            }
            
            //i감소, j감소(위, 왼)
            temp_key.clear();
            temp_lock.clear();
            //key
            for(int z=(k_row_start+i); z<=k_row_end; z++){
                for(int w=(k_col_start+j); w<=k_col_end; w++){
                    temp_key.push_back(a[z][w]);
                }
            }
            //lock
            for(int z=l_row_start; z<=(l_row_end-i); z++){
                for(int w=l_col_start; w<=(l_col_end-j); w++){
                    temp_lock.push_back(l[z][w]);
                }
            }
            //일치하는지 확인
            temp_num = 0;
            lock_num = 0;
            for(int k=0; k<temp_lock.size(); k++){
                if((temp_key[k]+temp_lock[k]) == 1){
                    if(temp_lock[k] == 0){//들어간 부분
                        lock_num++;
                    }
                    temp_num++;
                }
            }
            if((temp_num == temp_key.size()) && (lock_num == final_lock)){
                check = true;
            }
            if(check == true){
                break;
            }
            
            //i감소, j증가(위, 오)
            temp_key.clear();
            temp_lock.clear();
            //key
            for(int z=(k_row_start+i); z<=k_row_end; z++){
                for(int w=k_col_start; w<=(k_col_end-j); w++){
                    temp_key.push_back(a[z][w]);
                }
            }
            //lock
            for(int z=l_row_start; z<=(l_row_end-i); z++){
                for(int w=(l_col_start+j); w<=l_col_end; w++){
                    temp_lock.push_back(l[z][w]);
                }
            }
            //일치하는지 확인
            temp_num = 0;
            lock_num = 0;
            for(int k=0; k<temp_lock.size(); k++){
                if((temp_key[k]+temp_lock[k]) == 1){
                    if(temp_lock[k] == 0){//들어간 부분
                        lock_num++;
                    }
                    temp_num++;
                }
            }
            if((temp_num == temp_key.size()) && (lock_num == final_lock)){
                check = true;
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
    //idx
    k_col_start = 0;
    k_col_end = col-1;
    k_row_start = 0;
    k_row_end = row-1;
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
    //idx
    l_col_start = 0;
    l_col_end = lock[0].size()-1;
    l_row_start = 0;
    l_row_end = lock.size()-1;
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