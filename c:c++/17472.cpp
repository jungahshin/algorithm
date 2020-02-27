//다리 만들기2
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int a[11][11] = {0, };
int a_[11][11] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = INT_MAX;
bool final_check = false;
bool final_temp = false;
//dir=0(왼쪽), 1(오른쪽), 2(위쪽), 3(아래쪽)

//for문으로 돌다가 1을 만나면 인접(상하좌우)하면서 1인 곳을 다 bfs로 찾아내서 2로 바꾸면서, 
//인접(상하)하면서 0인 곳은 다 bfs로 찾아내서 -1로 바꾼다.(0을 만날 때만 숫자를 더해준다.->다리 길이)
//숫자(다리길이)가 2이상이면서 1을 만나면 숫자만큼 더해준다.
//그렇게 해서 전체에서 1이 다 사라지면 다 이어진 것..!
//for문을 다 돌았지만 1이 다 사라지지 않으면 섬을 연결할 수 없는 것,'-1'출력

bool check(){
    bool temp = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_[i][j] == 1){
                temp =  true;
            }
        }
    }
    return temp;
}

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_[i][j] = a[i][j];
        }
    }
}

int bfs(int i, int j){
    final_temp = false;
    queue<pair<pair<int, int>, pair<int, int>>> q;
    queue<pair<int, int>> p;
    p.push(make_pair(i, j));
    q.push(make_pair(make_pair(i, j), make_pair(0, 5)));//0을 만날 때만 dir값을(0~3으로) 써준다. 
    a_[i][j] = 2;
    while(!p.empty()){
        int x = p.front().first;
        int y = p.front().second;
        p.pop();

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                if(a_[final_x][final_y] == 1){
                    p.push(make_pair(final_x, final_y));
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(0, 5)));//0을 만날 때만 dir값을(0~3으로) 써준다. 
                    a_[final_x][final_y] = 2;
                }
            }
        }
    }
    int num = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int len = q.front().second.first;//다리 길이
        int dir = q.front().second.second;
        q.pop();

        if(check() == false){//1이 하나도 없으면 모든 섬이 연결되었다->break;
            final_check = true;
            final_temp = true;
            break;
        }

        if(0<=dir && dir<=3){//0이었다
            int final_x = x+dx[dir];
            int final_y = y+dy[dir];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                if(a_[final_x][final_y] == 0){
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(len+1, dir)));
                    a_[final_x][final_y] = -1;
                }else if(a_[final_x][final_y] == 1){
                    if(len>=2){//0었다가 1을 만났는데 len이 2이상이면 다리 길이 더해준다.
                        num += len;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(len, 5)));
                        a_[final_x][final_y] = 2;
                        //bfs로 1을 모두 2로 바꿔준다.
                        queue<pair<int, int>> p;
                        p.push(make_pair(final_x, final_y));
                        while(!p.empty()){
                            int x = p.front().first;
                            int y = p.front().second;
                            p.pop();

                            for(int i=0; i<4; i++){
                                int final_x = x+dx[i];
                                int final_y = y+dy[i];
                                if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                                    if(a_[final_x][final_y] == 1){
                                        p.push(make_pair(final_x, final_y));
                                        q.push(make_pair(make_pair(final_x, final_y), make_pair(0, 5)));//0을 만날 때만 dir값을(0~3으로) 써준다. 
                                        a_[final_x][final_y] = 2;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(a_[final_x][final_y] == -1){
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(len+1, dir)));
                }
            }
        }else if(dir == 5){//1이었다
            for(int i=0; i<4; i++){
                int final_x = x+dx[i];
                int final_y = y+dy[i];
                if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                    if(a_[final_x][final_y] == 0){
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(1, i)));
                        a_[final_x][final_y] = -1;
                    }else if(a_[final_x][final_y] == 1){
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(0, 5)));
                        a_[final_x][final_y] = 2;
                    }
                    else if(a_[final_x][final_y] == -1){
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(1, i)));
                    }
                }
            }            
        }
    }
    return num;
}

void go(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 1){
                copy();
                int temp = bfs(i, j);
                if(final_temp == true){
                    final = min(final, temp);                    
                }
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
    go();
    if(final_check == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}