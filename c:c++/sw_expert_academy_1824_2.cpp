#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int x,y,mem,dir;
    
    node(){ }
    node(int _x,int _y,int _mem,int _dir) : x(_x),y(_y),mem(_mem),dir(_dir) { }
};

int testcase;
int n,m;
string ans;
char map[21][21];
bool visited[21][21][16][4];
vector<string> v;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool bfs(){
    queue<node> q;
    q.push(node(0,0,0,0));
    visited[0][0][0][0] = true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int mem = q.front().mem;
        int dir = q.front().dir;
        q.pop();
        
        if(map[x][y]>='0' && map[x][y]<='9'){
            mem = map[x][y] - '0';
        }
        else if(map[x][y] == '>'){
            dir = 0;
        } 
        else if(map[x][y] == '<'){
            dir = 1;
        } 
        else if(map[x][y] == 'v'){
            dir = 2; 
        } 
        else if(map[x][y] == '^'){
            dir = 3; 
        } 
        else if(map[x][y] == '+'){
            mem = mem == 15 ? 0 : mem + 1; 
        } 
        else if(map[x][y] == '-'){
            mem = mem == 0 ? 15 : mem - 1; 
        } 
        else if(map[x][y] == '_'){
            dir = mem == 0 ? 0 : 1;
        } 
        else if(map[x][y] == '|'){
            dir = mem == 0 ? 2 : 3; 
        } 
        else if(map[x][y] == '@'){
            return true;
        } 
        else if(map[x][y] == '?'){
            for(int i=0; i<4; i++){//상하좌우 모두 해보기!!
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx == -1) nx = n-1;
                else if(nx == n) nx = 0;
                if(ny == -1) ny = m-1;
                else if(ny == m) ny = 0;
                
                if(!visited[nx][ny][mem][i]){
                    q.push(node(nx,ny,mem,i));
                    visited[nx][ny][mem][i] = true;
                }
            }
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx == -1) nx = n-1;
        else if(nx == n) nx = 0;
        if(ny == -1) ny = m-1;
        else if(ny == m) ny = 0;
        
        if(!visited[nx][ny][mem][dir]){
            q.push(node(nx,ny,mem,dir));
            visited[nx][ny][mem][dir] = true;
        }
    }
    
    return false;
}

int main() {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> testcase;
    for(int t=1; t<=testcase; t++){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> map[i][j];
            }
        }
        
        memset(visited, false, sizeof(visited));
        if(bfs() == false){
            ans = "NO";
        }else{
            ans = "YES";
        }

        v.push_back(ans);
    }

    for(int i=0; i<v.size(); i++){
        cout<<"#"<<i+1<<" "<<v[i]<<"\n";
    }
    return 0;
}