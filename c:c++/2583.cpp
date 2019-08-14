//사각형도 결국 같은 점의 일부라고 생각하기!!! 사각형의 왼쪽 아래 점이 채워있으면 사각형이 채워있는 것으로 간주!!
#include<iostream>
#include<vector>
using namespace std;
int visited[101][101] = {0, };
int input[101][101];
vector<int> output;
int tmp;

int m,n,k,i,j;
int left_x, left_y, right_x, right_y;
int empty_num = 0;

void dfs_distributed(int a, int b){//4개의 점을 검증하는 함수-->분리된 영역 수 세기
    visited[a][b] = 1;
    if(0<=a<=n && 0<=b<=m && 0<=a+1<=n && 0<=b+1<=m){
        if(!(visited[a][b] && visited[a+1][b] && visited[a][b+1] && visited[a+1][b+1]) && !(input[a][b] && input[a+1][b] && input[a][b+1] && input[a+1][b+1])){
            //하나의 점이라도 visitied하지 않고, 하나의 점이라도 input값이 0일때 빈 영역이다.
            visited[a+1][b] = 1;
            visited[a][b+1] = 1;
            visited[a+1][b+1] = 1;
            empty_num++;
            dfs_distributed(a+1, b);
            dfs_distributed(a, b+1);
            dfs_distributed(a+1, b+1);//퍼져나간다.
        }
    }
}

int main(){
    cin>>m;
    cin>>n;
    cin>>k;

    for(int i=0; i<k; i++){
        cin>>left_x;
        cin>>left_y;
        cin>>right_x;
        cin>>right_y;
        for(i= left_x; i<=right_x; i++){
            for(j=left_y; i<=right_y; j++){
                input[i][j] = 1;
            }
        }
    }
    for(i=0; i<=n; i++){
        for(j=0; j<=m; j++){
            dfs_distributed(i, j);
            output.push_back(empty_num);
            empty_num = 0;//초기화
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
}