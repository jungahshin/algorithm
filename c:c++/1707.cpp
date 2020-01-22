//이분 그래프
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int k, v, e, a, b;
vector<int> graph[20002];
queue<int> q;//정점의 번호와 칠한 색깔을 저장한다.
int visited[20002] = {0, };//bfs

bool check_bfs(int n){//모든 곳에 색깔을 일단 칠했으면(방문했으면) true를 리턴한다.
    visited[n] = 1;
    q.push(n);
    bool temp = true;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i=0; i<graph[num].size(); i++){
            if(visited[graph[num][i]] == 0){//아직 방문하지 않았다
                if(visited[num] == 1){//파랑
                    visited[graph[num][i]] = 2;
                    q.push(graph[num][i]);
                }else{
                    visited[graph[num][i]] = 1;
                    q.push(graph[num][i]);
                }
            }else if(visited[graph[num][i]] != 0){//연결이 되어 있지만 이미 방문한 상태->같은 색깔인지 확인
                if(visited[num] == visited[graph[num][i]]){
                    temp = false;
                }
            }
        }
    }
    return temp;
}

int main(){
    cin>>k;
    for(int i=0; i<k; i++){
        bool temp = true;
        //graph 초기화하기
        for(int i=1; i<=v; i++){
            graph[i].clear();
        }
        //visited 초기화하기
        memset(visited, 0, sizeof(visited));
        //q초기화 하기
        while(!q.empty()){
            q.pop();
        }
        cin>>v>>e;
        for(int j=0; j<e; j++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1; i<=v; i++){
            if(visited[i] == 0){
                if(check_bfs(i) == false){
                    temp = false;
                    cout<<"NO"<<"\n";
                }                
            }
        }
        if(temp == true){
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}