// 문제집
#include <queue>
#include <vector>
#include <iostream>
 
using namespace std;
 
int n, m, a, b;
int isDone[32001] = {0, };
vector<int> seq[32001];
priority_queue<int, vector<int>, greater<int>> pq;
 
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        isDone[b]++;
        seq[a].push_back(b);
    }
 
    for(int i=1; i<=n; i++){
        if(isDone[i]==0){
            pq.push(i);
        }
    }
 
    while(!pq.empty()){
        int problem = pq.top();
        pq.pop();
 
        cout<<problem<<" ";
 
        for(int i=0; i<seq[problem].size(); i++){
            int next = seq[problem][i];
            isDone[next]--;
            if(isDone[next]==0){
                pq.push(next);
            }
        }
    }
 
    cout<<"\n";
    return 0;
}// 문제집
#include <queue>
#include <vector>
#include <iostream>
 
using namespace std;
 
int n, m, a, b;
int isDone[32001] = {0, };
vector<int> seq[32001];
priority_queue<int, vector<int>, greater<int>> pq;
 
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        isDone[b]++;
        seq[a].push_back(b);
    }
 
    for(int i=1; i<=n; i++){
        if(isDone[i]==0){
            pq.push(i);
        }
    }
 
    while(!pq.empty()){
        int problem = pq.top();
        pq.pop();
 
        cout<<problem<<" ";
 
        for(int i=0; i<seq[problem].size(); i++){
            int next = seq[problem][i];
            isDone[next]--;
            if(isDone[next]==0){
                pq.push(next);
            }
        }
    }
 
    cout<<"\n";
    return 0;
}
