//구슬 탈출2(최소! 무조건 -> bfs)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char a[11][11];
char a_copy[11][11];
int red_x, red_y, blue_x, blue_y, end_x, end_y = 0;
int dx[4] = {0, 0, 1, -1};//동, 서, 남, 북
int dy[4] = {1, -1, 0, 0};
bool visited[11][11][11][11];

bool corner(int x, int y, int dir){//모퉁이에 있는지 검사
    bool temp = true;
    int final_x = x + dx[dir];
    int final_y = y + dy[dir];
    if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
        if(a_copy[final_x][final_y] == '#' || a_copy[final_x][final_y] == 'R' || a_copy[final_x][final_y] == 'B'){
            temp = false;
        }
    }
    return temp;
}

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 'R' || a[i][j] == 'B'){
                a_copy[i][j] = '.';
            }
        }
    }
}

bool dir_check(int dir, int red_x, int red_y, int blue_x, int blue_y){
    bool temp = false;
    if(dir == 0){
        if(red_y >= blue_y){
            temp = true;
        }
    }else if(dir == 1){
        if(red_y <= blue_y){
            temp = true;
        }
    }else if(dir == 2){
        if(red_x >= blue_x){
            temp = true;
        }
    }else if(dir == 3){
        if(red_x <= blue_x){
            temp = true;
        }
    }
    return temp;
}

int play(){
    //일단 큐에는 빨강만 넣고
    //빨강이 가능한 방향을 찾는다->., O, B 있으면 가능
    //가능한 방향으로 우선순위(먼저 움직여야 하는 색)에 있는 색을 찾고 
    //그 우선순위의 색을 먼저 움직이지 못할 때까지 움직이고 나머지 색 움직이고
    //또 빨간색을 기준으로 가능한 방향을 찾는다.
    //항상 red_x, red_y, blue_x, blue_y는 업데이트 시켜야 한다.

    queue<pair<pair<int, int>, pair<int, int>>> q;
    queue<pair<int, int>> blue;
    //일단 맨 처음 방향잡기-->빨강만
    for(int i=0; i<4; i++){
        q.push(make_pair(make_pair(red_x, red_y), make_pair(i, 1)));
    }
    for(int k=0; k<4; k++){
        blue.push(make_pair(blue_x, blue_y));        
    }
   
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;//몇 번째 이동인지(기울이기)
        int num = q.front().second.second;//무슨 방향인지
        int bx = blue.front().first;
        int by = blue.front().second;
        q.pop();
        blue.pop();

        //a배열 초기화하기
        copy();

        a_copy[x][y] = 'R';
        a_copy[bx][by] = 'B';

        //x, y좌표가 구멍 위치인지 확인!
        if(num > 10){
            return 0;
        }

        blue_x = bx;
        blue_y = by;
        red_x = x;
        red_y = y;

        if(dir_check(dir, red_x, red_y, blue_x, blue_y) == true){//빨강먼저
            vector<pair<pair<int, int>, pair<int, int>>> v;
            bool final_check_red = false;
            bool final_check_blue = false;
            while(corner(x, y, dir)){//막다른 길에 다다르면 false로 바뀐다.
                int final_x = x + dx[dir];
                int final_y = y + dy[dir];
                if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                    if(a_copy[final_x][final_y] == '.' || a_copy[final_x][final_y] == 'O'){//빈칸이거나 구멍이면 지나갈 수 있다.
                        x = final_x;
                        y = final_y;
                        if(a_copy[final_x][final_y] == 'O'){
                            final_check_red = true;
                        }
                    }
                }            
            }
            //원래 자리 빨강 a배열에서 빈칸으로 만들기
            a_copy[red_x][red_y] = '.';
            //red_x, red_y위치 업데이트
            red_x = x;
            red_y = y;
            if(final_check_red != true){
                a_copy[red_x][red_y] = 'R';
            }
            //막다른 길이면 다른 방향 찾아서 다시 push해준다.
            for(int i=0; i<4; i++){
                v.push_back(make_pair(make_pair(x, y), make_pair(i, num+1)));
            }
            //파랑 움직임
            while(corner(bx, by, dir)){//막다른 길에 다다르면 false로 바뀐다.
                int final_x = bx + dx[dir];
                int final_y = by + dy[dir];
                if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                    if(a_copy[final_x][final_y] == '.' || a_copy[final_x][final_y] == 'O'){//빈칸이거나 구멍이면 지나갈 수 있다.
                        bx = final_x;
                        by = final_y;
                        if(a_copy[final_x][final_y] == 'O'){
                            final_check_blue = true;
                            break;
                        }
                    }
                }            
            }
            a_copy[blue_x][blue_y] = '.';
            blue_x = bx;
            blue_y = by;
            a_copy[blue_x][blue_y] = 'B';
            if(final_check_red == true){
                if(final_check_blue == true){//둘다 true이면
                    continue;
                }else{
                    return num;
                }
            }
            if(final_check_red == false){
                if(final_check_blue == true){
                    continue;
                }else{//큐에 넣기
                    if(visited[x][y][bx][by] == false){
                        visited[x][y][bx][by] = true;
                        for(int k=0; k<v.size(); k++){
                            blue.push(make_pair(bx, by));  
                            q.push(make_pair(make_pair(v[k].first.first, v[k].first.second), make_pair(v[k].second.first, v[k].second.second)));
                        }                              
                    }
                }
            }
        }else{//파랑먼저
            vector<pair<pair<int, int>, pair<int, int>>> v;
            bool final_check_red = false;
            bool final_check_blue = false;
            while(corner(bx, by, dir)){//막다른 길에 다다르면 false로 바뀐다.
                int final_x = bx + dx[dir];
                int final_y = by + dy[dir];
                if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                    if(a_copy[final_x][final_y] == '.' || a_copy[final_x][final_y] == 'O'){//빈칸이거나 구멍이면 지나갈 수 있다.
                        bx = final_x;
                        by = final_y;
                        if(a_copy[final_x][final_y] == 'O'){
                            final_check_blue = true;
                        }
                    }
                }            
            }
            a_copy[blue_x][blue_y] = '.';
            blue_x = bx;
            blue_y = by;
            a_copy[blue_x][blue_y] = 'B';
            while(corner(x, y, dir)){//막다른 길에 다다르면 false로 바뀐다.
                int final_x = x + dx[dir];
                int final_y = y + dy[dir];
                if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m){
                    if(a_copy[final_x][final_y] == '.' || a_copy[final_x][final_y] == 'O'){//빈칸이거나 구멍이면 지나갈 수 있다.
                        x = final_x;
                        y = final_y;
                        if(a_copy[final_x][final_y] == 'O'){
                            final_check_red = true;
                        }
                    }
                }            
            }
            //원래 자리 빨강 a배열에서 빈칸으로 만들기
            a_copy[red_x][red_y] = '.';
            //red_x, red_y위치 업데이트
            red_x = x;
            red_y = y;
            if(final_check_red != true){
                a_copy[red_x][red_y] = 'R';
            }                
            //막다른 길이면 다른 방향 찾아서 다시 push해준다.
            for(int i=0; i<4; i++){
                v.push_back(make_pair(make_pair(x, y), make_pair(i, num+1)));
            }
            if(final_check_red == true){
                if(final_check_blue == true){//둘다 true이면
                    continue;
                }else{
                    return num;
                }
            }
            if(final_check_red == false){
                if(final_check_blue == true){
                    continue;
                }else{
                    if(visited[x][y][bx][by] == false){
                        visited[x][y][bx][by] = true;
                        for(int k=0; k<v.size(); k++){
                            blue.push(make_pair(bx, by));  
                            q.push(make_pair(make_pair(v[k].first.first, v[k].first.second), make_pair(v[k].second.first, v[k].second.second)));
                        }                              
                    } 
                }
            }
        }
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'R'){
                red_x = i;
                red_y = j;
            }else if(a[i][j] == 'B'){
                blue_x = i;
                blue_y = j;
            }else if(a[i][j] == 'O'){
                end_x = i;
                end_y = j;
            }
        }
    }
    int final = play();
    if(final == 0){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";        
    }
}