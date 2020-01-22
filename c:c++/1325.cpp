//효율적인 해킹
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, a, b;
vector<int> trust[10002];
int visited[10002] = {0, };
vector<pair<int, int>> v;
vector<int> really;

//일단, 나를 신뢰하는 애들의 수를 구한다.(1~n for문)
//trust[i][n]은 i가 n을 신뢰한다는 것
//v[n]은 n을 신뢰하는 애들의 집합
//n을 기준으로 trust[i][n]인 것들을 찾고 일단 v[n].size()만큼 더해주고 또 그 i들을 bfs로 i를 큐에 넣어주고 num은 그냥 계속 더해준다.

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}


int bfs(int n){
    int num = 1;//자기 자신은 항상 해킹 가능하다.
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        visited[x] = 1;
        q.pop();
        
        int size = trust[x].size();
        if(size > 0){
            // num += size;
            for(int i=0; i<size; i++){
                if(!visited[trust[x][i]]){
                    visited[trust[x][i]] = 1;
                    q.push(trust[x][i]);
                    num++;
                }
            }
        }
    }
    return num;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;//a가 b를 신뢰한다.
        trust[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        memset(visited, 0, sizeof(visited));
        int temp = bfs(i);
        v.push_back(make_pair(temp, i));
    }
    sort(v.begin(), v.end(), cmp);//오름차순
    int size_1 = v.size();
    for(int i=0; i<size_1; i++){
        if(v[i].first == v[size_1-1].first){
            cout<<v[i].second<<" ";
        }
    }
    cout<<"\n";
    return 0;
}