// 회장뽑기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
int n, a ,b;
vector<int> connect[51];
vector<pair<int, int>> ans; // 친구의 수, 번호
 
void bfs()
{
    for(int i=1; i<=n; i++){
        if(connect[i].size()==0) continue;
        queue<pair<int, int>> q;
        int visited[51] = {0, };
        int totalLevel = 0;
        q.push(make_pair(i, 0));
 
        while(!q.empty()){
            int friends = q.front().first;
            int level = q.front().second;
            visited[friends] = true;
            q.pop();
 
            totalLevel = max(totalLevel, level);
 
            for(int j=0; j<connect[friends].size(); j++){
                if(visited[connect[friends][j]]) continue;
                visited[connect[friends][j]] = true;
                q.push(make_pair(connect[friends][j], level+1));
            }
        }
        ans.push_back(make_pair(totalLevel, i));
    }
}
 
int main()
{
    cin>>n;
    while(1){
        cin>>a>>b;
        if(a==-1 && b==-1) break;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
 
    bfs();
    sort(ans.begin(), ans.end());
 
    int ansCnt = 0;
    int ansFriends = ans[0].first;
    vector<int> Ans;
    for(int i=0; i<ans.size(); i++){
        if(ans[0].first==ans[i].first){
            ansCnt++;
            Ans.push_back(ans[i].second);
        }
    }
 
    cout<<ansFriends<<" "<<ansCnt<<"\n";
    for(int i=0; i<Ans.size(); i++){
        cout<<Ans[i]<<" ";
    }
    cout<<"\n";
 
    return 0;
}