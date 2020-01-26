//뱀
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[102][102] = {0, };
queue<pair<int, char>> q;//방향 전환 시기, 방향 저장
int count_ = 0;//시간 카운트
int time_, dir = 0;
int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};//오, 왼, 위, 아래
vector<pair<int, int>> snake;//뱀의 몸을 저장
int start_x, start_y = 0;//뱀의 머리가 있는 곳
int n, k, c, d, e, l;
char f;
bool final = false;

void play(){
    while(1){
        if(!q.empty()){
            if(q.front().first == count_){
                if(dir == 0){
                    if(q.front().second == 'L'){
                        dir = 2;
                    }else if(q.front().second == 'D'){
                        dir = 3;
                    }
                }else if(dir == 1){
                    if(q.front().second == 'L'){
                        dir = 3;
                    }else if(q.front().second == 'D'){
                        dir = 2;
                    }
                }else if(dir == 2){
                    if(q.front().second == 'L'){
                        dir = 1;
                    }else if(q.front().second == 'D'){
                        dir = 0;
                    }
                }else if(dir == 3){
                    if(q.front().second == 'L'){
                        dir = 0;
                    }else if(q.front().second == 'D'){
                        dir = 1;
                    }
                }
                q.pop();
            }
        }
        count_++;
        //이동한다.
        //이동할 곳에 사과가 있는지 여부를 판단한다.
        int final_x = dir_x[dir] + start_x;
        int final_y = dir_y[dir] + start_y;
        start_x = final_x;
        start_y = final_y;
        for(int k=0; k<snake.size(); k++){
            if(snake[k].first == final_x && snake[k].second == final_y){//이동할 곳에 자기 자신의 몸이 있다면...end...
                final = true;
            }
        }
        if(final == true){
            break;
        }
        if(0<=final_x && final_x<n && 0<=final_y && final_y<n){
            if(a[final_x][final_y] == 2){//사과가 있으면
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(final_x, final_y));
                for(int i=0; i<snake.size(); i++){
                    temp.push_back(make_pair(snake[i].first, snake[i].second));
                }
                snake.clear();
                for(int i=0; i<temp.size(); i++){
                    snake.push_back(make_pair(temp[i].first, temp[i].second));
                }
                a[final_x][final_y] = 0;
            }else{//사과가 없으면
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(final_x, final_y));
                for(int i=0; i<snake.size(); i++){//맨 마지막 꼬리는 버린다.
                    temp.push_back(make_pair(snake[i].first, snake[i].second));
                }
                temp.pop_back();
                snake.clear();
                for(int i=0; i<temp.size(); i++){
                    snake.push_back(make_pair(temp[i].first, temp[i].second));
                }            
            }
        }else{//end...
            final = true;
            break;
        }
    }
    
}

int main(){
    cin>>n;
    cin>>k;
    //사과 있는 곳의 위치
    for(int i=0; i<k; i++){
        cin>>c>>d;
        a[c-1][d-1] = 2;
    }
    cin>>l;
    for(int i=0; i<l; i++){
        cin>>e>>f;
        q.push(make_pair(e, f));
    }
    snake.push_back(make_pair(0, 0));//맨 처음 뱀이 있는 곳
    play();
    cout<<count_<<"\n";
    return 0;
}