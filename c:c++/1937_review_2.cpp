//욕심쟁이 판다 복습
#include <iostream>
using namespace std;

int n;
int forest[501][501] = {0, };
int DP[501][501] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;

int eat(int x, int y){
    if(DP[x][y] != 1){
        return DP[x][y];
    }

    for(int i=0; i<4; i++){
        int final_x = x+dx[i];
        int final_y = y+dy[i];
        if(0<=final_x && final_x<n && 0<=final_y && final_y<n){
            if(forest[final_x][final_y]>forest[x][y]){
                DP[x][y] = max(DP[x][y], eat(final_x, final_y)+1);
            }
        }
    }

    return DP[x][y];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>forest[i][j];
            DP[i][j] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            final = max(final, eat(i, j));
        }
    }
    cout<<final<<"\n";
    return 0;
}