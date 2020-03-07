//보석 줍기
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int island[101][101] = {0, };//섬이 연결되어 있는지 여부(숫자-견딜 수 있는 보석 수)
int jewelry[101] = {0, };//1->보석 있음, 0->보석 없음
int visited[101][15] = {0, };
int DP[101] = {0, };
int final = 0;
int n, m, k, a, b, c, t;

bool check(){
    bool temp = false;
    for(int i=1; i<=n; i++){
        if(island[1][i] > 0 && jewelry[i] == 1){//1과 인접해있으면서 보석이 있으면
            temp = true;
        }
    }
    return temp;
}

void go(int num, int area){//num->지금까지 캔 보석 수, area->도착한 섬 번호
    if(area == 1){
        if(check() == false){//더 이상 1 주위에 보석 있는 곳이 없다.
            if(jewelry[1] == 1){
                // cout<<"남아있다~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
                final = max(final, num+1);
                return;
            }
            final = max(final, num);
            return;
        }
    }
    //방문한 섬이 보석이 있는 지 없는 지 체크
    if(jewelry[area] == 1){//있으면, 보석을 가져갈 수도 있고 버리고 갈 수도 있다.
        // cout<<"보석 있는 섬"<<"\n";
        for(int i=1; i<=n; i++){
            if(island[area][i] > 0){
                // cout<<"i"<<i<<"견딜 수 있는 무게"<<island[area][i]<<"\n";
                if(num+1<=island[area][i]){
                    if(!visited[i][num+1]){
                        // cout<<"견딜 수 있어서 가져감"<<"\n";
                        //견딜 수 있으니 가져가거나
                        visited[i][num+1] = 1;
                        jewelry[area] = 0;
                        go(num+1, i);
                        visited[i][num+1] = 0;
                        jewelry[area] = 1;
                    }
                    if(!visited[i][num]){
                        // cout<<"견딜 수 있지만 버리고 감"<<"\n";
                        //버리고 가
                        visited[i][num] = 1;
                        go(num, i);
                        visited[i][num] = 0;
                    }                        
                }else{
                    if(num<=island[area][i]){
                        if(!visited[i][num]){
                            // cout<<"견딜 수 있지만 없어서 그냥 감"<<"\n";
                            visited[i][num] = 1;
                            go(num, i);
                            visited[i][num] = 0;                        
                        }
                    }else{
                        // cout<<"견딜 수도 없고,,, 그냥 못 가"<<"\n";
                        //그냥 못 가
                        continue;
                    }
                }
            }
        }
    }else{//없으면 그냥 간다.
        // cout<<"보석 없는 섬"<<"\n";
        for(int i=1; i<=n; i++){
            if(island[area][i] > 0){
                // cout<<"인접 한 곳"<<i<<"\n";
                if(num<=island[area][i]){
                    if(!visited[i][num]){
                        // cout<<"견딜 수 있지만 없어서 그냥 감"<<"\n";
                        visited[i][num] = 1;
                        go(num, i);
                        visited[i][num] = 0;                        
                    }
                }else{
                    // cout<<"견딜 수도 없고,,, 그냥 못 가"<<"\n";
                    //그냥 못 가
                    continue;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<k; i++){
        cin>>t;
        jewelry[t] = 1;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        island[a][b] = c;
        island[b][a] = c;
    }
    //1번과 인접한 섬을 찾는다.
    for(int i=1; i<=n; i++){
        if(island[1][i] > 0){
            // cout<<"1에서 "<<i<<"\n";
            memset(visited, 0, sizeof(visited));
            visited[i][0] = 1;
            go(0, i);//처음 1번 섬에서 빈손으로 출발
            visited[i][0] = 0;
        }
    }
    cout<<final<<"\n";
}
