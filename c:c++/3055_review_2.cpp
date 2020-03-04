//탈출 복습
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string s;
int r, c;
char map[51][51] = {0, };
int start_x, start_y, final_x, final_y;
vector<pair<int, int>> water;
vector<pair<pair<int, int>, int>> temp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[51][51] = {0, };
int visited_S[51][51] = {0, };//고슴도치가 이미 스스로가 방문한 곳은 방문 못하지만 물은 방문할 수 있으므로 별개로 만듬
int final = 0;
bool check = false;

void go(){
    queue<pair<pair<int, int>, int>> move;//고슴도치 이동
    move.push(make_pair(make_pair(start_x, start_y), 0));

    while(!move.empty()){//더 이상 고슴도치가 움직일 곳이 없을 때까지
        //물이 먼저 찬다.
        int water_size = water.size();
        for(int i=0; i<water_size; i++){
            int water_x = water[i].first;
            int water_y = water[i].second;
            for(int j=0; j<4; j++){
                int final_x = water_x+dx[j];
                int final_y = water_y+dy[j];
                if(0<=final_x && final_x<r && 0<=final_y && final_y<c && !visited[final_x][final_y]){
                    if(map[final_x][final_y] == '.'){
                        visited[final_x][final_y] = 1;
                        map[final_x][final_y] = '*';
                        water.push_back(make_pair(final_x, final_y));
                    }
                }
            }
        }        

        //고슴도치 이동
        while(!move.empty()){
            int x = move.front().first.first;
            int y = move.front().first.second;
            int num = move.front().second;
            visited_S[x][y] = 1;
            move.pop();

            if(x == final_x && y == final_y){//도착지점에 도착
                check = true;
                final = num;
                break;
            }

            for(int i=0; i<4; i++){
                int s_x = x+dx[i];
                int s_y = y+dy[i];
                if(0<=s_x && s_x<r && 0<=s_y && s_y<c && !visited_S[s_x][s_y]){
                    if(map[s_x][s_y] == '.' || map[s_x][s_y] == 'D'){
                        visited_S[s_x][s_y] = 1;
                        temp.push_back(make_pair(make_pair(s_x, s_y), num+1));
                    }
                }
            }            
        }

        if(check == true){
            break;
        }

        for(int i=0; i<temp.size(); i++){
            move.push(make_pair(make_pair(temp[i].first.first, temp[i].first.second), temp[i].second));
        }
        temp.clear();
    }
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j];
            if(s[j] == 'S'){
                start_x = i;
                start_y = j;
                map[i][j] = '.';//고슴도치 자리 빈 자리로..
            }else if(s[j] == 'D'){
                final_x = i;
                final_y = j;
            }else if(s[j] == '*'){
                water.push_back(make_pair(i, j));
            }
        }
    }
    for(int i=0; i<water.size(); i++){
        visited[water[i].first][water[i].second] = 1;
    }
    go();
    if(check == false){//이동 불가능
        cout<<"KAKTUS"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}