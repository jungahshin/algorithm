//탈출 -bfs 2번(물 확장 bfs 한 번, 이동하는 bfs 한 번)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char a[51][51];
queue<pair<int, int>> water;
queue<pair<int, int>> S;
vector<pair<int, int>> D;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int num[51][51] = {0, };
int r, c;

int go(){
    while(!S.empty()){
        //bfs로 물 확장
        int waterSize = water.size();
        for(int i=0; i<waterSize; i++){
            int x = water.front().first;
            int y = water.front().second;
            water.pop();
            for(int j=0; j<4; j++){
                int final_x = x + dx[j];
                int final_y = y + dy[j];
                if(0 <= final_x && final_x < r && 0 <= final_y && final_y < c){
                    if(a[final_x][final_y] == '.'){
                        a[final_x][final_y] = '*';
                        water.push(make_pair(final_x, final_y));
                    }
                }
            }
        }
        int size = S.size();//두더지가 갈 수 있는 곳의 개수
        for(int i=0; i<size; i++){
            int x = S.front().first;
            int y = S.front().second;
            S.pop();
            //S의 위치와 D의 위치가 같은 지 확인!
            if(x == D[0].first && y == D[0].second){
                return num[x][y];
            }
            for(int j=0; j<4; j++){
                int final_x = x + dx[j];
                int final_y = y + dy[j];
                if(0 <= final_x && final_x < r && 0 <= final_y && final_y < c){
                    if((a[final_x][final_y] == '.' || a[final_x][final_y] == 'D') && num[final_x][final_y] == 0){
                        num[final_x][final_y] = num[x][y] + 1;
                        S.push(make_pair(final_x, final_y));
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a[i][j];
            if(a[i][j] == '*'){//물
                water.push(make_pair(i, j));
            }else if(a[i][j] == 'S'){//고슴도치
                S.push(make_pair(i, j));
            }else if(a[i][j] == 'D'){//비버의 굴
                D.push_back(make_pair(i, j));
            }
        }
    }
    int result = go();
    if(result == -1){//경우가 없는 경우
        cout<<"KAKTUS"<<"\n";
    }else{
        cout<<result<<"\n";
    }
}