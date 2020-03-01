//로봇 시뮬레이션
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, char>> robot;
vector<pair<pair<char, int>, int>> command;
int x, y, c, e, a, b, n, m;
char dir, d;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool wall = false;
bool crash = false;
int final = 0;
int final_ = 0;
int final_x, final_y;

//로봇들 차례대로 명령 이행
void go(){
    for(int i=0; i<command.size(); i++){
        if(crash == true || wall == true){
            break;
        }
        int idx = command[i].second-1;//robot에서의 idx
        int num = command[i].first.second;//명령의 반복 횟수
        char kind = command[i].first.first;//명령의 종류
        int r_x = robot[idx].first.first;
        int r_y = robot[idx].first.second;
        char r_dir = robot[idx].second;
        final = command[i].second;
        for(int j=0; j<num; j++){//명령의 반복 횟수 만큼
            if(crash == true || wall == true){
                break;
            }
            if(kind == 'L'){//왼쪽으로 90회전
                if(r_dir == 'E'){
                    r_dir = 'N';
                }else if(r_dir == 'W'){
                    r_dir = 'S';
                }else if(r_dir == 'S'){
                    r_dir = 'E';
                }else if(r_dir == 'N'){
                    r_dir = 'W';
                }
            }else if(kind == 'R'){//오른쪽으로 90회전
                if(r_dir == 'E'){
                    r_dir = 'S';
                }else if(r_dir == 'W'){
                    r_dir = 'N';
                }else if(r_dir == 'S'){
                    r_dir = 'W';
                }else if(r_dir == 'N'){
                    r_dir = 'E';
                }
            }else if(kind == 'F'){//한 칸 움직임
                if(r_dir == 'E'){
                    final_x = dx[0]+r_x;
                    final_y = dy[0]+r_y;
                }else if(r_dir == 'W'){
                    final_x = dx[1]+r_x;
                    final_y = dy[1]+r_y;
                }else if(r_dir == 'S'){
                    final_x = dx[2]+r_x;
                    final_y = dy[2]+r_y;
                }else if(r_dir == 'N'){
                    final_x = dx[3]+r_x;
                    final_y = dy[3]+r_y;
                }
                if(1<=final_x && final_x<=a && 1<=final_y && final_y<=b){//범위 안에 있고
                    for(int k=0; k<robot.size(); k++){
                        if(robot[k].first.first == final_x && robot[k].first.second == final_y){
                            //부딪혀서 end
                            crash = true;
                            final_ = k+1;
                            break;
                        }
                    }
                    //이동가능
                    r_x = final_x;
                    r_y = final_y;
                }else{//벗어나면 end
                    wall = true;
                    break;
                }
            }
            //robot벡터에 update해주기
            robot[idx].first.first = r_x;
            robot[idx].first.second = r_y;
            robot[idx].second = r_dir;
        }
    }
}

int main(){
    cin>>a>>b;
    cin>>n>>m;//로봇들의 초기위치, 명령
    for(int i=0; i<n; i++){
        cin>>x>>y>>dir;
        robot.push_back(make_pair(make_pair(x, y), dir));
    }
    for(int i=0; i<m; i++){
        cin>>c>>d>>e;//로봇 번호, 명령 종류, 반복 횟수
        command.push_back(make_pair(make_pair(d, e), c));
    }
    go();
    if(wall == true){
        cout<<"Robot "<<final<<" crashes into the wall"<<"\n";
        return 0;
    }
    if(crash == true){
        cout<<"Robot "<<final<<" crashes into robot "<<final_<<"\n";
        return 0;
    }
    cout<<"OK"<<"\n";
}