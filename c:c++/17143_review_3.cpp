//낚시왕 복습
#include <iostream>
#include <vector>
using namespace std;

int R, C, m, r, c, s, d, z;
vector<pair<int, pair<int, int>>> river[101][101];//상어의 크기 저장
vector<pair<int, pair<int, int>>> temp[101][101];//임시
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int final = 0;

void move(int r, int c, int s, int d, int z){
    if(d == 1 || d == 2){//위, 아래
        int num = s%(2*R-2);
        int final_r = r;
        int final_c = c;
        int dir = d;
        for(int i=0; i<num; i++){
            final_r += dx[dir-1];
            final_c += dy[dir-1];
            if(1<=final_r && final_r<=R && 1<=final_c && final_c<=C){
                continue;
            }else{
                if(dir == 1){
                    dir = 2;
                }else if(dir == 2){
                    dir = 1;
                }
                final_r += (2*dx[dir-1]);
                final_c += (2*dy[dir-1]);                    
            }
        }
        temp[final_r][final_c].push_back(make_pair(z, make_pair(s, dir)));
    }else if(d == 3 || d == 4){//왼, 오
        int num = s%(2*C-2);
        int final_r = r;
        int final_c = c;
        int dir = d;
        for(int i=0; i<num; i++){
            final_r += dx[dir-1];
            final_c += dy[dir-1];
            if(1<=final_r && final_r<=R && 1<=final_c && final_c<=C){
                continue;
            }else{
                if(dir == 3){
                    dir = 4;
                }else if(dir == 4){
                    dir = 3;
                }
                final_r += (2*dx[dir-1]);
                final_c += (2*dy[dir-1]);                    
            }
        }
        temp[final_r][final_c].push_back(make_pair(z, make_pair(s, dir)));
    }
}

void go(){
    int king = 0;
    while(1){
        //낚시왕 이동
        king++;
        if(king>C){
            break;
        }
        //가장 가까운 상어를 잡는다.
        for(int i=1; i<=R; i++){
            if(river[i][king].size()>0){
                final += river[i][king][0].first;
                river[i][king].clear();
                break;
            }
        }
        //상어 이동
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(river[i][j].size()>0){
                    move(i, j, river[i][j][0].second.first, river[i][j][0].second.second, river[i][j][0].first);
                }
            }
        }
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(river[i][j].size()>0){
                    river[i][j].clear();
                }
                if(temp[i][j].size()>0){
                    if(temp[i][j].size()>1){
                        sort(temp[i][j].begin(), temp[i][j].end());
                        int idx = temp[i][j].size()-1;  
                        river[i][j].push_back(make_pair(temp[i][j][idx].first, make_pair(temp[i][j][idx].second.first, temp[i][j][idx].second.second)));
                    }else{
                        river[i][j].push_back(make_pair(temp[i][j][0].first, make_pair(temp[i][j][0].second.first, temp[i][j][0].second.second)));
                    }
                    temp[i][j].clear();                    
                }
            }
        }
    }
}

int main(){
    cin>>R>>C>>m;
    for(int i=0; i<m; i++){
        cin>>r>>c>>s>>d>>z;
        river[r][c].push_back(make_pair(z, make_pair(s, d)));
    }
    go();
    cout<<final<<"\n";
    return 0;
}