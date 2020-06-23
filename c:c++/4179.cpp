//불!
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int r, c, start_x, start_y;
char maze[1001][1001];
int visited[1001][1001] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int> > fire;
string s;
int final = 0;
bool check = false;

void bfs()
{
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(start_x, start_y), 0));
    queue<pair<int, int> > FIRE;
    for(int i=0; i<fire.size(); i++){
        FIRE.push(make_pair(fire[i].first, fire[i].second));
    }

    while(!q.empty()){
        //불 움직이기
        int FNUM = FIRE.size();
        for(int i=0; i<FNUM; i++){
            int fx = FIRE.front().first;
            int fy = FIRE.front().second;
            FIRE.pop();

            for(int j=0; j<4; j++){
                int nfx = fx+dx[j];
                int nfy = fy+dy[j];
                if(0<=nfx && nfx<r && 0<=nfy && nfy<c){
                    if(maze[nfx][nfy] == '.'){
                        maze[nfx][nfy] = 'F';
                        FIRE.push(make_pair(nfx, nfy));
                    }
                }
            }
        }
        
        //지훈 움직이기
        int NUM = q.size();
        for(int i=0; i<NUM; i++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int num = q.front().second;
            visited[x][y] = 1;
            q.pop();

            if(x==0 || x==r-1 || y==0 || y==c-1){
                check = true;
                final = num+1;
                //여기에서 그 자리에 불도 있으면 못 가
                break;
            }

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(0<=nx && nx<r && 0<=ny && ny<c && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    if(maze[nx][ny] == '.'){
                        q.push(make_pair(make_pair(nx, ny), num+1));
                    }
                }
            }                
        }
        if(check == true){
            break;
        }
    }
}

int main()
{
    cin>>r>>c;
    for(int i=0; i<r; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            maze[i][j] = s[j];
            if(s[j] == 'J'){//지훈의 위치
                maze[i][j] = '.';
                start_x = i;
                start_y = j;
            }else if(s[j] == 'F'){
                fire.push_back(make_pair(i, j));
            }
        }
    }
    bfs();

    if(check == false){
        cout<<"IMPOSSIBLE"<<"\n";
    }else{
        cout<<final<<"\n";        
    }
    return 0;
}