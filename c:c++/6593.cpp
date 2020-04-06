//상범빌딩
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char building[31][31][31];
int visited[31][31][31] = {0, };
//동서남북상하
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};
int l, r, c;
string s;
int start_x, start_y, start_h, end_x, end_y, end_h;
int final = 0;
bool check = false;

void go(){
    queue<pair<pair<int, int>, pair<int, int>>> q;//시작점 x, y, h, 이동 시간
    q.push(make_pair(make_pair(start_x, start_y), make_pair(start_h, 0)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int h = q.front().second.first;
        int min = q.front().second.second;
        visited[x][y][h] = 1;
        q.pop();

        if(building[h][x][y] == 'E'){
            check = true;
            final = min;
            break;
        }

        for(int i=0; i<6; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            int final_h = h+dh[i];
            if(0<=final_x && final_x<=r && 0<=final_y && final_y<=c && 0<=final_h && final_h<=l && !visited[final_x][final_y][final_h]){
                visited[final_x][final_y][final_h] = 1;
                if((building[final_h][final_x][final_y] == '.') || (building[final_h][final_x][final_y] == 'E')){
                    q.push(make_pair(make_pair(final_x, final_y), make_pair(final_h, min+1)));
                }
            }
        }
    }

}

int main(){
    while(1){
        cin>>l>>r>>c;
        if(l==0 && r==0 && c==0){
            break;
        }
        for(int k=0; k<l; k++){
            for(int i=0; i<r; i++){
                cin>>s;
                for(int j=0; j<s.size(); j++){
                    building[k][i][j] = s[j];
                    if(s[j] == 'S'){//시작점
                        start_x = i;
                        start_y = j;
                        start_h = k;
                    }
                }            
            }
        }
        memset(visited, 0, sizeof(visited));
        check = false;
        go();            
        if(check == true){
            cout<<"Escaped in "<<final<<" minute(s)."<<"\n";
        }else{
            cout<<"Trapped!"<<"\n";
        }
    }
    return 0;
}