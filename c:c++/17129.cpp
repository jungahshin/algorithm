//윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int n, m, start_x, start_y;
string s;
char island[3001][3001];
int visited[3001][3001] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int final = INT_MAX;

void bfs()
{
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(start_x, start_y), 0));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        visited[x][y] = 1;
        q.pop();

        if(island[x][y] == '3' || island[x][y] == '4' || island[x][y] == '5'){
            final = num;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]){
                visited[nx][ny] = 1;
                if(island[nx][ny] == '0' || island[nx][ny] == '3' || island[nx][ny] == '4' || island[nx][ny] == '5'){
                    q.push(make_pair(make_pair(nx, ny), num+1));
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            island[i][j] = s[j];
            if(s[j] == '2'){
                start_x = i;
                start_y = j;                
            }
        }
    }
    bfs();
    if(final == INT_MAX){
        cout<<"NIE"<<"\n";
    }else{
        cout<<"TAK"<<"\n";
        cout<<final<<"\n";
    }
    return 0;
}