//상근이의 여행
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t, n, m, a, b;
int plane[1001][1001] = {0, };
int visited[1001] = {0, }; 

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        memset(visited, 0, sizeof(visited));
        cin>>n>>m;
        for(int j=0; j<m; j++){
            cin>>a>>b;
            plane[a][b] = 1;
            plane[b][a] = 1;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        int temp = 0;

        while(!q.empty()){
            int country = q.front().first;
            int num = q.front().second;
            visited[country]= 1;
            q.pop();

            for(int k=1; k<=n; k++){
                if(!visited[k] && (plane[country][k] == 1 || plane[k][country] == 1)){
                    temp++;
                    visited[k] = 1;
                    q.push(make_pair(k, num+1));
                }
            }
        }
        cout<<temp<<"\n";
    }
    return 0;
}