//미로 만들기
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int room[51][51] = {0, };
int n;
string s;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[51][51];//검은 방의 수 저장
int final = INT_MAX;

//일단, 조합으로 검은방 중 여러개를 선택한다면 시간초과 분명...
//따라서 bfs로 진행하되 검은 방을 만나면 무조건 num+1값을 큐에 계속 넣어준다.
//그리고 항상 지난 칸은 visited처리 해주기

void go(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));//시작위치, 검은방 개수
    visited[0][0] = 0;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        q.pop();

        if((x == n-1) && (y == n-1)){//도착 완료!
            final = min(final, num);
        }
        
        for(int i=0; i<4; i++){
            int final_x = x+dx[i];
            int final_y = y+dy[i];
            if(0<=final_x && final_x<n && 0<=final_y && final_y<n){
                if(room[final_x][final_y] == 1 && visited[final_x][final_y]>num){//흰 방(그냥 지나감)
                    visited[final_x][final_y] = num;
                    q.push(make_pair(make_pair(final_x, final_y), num));
                }
                if(room[final_x][final_y] == 0 && visited[final_x][final_y]>num+1){//검은 방(num+1)
                    visited[final_x][final_y] = num+1;
                    q.push(make_pair(make_pair(final_x, final_y), num+1));
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            room[i][j] = s[j]-'0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = INT_MAX;
        }
    }
    go();
    cout<<final<<"\n";
}