//카탄의 개척자
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int tile, testcase;
int dir[6] = {1, 0, 1, 1, 1, 1};//각 이동하는 방향 순으로 나눈다.
int map[1000][1000] = {0, };//좌표를 총 (1000, 1000)으로 잡고 중간값인 (500, 500)을 시작점으로 한다.
int dx[6] = {-1, -2, -1, 1, 2, 1};
int dy[6] = {1, 0, -1, -1, 0, 1};
int kind[7] = {0, };//각 자원의 수
int end_x, end_y = 0;

void go(int n){
    //초기 setting
    int num = 1;
    int x = 500;
    int y = 500;
    bool check = false;
    while(1){
        for(int i=0; i<6; i++){//6방향만큼 반복
            for(int j=0; j<dir[i]; j++){
                num++;
                x += dx[i];
                y += dy[i];
                //6방향 주위에 있는 것들을 파악
                int temp[7] = {0, };
                vector<pair<int, int>> final;
                for(int k=0; k<6; k++){
                    int final_x = x+dx[k];
                    int final_y = y+dy[k];
                    temp[map[final_x][final_y]]++;
                }
                for(int k=1; k<=5; k++){
                    if(temp[k] == 0){
                        final.push_back(make_pair(kind[k], k));
                    }
                }
                sort(final.begin(), final.end());
                map[x][y] = final[0].second;
                kind[final[0].second]++;
                if(num == n){
                    end_x = x;
                    end_y = y;
                    check = true;
                    break;
                }
            }
            if(check == true){
                break;
            }
        }
        if(check == true){
            break;
        }
        //6방향을 모두 순회하고 난 후에는, dir배열 원소 +1씩 증가
        for(int i=0; i<6; i++){
            dir[i]++;
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>tile;
        memset(map, 0, sizeof(map));
        memset(kind, 0, sizeof(kind));
        dir[0] = 1;
        dir[1] = 0;
        dir[2] = 1;
        dir[3] = 1;
        dir[4] = 1;
        dir[5] = 1;
        map[500][500] = 1;//시작점
        kind[1] = 1;
        if(tile == 1){
            cout<<"1"<<"\n";
        }else{
            go(tile);           
            cout<<map[end_x][end_y]<<"\n"; 
        }
    }
    return 0;
}