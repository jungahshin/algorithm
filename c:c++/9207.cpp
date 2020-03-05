//페그 솔리테어
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string s;
int testcase;
char map[6][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final_num = INT_MAX;
int final_move = 0;

//최대 핀 8개(맨 처음 핀부터 마지막 핀까지 백트래킹 진행->백트래킹으로 이동 수 인자 전달)
//더 이상 이동할 곳이 없을 때 판에 남아있는 핀의 갯수 세서 가장 적은 것 답
//이동을 했으면 MAP에서 핀 지우고 pin벡터에서도 erase하기

void go(int num){
    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            if(map[i][j] == 'o'){
                for(int k=0; k<4; k++){
                    int final_x = i+dx[k];
                    int final_y = j+dy[k];
                    if(0<=final_x && final_x<5 && 0<=final_y && final_y<9){
                        //핀의 인접한 곳에 핀이 있으면 그 방향으로 한 번 더 이동해서 핀 안착 & 인접한 핀 없애기
                        if(map[final_x][final_y] == 'o'){
                            //핀 안착
                            int temp_x = final_x+dx[k];
                            int temp_y = final_y+dy[k];
                            if(0<=temp_x && temp_x<5 && 0<=temp_y && temp_y<9){
                                if(map[temp_x][temp_y] == '.'){
                                    map[temp_x][temp_y] = 'o';
                                    map[final_x][final_y] = '.';
                                    map[i][j] = '.';
                                    go(num+1);
                                    map[temp_x][temp_y] = '.';
                                    map[i][j] = 'o';
                                    map[final_x][final_y] = 'o';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int temp = 0;
    for(int n=0; n<5; n++){
        for(int m=0; m<9; m++){
            if(map[n][m] == 'o'){
                temp++;
            }
        }
    }
    final_num = min(final_num, temp);
    final_move = max(final_move, num);
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        final_num = INT_MAX;
        final_move = 0;
        for(int j=0; j<5; j++){
            cin>>s;
            for(int k=0; k<s.size(); k++){
                map[j][k] = s[k];
            }
        }
        go(0);//이동 횟수, 배열 map 반환(현재 map의 상태)
        cout<<final_num<<" "<<final_move<<"\n";
    }
}