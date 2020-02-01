//⚾복습
#include <iostream>
#include <cstring>
using namespace std;

int seq[10] = {0, };
int seq_copy[10] = {0, };
int score[51][10] = {0, };//이닝마다 점수
int ground[4] = {0,};//그라운드 1루, 2루, 3루 채워진 여부
int visited[10] = {0, };
int final = 0;
int n;

void copy(){
    for(int i=1; i<4; i++){
        seq_copy[i] = seq[i];
    }
    seq_copy[4] = 1;
    for(int i=4; i<=8; i++){
        seq_copy[i+1] = seq[i];
    }
}

void go(){
    copy();
    int a = 1;//타순(idx)
    int num = 0;//득점 수
    for(int i=0; i<n; i++){
        int fail = 0;//아웃 수
        memset(ground, 0, sizeof(ground));
        int temp_num = 0;
        while(fail<3){
            int temp = score[i][(seq_copy[a]-1)];//이만큼 움직여
            if(temp == 0){//아웃
                fail++;
                a++;
            }else{
                int ground_copy[4] = {0, };
                for(int j=2; j>=0; j--){
                    if(ground[j] == 1){
                        if((j+temp) <= 2){
                            ground_copy[j] = 0;
                            ground_copy[j+temp] = 1;
                        }else if((j+temp) > 2){
                            ground_copy[j] = 0;
                            temp_num++;
                        }
                    }
                }           
                if(temp < 4){
                    ground_copy[temp-1] = 1;                    
                }else if(temp == 4){
                    temp_num++;
                }
                for(int j=0; j<3; j++){
                    ground[j] = ground_copy[j];
                }
                a++;
            }
            if(a == 10){
                a = 1;//다시 1타수부터 시작
            }
        }
        num += temp_num;
    }    
    final = max(final, num);
}

void choose(int idx, int sequence, int num){
    if(num == 1){
        seq[sequence] = idx;
        if(sequence == 8){
            memset(seq_copy, 0, sizeof(seq_copy));
            go();
            return;
        }
        choose(1, sequence, 0);
    }

    for(int i=idx; i<=9; i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        sequence++;

        choose(i, sequence, num+1);
        visited[i] = false;
        sequence--;
    }
}

int main(){
    cin>>n;
    for(int j=0; j<n; j++){
        for(int i=0; i<9; i++){
            cin>>score[j][i];
        }        
    }
    visited[1] = 1;
    choose(1, 0, 0);
    cout<<final<<"\n";
}