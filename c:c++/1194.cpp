//달이 차오른다, 가자(비트마스킹)
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

int n, m;
char maze[51][51] = {0, };
int start_x, start_y;//출발 지점
vector<pair<int, int>> end_;//도착 지점(여러 개)
int visited[51][51][50] = {0, };
int final = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool final_check = false;

//visited[i][j][보유한 열쇠]로 한다.

bool check(int x, int y){//도착지점에 왔는지 여부
    bool temp = false;
    for(int i=0; i<end_.size(); i++){
        if(end_[i].first == x && end_[i].second == y){
            temp = true;
            break;
        }
    }
    return temp;
}

void play(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(start_x, start_y), make_pair(0, 0)));
    visited[start_x][start_y][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second.first;//지금까지 이동한 횟수
        int key_num = q.front().second.second;//지금까지 획득한 열쇠
        q.pop();

        if(check(x, y) == true){//도착지점에 도착
            final_check = true;
            final = num;
            break;
        }

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                if(maze[final_x][final_y] == '.' && !visited[final_x][final_y][key_num]){
                    visited[final_x][final_y][key_num] = 1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, key_num)));
                }else if('a'<=maze[final_x][final_y] && maze[final_x][final_y]<='f'){//열쇠
                    int add_key = key_num | (1 << (maze[final_x][final_y]-'a'));
                    if(!visited[final_x][final_y][add_key]){
                        visited[final_x][final_y][add_key] = 1;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, add_key)));
                    }
                }else if('A'<=maze[final_x][final_y] && maze[final_x][final_y]<='F'){//문
                    int chk_key = key_num & (1 << (maze[final_x][final_y]-'A'));
                    if(chk_key != 0 && !visited[final_x][final_y][key_num]){//0이 아닌 숫자가 나오면 열쇠가 있다는 것
                        visited[final_x][final_y][key_num] = 1;
                        q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, key_num)));
                    }
                }else if(maze[final_x][final_y] == '1' && !visited[final_x][final_y][key_num]){//도착 지점
                    visited[final_x][final_y][key_num] = 1;
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(num+1, key_num)));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j] == '0'){
                start_x = i;
                start_y = j;
                maze[i][j] = '.';
            }else if(maze[i][j] == '1'){
                end_.push_back(make_pair(i, j));
            }
        }
    }
    play();
    if(final_check == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}