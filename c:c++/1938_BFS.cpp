//통나무 옮기기 --> bfs버전
//고등부 올림피아드 기출문제
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int n;
string s;
vector<string> v;//n*n이 저장되어 있는 공간
char save[51][51];
vector<pair<int, int>> start;//시작 위치(3개)
vector<pair<int, int>> done;//끝나는 위치(3개)
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};//회전할 때 중간점을 기준으로 확인해야하는 방향
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int visited[51][51][2] = {0, };//중간점, 방향
int final_dir = 0;
int final_num = INT_MAX;

void go(int x, int y, int dir, int num){//중간점을 항상 기준으로 생각한다. 큐에 있는 dir이 0이면-->(x, y-1),(x, y),(x, y+1), dir이 1이면 -->(x-1, y),(x, y),(x+1, y)
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(x, y), make_pair(dir, num)));
    
    while(!q.empty()){
        int a = q.front().first.first;//행
        int b = q.front().first.second;//열
        int c = q.front().second.first;//방향(가로, 세로)
        int h = q.front().second.second;//이동 횟수
        q.pop();

        //도착 지점에 왔는지 확인하기
        if(a == done[1].first && b == done[1].second && c == final_dir){//중심점과 방향 모두 같으면 도착지점이다.
            final_num = min(final_num, h);
            continue;
        }

        if(c == 0){//행
            //U(상)-->x값들을 -1씩 한다.(x값들만 범위 내에 있는 지 체크)
            if(0 <= (a-1) && (a-1) < n){
                if((save[a-1][b-1] == '0' || save[a-1][b-1] == 'E') && (save[a-1][b] == '0' || save[a-1][b] == 'E') && (save[a-1][b+1] == '0' || save[a-1][b+1] == 'E') && !visited[a-1][b][0]){//모두 빈칸이면 이동 가능!
                    visited[a-1][b][0] = 1;
                    q.push(make_pair(make_pair(a-1, b), make_pair(0, h+1)));
                }
            }
            //D(하)-->x값들을 +1씩 한다.(x값들만 범위 내에 있는 지 체크)
            if(0 <= (a+1) && (a+1) < n){
                if((save[a+1][b-1] == '0' || save[a+1][b-1] == 'E') && (save[a+1][b] == '0' || save[a+1][b] == 'E') && (save[a+1][b+1] == '0' || save[a+1][b+1] == 'E') && !visited[a+1][b][0]){//모두 빈칸이면 이동 가능!
                    visited[a+1][b][0] = 1;
                    q.push(make_pair(make_pair(a+1, b), make_pair(0, h+1)));
                }
            }
            //L(좌) -->y값들을 -1씩 한다.(y값들만 범위 내에 있는 지 체크)
            if(0 <= (b-2) && (b-2) < n){
                if((save[a][b-2] == '0' || save[a][b-2] == 'E') && !visited[a][b-1][0]){
                    visited[a][b-1][0] = 1;
                    q.push(make_pair(make_pair(a, b-1), make_pair(0, h+1)));
                }
            }
            //R(우) -->y값들을 +1씩 한다.(y값들만 범위 내에 있는 지 체크)
            if(0 <= (b+2) && (b+2) < n){
                if((save[a][b+2] == '0' || save[a][b+2] == 'E') && !visited[a][b+1][0]){
                    visited[a][b+1][0] = 1;
                    q.push(make_pair(make_pair(a, b+1), make_pair(0, h+1)));
                }
            }
            //T(90도 회전)-->3*3내에 아무것도 없어야 한다.
            int temp = 0;
            for(int i=0; i<8; i++){
                int x = a + dx[i];
                int y = b + dy[i];
                if(0 <= x && x < n && 0 <= y && y < n){
                    if(save[x][y] == '0' || save[x][y] == 'E'){
                        temp++;
                    }
                } 
            }
            if(temp == 8 && !visited[a][b][1]){//회전 가능
                visited[a][b][1] = 1;
                q.push(make_pair(make_pair(a, b), make_pair(1, h+1)));
            }
        }else if(c == 1){//열
        //U(상)-->x값들을 -1씩 한다.(x값들만 범위 내에 있는 지 체크)
            if(0 <= (a-2) && (a-2) < n){
                if((save[a-2][b] == '0' || save[a-2][b] == 'E') && !visited[a-1][b][1]){//모두 빈칸이면 이동 가능!
                    visited[a-1][b][1] = 1;
                    q.push(make_pair(make_pair(a-1, b), make_pair(1, h+1)));
                }
            }
            //D(하)-->x값들을 +1씩 한다.(x값들만 범위 내에 있는 지 체크)
            if(0 <= (a+2) && (a+2) < n){
                if((save[a+2][b] == '0' || save[a+2][b] == 'E') && !visited[a+1][b][1]){//모두 빈칸이면 이동 가능!
                    visited[a+1][b][1] = 1;
                    q.push(make_pair(make_pair(a+1, b), make_pair(1, h+1)));
                }
            }
            //L(좌) -->y값들을 -1씩 한다.(y값들만 범위 내에 있는 지 체크)
            if(0 <= (b-1) && (b-1) < n){
                if((save[a-1][b-1] == '0' || save[a-1][b-1] == 'E') && (save[a][b-1] == '0' || save[a][b-1] == 'E') && (save[a+1][b-1] == '0' || save[a+1][b-1] == 'E') && !visited[a][b-1][1]){
                    visited[a][b-1][1] = 1;
                    q.push(make_pair(make_pair(a, b-1), make_pair(1, h+1)));
                }
            }
            //R(우) -->y값들을 +1씩 한다.(y값들만 범위 내에 있는 지 체크)
            if(0 <= (b+1) && (b+1) < n){
                if((save[a-1][b+1] == '0' || save[a-1][b+1] == 'E') && (save[a][b+1] == '0' || save[a][b+1] == 'E') && (save[a+1][b+1] == '0' || save[a+1][b+1] == 'E') && !visited[a][b+1][1]){
                    visited[a][b+1][1] = 1;
                    q.push(make_pair(make_pair(a, b+1), make_pair(1, h+1)));
                }
            }
            //T(90도 회전)-->3*3내에 아무것도 없어야 한다.
            int temp = 0;
            for(int i=0; i<8; i++){
                int x = a + dx[i];
                int y = b + dy[i];
                if(0 <= x && x < n && 0 <= y && y < n){
                    if(save[x][y] == '0' || save[x][y] == 'E'){
                        temp++;
                    }
                } 
            }
            if(temp == 8 && !visited[a][b][0]){//회전 가능
                visited[a][b][0] = 1;
                q.push(make_pair(make_pair(a, b), make_pair(0, h+1)));
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        v.push_back(s);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == 'B'){//시작 지점(3개)
                start.push_back(make_pair(i, j));
            }else if(v[i][j] == 'E'){//최종 도착 지점(3개)
                done.push_back(make_pair(i, j));
            }
            save[i][j] = v[i][j];
        }
    }
    save[(start[0].first)][(start[0].second)] = '0';//중심점만 넣는다.
    save[(start[2].first)][(start[2].second)] = '0';
    save[(start[1].first)][(start[1].second)] = '0';
    if(done[0].second == done[1].second){//열의 값이 같으면 --> dir 1
        final_dir = 1;
    }else{
        final_dir = 0;
    }
    if(start[0].second == start[1].second){//열의 값이 같으면 --> dir 1
        visited[start[1].first][start[1].second][1] = 1;
        go(start[1].first, start[1].second, 1, 0);
    }else{
        visited[start[1].first][start[1].second][0] = 1;
        go(start[1].first, start[1].second, 0, 0);
    }
    
    if(final_num == INT_MAX){//이동 불가
        cout<<"0"<<"\n";
    }else{
        cout<<final_num<<"\n";
    }
}