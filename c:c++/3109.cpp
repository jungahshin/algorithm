//빵집
#include <iostream>
using namespace std;

int r, c;
string s;
char bread[10001][501];
int visited[10001][501] = {0, };
int final = 0;
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

bool dfs(int x, int y, int num){//열마다 진행하기
    if(y == c-1){
        final++;
        return true;
    }

    for(int i=0; i<3; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx<r && 0<=ny && ny<c && bread[nx][ny] == '.' && !visited[nx][ny]){
            visited[nx][ny] = 1;
            if(dfs(nx, ny, num) == true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            bread[i][j] = s[j];
        }
    }
    for(int i=0; i<r; i++){
        if(!visited[i][0]){
            visited[i][0] = 1;
            dfs(i, 0, 0);
        }
    }
    cout<<final<<"\n";
    return 0;
}