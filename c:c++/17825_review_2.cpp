//주사위윷놀이 복습
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dice;
//-1>시작지점, 0>도착지점
//25, 30, 35, 40은 반드시 확인 또 해줘야 해 배열마다 겹치는 구간이기 때문에!!!!!!!!!!!!!!!!!!!!!!
int way1[22] = {-1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0};//1번 배열(기본)
int way2[9] = {10, 13, 16, 19, 25, 30, 35, 40, 0};//2번 배열
int way3[8] = {20, 22, 24, 25, 30, 35, 40, 0};//3번 배열
int way4[9] = {30, 28, 27, 26, 25, 30, 35, 40, 0};//4번 배열
vector<pair<int, int>> horse;//말이 현재 위치해있는 배열 번호와 idx(칸) 저장
int final = 0;

bool check(int array, int idx, vector<pair<int, int>> temp){
    bool temp2 = true;
    if((array == 1 && idx == 20) || (array == 2 && idx == 7) || (array == 3 && idx == 6) || (array == 4 && idx == 7)){
        for(int j=0; j<4; j++){
            if((temp[j].first == 2 && temp[j].second == 7) ||(temp[j].first == 3 && temp[j].second == 6) || (temp[j].first == 4 && temp[j].second == 7) || (temp[j].first == 1 && temp[j].second == 20)){
                temp2 = false;
            }
        }
    }else if((array == 2 && idx == 4) || (array == 3 && idx == 3) || (array == 4 && idx == 4)){
        for(int j=0; j<4; j++){
            if((temp[j].first == 2 && temp[j].second == 4) || (temp[j].first == 3 && temp[j].second == 3) || (temp[j].first == 4 && temp[j].second == 4)){
                temp2 = false;
            }
        }
    }else if((array == 2 && idx == 5) || (array == 3 && idx == 4) || (array == 4 && idx == 5)){
        for(int j=0; j<4; j++){
            if((temp[j].first == 2 && temp[j].second == 5) || (temp[j].first == 3 && temp[j].second == 4) || (temp[j].first == 4 && temp[j].second == 5)){
                temp2 = false;
            }
        }
    }else if((array == 2 && idx == 6) || (array == 3 && idx == 5) || (array == 4 && idx == 6)){
        for(int j=0; j<4; j++){
            if((temp[j].first == 2 && temp[j].second == 6) || (temp[j].first == 3 && temp[j].second == 5) || (temp[j].first == 4 && temp[j].second == 6)){
                temp2 = false;
            }
        }
    }

    for(int i=0; i<4; i++){
        if(temp[i].first == array && temp[i].second == idx){
            temp2 = false;
        }
    }    
    return temp2;
}

void play(int k, vector<pair<int, int>> temp, int score){
    if(k==10){
        final = max(final, score);
        return;
    }
    vector<pair<int, int>> temp2;
    for(int i=0; i<temp.size(); i++){
        temp2.push_back(make_pair(temp[i].first, temp[i].second));
    }
    int num = dice[k];//주사위 수
    //항상 이동해보고 horse벡터에 이동한 후 칸에 말이 없는지 확인 후 위치 확정하기!-->25, 30, 35, 40 확인 잘해주기...!
    for(int j=0; j<4; j++){//말 마다 진행
        bool real = false;
        int array = temp2[j].first;
        int idx = temp2[j].second;
        int next_idx = idx;
        if((array==1 && idx==21) || (array==2 && idx==8) || (array==3 && idx==7) || (array==4 && idx==8)){
            continue;
        }
        for(int t=0; t<num; t++){
            if(array == 1){
                next_idx++;
                if(next_idx == 21){
                    break;
                }
            }else if(array == 2){
                next_idx++;
                if(next_idx == 8){
                    break;
                }
            }else if(array == 3){
                next_idx++;
                if(next_idx == 7){
                    break;
                }
            }else if(array == 4){
                next_idx++;
                if(next_idx == 8){
                    break;
                }
            }                
        }
        if(array == 1 && way1[next_idx] == 10){
            array = 2;
            next_idx = 0;
        }
        if(array == 1 && way1[next_idx] == 20){
            array = 3;
            next_idx = 0;
        }
        if(array == 1 && way1[next_idx] == 30){
            array = 4;
            next_idx = 0;
        }
        //이동 후 위치에 말이 없는 것 확인 후
        if((array==1 && next_idx==21) || (array==2 && next_idx==8) || (array==3 && next_idx==7) || (array==4 && next_idx==8)){
            temp2[j].first = array;
            temp2[j].second = next_idx;
            play(k+1, temp2, score);
            temp2[j].first = temp[j].first;
            temp2[j].second = temp[j].second;
        }else{
            if(check(array, next_idx, temp2) == true){
                //위치 udpate하기
                temp2[j].first = array;
                temp2[j].second = next_idx;
                int score_temp = 0;
                if(array == 1){
                    score_temp = way1[next_idx];
                }else if(array == 2){
                    score_temp = way2[next_idx];
                }else if(array == 3){
                    score_temp = way3[next_idx];
                }else if(array == 4){
                    score_temp = way4[next_idx];
                }
                play(k+1, temp2, score+score_temp);
                temp2[j].first = temp[j].first;
                temp2[j].second = temp[j].second;
            }
        }
    }
}

int main(){
    for(int i=0; i<10; i++){
        cin>>n;//주사위에 나올 수
        dice.push_back(n);
    }
    for(int i=0; i<4; i++){
        horse.push_back(make_pair(1, 0));
    }
    play(0, horse, 0);
    cout<<final<<"\n";
}