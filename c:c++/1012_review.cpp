//유기농 배추 복습
#include <iostream>
#include <vector>
using namespace std;

int a[51][51] = {0, };
int visited[51][51] = {0, };
int num = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<int> final;
int t, m, n, k, x, y;

void dfs(int i, int j){
    int x_ = i;
    int y_ = j;
    for(int k=0; k<4; k++){
        int nx = x_+dx[k];
        int ny = y_+dy[k];
        if(0<=nx && nx<m && 0<=ny && ny<n){
            if(a[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = 1;
                dfs(nx, ny);
            }
        }
    }
}

void go(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 1 && !visited[i][j]){
                num++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>m>>n>>k;
        for(int j=0; j<k; j++){//배추의 개수
            cin>>x>>y;
            a[x][y] = 1;
        }
        go();
        final.push_back(num);
        num = 0;
        for(int h=0; h<51; h++){
            for(int j=0; j<51; j++){
                a[h][j] = 0;
                visited[h][j] = 0;
            }
        }
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
    return 0;
}