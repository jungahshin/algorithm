//2806. N-Queen
#include <iostream>
#include <vector>
using namespace std;

int testcase, n;
vector<int> final;
int num;
int row[11] = {0, };//행
int col[11] = {0, };//열
int total;
int line_1[20] = {0, };//왼쪽 대각선(sum)
int line_2[20] = {0, };//오른쪽 대각선(x, y)가 있으면 8-y+x
int visited[11][21] = {0, };//total(n), h(대각선)

//dfs
void go(int n, int total, int h){
    // cout<<"n"<<n<<"total"<<total<<"h"<<h<<"\n";
    if(n == total){//대각선에 있는 애들이 n이되면 경우의 수 num++
        num++;
        return;
    }
    for(int i=h; i<=(2*n-1); i++){
        int sum = i-1;//행과 열의 합이 i-1이 되어야 한다.
        for(int j=0; j<=sum; j++){
            //(0, sum), (1, sum-1), (2, sum-2)등등...
            //대각선에는 겹치는 것들이 없는지 살펴본다.
            if(0<=j && j<n && 0<=(sum-j) && (sum-j)<n){
                //(j, sum-j)
                if((row[j] == 0) && (col[sum-j] == 0) && (line_1[sum+1] == 0) && (line_2[n-(sum-j)+j] == 0)){
                    row[j] = 1;
                    col[sum-j] = 1;
                    line_1[sum+1] = 1;
                    line_2[n-(sum-j)+j] = 1;
                    total++;
                    go(n, total, i+1);
                    total--;
                    row[j] = 0;
                    col[sum-j] = 0;
                    line_1[sum+1] = 0;
                    line_2[n-(sum-j)+j] = 0;
                }
            }
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n;
        num = 0;//경우의 수
        total = 0;//대각선에 해당되는 애들의 총 합인 total은 n이여야 한다.
        for(int j=0; j<=11; j++){
            row[j] = 0;
            col[j] = 0;
        }
        for(int j=0; j<=20; j++){
            line_1[j] = 0;
            line_2[j] = 0;
        }
        go(n, total, 1);
        final.push_back(num);
    }
    for(int i=0; i<final.size(); i++){
        cout<<"#"<<i+1<<" "<<final[i]<<"\n";
    }
}