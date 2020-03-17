//보물섬
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
string s;
char map[51][51] = {0, };
int visited[51][51] = {0, };
int final = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void go(){
    //각 (i, j)지점별로 경로 수를 센다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'L'){
                memset(visited, 0, sizeof(visited));
                queue<pair<pair<int, int>, int>> q;
                q.push(make_pair(make_pair(i, j), 0));
                int temp = 0;

                while(!q.empty()){
                    int x = q.front().first.first;
                    int y = q.front().first.second;
                    int num = q.front().second;
                    visited[x][y] = 1;
                    q.pop();

                    temp = max(temp, num);

                    for(int k=0; k<4; k++){
                        int final_x = x+dx[k];
                        int final_y = y+dy[k];
                        if(0<=final_x && final_x<n && 0<=final_y && final_y<m && !visited[final_x][final_y]){
                            visited[final_x][final_y] = 1;
                            if(map[final_x][final_y] == 'L'){
                                q.push(make_pair(make_pair(final_x, final_y), num+1));
                            }
                        }
                    }
                }

                final = max(final, temp);                
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j];
        }
    }
    go();
    cout<<final<<"\n";
    return 0;
}