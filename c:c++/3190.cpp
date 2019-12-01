//뱀
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, L, X;
int r, c;
char C;//방향 위치
int a[101][101] = {0, };//뱀과 과일 위치 표시(0-빈칸, 1-뱀, 2-과일)
queue<pair<int, char>> dir;//방향
vector<pair<int, int>> apple;//사과의 위치
vector<pair<int, int>> snake;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int num = 0;

void go(int x, int y){//임시 벡터의 맨 앞에 새로운 아이를 넣고 다시 snake벡터에 넣어준다.
    vector<pair<int, int>> temp;
    temp.push_back(make_pair(x, y));
    for(int i=0; i<snake.size(); i++){
        temp.push_back(make_pair(snake[i].first, snake[i].second));
    }
    snake.clear();
    for(int i=0; i<temp.size(); i++){
        snake.push_back(make_pair(temp[i].first, temp[i].second));
    }
}

void play(int b, int d, int e){//시작 위치(x, y), 방향(z)
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(b, d), e));
    
    while(!q.empty()){
        int x = q.front().first.first;//위치
        int y = q.front().first.second;
        int z = q.front().second;//방향
        q.pop();
        num++;

        int final_x = x + dx[z];
        int final_y = y + dy[z];
        if(1 <= final_x && final_x <= n && 1 <= final_y && final_y <= n){
            if(a[final_x][final_y] == 0){//빈칸
                a[final_x][final_y] = 1;
                a[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;//snake의 맨 마지막요소의 위치 0으로 해주기
                go(final_x, final_y);
                snake.pop_back();
            }else if(a[final_x][final_y] == 2){//과일
                a[final_x][final_y] = 1;
                go(final_x, final_y);
            }else if(a[final_x][final_y] == 1){//뱀(자기 자신과 마주친다면)-->끝
                return;
            }
        }else{
            return;
        }
        //방향 확인하고 q에 푸시하기!
        if(num == dir.front().first){
            if(dir.front().second == 'L'){//왼쪽
                if(z-1 < 0){
                    z = 3;
                }else{
                    z -= 1;
                }
                q.push(make_pair(make_pair(final_x, final_y), z));
            }else if(dir.front().second == 'D'){//오른쪽
                if(z+1 > 3){
                    z = 0;
                }else{
                    z += 1;
                }
                q.push(make_pair(make_pair(final_x, final_y), z));
            }
            dir.pop();
        }else{
            q.push(make_pair(make_pair(final_x, final_y), z));
        }
    }
}

int main(){
    cin>>n;//1부터 시작하기
    cin>>k;
    for(int i=0; i<k; i++){//사과의 위치
        cin>>r>>c;
        apple.push_back(make_pair(r, c));
        a[r][c] = 2;
    }
    cin>>L;
    for(int i=0; i<L; i++){//방향 변환
        cin>>X>>C;
        dir.push(make_pair(X, C));
    }
    snake.push_back(make_pair(1, 1));
    a[1][1] = 1;//뱀의 처음 위치
    play(1, 1, 0);
    cout<<num<<"\n";
}