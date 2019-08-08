#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b;

int input[101][101];
int visited[101][101] = {0, };
// int dx[4] = {0,0,-1,1};
// int dy[4] = {-1,1,0,0};
int num = 0;

void dfs(int top, int x, int y){
    // for(int i=0; i<4; i++){
    //     int final_x = x+dx[i];
    //     int final_y = y+dy[i];
    //     if(0<final_x<=n && 0<final_y<=n){
    //         if(!visited[final_x][final_y] && input[final_x][final_y]){
                
    //         }
    //     }
    // }
    for(int i=1; i<=n; i++){
        if(!visited[top][i] && input[y][i]){
            visited[top][i] = 1;
            num++;
            dfs(top, y, i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    if(n<2 || n>100 || m<1 || m>5000){
        return 0;
    }
    vector<int> v;

    for(int i=0; i<m; i++){
        cin>>a>>b;
        input[a][b] = 1;
        input[b][a] = 1;
    }

    for(int i =1; i<=n; i++){//top
        for(int j=1; j<=n; j++){
            if(input[i][j] && !visited[i][j]){
                visited[i][j] = 1;
                num++;
                dfs(i, i, j);//top, x, y
            }
        }
        v.push_back(num);//top마다 베이컨 총 수 
        num = 0;//top이 바뀌니까 초기화
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}