//스티커
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int testcase, n;
int a[3][100010] = {0, };
int DP[3][100010] = {0, };
vector<int> final;
int num = 0;

int go(int x, int y){
    if(DP[x][y] != 0){
        return DP[x][y];
    }

    if(y == 1){
        if(x == 0){
            return DP[0][1];
        }else if(x == 1){
            return DP[1][1];
        }
    }else if(y == 2){
        if(x == 0){
            return DP[0][2];
        }else if(x == 1){
            return DP[1][2];
        }
    }

    if(x == 0){//0행이면
        DP[0][y] = max(go(1, y-1), go(1, y-2)) + a[0][y];
        return DP[0][y];
    }else if(x == 1){
        DP[1][y] = max(go(0, y-1), go(0, y-2)) + a[1][y];
        return DP[1][y];
    }
    return 0;
}

int main(){
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++){
        scanf("%d", &n);
        for(int k=0; k<2; k++){//행
            for(int j=1; j<=n; j++){//열
                scanf("%d", &a[k][j]);
            }            
        }
        num = 0;
        memset(DP, 0, sizeof(DP));
        DP[0][1] = a[0][1];
        DP[0][2] = a[0][2] + a[1][1];
        DP[1][1] = a[1][1];
        DP[1][2] = a[1][2] + a[0][1];
        num = max(go(1, n), go(0, n));
        final.push_back(num);
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}