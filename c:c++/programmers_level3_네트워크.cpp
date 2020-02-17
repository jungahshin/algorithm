//네트워크
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201] = {0, };
int final = 0;

int solution(int n, vector<vector<int>> computers) {
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            final++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int com = q.front();
                q.pop();
                visited[com] = 1;

                for(int i=1; i<=n; i++){
                    if(!visited[i] && computers[com-1][i-1] == 1){
                        visited[i] = 1;
                        q.push(i);
                    }
                }
            }            
        }
    }
    return final;
}