//가장 먼 노드
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int connect[20001][20001] = {0, };
int visited[20001] = {0, };//노드 방문 여부
vector<pair<int,int>> final;
int final_num = 0;

int solution(int n, vector<vector<int>> edge) {
    for(int i=0; i<edge.size(); i++){
        connect[edge[i][0]][edge[i][1]] = 1;
        connect[edge[i][1]][edge[i][0]] = 1;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    while(!q.empty()){
        int node = q.front().first;
        int num = q.front().second;//연결 간선 수
                
        q.pop();
        visited[node] = 1;
        
        final.push_back(make_pair(num, node));
        
        for(int j=1; j<=n; j++){
            if((connect[node][j] == 1) && (!visited[j])){
                visited[j] = 1;
                q.push(make_pair(j, num+1));
            }
        }
    }
    sort(final.begin(), final.end());
    for(int i=0; i<final.size(); i++){
        if(final[(final.size()-1)].first == final[i].first){//간선 수가 같다면 ++
            final_num++;
        }
    }
        
    return final_num;
}