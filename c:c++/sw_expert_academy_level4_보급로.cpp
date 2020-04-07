// 1249. [S/W 문제해결 응용] 4일차 - 보급로
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

char map[101][101];
int visited[101][101];//값으로 특정위치까지의 가장 작은 복구작업 시간을 담는다.
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, testcase;
string s;

void go(){
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n){
                if(visited[final_x][final_y]>(visited[x][y]+(map[final_x][final_y]-'0'))){
                    visited[final_x][final_y] = visited[x][y]+(map[final_x][final_y]-'0');
                    q.push(make_pair(final_x, final_y));
                }
            }
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n;
        for(int k=0; k<n; k++){
            cin>>s;
            for(int t=0; t<s.size(); t++){
                map[k][t] = s[t];
            }
        }
        for(int k=0; k<n; k++){
            for(int t=0; t<n; t++){
                visited[k][t] = INT_MAX;
            }
        }
        visited[0][0] = 0;
        go();
        cout<<"#"<<i+1<<" "<<visited[n-1][n-1]<<"\n";
    }
}