//트리의 지름
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int n, a, b, c;
vector<pair<int, int>> weights[10001];
int visited[10001] = {0, };
int final_num = 0;

int bfs(int i){
    int temp = 0;
    queue<pair<int, int>> q;//노드, 가중치 누적
    q.push(make_pair(i, 0));

    while(!q.empty()){
        int x = q.front().first;
        int num = q.front().second;
        visited[x] = 1;
        q.pop();

        temp = max(temp, num);

        for(int i=0; i<weights[x].size(); i++){
            if(!visited[weights[x][i].first]){
                visited[weights[x][i].first] = 1;
                q.push(make_pair(weights[x][i].first, num+weights[x][i].second));
            }
        }
    }

    return temp;
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>c;
        weights[a].push_back(make_pair(b, c));
        weights[b].push_back(make_pair(a, c));
    }
    for(int i=1; i<=n; i++){
        if(weights[i].size() == 1){//leaf노드인 경우
            memset(visited, 0, sizeof(visited));
            final_num = max(final_num, bfs(i));
        }
    }
    cout<<final_num<<"\n";
    return 0;
}