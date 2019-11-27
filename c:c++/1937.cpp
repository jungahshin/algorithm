//욕심쟁이 판다
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int forest[510][510] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;
int n;
int visited[510][510] = {0, };//x, y->도착, z->num

void go(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //한 칸씩 진행하면서 시작 점으로 가장 좋은 지점 찾기!
            queue<pair<pair<int, int>, int>> q;
            q.push(make_pair(make_pair(i, j), 1));
            for(int a=0; a<n; a++){
                for(int b=0; b<n; b++){
                    visited[a][b] = 0;
                }
            }

            while(!q.empty()){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int num = q.front().second;
                q.pop();
                visited[x][y] = 1;
                //num이 가장 큰 값을 출력한다.
                final = max(final, num);
            
                for(int t=0; t<4; t++){
                    int final_x = x + dx[t];
                    int final_y = y + dy[t];
                    if(0 <= final_x && final_x <n && 0 <= final_y && final_y < n && !visited[final_x][final_y]){
                        if(forest[x][y] < forest[final_x][final_y]){
                            visited[final_x][final_y] = 1;
                            q.push(make_pair(make_pair(final_x, final_y), num+1));              
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>forest[i][j];
        }
    }
    go();
    cout<<final<<"\n";
}