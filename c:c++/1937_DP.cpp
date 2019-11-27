//욕심쟁이 판다-->DP버전(시간 초과 해결)
//반대로 계속 더해 나가야 한다.
#include <iostream>
#include <algorithm>
using namespace std;

int forest[501][501] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int num[501][501] = {0, };
int final = 0;
int n;

int eat(int x, int y){
    if(num[x][y] != 0){
        return num[x][y];
    }else{
        num[x][y] = 1;
    }

    for(int i=0; i<4; i++){
        int final_x = x + dx[i];
        int final_y = y + dy[i];
        if(0 <= final_x && final_x <n && 0 <= final_y && final_y < n){
            if(forest[x][y] < forest[final_x][final_y]){
                num[x][y] = max(num[x][y], eat(final_x, final_y)+1);//돌아다니면서 num이 계속 정의가 된다., 여기도 그 중에서도 가장 큰 값이 된다.
            }
        }
    }

    return num[x][y];
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
            int temp = eat(i, j);
            final = max(final, temp);//dfs로 계속 들어가다가 맨 마지막에 i, j에 대한 num이 정의가 된다.
        }
    }
    cout<<final<<"\n";
}