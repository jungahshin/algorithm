//DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, v;
int a, b;
int map[1001][1001] = {0, };
int visited_dfs[1001] = {0, };//정점의 개수만큼
int visited_bfs[1001] = {0, };
vector<int> v_dfs;
vector<int> v_bfs;
queue<int> q;

void dfs(int v){
    for(int i=1; i<=n; i++){
        if(map[v][i] == 1 && visited_dfs[i] == 0){//간선이 존재하면
            visited_dfs[i] = 1;
            v_dfs.push_back(i);
            dfs(i);
        }
    }
}

void bfs(){
    v_bfs.push_back(v);
    q.push(v);
    visited_bfs[v] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(map[x][i] == 1 && visited_bfs[i] == 0){
                visited_bfs[i] = 1;
                v_bfs.push_back(i);
                q.push(i);
            }
        }
    }
}

int main(){
    cin>>n>>m>>v;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    v_dfs.push_back(v);
    visited_dfs[v] = 1;
    dfs(v);
    bfs();
    for(int i=0; i<v_dfs.size(); i++){
        cout<<v_dfs[i]<<" ";
    }
    cout<<"\n";
    for(int i=0; i<v_bfs.size(); i++){
        cout<<v_bfs[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
