//원판돌리기 복습
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m, t, x, d, k;
int round[55][55] = {0, };
int round_[55][55] = {0, };
int visited[55][55] = {0, };
vector<pair<pair<int, int>, int>> rotation;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;

void copy(){
    for(int k=1; k<=n; k++){
        for(int t=0; t<=m; t++){
            round_[k][t] = round[k][t];
        }
    }
}

void rotate(int a, int b, int c){
    for(int i=1; i<=n; i++){
        if(i%a==0){//a의 배수만 회전 진행
            if(b==0){
                for(int k=0; k<c; k++){
                    vector<int> temp;
                    temp.push_back(round[i][m]);
                    for(int k=1; k<m; k++){
                        temp.push_back(round[i][k]);
                    }
                    for(int k=0; k<temp.size(); k++){
                        round[i][k+1] = temp[k];
                    }                      
                }
            }else if(b==1){
                for(int k=0; k<c; k++){
                    vector<int> temp;
                    for(int k=2; k<=m; k++){
                        temp.push_back(round[i][k]);
                    }
                    temp.push_back(round[i][1]);
                    for(int k=0; k<temp.size(); k++){
                        round[i][k+1] = temp[k];
                    }                    
                }
            }
        }
    }
}

bool remove(){//인접한 수 다 지우기
    bool check = false;
    memset(visited, 0, sizeof(visited));
    //round[n][m+1]로 만들기
    for(int i=1; i<=n; i++){
        round[i][0] = round[i][m];
    }
    copy();
    //0~m까지 bfs진행
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(round_[i][j] != 0 && !visited[i][j]){
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    visited[x][y] = 1;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int final_x = x+dx[k];
                        int final_y = y+dy[k];
                        if(1<=final_x && final_x<=n && 0<=final_y && final_y<=m && !visited[final_x][final_y]){
                            if(round_[final_x][final_y] == round_[x][y]){
                                check = true;
                                visited[final_x][final_y] = 1;
                                round[final_x][final_y] = 0;
                                round[x][y] = 0;
                                q.push(make_pair(final_x, final_y));
                            }
                        }
                    }                
                }                
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(round[i][0] == 0){
            round[i][m] = 0;
        }
    }
    return check;
}

void play(){
    for(int i=0; i<rotation.size(); i++){
        int a = rotation[i].first.first;
        int b = rotation[i].first.second;
        int c = rotation[i].second;
        rotate(a, b, c);
        if(remove() == false){//지워진 수가 없어->평균 계산
            int num = 0;
            int total = 0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(round[i][j]!=0){
                        num++;
                        total += round[i][j];
                    }
                }
            }
            if(total>0){
                float reverage = (float)total/(float)num;
                for(int k=1; k<=n; k++){
                    for(int t=1; t<=m; t++){
                        if(round[k][t]!=0){
                            if(round[k][t]>reverage){
                                round[k][t] -= 1;
                            }else if(round[k][t]<reverage){
                                round[k][t] += 1;
                            }    
                        }
                    }
                }                
            }
        }
    }
}

int main(){
    cin>>n>>m>>t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>round[i][j];
        }
    }
    for(int i=0; i<t; i++){
        cin>>x>>d>>k;//x의 배수를 d방향으로 k칸 회전시킨다.
        rotation.push_back(make_pair(make_pair(x, d), k));
    }
    play();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            final += round[i][j];
        }
    }
    cout<<final<<"\n";
    return 0;
}