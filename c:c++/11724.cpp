#include <iostream>
using namespace std;
//#include <stdio.h>
int input[1001][1001]={0, };
int visited[1001][1001]={0, };
int connected_component = 0;
int a,b,m,n ;
int sum = 0;

void dfs(int x, int y){
    for(int i=1; i<=a; i++){
        if(input[y][i] && !visited[y][i]){
            visited[y][i] = 1;
            visited[i][y] = 1;
            dfs(y,i);
        }
    }
}

int main(){
    //scanf("%d %d", &a, &b);//a-정점, b-간선
    cin>>a>>b;
    if(a<1 || a>1000 || b<0 || b>a*(a-1)/2){
        return 0;
    }
    if(b>0){
         for(int i=1; i<=b; i++){//간선의 개수 b만큼 입력을 받는다
            //scanf("%d %d", &m, &n);//연결된 두 정점 m과 n
            cin>>m>>n;
            input[m][n]=1;//무방향 그래프
            input[n][m]=1;
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
    if(m<1 || n>a){
        return 0;
    }
    }

    //전혀 간선이 하나도 없는 정점은 무조건 connected_component++해준다.
    for(int i=1; i<=a; i++){
        for(int j=1; j<=a; j++){
            sum += input[i][j];
        }
        if(sum == 0){
            connected_component++;
        }
        sum = 0;
    }

    cout<<connected_component<<"\n";
}

