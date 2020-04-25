//외판원 순회(DP+비트마스킹)
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

// (1<<(n번째 섬-1))
// ex) 1 | (1<<4) -> 1번 섬과 5번 섬을 방문했다는 것.
// if ((0 | visited[n]) == visited[n])이면 모두 방문했다는 것.

int n;
int a[17][17] = {0, };
int DP[17][1<<16] = {0, };
int all = 0;

int go(int x, int visited){//x섬에 방문이 visited이 상태
    if(all == visited){//모든 섬을 방문
        if(a[x][1] > 0){//1번 도시로 돌아갈 수 있다.
            return a[x][1];
        }else{
            return 987654321;//1번으로 돌아갈 수 없는 방법은 그냥 최댓값으로 넣어줘 최소값이 될 수 없게 한다.
        }
    }

    if(DP[x][visited] != 0){//이미 다른 값이 있으면 그것을 반환
        return DP[x][visited];
    }
    DP[x][visited] = 987654321;//값이 없으면 최대값으로 만들고 시작,,

    for(int j=1; j<=n; j++){
        if(visited & (1<<(j-1)) || a[x][j] == 0){//이미 방문했거나 이어져 있지 않으면
            continue;
        }
        int new_visited = (visited | (1<<(j-1)));
        DP[x][visited] = min(go(j, new_visited) + a[x][j], DP[x][visited]);
    }
    return DP[x][visited];
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>> a[i][j];
        }
        all = (all | (1<<(i-1)));//모두 방문했을 때의 값
    }    
    cout<<go(1, 1)<<"\n";
    return 0;
}