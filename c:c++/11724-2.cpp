//인접 리스트 이용!(c++ vector사용)
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
vector<int> map[1001];//vector가 java에서의 인접리스트 느낌?
int check[1001] = {0, };
int connected_component=0;

void dfs(int v){
    for(int i=0; i<map[v].size(); i++){
        int next = map[v][i];
        if(check[next] == 0){
            check[next] = 1;
            dfs(next);
        }
    }
}
int main(void){
    int n,m;
    cin >> n >> m;

    for(int i=0; i< m; i++){
        int u,v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(check[i] == 0){
            check[i] = 1;
            dfs(i); //값 체크
            connected_component++;
        }
    }
    cout << connected_component<<"\n";
}