// 트리(유니온파인드)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
 
using namespace std;
 
int n, m, a, b;
int connect[555] = {0, };
bool cycle[555];
 
int find(int node)
{
    if(connect[node]==node){
        return node;
    }
 
    return connect[node] = find(connect[node]);
}
 
void setting()
{
    for(int i=1; i<=n; i++){
        connect[i] = i;
        cycle[i] = false;
    }
}
 
int countTree()
{
    map<int, int> m;
    int ans = 0;
    for(int i=1; i<=n; i++){
        int node = find(i);
        if(cycle[node]) continue;
        if(m.count(node)==0){
            m[node] = 1;
            ans++;
        }
    }
 
    return ans;
}
 
int main()
{
    int testcase = 0;
    while(1){
        testcase++;
        cin>>n>>m;
        if(n==0 && m==0) break;
        setting();
        for(int i=0; i<m; i++){
            cin>>a>>b;
            int from = find(a);
            int to = find(b);
 
            if(from!=to){
                if(cycle[from] || cycle[to]){
                    cycle[from] = true;
                    cycle[to] = true;
                }
                connect[from] = to;
            }else{
                cycle[from] = true;
            }
        }
 
        int cnt = countTree();
        if(cnt==0){
            cout<<"Case "<<testcase<<": No trees."<<"\n";
        }else if(cnt==1){
            cout<<"Case "<<testcase<<": There is one tree."<<"\n";
        }else{
            cout<<"Case "<<testcase<<": A forest of "<<cnt<<" trees."<<"\n";
        }
    }
    
    return 0;
}