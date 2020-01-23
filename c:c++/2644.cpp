//촌수계산
#include <iostream>
#include <queue>
using namespace std;

int n, m, a, b, x, y;
int relation[101][101] = {0, };//부모, 자식 관계
int visited[101] = {0, };
int final = 0;
bool check = false;

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    while(!q.empty()){
        int mem = q.front().first;
        int num = q.front().second;
        q.pop();
        visited[mem] = 1;

        if(mem == b){
            check = true;
            final = num;
            break;
        }

        for(int i=1; i<=n; i++){
            if(relation[mem][i] == 1 && relation[i][mem] == 1 && !visited[i]){
                visited[i] = 1;
                q.push(make_pair(i, num+1));
            }
        }
    }
}

int main(){
    cin>>n;
    cin>>a>>b;//a와 b의 촌수를 구해야 한다.
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        relation[x][y] = 1;
        relation[y][x] = 1;
    }
    bfs();
    if(check == false){//피가 섞이지 않았음
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}