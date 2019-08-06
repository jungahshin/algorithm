#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int copy_input[9][9] = {0, };
int input[9][9] = {0, };
int n,m,num;
int safe = 0;
int dx[4]={0,0,1,-1};//상, 하, 우, 좌 
int dy[4]={1,-1,0,0};

// 연구소 상황을 입력 받는다.
// 받은 연구소 상황을 다른 배열에 복사한다.
// 복사한 연구소에서 안전구역인 곳에 3개의 벽을 세운다.
// 벽을 세운 상태에서 바이러스를 퍼트린다.
// 다 퍼트린 후, 안전 구역의 수를 센다.
// 구역의 수를 기존의 저장값과 비교하여 최대인지 확인한다.
// 모든 벽을 세울 수 있는 경우를 계산 할 때까지 3번과정부터 반복한다.

//그리고 입력받을 때 바이러스가 있는 곳도 입력을 받아서 queue<pair<int, int>>형태로... 나중에 그 지점을 차례대로 dfs돌기

//연구소 복사하기
void copy(int (*a)[9], int (*b)[9]){//앞의 인자는 복사 연구소, 뒤의 인자는 원본 연구소
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] = b[i][j];
        }
    }
}

//바이러스 퍼뜨리기-->바이러스를 퍼뜨리기 위한 복사 연구소가 하나 더 필요하다!
//copy_input은 벽을 세우기 위한 복사 연구소인데 이것에 바이러스를 퍼뜨리면 벽을 세우기 위한 여러 경우의 수를 만들지 못한다.
void spread(){
    int virus_input[9][9] = {0, };
    copy(virus_input, copy_input);

    while(!q.empty()){//큐에 무언가가 들어있으면 반복
        int x =q.front().first;
        int y =q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int final_x=x+dx[i];
            int final_y=y+dy[i];
            if(0<final_x<=n && 0<final_y<=m){
                if(virus_input[final_x][final_y] == 0){
                    virus_input[final_x][final_y] = 2;
                    q.push(make_pair(final_x, final_y));//큐에 새롭게 점염된 좌표를 넣는다.
                }
            }
        }
    }

    //바이러스 퍼뜨리고 0개수(t) 센다음에 더 큰 값을 반환하기 safe = max(t,safe)
    int t = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(virus_input[i][j] == 0){
                t++;
            }
        }
    }
    safe = max(t, safe);
}



//0 중에 임의로 3개를 정해서 1로 만들어 주기!(벽 만들기)
void wall(int num){
    //벽 3개가 만들어지면 바이러스를 퍼뜨린다.
    if(num == 3){
        spread();
        return;
    }

    for(int i=1; i<=n; i++){//첫 번째, 두 번째 벽이 고정된 상태에서 계속 재귀로 세 번째 벽이 바뀌고(for문 때문에) 
    //for문 다 돌면, 두 번째 벽이 바뀌고 그에 따라 또 세 번째 벽이 계속 바뀌고 맨 나중에는 첫 번째 벽이 바뀐다.
        for(int j=1; j<=m; j++){
            //0을 찾는다
            if(copy_input[i][j] == 0){
                copy_input[i][j] = 1;//벽 세우기
                wall(num+1);
                copy_input[i][j] = 0;//복사 연구소 벽세운거 다시 초기화
                //zero.push_back();
            }
        }
    }  

}

int main(){
    cin>>n>>m;//연구소의 크기 n*m을 입력받는다.
    if(n<3 || m>8){//n과m의 조건
        return 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>input[i][j];//띄어쓰기?
            if(input[i][j] == 2){//바이러스 큐에 저장하기
                q.push(make_pair(i, j));
            }
        }
        //cin>>endl; 엔터 해줘야 하나?
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(input[i][j] == 0){// 첫 번째 벽이니까 원본의 연구소에 0인지 판별한다.
                copy(copy_input,input);//연구소 복사
                copy_input[i][j] = 1;//벽 1개 세움
                wall(1);
                copy_input[i][j] = 0;//벽 다시 허뭄-->첫 번째 고정점
            }
        }
    }
    cout<<safe<<"\n";

    return 0;
}