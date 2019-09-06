//미로탐색
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstdio>
#include<stdio.h>
using namespace std;

int input[1000][1000] = {0, };

int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[1000][1000] = {0, }
vector <int> queue_num;
vector <int> final;

//N, M(2 ≤ N, M ≤ 100)

void shortest(int a, int b, int c){//출발 점 위치랑 num
    visited[a][b] = 1;
    queue <tuple<int, int, int>> q;
    q.push(make_tuple(a, b, c));

    bool exit = false;
    while(!q.empty()){
        int queue_a = get<0>(q.front());
        int queue_b = get<1>(q.front());
        int num = get<2>(q.front());
        queue_num.push_back(num);
        q.pop();

        for(int i=0; i<4; i++){
            int next_a = queue_a + dx[i];
            int next_b = queue_b + dy[i];
 
            if(1<=next_a && next_a<=n && 1<=next_b && next_b<=m){
                if(!visited[next_a][next_b] && input[next_a][next_b] == 1){
                    num = queue_num[0]+1;//지나갈 수 있음
                    visited[next_a][next_b] = 1;

                    if(next_a == n && next_b == m){//도착 지점
                        final.push_back(num);
                        exit = true;
                        break;
                    }else{
                        q.push(make_tuple(next_a, next_b, num));
                    }
                }
            }
        }
        queue_num.clear();
        if(exit == true){
            break;
        }
    }

}

int main(){
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &input[i][j]);
        }
    }

    shortest(1,1,1);//출발점

    cout<<final[0]<<"\n";
    return 0;
}


