//단지번호 붙이기(BFS)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
string s;
vector<int> town;
int map[26][26] = {0, };
int visited[26][26] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int i, int j){
    int final = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while(!q.empty()){
        final++;
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;
        q.pop();

        for(int k=0; k<4; k++){
            int final_x = x+dx[k];
            int final_y = y+dy[k];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                if(map[final_x][final_y] == '1'){
                    visited[final_x][final_y] = 1;
                    q.push(make_pair(final_x, final_y));                    
                }
            }
        }
    }

    return final;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == '1' && !visited[i][j]){
                int temp = bfs(i, j);
                town.push_back(temp);
            }
        }
    }
    sort(town.begin(), town.end());
    cout<<town.size()<<"\n";
    for(int i=0; i<town.size(); i++){
        cout<<town[i]<<"\n";
    }
}