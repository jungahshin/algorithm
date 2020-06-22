//수영장 만들기
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
string s;
int temp[51][51] = {0, };
int pool[51][51][10] = {0, };
int visited[51][51] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int height = 0;
int num = 0;

void bfs()
{
    //맨 윗줄부터 bfs로 가장 자리 블록들과 인접해있는 물들을 다 없애준다. -> -1로 바꾸기
    for(int i=height; i>=1; i--)
    {
        memset(visited, 0, sizeof(visited));
        for(int k=1; k<=n; k++)
        {
            for(int t=1; t<=m; t++)
            {
                if((k==1 || k==n || t==1 || t==m) && !visited[k][t] && pool[k][t][i] == 0)//가장자리
                {
                    queue<pair<int, int> > q;
                    q.push(make_pair(k, t));
                    pool[k][t][i] = -1;
                    num--;
                    
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        visited[x][y] = 1;
                        q.pop();

                        for(int z=0; z<4; z++)
                        {
                            int nx = x+dx[z];
                            int ny = y+dy[z];
                            if(1<=nx && nx<=n && 1<=ny && ny<=m && !visited[nx][ny])
                            {
                                if(pool[nx][ny][i] == 0)
                                {   
                                    q.push(make_pair(nx, ny));
                                    pool[nx][ny][i] = -1;
                                    num--;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1; i <=n; i++)
    {
        cin>>s;
        for(int j=0; j<s.size(); j++)
        {
            temp[i][j+1] = s[j]-'0';
            height = max(height, temp[i][j+1]);
        }
    }
    
    for(int i=height ; i>=1; i--)
    {
        for(int k=1; k<=n; k++)
        {
            for(int t=1; t<=m; t++)
            {
                if(i<=temp[k][t])
                {
                    pool[k][t][i] = 1;//물을 채울 수 없는 공간
                }else{
                    num++;
                    pool[k][t][i] = 0;//물을 채우는 공간
                }
            }
        }
    }
    
    bfs();
    cout<<num<<"\n";
    return 0;
}