//삼성 2018하반기 코테 문제
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int n, status;
int input[21][21] = {0, };
int a,b;
int c,d;
int shark_size = 2;//초기 아기상어 크기
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[21][21] = {0, };
vector <tuple<int, int, int>> final_num;//최단거리(몇로 걸렸는지)-->나중에 여기 값들 다 더하면 총 걸린 시간 나옴
vector <pair<int,int>> can_eat;
int num;
int count = 0;

//N(2 ≤ N ≤ 20)
//지나갈 수 있는 -> 크기 같, 작
//먹을 수 있는 -> 크기 작
//최단 거리(상하좌우)에 있는 물고기를 먹는다, 최단거리가 같다면 가장 위에 있는 그 중에서도 가장 왼쪽에 있는 물고기를 먹는다.
//아기 상어 자기 자신의 크기 갯수만큼 물고기를 먹어야 +1 크기 증가
//더 이상 먹을 수 있는 물고기가 없으면 엄마 호출

//최단 경로에 있는 물고기를 먹는 함수---------------->visited초기화!!!!!!!!!!!!!!!!반드시 어디선가 하기!!!!!!!!!!!!!!!!!!
void shortest(int x, int y){//도착지점
    // queue<pair<int, int>> q;
    // queue <int> q_num;
    queue<tuple<int, int, int>> q;
    // q.push(make_pair(a, b));//출발지점
    // q_num.push(0);
    q.push(make_tuple(a, b, 0));
    visited[a][b] = 1;

    while(!q.empty()){
        int shortest_x =get<0>(q.front());
        int shortest_y =get<1>(q.front());
        int num = get<2>(q.front());
        q.pop();
        // q_num.pop();

        for(int i=0; i<4; i++){
            int final_x = shortest_x+dx[i];//출발지점
            int final_y = shortest_y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n){
                if(intput[final_x][final_y] <= shark_size && !visited[final_x][final_y]){//지나갈 수 있는 조건
                    num++;
                    visited[final_x][final_y] = 1;
                    if(final_x == x && final_y == y){//값이 도착지점과 같으면
                        final_num.push_back(make_tuple(final_x, final_y, num));
                        //input[final_x][final_y] = 9;
                        //input[a][b] = 0;
                        //a = final_x, b = final_y-->출발 점이 바뀜
                        break;
                    }
                    q.push(make_tuple(final_x, final_y, num));
                }
            }
        }
    }

}



//아기 상어보다 크기가 작은(먹을 수 있는) 물고기 위치 찾기!
int find(int size){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(input[i][j] < size){//먹을 수 있는 물고기
                //bfs로 최단거리(상, 하, 좌, 우)
                can_eat.push_back(make_pair(i,j));
                // int num = 0;
            }
        }
    }
    for(int i=0; i<can_eat.size(); i++){
        shortest(can_eat[i].first, can_eat[i].second);//모든 먹을 수 있는 물고기 위치에 대해 최단인 거리 구해보기
        int visited[21][21] = {0, };
    }
    //for문으로 final_num에 들은 num값 중에 가장 작은 값의 위치가 다시 시작점이되고 input값은 9가 되고 input[a][b] = 0이되고 다시 그 위치가 = a,b(시작점)가 된다.
    //input[final_x][final_y] = 9;
    //input[a][b] = 0;
    //a = final_x, b = final_y-->출발 점이 바뀜
    //그리고 결론적으로 다시 그 점으로 find를 돈다.

    sort(final_num.begin(), final_num.end(), sortbyth); //num에 대해 정렬
    vector<pair<int, int>> priority;
    for(int i=0; i<final_num.size(); i++){
        if(get<2>(final_num[0]) == get<2>(final_num[i])){//num같으면 prioirty에 넣어
            priority.push_back(make_pair(get<0>(final_num[i]), get<1>(final_num[i])));
        }
    }
    
    

    //count수가 
    //위치 반환하기-->만약에 최단 거리에 있는 물고기가 여러개라면 우선순위 판별해서 하나의 위치만 반환
}

int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>status;
            if(status == 9){//아기 상어
                //아기 상어의 위치 저장
                a = i;
                b = j;
            }else{//물고기들 크기만 저장
                input[i][j] = status;
            }
        }
    }

    find(shark_size);

}