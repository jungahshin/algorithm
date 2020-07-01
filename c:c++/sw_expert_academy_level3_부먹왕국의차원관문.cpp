// 7964. 부먹왕국의 차원 관문
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int testcase, n, d, l;
vector<int> door;
int visited[300001] = {0, };
queue<int> q;//위치 개수
int num = 0;
int dir[2] = {-1, 1};

void bfs()
{
    while(!q.empty())
    {
        int x = q.front();
        visited[x] = 1;
        q.pop();

        for(int i=0; i<2; i++){
            for(int k=1; k<=d; k++){
                int nx = x+k*dir[i];
                if(k == d){
                    if(1<=nx && nx<=n && !visited[nx]){
                        if(door[nx] == 0){
                            num++;
                            visited[nx] = 1;
                            q.push(nx);
                        }
                    }else{
                        break;
                    }
                }else{
                    if(1<=nx && nx<=n && !visited[nx]){
                        visited[nx] = 1;
                    }else{
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        num = 0;
        memset(visited, 0, sizeof(visited));
        door.clear();
        bool check = false;
        cin>>n>>d;
        door.push_back(1);
        q.push(0);
        visited[0] = 1;
        for(int j=1; j<=n; j++){
            cin>>l;
            if(l == 1){
                check = true;
                q.push(j);
                visited[j] = 1;
            }
            door.push_back(l);
        }
        door.push_back(1);
        q.push(n+1);
        visited[n+1] = 1;
        bfs();
        cout<<"#"<<i+1<<" "<<num<<"\n";
    }

    return 0;
}