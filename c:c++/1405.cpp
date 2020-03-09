//미친로봇
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int n, a, b, c, d;
double p_east, p_west, p_south, p_north, final;
int visited[50][50] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double p[4];

void go(int num, double percent, int x, int y, bool check){//총 이동횟수, 총 확률, 단순한지 여부
    if(check == false){//이미 단순하지 않으면 굳이 계속 진행할 필요 없다.
        return;
    }
    if(num == n){//n번 이동을 하였으면, 최종 확률 계산을 한다.
        if(check == true){//단순하면 더한다.
            final += percent;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int final_x = x+dx[i];
        int final_y = y+dy[i];
        if(!visited[final_x][final_y]){//아직 방문하지 않았다.
            visited[final_x][final_y] = 1;
            go(num+1, percent*p[i], final_x, final_y, true);
            visited[final_x][final_y] = 0;
        }else{//이미 방문했다.
            go(num+1, percent*p[i], final_x, final_y, false);
        }
    }
}

int main(){
    //시작점은 안전하게 (20, 20)..
    cin>>n>>p_east>>p_west>>p_south>>p_north;
    p_east /= 100.0;
    p[0] = p_east;
    p_west /= 100.0;
    p[1] = p_west;
    p_south /= 100.0;
    p[2] = p_south;
    p_north /= 100.0;
    p[3] = p_north;
    memset(visited, 0, sizeof(visited));
    visited[20][20] = 1; 
    visited[20][21] = 1;
    go(1, p_east, 20, 21, true);
    memset(visited, 0, sizeof(visited));
    visited[20][20] = 1; 
    visited[20][19] = 1;
    go(1, p_west, 20, 19, true);
    memset(visited, 0, sizeof(visited));
    visited[20][20] = 1; 
    visited[21][20] = 1;
    go(1, p_south, 21, 20, true);
    memset(visited, 0, sizeof(visited));
    visited[20][20] = 1; 
    visited[19][20] = 1;
    go(1, p_north, 19, 20, true);
    //출력값의 소수점을 고정적으로 출력해준다.
    cout << fixed;
    cout.precision(11);
    cout<<final<<"\n";
    return 0;
}