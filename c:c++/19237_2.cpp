//어른 상어
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k, dir;
vector<pair<int, int>> sea[22][22]; // 상어의 번호와 남은 시간 저장(상어의 자취)
int shark_num[22][22] = {0, }; // 바다에서의 상어 위치(상어 번호로)
int shark_temp[22][22] = {0, }; // 임시
int shark_dir[402] = {0, }; // 각 상어의 현재 방향 저장 -> 상어가 도중에 죽었으면 방향 값을 -1로 바꿔준다.
vector<pair<int, int>> shark_location[402]; // 각 상어의 현재 위치 저장
vector<int> priority[402][5]; // 각 상어마다 특정 방향에 있어서 우선순위 저장
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sec = 0;
bool final = false;

void move()
{
    memset(shark_temp, 0, sizeof(shark_temp));

    //shark_num을 기준으로 현재 상어의 위치를 보되, 값은 shark_temp에 값을 넣으려고 하는데 이미 값이 있으면 더 작은 번호의 값을 넣어준다.
    //그리고 맨 나중에 모든 배열 상태들 update해준다.

    for(int i=1; i<=m; i++){
        if(shark_dir[i] == -1){ // 죽은 상어
            continue;
        }

        int x = shark_location[i][0].first; // 현재 상어의 위치
        int y = shark_location[i][0].second;
        int dir = shark_dir[i]; // 현재 상어의 방향
        
        bool check = false;

        //먼저 인접한 곳 중에 빈칸이 있는 지 확인
        for(int j=0; j<priority[i][dir].size(); j++){
            int idx = priority[i][dir][j]-1; // 우선순위에 따른 방향
            int nx = x+dx[idx];
            int ny = y+dy[idx];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(shark_num[nx][ny]==0 && sea[nx][ny].size()==0){
                    check = true;
                    if(shark_temp[nx][ny]==0){
                        shark_temp[nx][ny] = i;
                        shark_dir[i] = priority[i][dir][j];
                        if(shark_location[i].size()>0){
                            shark_location[i].clear();
                        }
                        shark_location[i].push_back(make_pair(nx, ny));
                    }else{ // 같은 곳에 다른 상어가 있다. 번호가 작은 값이 살아남는다.
                        if(shark_temp[nx][ny]<i){ // 원래 있던 상어가 더 번호가 작은 경우 -> 현재 상어가 죽는다.
                            shark_dir[i] = -1;
                        }else{ // 원래 상어가 죽는다.
                            shark_dir[shark_temp[nx][ny]] = -1;
                            shark_temp[nx][ny] = i;
                            shark_dir[i] = priority[i][dir][j];
                            if(shark_location[i].size()>0){
                                shark_location[i].clear();
                            }
                            shark_location[i].push_back(make_pair(nx, ny));
                        }
                    }
                    break;
                }
            }
        }

        if(check == false){ // 빈칸을 찾지 못해 자신의 냄새가 있는 곳을 찾는다.
            for(int j=0; j<priority[i][dir].size(); j++){
                int idx = priority[i][dir][j]-1; // 우선순위에 따른 방향
                int nx = x+dx[idx];
                int ny = y+dy[idx];
                if(0<=nx && nx<n && 0<=ny && ny<n){
                    if(sea[nx][ny][0].first==i){ // 인접한 곳에 자신의 냄새가 있는 곳도 우선순위로...
                        shark_temp[nx][ny] = i;
                        shark_dir[i] = priority[i][dir][j];
                        if(shark_location[i].size()>0){
                            shark_location[i].clear();
                        }
                        shark_location[i].push_back(make_pair(nx, ny));
                        break;
                    }                    
                }
            }
        }
    }

    //shark_temp -> shark_num으로 옮겨주기!!
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            shark_num[i][j] = shark_temp[i][j];
        }
    }


    //그리고 마지막으로 현재 sea배열에 들어있는 k값들을 -1씩 감소시킨다.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(sea[i][j].size()>0){
                sea[i][j][0].second--;
                if(sea[i][j][0].second==0){ // 그냥 없애준다.
                    sea[i][j].clear();
                }
            }
        }
    }

    //최종적으로 shark_num에 있는 상어의 번호를 sea에 update시켜준다. (상어 번호, k)저장
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(shark_num[i][j]!=0){
                if(sea[i][j].size()>0){
                    sea[i][j].clear();
                }
                sea[i][j].push_back(make_pair(shark_num[i][j], k));
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>shark_num[i][j];
            if(shark_num[i][j]!=0){
                sea[i][j].push_back(make_pair(shark_num[i][j], k));
                shark_location[shark_num[i][j]].push_back(make_pair(i, j));
            }
        }
    }

    //각 상어의 현재 방향
    for(int i=1; i<=m; i++){
        cin>>dir;
        shark_dir[i] = dir;
    }

    for(int i=1; i<=m; i++){ // 각 상어
        for(int j=1; j<=4; j++){ // 방향마다
            for(int k=0; k<4; k++){
                cin>>dir;
                priority[i][j].push_back(dir); // i번 상어가 j번 방향에서의 우선순위 방향 저장
            }
        }
    }

    
    while(1){
        sec++;
        if(sec>1000){
            final = true;
            break;
        }

        //매번 움직일 때마다 새로운 곳에 저장해야 중복처리를 잘 할 수 있다.
        move();
        
        //1번 상어만 남게 되면 나오기 ->sec출력
        int num = 0;
        for(int i=1; i<=m; i++){
            if(shark_dir[i]!=-1){ // 1이 살아남음
                num++;
            }
        }

        if(num==1){
            break;
        }
    }

    if(final == true){
        cout<<"-1"<<"\n";
    }else{
        cout<<sec<<"\n";
    }
    return 0;
}