//사다리 조작
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, h, a, b;
int A[31][11] = {0, };
int final = INT_MAX;
int really_final = 0;

void dfs(int idx, int n){
    for(int i=n; i<=h; i++){
        if(A[i][idx] == 1){
            idx++;
        }else if(A[i][idx-1] == 1){
            idx--;
        }
    }
    //여기에 나오면 끝났다는 것!
    really_final = idx;
}

bool prepare(){
    int temp = 0; 
    for(int i=1; i<=n; i++){//세로선 기준
        dfs(i, 1);
        if(really_final == i){
            temp++;
        }
    }
    if(temp == n){//성공!
        return true;
    }else{
        return false;
    }
}

void choose(int num){
    if(num > 3){
        return;
    }

    if(prepare() == true){
        final = min(final, num);
        return;//어차피 최소값이니까 여기에 한 번 들어가면 또 더 깊게 num+1을 할 필요가 없다
    }

    for(int i=1; i<=h; i++){//가장자리 부분
        for(int j=1; j<n; j++){
            if(A[i][j] == 1) continue;
            if(A[i][j-1] == 1) continue;
            if(A[i][j+1] == 1) continue;

            A[i][j] = 1;
            choose(num+1);
            A[i][j] = 0;
        }
    }

}

int main(){
    cin>>n>>m>>h;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        A[a][b] = 1;
    }

    choose(0);
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;

}