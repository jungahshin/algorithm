//파이프 옮기기1
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[20][20] = {0, };
int final = 0;
int dx_0[4] = {0, 1};//가로
int dy_0[4] = {1, 1};//가로
int dx_1[4] = {1, 1};//세로
int dy_1[4] = {0, 1};//세로
int dx_2[4] = {0, 1, 1};//대각선
int dy_2[4] = {1, 0, 1};//대각선

void go(int x, int y, int z){//(x, y)파이프 차지하는 좌표, z-방향
    if(final > 1000000){//불가능한 경우
        cout<<"0"<<"\n";
        return;
    }
    if(x == n && y == n){
        final++;
        return;
    }

    if(z == 0){//가로(2가지 방법),
        for(int i=0; i<2; i++){
            int final_x = dx_0[i] + x;
            int final_y = dy_0[i] + y;
            if(1 <= final_x && final_x <= n && 1 <= final_y &&  final_y <= n && a[final_x][final_y] == 0){
                if(i == 0){
                    z = 0;
                    go(final_x, final_y, z);
                }else{
                    if(a[final_x-1][final_y] == 0 && a[final_x][final_y-1] == 0){
                        z = 2;
                        go(final_x, final_y, z);
                    }
                }
            }
        }
    }else if(z == 1){//세로(2가지 방법)
        for(int i=0; i<2; i++){
            int final_x = dx_1[i] + x;
            int final_y = dy_1[i] + y;
            if(1 <= final_x && final_x <= n && 1 <= final_y &&  final_y <= n && a[final_x][final_y] == 0){
                if(i == 0){
                    z = 1;
                    go(final_x, final_y, z);
                }else{
                    if(a[final_x-1][final_y] == 0 && a[final_x][final_y-1] == 0){
                        z = 2;
                        go(final_x, final_y, z);                   
                    }
                }
            }
        }
    }else if(z == 2){//대각선(3가지 방법)
        for(int i=0; i<3; i++){
            int final_x = dx_2[i] + x;
            int final_y = dy_2[i] + y;
            if(1 <= final_x && final_x <= n && 1 <= final_y &&  final_y <= n && a[final_x][final_y] == 0){
                if(i == 0){
                    z = 0;
                    go(final_x, final_y, z);
                }else if(i == 1){
                    z = 1;
                    go(final_x, final_y, z);
                }else{
                    if(a[final_x-1][final_y] == 0 && a[final_x][final_y-1] == 0){
                        z = 2;                  
                        go(final_x, final_y, z);           
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    go(1, 2, 0);//파이프의 맨 마지막으로 차지하고 있는 공간을 인자로 둔다.
    cout<<final<<"\n";
}