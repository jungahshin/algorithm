//적록색약
#include <iostream>
#include <cstdio>
using namespace std;
char input[101][101];
int visited[101][101] = {0, };
int visited_RG[101][101] ={0, };
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int area = 0;//일반인
int area_RG= 0;//적록색맹
int n;

void dfs(int x, int y){//일반인
    for(int i=0; i<4; i++){
        int final_x = x+dx[i];
        int final_y = y+dy[i];
        if(0<=final_x<n && 0<=final_y<n){
            if(input[final_x][final_y] == input[x][y] && !visited[final_x][final_y]){//들어 있는 값이 같으면, dfs 반복
                visited[final_x][final_y] = 1;
                dfs(final_x, final_y);
            }
        }
    }
}

void dfs_RG(int x, int y){//적록 색맹
    for(int i=0; i<4; i++){
        int final_x = x+dx[i];
        int final_y = y+dy[i];
        if(0<=final_x<n && 0<=final_y<n){
            if(input[x][y] == 'R' && !visited_RG[final_x][final_y]){//적
                if(input[final_x][final_y] == 'R' || input[final_x][final_y] == 'G'){
                    visited_RG[final_x][final_y] = 1;
                    dfs_RG(final_x, final_y);
                }
            }
            if(input[x][y] == 'G' && !visited_RG[final_x][final_y]){//록
                if(input[final_x][final_y] == 'G' || input[final_x][final_y] == 'R'){
                    visited_RG[final_x][final_y] = 1;
                    dfs_RG(final_x, final_y);
                }
            }
            if(input[x][y] == 'B' && !visited_RG[final_x][final_y]){
                if(input[final_x][final_y] == 'B'){
                    visited_RG[final_x][final_y] = 1;
                    dfs_RG(final_x, final_y);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }

    for(int i=0; i<n; i++){//일반인
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                area++;
                dfs(i, j);
            }
        }
    }

    for(int i=0; i<n; i++){//적록색맹
        for(int j=0; j<n; j++){
            if(!visited_RG[i][j]){
                visited_RG[i][j] = 1;
                area_RG++;
                dfs_RG(i, j);
            }
        }
    }
    
    cout<<area<<" "<<area_RG<<"\n";
    return 0;
}