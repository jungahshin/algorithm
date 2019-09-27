//인구 이동
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>
using namespace std;

int a[51][51] = {0, };//각 나라의 인구 수
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int final_pop = 0;
int num = 0;//인구 이동 수
int n, l, r;
bool moveflag = true;

typedef struct{
    int x;
    int y;
    int population;
}nation;

vector<nation> v;

void one(){//연합할 수 있는 지 판단

    queue<pair<pair<int, int>, int>> q;//좌표와 인구 수

    while(moveflag){
        moveflag = false;
        int visited[51][51] = {0, };
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                v.clear();
                final_pop = 0;
                if(!visited[i][j]){
                    q.push(make_pair(make_pair(i, j), a[i][j]));
                    visited[i][j] = 1;
                    nation temp;
                    temp.x = i;
                    temp.y = j;
                    temp.population = a[i][j];
                    v.push_back(temp);

                    while(!q.empty()){
                        int nx = q.front().first.first;
                        int ny = q.front().first.second;
                        int pop = q.front().second;
                        q.pop();

                        for(int k=0; k<4; k++){
                            int final_x = nx + dx[k];
                            int final_y = ny+ dy[k];
                            if(0<final_x && final_x<=n && 0<final_y && final_y<=n && !visited[final_x][final_y]){
                                if(l <= abs(pop-a[final_x][final_y]) && abs(pop-a[final_x][final_y]) <= r){
                                    visited[final_x][final_y] = 1;//연결된 부분만 1로 해야된다!!!->연합 국가가 아닌데 1로 하면 나중에 이 국가는 지나침...
                                    nation temp_;
                                    temp_.x = final_x;
                                    temp_.y = final_y;
                                    temp_.population = a[final_x][final_y];
                                    v.push_back(temp_);
                                    q.push(make_pair(make_pair(final_x, final_y), a[final_x][final_y]));
                                }
                            }
                        }
                    }
                    if(v.size()>1){
                    //계산해줘서 각 위치 저장된 나라에 나눈 값(인구값) 넣어주기
                        for(int i=0; i<v.size(); i++){
                            final_pop += v[i].population;
                        }
                        cout<<final_pop<<"/"<<v.size()<<"\n";
                        for(int i=0; i<v.size(); i++){
                            a[v[i].x][v[i].y] = (final_pop/v.size());
                        }
                        moveflag = true;//이 부분을 한 번도 거치지 않았으면 인구이동을 한 번도 하지 않은 것!
                    }
                }
            }
        }
        //뭐라도 움직임이 있었으면
        if(!moveflag){
            break;
        }else{
            num++;
        }

    }
}

int main(){
    cin>>n>>l>>r;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    one();
    cout<<num<<"\n";
}