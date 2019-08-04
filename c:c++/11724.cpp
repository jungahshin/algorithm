#include <iostream>
using namespace std;
int input[1001][1001]={0, };
int visited[1001][1001]={0, };
int connected_component = 0;
int a,b,m,n = 0;

int dfs(int x, int y){
    for(int i=1; i<=a; i++){
        if(input[y][i] && !visited[y][i]){
            visited[y][i] = 1;
            visited[i][y] = 1;
            dfs(y,i);
        }
    }
}

int main(){
    scanf("%d %d", &a, &b);//a-정점, b-간선
    for(int i=1; i<=b; i++){//간선의 개수 b만큼 입력을 받는다
        scanf("%d %d", &m, &n);//연결된 두 정점 m과 n
        input[m][n]=1;//무방향 그래프
        input[n][m]=1;
    }
    if(m<1 || n>a){
        return 0;
    }
    for(int i=1; i<= a; i++){
        for(int j=1; j<=a; j++){
            if(input[i][j] && !visited[i][j]){
                visited[i][j] = 1;
                visited[j][i] = 1;
                connected_component++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n", connected_component);
}

