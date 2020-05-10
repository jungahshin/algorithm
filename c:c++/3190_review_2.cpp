//뱀 복습
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int dummy[101][101] = {0, };
int check[101][101] = {0, };
int n, k, a, b, x, l;
char c;
map<int, char> change;//변환 정보 저장
int dir = 1;//맨 처음 방향 오른쪽(idx)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> snake;//뱀의 몸위치 저장
int final = 0;

void start(){
    //뱀의 머리 위치
    int x = 1;
    int y = 1;
    check[x][y] = 1;
    snake.push_back(make_pair(x, y));
    while(1){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(1<=nx && nx<=n && 1<=ny && ny<=n){
            if(check[nx][ny] == 0){//뱀의 몸통과 부딪히지 않는다.
                if(dummy[nx][ny] == 1){//사과가 있다.
                    dummy[nx][ny] = 0;
                    check[nx][ny] = 1;
                    x = nx;
                    y = ny;
                    vector<pair<int, int>> temp;
                    temp.push_back(make_pair(nx, ny));
                    for(int j=0; j<snake.size(); j++){
                        temp.push_back(make_pair(snake[j].first, snake[j].second));
                    }
                    snake.clear();
                    for(int j=0; j<temp.size(); j++){
                        snake.push_back(make_pair(temp[j].first, temp[j].second));
                    }
                }else{
                    check[nx][ny] = 1;
                    x = nx;
                    y = ny;
                    check[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
                    vector<pair<int, int>> temp;
                    temp.push_back(make_pair(nx, ny));
                    for(int j=0; j<snake.size()-1; j++){//꼬리만 빼고 저장.
                        temp.push_back(make_pair(snake[j].first, snake[j].second));
                    }
                    snake.clear();
                    for(int j=0; j<temp.size(); j++){
                        snake.push_back(make_pair(temp[j].first, temp[j].second));
                    }
                }
            }else{//뱀의 몸통과 부딪힌다.
                break;
            }
        }else{//머리가 벽에 부딪힌다.
            break;
        }
        final++;
        if(change.count(final) != 0){
            if(change[final] == 'L'){//왼쪽 방향 전환
                dir--;
                if(dir == -1){
                    dir = 3;
                }
            }else if(change[final] == 'D'){//오른쪽 방향 전환
                dir++;
                if(dir == 4){
                    dir = 0;
                }
            }
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0; i<k; i++){
        cin>>a>>b;
        dummy[a][b] = 1;//사과 위치 
    }
    cin>>l;
    for(int i=0; i<l; i++){
        cin>>x>>c;
        change[x] = c;
    }
    start();
    cout<<final+1<<"\n";
    return 0;
}