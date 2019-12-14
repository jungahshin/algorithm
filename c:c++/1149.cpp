//RGB거리->DP, BFS는 메모리 초과,,,
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, r, g, b;
int cost[1001][4] = {0, };
int final = INT_MAX;
int dp[1001][4];//같은 index에 같은 색깔 최소 값 저장

int go(int color, int index){
    if(index == n-1){
        dp[index][color] = cost[index][color];
        return cost[index][color];
    }

    if(dp[index][color] != INT_MAX){
        return dp[index][color];
    }else{
        int final_index = index + 1;
        if(0 <= final_index < n){
            if(color == 0){//R
                dp[index][color] = min(dp[index][color], go(1, final_index)+cost[index][color]);
                dp[index][color] = min(dp[index][color], go(2, final_index)+cost[index][color]);
            }else if(color == 1){//G
                dp[index][color] = min(dp[index][color], go(0, final_index)+cost[index][color]);
                dp[index][color] = min(dp[index][color], go(2, final_index)+cost[index][color]);
            }else if(color == 2){//B
                dp[index][color] = min(dp[index][color], go(0, final_index)+cost[index][color]);
                dp[index][color] = min(dp[index][color], go(1, final_index)+cost[index][color]);
            }
        }
        return dp[index][color];
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>r>>g>>b;
        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }

    for(int i=0; i<1001; i++){
        for(int j=0; j<4; j++){
            dp[i][j] = INT_MAX;
        }
    }
    go(0, 0);//R
    go(1, 0);//G
    go(2, 0);//B

    final = min(dp[0][0], dp[0][1]);
    final = min(final, dp[0][2]);

    cout<<final<<"\n";
}