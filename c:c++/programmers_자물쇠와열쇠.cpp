// 자물쇠와 열쇠
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int l_row, l_col, row, col;
int KEY[21][21] = {0, };
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};
int final_lock = 0;

// lock과 key가 일치하는지 확인
bool move(int key[21][21], vector<vector<int>> lock)
{
    for(int i=0; i<l_row; i++){
        for(int j=0; j<l_col; j++){            
            for(int p=0; p<4; p++){ // 상, 하, 좌, 우 4방향으로 가능하다.
                bool check = true;
                int num = 0; // Lock의 홈 개수 세기
                int k_r = 0, k_c = 0; // key의 위치
                // lock의 시작점
                int l_r = i;
                int l_c = j;
                // 이동할 방향
                int r_idx = dx[p];
                int c_idx = dy[p];
                // key의 시작점 잡기
                if(r_idx==1 && c_idx==-1){
                    k_r = 0;
                    k_c = col-1;
                }else if(r_idx==-1 && c_idx==-1){
                    k_r = row-1;
                    k_c = col-1;
                }else if(r_idx==-1 && c_idx==1){
                    k_r = row-1;
                    k_c = 0;
                }
                while(1){
                    if((lock[l_r][l_c]+key[k_r][k_c]) == 1){
                        // 돌기와 돌기가 만나거나 홈과 홈이 만나거나
                        if(lock[l_r][l_c]==0){
                            num++;
                        }
                    }else{
                        check = false;
                        break;
                    }
                    l_c += c_idx;
                    k_c += c_idx;
                    if(l_c>=l_col || l_c<0 || k_c>=col || k_c<0){
                        l_r += r_idx;
                        k_r += r_idx;
                        l_c = j;
                        if(c_idx==-1){
                            k_c = col-1;
                        }else if(c_idx==1){
                            k_c = 0;
                        }
                        if(l_r>=l_row || l_r<0 || k_r>=row || k_r<0){
                            break;
                        }
                    }
                }
                
                if(check==true){
                    if(final_lock==num){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// key를 시계방향으로 90도 돌리기
bool rotate(int num, int key[21][21], vector<vector<int>> lock) // key를 i만큼 시계방향으로 90도 회전시킨다.
{
    int key_temp[21][21] = {0, };
    int temp = 0;
    while(1){
        temp++;
        if(temp>num){
            break;
        }
        int col_temp = row-1;//이것이 열이 된다.
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                key_temp[j][col_temp] = key[i][j];
            }
            col_temp--;
        }
        //행과 열의 수가 바뀐다.
        row = col;
        col = row;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                key[i][j] = key_temp[i][j];
            }
        }
    }
    
    // lock에 key를 대보면서 맞는지 확인한다.
    if(move(KEY, lock)==true){
        return true;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    row = key.size();
    col = key[0].size();
    l_row = lock.size();
    l_col = lock[0].size();
    
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key[i].size(); j++){
            KEY[i][j] = key[i][j];
        }
    }
    
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock[i].size(); j++){
            if(lock[i][j]==0){
                final_lock++;
            }
        }
    }
    
    for(int i=0; i<4; i++){
        if(rotate(i, KEY, lock)==true){
            answer = true;
            break;
        }else{
            answer = false;
        }
    }
    
    return answer;
}