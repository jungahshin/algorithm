//인구이동 복습
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, l, r;
int a[51][51] = {0, };
int visited[51][51] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int num = 0;//인구이동 횟수

void move(){
    while(1){
        bool temp = false;//연합국이 하나라도 생성 되었는지 확인하는 변수(연합국이 하나라도 만들어지면 true)
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    // memset(visited, 0, sizeof(visited));
                    vector<pair<int, int>> v;//나중에 인구 이동할때 연합국의 위치 저장
                    int count = 0;//연합국 안에 몇개의 나라가 있는지 카운트
                    int total = 0;//연합국 안에 총 몇명의 사람이 있는지 카운트
                    queue<pair<int, int>> q;//(r, c)
                    q.push(make_pair(i, j));
                    v.push_back(make_pair(i, j));
                    count++;
                    total += a[i][j];

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        visited[x][y] = 1;                    
                        
                        for(int t=0; t<4; t++){
                            int final_x = dx[t]+x;
                            int final_y = dy[t]+y;
                            if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                                if(l<=abs(a[x][y]-a[final_x][final_y]) && abs(a[x][y]-a[final_x][final_y])<=r){
                                    visited[final_x][final_y] = 1;
                                    count++;
                                    total += a[final_x][final_y];
                                    q.push(make_pair(final_x, final_y));
                                    v.push_back(make_pair(final_x, final_y));                                    
                                }
                            }
                        }
                    }

                    if(v.size() > 1){//두 나라 이상 존재시
                        temp = true;
                    }else{
                        continue;
                    }

                    //인구 이동 시작
                    int each_pop = total/count;//각 나라 인구수
                    for(int k=0; k<v.size(); k++){
                        a[(v[k].first)][(v[k].second)] = each_pop;
                    }
                    v.clear();                    
                }
            }
        }
        if(temp == false){//인구 이동 존재하지 않았다.
            break;
        }else{
            num++;
        }
    }
}

int main(){
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    move();
    cout<<num<<"\n";
}