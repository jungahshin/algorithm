//연구소3
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
queue<pair<pair<int, int>, int>> q;//활성 바이러스 저장소(q.front().first.first, q.front().first.second, q.front().second)
vector<pair<int, int>> v;
int time_ = 0;//걸리는 시간
vector<int> final_time;
bool selected[2501];//가능한 바이러스 수
int a[51][51] = {0, };
int a_[51][51] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void copy(){//맨 처음 상태를 그래도 복사해놓는다.
    // a_[51][51] = {0, };
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_[i][j] = a[i][j];
        }
    }
}

void spread(){//바이러스 퍼뜨리기(비활성도 활성과 만나면 활성바이러스 큐에 들어감)
    // cout<<"spread"<<"\n";
    int visited[51][51] = {0, };

    while(!q.empty()){
        //중간에 조건으로 모든 빈칸이 바이러스가 번지면 마지막 큐의 시간 출력하고 break하도록 하기
        //큐의 요소->i, j, time
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        cout<<"time"<<z<<"\n";
        visited[x][y] = 1;
        q.pop();

        //모든 빈칸이 바이러스가 번지면 마지막 큐의 시간 출력하고 break하도록 하기
        int temp = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a_[i][j] == 0){//빈칸이 있을 시
                    temp++;
                }
            }
        }
        if(temp == 0){//바이러스가 다 번짐
            final_time.push_back(z+1);
            while( !q.empty() ) q.pop();
            break;
        }else{//다 퍼뜨리지 못한 상태
            final_time.push_back(-1);
        }
        
        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
                visited[final_x][final_y] = 1;
                if(a_[final_x][final_y] == 0){//빈칸일때
                    a_[final_x][final_y] = 3;//활성 바이러스가 된다.
                    q.push(make_pair(make_pair(final_x,final_y),z+1));
                }else if(a_[final_x][final_y] == 2){//비활성 바이러스일 때
                    //큐에 넣는다.
                    a_[final_x][final_y] = 3;//활성 바이러스가 된다.
                    q.push(make_pair(make_pair(final_x,final_y),z+1));
                }
            }
        }
    }
}

void active(){//활성 바이러스들만 큐에 넣어주는 함수->여기서 spread함수 호출
    copy();
    // queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<v.size(); i++){
        if(selected[i] == true){
            q.push(make_pair(make_pair(v[i].first, v[i].second),0));//큐에 위치 저장
            a_[(v[i].first)][(v[i].second)] = 3;//활성 바이러스
            // cout<<"활성"<<v[i].first<<"/"<<v[i].second<<"\n";
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<a_[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    spread();
}

void choose(int idx, int num){
    if(num == m){
        active();//활성 바이러스들만 벡터에 넣어주는 함수
        return;
    }

    for(int i=idx; i<v.size(); i++){
        if(selected[i] == true) continue;
        selected[i] = true;

        choose(i, num+1);//여기 i말고 idx로 하면..ㅎㅎ
        selected[i] = false;
    }
}

//2-비활 바이러스, 1-벽, 0-빈칸, 3-활성 바이러스
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){//바이러스들은 위치를 벡터에 저장-->나중에 그것들 중 m개를 뽑아서 활성 바이러스만 큐에 넣어
                v.push_back(make_pair(i,j));
            }
        }
    }
    //이미 a배열에 0값이 하나도 없으면 그냥 바로 0출력하고 끝내기!
    int zero = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 0){//빈칸이 있을 시
                zero++;
            }
        }
    }
    if(zero == 0){//바이러스가 다 번짐
        cout<<"0"<<"\n";
        return 0;
    }

    choose(0,0);//활성 바이러스 m개 뽑아서 각 경우 spread한 후 가장 최소로 걸리는 시간 출력
    sort(final_time.begin(), final_time.end());
    int temp = 0;
    int temp_ = 0;
    for(int i=0; i<final_time.size(); i++){
        if(final_time[i] != -1){
            temp++;
        }
        if(final_time[i] == -1){
            temp_++;
        }
    }
    if(temp_ == 0){//-1이 하나도 없으면 맨 앞의 값 출력
        cout<<final_time[0]<<"\n";
    }else{
        if(temp != 0){//-1말고 시간 출력
            //-1다 지우고 맨 앞의 것 출력
            for(int i=0; i<final_time.size(); i++){
                if(final_time[i] != -1){
                    cout<<final_time[i]<<"\n";
                    break;
                }
            }
        }else{//다 -1이니 -1출력
            cout<<"-1"<<"\n";
        }        
    }
    return 0;
}