//Puyo Puyo
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char puyo[13][7];
vector<pair<int, int>> v;//남아있는 뿌요들 저장-->매번 연쇄 한 번 씩 일어날때마다 clear하고 puyo배열에서 .이 아니면 넣어주기
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int final = 0;

void play(){
    while(1){//하나도 뿌요가 터지지 않으면 빠져나온다.
        //bfs로 인접한 같은 색깔의 뿌요들이 4개 이상이면 없애기
        int visited[13][7] = {0, };
        v.clear();
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(puyo[i][j] != '.'){
                    v.push_back(make_pair(i, j));//남아 있는 뿌요들 v에 넣기
                }
            }
        }
        bool check = false;
        for(int i=0; i<v.size(); i++){
            if(!visited[v[i].first][v[i].second]){//방문하지 않은 뿌요들만
                vector<pair<int, int>> temp;//인접한 뿌요들 저장
                int num = 0;//인접한 뿌요들 세기
                queue<pair<int, int>> q;
                q.push(make_pair(v[i].first, v[i].second));
                temp.push_back(make_pair(v[i].first, v[i].second));

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    visited[x][y] = 1;
                    num++;

                    for(int j=0; j<4; j++){
                        int final_x = x + dx[j];
                        int final_y = y + dy[j];
                        if(0 <= final_x && final_x < 12 && 0 <= final_y && final_y < 6){
                            if(puyo[final_x][final_y] == puyo[x][y] && !visited[final_x][final_y]){
                                visited[final_x][final_y] = 1;
                                q.push(make_pair(final_x, final_y));
                                temp.push_back(make_pair(final_x, final_y));
                            }
                        }
                    }
                }
                if(num >= 4){//없애기+위쪽 애들 밑으로 땡기기
                    check = true;
                    sort(temp.begin(), temp.end());//정렬하기 행 순으로
                    for(int j=0; j<temp.size(); j++){
                        for(int k=(temp[j].first-1); k>=0; k--){
                            puyo[k+1][temp[j].second] = puyo[k][temp[j].second];
                        }
                        puyo[0][temp[j].second] = '.';
                    }
                }
            }
        }
        if(check == false){
            break;//while문 탈출
        }else{
            final++;
        }
    }
}

int main(){
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin>>puyo[i][j];
        }
    }
    play();
    cout<<final<<"\n";
}