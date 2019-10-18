//경로찾기 복습
#include <iostream>
#include <vector>
using namespace std;

int a[101][101] = {0, };
int a_copy[101][101] = {0, };
int visited[101][101] = {0, };
int n;

void dfs(int idx, int i){
    for(int k=1; k<=n; k++){//열 기준
        if(a[i][k] == 1 && !visited[idx][k]){
            visited[idx][k] = 1;
            a_copy[idx][k] = 1;
            dfs(idx, k);
        }
    }
}

void go(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == 1 && !visited[i][j]){
                visited[i][j] = 1;
                a_copy[i][j] = 1;
                dfs(i,j);//i가 기준 j가 탐색시작하는 점
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    go();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<a_copy[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}