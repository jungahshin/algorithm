//체스판 다시 칠하기
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
char dx[8] = {'B','W','B','W','B','W','B','W'};
char dy[8] = {'W','B','W','B','W','B','W','B'};
char a[51][51];
int final = INT_MAX;

void go(int x, int y){//맨 왼쪽, 맨 위 좌표
    //블랙으로 시작될 경우
    int num = 0;
    for(int i=0; i<8; i++){//x+i, y+j
        for(int j=0; j<8; j++){
            if(i % 2 == 0){//짝수->dx와 비교
                if(a[x+i][y+j] != dx[j]){
                    num++;
                }
            }else{//홀수->dy와 비교
                if(a[x+i][y+j] != dy[j]){
                    num++;
                }
            }
        }
    }
    final = min(final, num);
    //화이트로 시작될 경우
    int num_w = 0;
    for(int i=0; i<8; i++){//x+i, y+j
        for(int j=0; j<8; j++){
            if(i % 2 == 0){//짝수->dx와 비교
                if(a[x+i][y+j] != dy[j]){
                    num_w++;
                }
            }else{//홀수->dy와 비교
                if(a[x+i][y+j] != dx[j]){
                    num_w++;
                }
            }
        }
    }
    final = min(final, num_w);
}

void cut(){//8*8모양의 체스판 크기로 자르기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //i, j가 맨 왼쪽, 맨 위 기준이 된다.
            if(0 <= (i+7) && (i+7) < n && 0 <= (j+7) && (j+7) < m){
                //체스판 크기로 자를 수 있다.
                go(i, j);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    cut();
    cout<<final<<"\n";
}