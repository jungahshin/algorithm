//톱니바퀴
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k, t_num, t_dir;
string v[4];
char t_1[8];
char t_2[8];
char t_3[8];
char t_4[8];
vector<pair<int, int>> turn;
int temp[2] = {-1, 1};//왼쪽, 오른쪽
int score = 0;
queue<pair<int, int>> q;

void cal(int x, int y){//계산하기
    if(x == 1){
        if(y == 1){//시계
            t_1[0] = v[0][7];
            for(int i=0; i<7; i++){
                t_1[i+1] = v[0][i];
            }
        }else{//반시계
            t_1[7] = v[0][0];
            for(int i=1; i<8; i++){
                t_1[i-1] = v[0][i];
            }
        }
    }else if(x == 2){
        if(y == 1){//시계
            t_2[0] = v[1][7];
            for(int i=0; i<7; i++){
                t_2[i+1] = v[1][i];
            }
        }else{//반시계
            t_2[7] = v[1][0];
            for(int i=1; i<8; i++){
                t_2[i-1] = v[1][i];
            }
        }
    }else if(x == 3){
        if(y == 1){//시계
            t_3[0] = v[2][7];
            for(int i=0; i<7; i++){
                t_3[i+1] = v[2][i];
            }
        }else{//반시계
            t_3[7] = v[2][0];
            for(int i=1; i<8; i++){
                t_3[i-1] = v[2][i];
            }
        }
    }else if(x == 4){
        if(y == 1){//시계
            t_4[0] = v[3][7];
            for(int i=0; i<7; i++){
                t_4[i+1] = v[3][i];
            }
        }else{//반시계
            t_4[7] = v[3][0];
            for(int i=1; i<8; i++){
                t_4[i-1] = v[3][i];
            }
        }
    }
}

void go(){
    for(int i=0; i<turn.size(); i++){//회전 횟수만큼
        //여기서 v가 바뀌어야 함
        for(int i=0; i<8; i++){
            v[0][i] = t_1[i];
            v[1][i] = t_2[i];
            v[2][i] = t_3[i];
            v[3][i] = t_4[i];
        }

        int visited[4] = {0, };//바퀴 방문 여부
        q.push(make_pair(turn[i].first, turn[i].second));

        while(!q.empty()){
            int x = q.front().first;//바퀴 번호
            int y = q.front().second;//바퀴 회전 방향
            //본격 회전한 값 넣기
            q.pop();
            cal(x, y);
            visited[x-1] = 1;

            for(int i=0; i<2; i++){//왼쪽 오른쪽
                int dx = x+temp[i];
                if(1 <= dx && dx <= 4 && !visited[dx-1]){
                    visited[dx-1] = 1;
                    //방향 판별하기
                    if(i == 0){//왼쪽
                        if(v[x-1][6] != v[dx-1][2]){
                            if(y == 1){//시계
                                q.push(make_pair(dx, -1));
                            }else if(y == -1){//반시계
                                q.push(make_pair(dx, 1));
                            }
                        }
                    }else if(i == 1){//오른쪽
                        if(v[x-1][2] != v[dx-1][6]){//반대방향으로 회전
                            if(y == 1){//시계
                                q.push(make_pair(dx, -1));
                            }else if(y == -1){//반시계
                                q.push(make_pair(dx, 1));
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    for(int i=0; i<4; i++){//4개의 톱니바퀴
        cin>>v[i];
    }

    for(int i=0; i<8; i++){
        t_1[i] = v[0][i];
        t_2[i] = v[1][i];
        t_3[i] = v[2][i];
        t_4[i] = v[3][i];
    }

    cin>>k;
    for(int i=0; i<k; i++){
        cin>>t_num>>t_dir;//톱니바퀴 번호, 회전 방향
        turn.push_back(make_pair(t_num, t_dir));
    }

    go();
    
    if(t_1[0] == '1'){
        score += 1;
    }
    if(t_2[0] == '1'){
        score += 2;
    }
    if(t_3[0] == '1'){
        score += 4;
    }
    if(t_4[0] == '1'){
        score += 8;
    }
    cout<<score<<"\n";

    return 0;
}