// SNS
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
 
const int MAX = 1000001;
int n, u, v;
vector<int> connect[MAX]; // 친구 관계
vector<int> oneWay[MAX]; // 단방향 트리로 바꿈
int dp[MAX][2] = {0, };
int visited[MAX] = {0, };
 
void oneWayTree(int node)
{
    visited[node] = true;
    for(int i=0; i<connect[node].size(); i++){
        int next = connect[node][i];
        if(!visited[next]){
            oneWay[node].push_back(next);
            oneWayTree(next);
        }
    }
}
 
int earlyAdaptor(int node, bool isEarly)
{
    int &result = dp[node][isEarly];
    if(result!=-1){
        return result;
    }
 
    if(isEarly){
        result = 1; // 자신이 얼리어답터 -> 자식이 얼리어답터든 아니든 상과없음.
        for(int i=0; i<oneWay[node].size(); i++){
            int next = oneWay[node][i];
            result += min(earlyAdaptor(next, false), earlyAdaptor(next, true));
        }
    }else{ // 얼리어답터가 아니었으면 -> 반드시, 자식은 얼리어답터!
        result = 0;
        for(int i=0; i<oneWay[node].size(); i++){
            int next = oneWay[node][i];
            result += earlyAdaptor(next, true);
        }
    }
 
    return result;
}
 
int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
 
    oneWayTree(1);
 
    cout<<min(earlyAdaptor(1, false), earlyAdaptor(1, true))<<"\n";
    return 0;
}