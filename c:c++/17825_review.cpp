//주사위 윷놀이
#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, int>> horse;//말의 위치를 저장하는 벡터(리스트이름, 리스트 idx)
int move_[11] = {0, };//이동 수를 저장
int a[22] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0};//21
int b[9] = {10, 13, 16, 19, 25, 30, 35, 40, 0};//8
int c[8] = {20, 22, 24, 25, 30, 35, 40, 0};//7
int d[9] = {30, 28, 27, 26, 25, 30, 35, 40, 0};//8
int final = 0;

bool check(char temp, int idx, vector<pair<char, int>> horse_temp){
    bool check = false;
    if((temp == 'a' && idx == 20) || (temp == 'b' && idx == 7) || (temp == 'c' && idx == 6) || (temp == 'd' && idx == 7)){
        for(int j=0; j<4; j++){
            if((horse_temp[j].first == 'b' && horse_temp[j].second == 7) ||(horse_temp[j].first == 'c' && horse_temp[j].second == 6) || (horse_temp[j].first == 'd' && horse_temp[j].second == 7) || (horse_temp[j].first == 'a' && horse_temp[j].second == 20)){
                check = true;
            }
        }
    }else if((temp == 'b' && idx == 4) || (temp == 'c' && idx == 3) || (temp == 'd' && idx == 4)){
        for(int j=0; j<4; j++){
            if((horse_temp[j].first == 'b' && horse_temp[j].second == 4) || (horse_temp[j].first == 'c' && horse_temp[j].second == 3) || (horse_temp[j].first == 'd' && horse_temp[j].second == 4)){
                check = true;
            }
        }
    }else if((temp == 'b' && idx == 5) || (temp == 'c' && idx == 4) || (temp == 'd' && idx == 5)){
        for(int j=0; j<4; j++){
            if((horse_temp[j].first == 'b' && horse_temp[j].second == 5) || (horse_temp[j].first == 'c' && horse_temp[j].second == 4) || (horse_temp[j].first == 'd' && horse_temp[j].second == 5)){
                check = true;
            }
        }
    }else if((temp == 'b' && idx == 6) || (temp == 'c' && idx == 5) || (temp == 'd' && idx == 6)){
        for(int j=0; j<4; j++){
            if((horse_temp[j].first == 'b' && horse_temp[j].second == 6) || (horse_temp[j].first == 'c' && horse_temp[j].second == 5) || (horse_temp[j].first == 'd' && horse_temp[j].second == 6)){
                check = true;
            }
        }
    }

    for(int i=0; i<4; i++){
        if(horse_temp[i].first == temp && horse_temp[i].second == idx){
            check = true;
        }
    }            
    
    return check;
}

void dfs(int horse_num, int idx, int score, vector<pair<char, int>> horse_){//움직일 말의 번호와 이동 수(move[idx])
    if(idx == 10){
        final = max(final, score);
        return;
    }
    //move[idx]만큼 말을 움직인다.
    //a배열(그냥 계속 이동)
    if(horse_[horse_num-1].first == 'a'){
        if(horse_[horse_num-1].second == 21){//이미 도착한 상태이면 움직이지 못한다.
            return;
        }
        int final_idx = move_[idx]+horse_[horse_num-1].second;
        if(final_idx>20){
            final_idx = 21;
            horse_[horse_num-1].second = 21;
        }else{
            if(final_idx == 5){
                //b배열로 이동
                if(check('b', 0, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                    return;
                }
                horse_[horse_num-1].first = 'b';
                horse_[horse_num-1].second = 0;
            }else if(final_idx == 10){
                //c배열로 이동
                if(check('c', 0, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                    return;
                }
                horse_[horse_num-1].first = 'c';
                horse_[horse_num-1].second = 0;
            }else if(final_idx == 15){
                //d배열로 이동
                if(check('d', 0, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                    return;
                }
                horse_[horse_num-1].first = 'd';
                horse_[horse_num-1].second = 0;
            }else{
                //그냥 계속 a배열에서 이동
                if(check('a', final_idx, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                    return;
                }
                horse_[horse_num-1].second = final_idx;
            }
        }

        //dfs
        for(int i=0; i<4; i++){
            dfs(i+1, idx+1, score+a[final_idx], horse_);
        }
    }

    //b배열
    else if(horse_[horse_num-1].first == 'b'){
        if(horse_[horse_num-1].second == 8){
            return;
        }
        int final_idx = move_[idx]+horse_[horse_num-1].second;
        if(final_idx>7){
            final_idx = 8;
            horse_[horse_num-1].second = 8;
        }else{
            if(check('b', final_idx, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                return;
            }
            horse_[horse_num-1].second = final_idx;
        }

        //dfs
        for(int i=0; i<4; i++){
            dfs(i+1, idx+1, score+b[final_idx], horse_);
        }
    }

    //c배열
    else if(horse_[horse_num-1].first == 'c'){
        if(horse_[horse_num-1].second == 7){
            return;
        }
        int final_idx = move_[idx]+horse_[horse_num-1].second;
        if(final_idx>6){
            final_idx = 7;
            horse_[horse_num-1].second = 7;
        }else{
            if(check('c', final_idx, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                return;
            }
            horse_[horse_num-1].second = final_idx;
        }

        //dfs
        for(int i=0; i<4; i++){
            dfs(i+1, idx+1, score+c[final_idx], horse_);
        }
    }

    //d배열
    else if(horse_[horse_num-1].first == 'd'){
        if(horse_[horse_num-1].second == 8){
            return;
        }
        int final_idx = move_[idx]+horse_[horse_num-1].second;
        if(final_idx>7){
            final_idx = 8;
            horse_[horse_num-1].second = 8;
        }else{
            if(check('d', final_idx, horse_) == true){//이동하려는 곳에 이미 다른 말이 있는 경우
                return;
            }
            horse_[horse_num-1].second = final_idx;
        }

        //dfs
        for(int i=0; i<4; i++){
            dfs(i+1, idx+1, score+d[final_idx], horse_);
        }
    }
}

//말 4마리(시작 지점)
//이동하려는 칸에 이미 말이 있는 경우->return(dfs)
int main(){
    for(int i=0; i<10; i++){
        cin>>move_[i];
    }
    for(int i=0; i<4; i++){
        horse.push_back(make_pair('a', 0));
    }
    //일단은 1번 말부터 이동한다.
    dfs(1, 0, 0, horse);
    cout<<final<<"\n";
    return 0;
}