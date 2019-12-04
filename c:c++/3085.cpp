//사탕게임
#include <iostream>
#include <algorithm>
using namespace std;

int n;
char candy[51][51];
char candy_temp[51][51];//모든 경우의 수를 다 수행해보는 임시 배열
int change_x = 0;
int change_y = 0;
int final = 0;

void copy_line(){//행
    //복사하기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            candy_temp[i][j] = candy[i][j];
        }
    }
    //위치 바꾸기(사탕 교환)
    candy_temp[change_x][change_y+1] = candy[change_x][change_y];
    candy_temp[change_x][change_y] = candy[change_x][change_y+1];
}

void copy_row(){//열
    //복사하기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            candy_temp[i][j] = candy[i][j];
        }
    }
    //위치 바꾸기(사탕 교환)
    candy_temp[change_x+1][change_y] = candy[change_x][change_y];
    candy_temp[change_x][change_y] = candy[change_x+1][change_y];
}

void play_line(){//행
    copy_line();
    for(int i=0; i<n; i++){//행
        int num = 1;
        for(int j=0; j<n-1; j++){
            if(candy_temp[i][j] == candy_temp[i][j+1]){
                num++;
            }else{
                num = 1;
            }
            final = max(final, num);
        }
    }
    for(int i=0; i<n; i++){//열
        int num = 1;
        for(int j=0; j<n-1; j++){
            if(candy_temp[j][i] == candy_temp[j+1][i]){
                num++;
            }else{
                num = 1;
            }
            final = max(final, num);
        }
    }
}

void play_row(){//열
    copy_row();
    //같은 색으로 가장 긴 연속 부분을 먹는다.
    for(int i=0; i<n; i++){//행
        int num = 1;
        for(int j=0; j<n-1; j++){
            if(candy_temp[i][j] == candy_temp[i][j+1]){
                num++;
            }else{
                num = 1;
            }
            final = max(final, num);
        }
    }
    for(int i=0; i<n; i++){//열
        int num = 1;
        for(int j=0; j<n-1; j++){
            if(candy_temp[j][i] == candy_temp[j+1][i]){
                num++;
            }else{
                num = 1;
            }
            final = max(final, num);
        }
    }
}

void ready(){
    //인접하고 다른 사탕의 색을 가지고 있는 모든 경우->게임 수행
    for(int i=0; i<n; i++){//행 부터 인접한 경우
        for(int j=0; j<n-1; j++){
            if(candy[i][j] != candy[i][j+1]){
                change_x = i;
                change_y = j;
                play_line();
            }
        }
    }
    for(int i=0; i<n; i++){//열 인접한 경우
        for(int j=0; j<n-1; j++){
            if(candy[j][i] != candy[j+1][i]){
                change_x = j;
                change_y = i;
                play_row();
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>candy[i][j];
        }
    }
    ready();
    cout<<final<<"\n";
}