//안전영역
#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int n;
int area[101][101] = {0, };
int a[101][101] = {0, };
int min_height = INT_MAX;
int max_height = 0;
int final = 1;//하나도 안잠길 경우
int visited[101][101] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void copy(){
    memset(a, 0, sizeof(a));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = area[i][j];
        }
    }
}

int go(int height){//잠기는 영역의 개수
    int temp = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && a[i][j] != -1){
                temp++;
                queue<pair<pair<int, int>, int>> q;
                q.push(make_pair(make_pair(i, j), 0));

                while (!q.empty())
                {
                    int x = q.front().first.first;
                    int y = q.front().first.second;
                    int num = q.front().second;
                    visited[x][y] = 1;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny]){
                            visited[nx][ny] = 1;
                            if(a[nx][ny] != -1){//잠기지 않았으면
                                q.push(make_pair(make_pair(nx, ny), num+1));
                            }
                        }
                    }
                }
                
            }
        }
    }
    return temp;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>area[i][j];
            min_height = min(min_height, area[i][j]);
            max_height = max(max_height, area[i][j]);
        }
    }
    for(int i=min_height; i<=max_height; i++){
        copy();
        memset(visited, 0, sizeof(visited));
        for(int k=0; k<n; k++){
            for(int t=0; t<n; t++){
                if(a[k][t]<=i){
                    a[k][t] = -1;//물에 잠겼다.
                    visited[k][t] = 1;
                }
            }
        }
        final = max(final, go(i));
    }

    cout<<final<<"\n";
    return 0;
}