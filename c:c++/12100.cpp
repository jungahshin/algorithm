//2048(easy)
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[21][21] = {0, };
int a_copy[21][21] = {0, };
int final = 0;

void copy(int a_[][21]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_copy[i][j] = a_[i][j];
        }
    }
}

void check(int a_[][21]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            final = max(final, a_[i][j]);
        }
    }
}

int (*move(int a_[][21], int dir))[21]{
    copy(a_);
    int temp[21][21] = {0, };
    if(dir == 0){
        for(int i=0; i<n; i++){//열 기준
            int idx = 0;//a에 들어갈 idx
            int num = 0;//전의 값 저장
            for(int j=0; j<n; j++){//행 증가
                if(a_copy[j][i] != 0){
                    if(num != a_copy[j][i]){
                        temp[idx][i] = a_copy[j][i];
                        idx++;
                        num = a_copy[j][i];
                    }else{
                        temp[idx-1][i] = num * 2;
                        num = 0;
                    }                
                }
            }
        }
    }
    else if(dir == 1){
        for(int i=0; i<n; i++){//열 기준
            int idx = n-1;
            int num = 0;
            for(int j=n-1; j>=0; j--){//행 감소
                if(a_copy[j][i] != 0){
                    if(num != a_copy[j][i]){
                        temp[idx][i] = a_copy[j][i];
                        idx--;
                        num = a_copy[j][i];
                    }else{
                        temp[idx+1][i] = num * 2;
                        num = 0;
                    }                
                }
            }
        }
    }
    else if(dir == 2){
        for(int i=0; i<n; i++){//행 기준
            int idx = 0;
            int num = 0;
            for(int j=0; j<n; j++){
                if(a_copy[i][j] != 0){
                    if(num != a_copy[i][j]){
                        temp[i][idx] = a_copy[i][j];
                        idx++;
                        num = a_copy[i][j];
                    }else{
                        temp[i][idx-1] = num * 2;
                        num = 0;
                    }                
                }
            }
        }
    }
    else if(dir == 3){
        for(int i=0; i<n; i++){//행 기준
            int idx = n-1;
            int num = 0;
            for(int j=n-1; j>=0; j--){
                if(a_copy[i][j] != 0){
                    if(num != a_copy[i][j]){
                        temp[i][idx] = a_copy[i][j];
                        idx--;
                        num = a_copy[i][j];
                    }else{
                        temp[i][idx+1] = num * 2;
                        num = 0;
                    }                
                }
            }
        }
    }
    //temp값을 다시 a에 넣어준다.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_copy[i][j] = temp[i][j];
        }
    }
    return a_copy;
}

void play(int num, int a_[][21]){
    if(num == 4){//5방향으로 이동을 다 했으면 반환한다.
        check(a_);
        return;
    }
    int b[21][21] = {0, };
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            b[i][j] = a_[i][j];
        }
    }
    for(int i=0; i<4; i++){          
        play(num+1, move(b, i));
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<4; i++){
        play(0, move(a, i));
    }
    cout<<final<<"\n";
    return 0;
}