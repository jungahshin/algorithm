//욕심쟁이 판다
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int DP[501][501] = {0, };
int forest[501][501] = {0, };
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int final = 0;
//BFS+DP
//일단 for문으로 쭉돌면서 BFS진행하고 그 중에서 가장 일 수가 큰 값이 그 곳의 DP값이 된다.
//방문한 곳의 DP값이 이미 존재하면 (DP값 +1) 중 가장 큰 값이 자신의 DP값이 된다.

int eat(int a, int b){
    if(DP[a][b] != 0){
        return DP[a][b];
    }

    for(int i=0; i<4; i++){
        int final_x = a+dx[i];
        int final_y = b+dy[i];
        if(0<=final_x && final_x<n && 0<=final_y && final_y<n){
            if(forest[final_x][final_y]>forest[a][b]){
                DP[a][b] = max(DP[a][b], eat(final_x, final_y)+1);
            }
        }
    }

    return DP[a][b];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>forest[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ 
            final = max(eat(i, j)+1, final);         
        }
    }

    cout<<final<<"\n";
}