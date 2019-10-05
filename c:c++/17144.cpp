//미세먼지 안녕!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, t, input;
int a[51][51] = {0, };//미세먼지 저장
vector<pair<int, int>> v;//공기청정기 위치 저장
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<int> temp;
queue<int> q;
int final = 0;

void spread(){//미세먼지 확산
    int b[51][51] = {0, };
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int num = 0;
            //공기청정기 있는 곳(-1) & 존재하지 않는 곳은 미세먼지 확산 노노
            if(a[i][j] == 0){
                continue;
            }else if(a[i][j] == -1){
                continue;
            }else{//미세 먼지 확산
                for(int k=0; k<4; k++){
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    if(0<=nx && nx<r && 0<=ny && ny<c){//확산 가능
                        if(a[nx][ny] != -1){
                            num++;//확산 가능한 곳 개수세기
                            b[nx][ny]+=(a[i][j]/5);
                        }
                    }
                }
                a[i][j]-=((a[i][j]/5)*num);
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            a[i][j] += b[i][j];
        }
    }
}

void wind(){//공기청정기 바람
    //공기청정기 위
    for(int i=1; i<c-1; i++){//맨 밑 행
        temp.push_back(a[v[0].first][i]);
    }
    for(int i=v[0].first; i>=0; i--){//맨 오른쪽 열
        temp.push_back(a[i][c-1]);
    }
    for(int i=c-2; i>=0; i--){
        temp.push_back(a[0][i]);
    }
    for(int i=1; i<v[0].first; i++){
        temp.push_back(a[i][v[0].second]);
    }

    temp.erase(temp.begin()+temp.size()-1);//맨 마지막 원소 지우기

    for(int i=0; i<temp.size(); i++){
        q.push(temp[i]);
    }
    
    temp.clear();

    for(int i=2; i<c-1; i++){//맨 밑 행
        int temp_1 = q.front();
        q.pop();
        a[v[0].first][i] = temp_1;
    }
    for(int i=v[0].first; i>=0; i--){//맨 오른쪽 열
        int temp_2 = q.front();
        q.pop();
        a[i][c-1] = temp_2;
    }
    for(int i=c-2; i>=0; i--){
        int temp_3 = q.front();
        q.pop();
        a[0][i] = temp_3;
    }
    for(int i=1; i<v[0].first; i++){
        int temp_4 = q.front();
        q.pop();
        a[i][v[0].second] = temp_4;
    }
    a[v[0].first][v[0].second+1] = 0;

    while( !q.empty() ) q.pop();

    //공기청정기 아래
    for(int i=1; i<c-1; i++){//맨 밑 행
        temp.push_back(a[v[1].first][i]);
    }
    for(int i=v[1].first; i<r; i++){
        temp.push_back(a[i][c-1]);
    }
    for(int i=c-2; i>=0; i--){
        temp.push_back(a[r-1][i]);
    }
    for(int i=r-2; i>v[1].first; i--){
        temp.push_back(a[i][v[1].second]);
    }

    temp.erase(temp.begin()+temp.size()-1);//맨 마지막 원소 지우기

    for(int i=0; i<temp.size(); i++){
        q.push(temp[i]);
    }
    temp.clear();

    for(int i=2; i<c-1; i++){//맨 밑 행
        int temp_5 = q.front();
        q.pop();
        a[v[1].first][i] = temp_5;
    }
    for(int i=v[1].first; i<r; i++){
        int temp_6 = q.front();
        q.pop();
        a[i][c-1] = temp_6;
    }
    for(int i=c-2; i>=0; i--){
        int temp_7 = q.front();
        q.pop();
        a[r-1][i] = temp_7;
    }
    for(int i=r-2; i>v[1].first; i--){
        int temp_8 = q.front();
        q.pop();
        a[i][v[1].second] = temp_8;
    }
    a[v[1].first][v[1].second+1] = 0;
}

int main(){
    cin>>r>>c>>t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>input;
            a[i][j] = input;
            if(input == -1){//공기청정기
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<t; i++){//t초만큼 반복하기
        //미세먼지 확산
        spread();
        //공기청정기 바람
        wind();
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j] != -1){
                final+=a[i][j];
            }
        }
    }
    cout<<final<<"\n";
}
