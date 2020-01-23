//이동하기
#include <iostream>
using namespace std;

int n, m;
int candy[1001][1001] = {0, };
int DP[1001][1001] = {0, };//DP[a][b]는 (1, 1)에서 (a, b)까지 오는 데에 먹을 수 있는 최대 사탕 수
int dir_x[3] = {1, 0, 1};
int dir_y[3] = {0, 1, 1};

// //그냥 오른쪽, 아래쪽으로 움직이는 경우만 고려
// int eat(int x, int y){
//     if(DP[x][y] != 0){
//         return DP[x][y];
//     }
//     if(1<=x && x<=n && 1<=(x-1) && (x-1)<=n && 1<=y && y<=m && 1<=(y-1) && (y-1)<=m){
//         DP[x][y] = max(eat(x, y-1), eat(x-1, y))+candy[x][y];
//     }else if(1<=(x-1) && (x-1)<=n && 1<=y && y<=m){
//         DP[x][y] = eat(x-1, y)+candy[x][y];
//     }else if(1<=x && x<=n && 1<=(y-1) && (y-1)<=m){
//         DP[x][y] = eat(x, y-1)+candy[x][y];
//     }
//     return DP[x][y];
// }

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>candy[i][j];
        }
    }
    DP[1][1] = candy[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]) + candy[i][j];
        }
    }
    cout<<DP[n][m]<<"\n";
}