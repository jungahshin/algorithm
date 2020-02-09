//로봇청소기 복습
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, r, c, d;
int a[51][51] = {0, };
int clean_num = 0;//로봇청소기가 청소하는 칸의 수
int visited[51][51] = {0, };//청소한 칸

void clean(){
    bool check = false;
    while(1){
        //현재위치 청소(1번)
        int x = r;
        int y = c;
        int dir = d;
        visited[x][y] = 1;
        clean_num++;
        
        //현재위치에서 현재 방향을 기준으로 왼쪽 방향부터 탐색 진행(2번)
        int temp = 0;
        while(1){
            if(temp == 4){
                //바라보는 방향을 유지한 채 한 칸 후진 후 2번
                int next_x, next_y;
                if(dir == 0){//북
                    next_x = x+1;
                    next_y = y;                    
                }else if(dir == 1){//동
                    next_x = x;
                    next_y = y-1;
                }else if(dir == 2){//남
                    next_x = x-1;
                    next_y = y;
                }else if(dir == 3){//서
                    next_x = x;
                    next_y = y+1;
                }
                if(1<=next_x && next_x<=n && 1<=next_y && next_y <=m && a[next_x][next_y] == 0){
                    r = next_x;
                    c = next_y;
                    x = r;
                    y = c;
                    dir = d;
                    temp = 0;
                    continue;                        
                }else{
                    check = true;
                    break;
                }
            }
            if(dir == 0){//서
                int next_x = x;
                int next_y = y-1;
                if(1<=next_x && next_x<=n && 1<=next_y && next_y<=m && !visited[next_x][next_y] && a[next_x][next_y] == 0){
                    d = 3;
                    r = next_x;
                    c = next_y;
                    break;
                }else{//청소할 공간이 없어
                    temp++;
                    dir = 3;
                    d = 3;
                    continue;
                }
            }else if(dir == 1){//북
                int next_x = x-1;
                int next_y = y;
                if(1<=next_x && next_x<=n && 1<=next_y && next_y<=m && !visited[next_x][next_y] && a[next_x][next_y] == 0){
                    d = 0;
                    r = next_x;
                    c = next_y;
                    break;
                }else{//청소할 공간이 없어
                    temp++;
                    dir = 0;
                    d = 0;
                    continue;
                }
            }else if(dir == 2){//동
                int next_x = x;
                int next_y = y+1;
                if(1<=next_x && next_x<=n && 1<=next_y && next_y<=m && !visited[next_x][next_y] && a[next_x][next_y] == 0){
                    d = 1;
                    r = next_x;
                    c = next_y;
                    break;
                }else{//청소할 공간이 없어
                    temp++;
                    dir = 1;
                    d = 1;
                    continue;
                }
            }else if(dir == 3){//남
                int next_x = x+1;
                int next_y = y;
                if(1<=next_x && next_x<=n && 1<=next_y && next_y<=m && !visited[next_x][next_y] && a[next_x][next_y] == 0){
                    d = 2;
                    r = next_x;
                    c = next_y;
                    break;
                }else{//청소할 공간이 없어
                    temp++;
                    dir = 2;
                    d = 2;
                    continue;
                }
            }            
        }

        if(check == true){
            break;
        }
    }
}

int main(){
    cin>>n>>m;
    cin>>r>>c>>d;//로봇청소기의 현재 위치->(r, c), 바라보는 방향->d(0-북, 1-동, 2-남, 3-서)
    r = r+1;
    c = c+1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    clean();
    cout<<clean_num<<"\n";
}