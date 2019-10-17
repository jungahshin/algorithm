//빙산
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[301][301] = {0, };
int a_check[301][301] = {0, };
vector<pair<int, int>> v;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int final = 0;//년수 세기
int n, m;
bool two = false;

bool all(){
    int temp=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != 0){
                temp++;
            }
        }
    }
    if(temp == 0){//모두 0이다.
        return false;
    }else{
        return true;
    }
}

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_check[i][j] = a[i][j];
        }
    }
}

bool check(){
    copy();
    queue<pair<int, int>> q;
    q.push(make_pair(v[0].first, v[0].second));
    
    while(!q.empty()){
        int x_ = q.front().first;
        int y_ = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int final_x = x_+dx[i];
            int final_y = y_+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<m){
                if(a_check[final_x][final_y] != 0){
                    a_check[final_x][final_y] = 0;
                    q.push(make_pair(final_x, final_y));
                }
            }
        }
    }
    //0의 개수 세서 모두 0이면 한 덩이->false, 모두 0이 아니면 두 덩이 이상이니->ture
    int temp_check = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_check[i][j] != 0){
                temp_check++;
            }
        }
    }
    if(temp_check == 0){
        return false;
    }else{
        return true;
    }
}

void go(){
    while(all()){//모두 0이 아니면 계속 진행
        //녹는 과정
        final++;
        int a_copy[301][301] = {0, };
        for(int i=0; i<v.size(); i++){//빙산의 일부인 애들 계산
            int num = 0;
            int x = v[i].first;
            int y = v[i].second;
            for(int j=0; j<4; j++){
                int nx = x+dx[j];
                int ny = y+dy[j];
                if(0<=nx && nx<n && 0<=ny && ny<m){
                    if(a[nx][ny] == 0){//주위가 바다이면
                        num++;
                    }
                }
            }
            if(a[x][y]<num){
                a_copy[x][y] = 0;
            }else{
                a_copy[x][y] = a[x][y] - num;
            }
        }
        //a_copy값을 다 a에 넣기
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = a_copy[i][j];
            }
        }
        //남아 있는 빙산 위치 v에 업데이트 하기
        v.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] != 0){//빙산이다.
                    v.push_back(make_pair(i, j));
                }
            }
        }
        //두 덩이 check
        if(check()){
            two = true;
            break;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] != 0){//빙산의 일부인 경우 벡터에 저장
                v.push_back(make_pair(i, j));
            }
        }
    }
    go();
    if(two == false){//두 덩이었던 적이 없다.
        cout<<"0"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}