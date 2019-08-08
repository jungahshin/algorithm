#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, m, a, b;

int input[101][101];
int visited[101]= {0, };
int connected[101]={0, };
int num = 0;
int sum = 0;
int t = 5000;
vector<int> final_v;
vector<int> v;

void bfs(int top){//맨 처음 숫자 의미
    visited[top] = 1;
    queue <int> q;
    q.push(top);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(!visited[i] && input[t][i]){
                visited[i] = 1;
                connected[i] = connected[t] + 1;//누적
                q.push(i);
            }
        }
    }
    for(int i=1; i<=n; i++){
        sum += connected[i];
    }
    final_v.push_back(sum);
    sum = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    if(n<2 || n>100 || m<1 || m>5000){
        return 0;
    }

    for(int i=0; i<m; i++){
        cin>>a>>b;
        input[a][b] = 1;
        input[b][a] = 1;
    }

    for(int i =1; i<=n; i++){//top
        bfs(i);
        memset(visited,0,sizeof(visited));//0으로 초기화
        memset(connected,0,sizeof(connected));//0으로 초기화
    }

    for(int i=0; i<final_v.size(); i++){
        t = min(t ,final_v[i]);
    }

    for(int i=0; i<final_v.size(); i++){
        if(final_v[i] == t){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    return 0;
}