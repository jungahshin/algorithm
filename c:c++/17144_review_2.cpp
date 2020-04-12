//미세먼지 안녕! 복습
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int r, c, t;
int room[51][51] = {0, };
int start_x, start_y, end_x, end_y;
int dust[51][51] = {0, };//확산된 먼지 저장
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void spread(){
    memset(dust, 0, sizeof(dust));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(room[i][j] != 0){
                int temp = room[i][j]/5;
                int temp_num = 0;
                for(int k=0; k<4; k++){
                    int final_x = i+dx[k];
                    int final_y = j+dy[k];
                    if(0<=final_x && final_x<r && 0<=final_y && final_y<c && room[final_x][final_y] != -1){
                        temp_num++;
                        dust[final_x][final_y] += temp;
                    }
                }
                room[i][j] -= (temp*temp_num);
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(dust[i][j] != 0){
                room[i][j] += dust[i][j];
            }
        }
    }
}

void work(){
    vector<int> v;
    vector<int> temp;
    //공기청정기(윗 부분)
    //순서대로 벡터에 넣어주기!
    //(start_x, 1) ~ (start_x, c-1)
    for(int i=1; i<=c-1; i++){
        v.push_back(room[start_x][i]);
    }
    //(start_x-1, c-1) ~ (0, c-1)
    for(int i=start_x-1; i>=0; i--){
        v.push_back(room[i][c-1]);
    }
    //(0, c-2) ~ (0, 0)
    for(int i=c-2; i>=0; i--){
        v.push_back(room[0][i]);
    }
    //(1, 0) ~ (start_x-1, 0)
    for(int i=1; i<=start_x-1; i++){
        v.push_back(room[i][0]);
    }
    temp.push_back(0);
    for(int i=0; i<v.size()-1; i++){
        temp.push_back(v[i]);
    }
    int idx = 0;
    for(int i=1; i<=c-1; i++){
        room[start_x][i] = temp[idx++];
    }
    for(int i=start_x-1; i>=0; i--){
        room[i][c-1] = temp[idx++];
    }
    for(int i=c-2; i>=0; i--){
        room[0][i] = temp[idx++];
    }
    for(int i=1; i<=start_x-1; i++){
        room[i][0] = temp[idx++];
    }
    temp.clear();
    v.clear();
    //공기청정기(아랫 부분)
    //(end_x, 1) ~ (end_x, c-1)
    for(int i=1; i<=c-1; i++){
        v.push_back(room[end_x][i]);
    }
    //(end_x+1, c-1) ~ (r-1, c-1)
    for(int i=end_x+1; i<=r-1; i++){
        v.push_back(room[i][c-1]);
    }
    //(r-1, c-2) ~ (r-1, 0)
    for(int i=c-2; i>=0; i--){
        v.push_back(room[r-1][i]);
    }
    //(r-2, 0) ~ (end_x+1, 0)
    for(int i=r-2; i>=end_x+1; i--){
        v.push_back(room[i][0]);
    }
    temp.push_back(0);
    for(int i=0; i<v.size()-1; i++){
        temp.push_back(v[i]);
    }
    idx = 0;
    for(int i=1; i<=c-1; i++){
        room[end_x][i] = temp[idx++];
    }
    for(int i=end_x+1; i<=r-1; i++){
        room[i][c-1] = temp[idx++];
    }
    for(int i=c-2; i>=0; i--){
        room[r-1][i] = temp[idx++];
    }
    for(int i=r-2; i>=end_x+1; i--){
        room[i][0] = temp[idx++];
    }
}

void go(){
    int sec = 0;
    while(1){
        sec++;
        if(sec>t){
            break;
        }
        //미세 먼지 확장
        spread();
        //공기청정기 작동
        work();
    }
}

int main(){
    cin>>r>>c>>t;
    int num = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>room[i][j];
            if(room[i][j] == -1 && num == 0){//공기청정기(윗 부분)
                num++;
                start_x = i;
                start_y = j;
            }
            if(room[i][j] == -1 && num == 1){//공기청정기(아랫 부분)
                end_x = i;
                end_y = j;
            }
        }
    }
    go();
    int final_num = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(room[i][j] != -1){
                final_num += room[i][j];
            }
        }
    }
    cout<<final_num<<"\n";
    return 0;
}