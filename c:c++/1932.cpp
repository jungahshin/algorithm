//정수 삼각형
#include <iostream>
using namespace std;

int triangle[501][501] = {0, };
int DP[501][501] = {0, };
int dx[2] = {-1, -1};
int dy[2] = {-1, 0};
int final = 0;
int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>triangle[i][j];
        }
    }
    DP[0][0] = triangle[0][0];
    //top-down 방식
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(DP[i][j] == 0){
                for(int k=0; k<2; k++){
                    int final_x = i+dx[k];
                    int final_y = j+dy[k];
                    if(final_y==-1 || final_x<final_y){
                        continue;
                    }
                    DP[i][j] = max(DP[i][j], DP[final_x][final_y]+triangle[i][j]);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        final = max(final, DP[n-1][i]);
    }
    cout<<final<<"\n";
}