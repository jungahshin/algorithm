// 동굴탐험
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
 
using namespace std;
 
vector<vector<int>> graph;
unordered_map<int, int> before;
unordered_map<int, int> after;
vector<bool> checked;
 
void bfs()
{
    queue<int> q;
    checked[0] = true;
    q.push(0);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(checked[next]) continue;
            if(!checked[before[next]]){
                after[before[next]] = next;
                continue;
            }
            
            q.push(next);
            checked[next] = true;
            
            if(after.find(next) != after.end()){
                q.push(after[next]);
                checked[after[next]] = true;
            }
        }
    }
}
 
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    graph.resize(n);
    checked.resize(n);
    
    for(int i=0; i<path.size(); i++){
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }
    
    for(int i=0; i<order.size(); i++){
        before[order[i][1]] = order[i][0];
    }
    
    // 0번방 이전에 방문해야하는 곳이 있다면, 불가능하다.(왜냐면, 동굴의 입구는 반드시 0번방부터 출발해야하기 때문..)
    if(before[0]!=0) return false;
    
    bfs();
    
    for(int i=0; i<n; i++){
        if(!checked[i]){
            answer = false;
            break;
        }
    }
    
    return answer;
}