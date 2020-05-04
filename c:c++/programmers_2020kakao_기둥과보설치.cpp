#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int N = 0;
int wall[101][101][3] = {0, };

bool go(int x, int y, int kind){
    if(kind == 0){//기둥
        //1)바닥 위
        if(y == 0){
            return 1;
        }
        //2)기둥 위
        if(wall[x][y-1][0] == 1 && 0<=y-1){
            return 1;
        }
        //3)보의 끝 부분
        if((0<=x-1 && wall[x-1][y][1] == 1) || wall[x][y][1] == 1){
            return 1;
        }
    }else{
        //1)한쪽 끝 부분 기둥 위
        if((wall[x][y-1][0] == 1 && 0<=y-1) || (wall[x+1][y-1][0] == 1 && x+1<=N && 0<=y-1)){
            return 1;
        }
        //2)양쪽 끝 부분이 동시에 보와 연결
        if((wall[x-1][y][1] == 1 && 0<=x-1) && (wall[x+1][y][1] == 1 && x+1<=N)){
            return 1;
        }
    }
    return 0;
}

bool remove(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<2; k++){
                if(wall[i][j][k] == 1){
                    wall[i][j][k] = 0;
                    if(go(i, j, k) == 0){//조건에 어긋난다.
                        wall[i][j][k] = 1;//일단 다시 넣고
                        return 0;
                    }
                    wall[i][j][k] = 1;
                }
            }
        }
    }
    //제거했는데도 모두 조건에 만족한다.
    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for(int i=0; i<build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if(a == 0){//기둥
            if(b == 0){//삭제
                wall[x][y][0] = 0;
                if(remove() == 0){//삭제했는데 조건에 어긋난다.
                    wall[x][y][0] = 1;//다시 넣어
                }
            }else{//추가
                if(go(x, y, a) == 1){
                    wall[x][y][a] = 1;
                }
            }
        }else{//보
            if(b == 0){//삭제
                wall[x][y][1] = 0;
                if(remove() == 0){//조건에 어긋남.
                    wall[x][y][1] = 1;//다시 넣어
                }
            }else{//추가
                if(go(x, y, a) == 1){
                    wall[x][y][a] = 1;
                }
            }
        }
    }
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<2; k++){
                if(wall[i][j][k] == 1){
                    vector<int> final;
                    final.push_back(i);
                    final.push_back(j);
                    final.push_back(k);
                    answer.push_back(final);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}