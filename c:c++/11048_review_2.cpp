//이동하기 복습
#include <iostream>
#include <algorithm>
using namespace std;

int candy[1001][1001] = {0, };
int DP[1001][1001] = {0, };
int dx[3] = {0, -1, -1};
int dy[3] = {-1, 0, -1};
int n, m;

void play(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(DP[i][j] == 0){
                for(int k=0; k<3; k++){
                    int final_x = i+dx[k];
                    int final_y = j+dy[k];
                    if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                        DP[i][j] = max(DP[final_x][final_y]+candy[i][j], DP[i][j]);
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>candy[i][j];
        }
    }
    DP[0][0] = candy[0][0];
    play();
    cout<<DP[n-1][m-1]<<"\n";
}