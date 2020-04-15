//토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
int tomato[1001][1001] = {0, };
int visited[1001][1001] = {0, };
int num = 0;
vector<pair<int, int>> v;
int final = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(){
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<v.size(); i++){
        q.push(make_pair(make_pair(v[i].first, v[i].second), 0));  
    }
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second;
        visited[x][y] = 1;
        q.pop();

        if(tomato[x][y] == 0){
            num--;
        }

        final = max(final, day);

        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<m && !visited[final_x][final_y]){
                visited[final_x][final_y] = 1;
                if(tomato[final_x][final_y] == 0){
                    q.push(make_pair(make_pair(final_x, final_y), day+1));
                }
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1){
                v.push_back(make_pair(i, j));
            }else if(tomato[i][j] == 0){
                num++;
            }
        }
    }
    bfs();
    if(num == 0){//토마토가 다 익었다.
        cout<<final<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
}