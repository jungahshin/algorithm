#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int input[101][101] = {0, };
int visited[101][101] = {0, };
vector<int> output; 
int num = 0;
int tmp;
int m,n,k;
int left_x, left_y, right_x, right_y;

void dfs(int a, int b){
    visited[a][b] = 1;
    for(int i=0; i<4; i++){
        int nx = a+dx[i];
        int ny = b+dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<m){
            if(!visited[nx][ny] && input[nx][ny] == 0){//빈영역
                num++;
                dfs(nx, ny);
            }
        }
    }
}

int main(void){
    cin>> m>> n>> k;

    for(int i=0; i<k; i++){
        cin>>left_x>>left_y>>right_x>>right_y;

        for(int i= left_x; i<right_x; i++){
            for(int j=left_y; j<right_y; j++){
                input[i][j] = 1;
            }
        }
    }

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && input[i][j] == 0){
                num++;
                dfs(i, j);
                output.push_back(num);
                num = 0;//초기화
            }
        }
    }
    
    cout<<output.size()<<"\n";
    
    for(int i=0; i<output.size(); i++){//버블 정렬
        for(int j=0; j<(output.size()-1)-i; j++){
            if(output[j]>output[j+1]){
                tmp  = output[j];
                output[j] = output[j+1];
                output[j+1] = tmp;
            }
        }
    }
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
    return 0;
}