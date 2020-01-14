//N-queen(1<=N<15)
#include <iostream>
using namespace std;

int n;
int num;
int row[15] = {0, };//행
int col[15] = {0, };//열
int total;
int line_1[30] = {0, };//왼쪽 대각선(sum)
int line_2[30] = {0, };//오른쪽 대각선(x, y)가 있으면 8-y+x

//dfs(백트래킹)
void go(int total){//행 기준
    if(n == total){//대각선에 있는 애들이 n이되면 경우의 수 num++
        num++;
        return;
    }
    for(int j=0; j<n; j++){//열 기준
        //행과 열이 차있는지 판단할 필요가 없다.
        int sum = total + j;
        if(col[j] == 0 && line_1[sum+1] == 0 && line_2[n-j+total] == 0){
            col[j] = 1;
            line_1[sum+1] = 1;
            line_2[n-j+total] = 1;
            go(total+1);
            col[j] = 0;
            line_1[sum+1] = 0;
            line_2[n-j+total] = 0;
        }
    }
}

int main(){
    cin>>n;
    num = 0;//경우의 수
    total = 0;//대각선에 해당되는 애들의 총 합인 total은 n이여야 한다.
    go(total);
    cout<<num<<"\n";
}