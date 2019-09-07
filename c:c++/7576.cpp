#include<iostream>
#include<vector>
#include<tuple>
#include <algorithm>  
#include<queue>
#include<cstdio>
#include<stdio.h>
using namespace std;
// 단, 2 ≤ M,N ≤ 1,000 이다.
int n,m,t;
int visited[1001][1001] = {0, };
int input[1001][1001] = {0, };
vector<tuple<int, int, int>> tomato;
int dx[4]={0,0,1,-1};//상, 하, 우, 좌 
int dy[4]={1,-1,0,0};
vector<int> day_num;
vector<int> final;
// int day = 0;

void spread(){//익은 토마토 퍼뜨리기
    queue<tuple<int, int, int>> q;
    for(int i=0; i<tomato.size(); i++){
        q.push(tomato[i]);//익은 토마토(1)위치들을 다 큐에 넣는다.
    }
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int day = get<2>(q.front());//default는 0이다.
        day_num.push_back(day);
        q.pop();
        
        for(int i=0; i<4; i++){//상하좌우는 하루만에 퍼뜨릴 수 있는 범위
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            if(0<=next_x && next_x<n && 0<=next_y && next_y<m){
                if(!visited[next_x][next_y] && input[next_x][next_y] == 0){//옆에 안익은 토마토가 있으면
                    visited[next_x][next_y] = 1;//방문했다
                    input[next_x][next_y] = 1;//익었다
                    day = day_num[0] + 1;
                    //day를 따로 저장
                    final.push_back(day);
                    q.push(make_tuple(next_x, next_y, day));
                }
            }
        }
        day_num.clear();
    }
}   

//dfs함수 다 하고 나서 모든 Input값들 중에 하나라도 0의 값이 있으면 -1출력, 다 1아니면 -1이면 ++한 숫자를 출력!
int main(){
    cin>>n;
    cin>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>input[i][j];
            if(input[i][j] == 1){//익은 토마토 위치 저장
                visited[i][j] = 1;
                tomato.push_back(make_tuple(i, j, 0));
            }
            if(input[i][j] == -1){
                visited[i][j] = 1;
            }
        }
    }

    //input에 있는 값들에 0이 하나도 없으면 이미 모두 익은 상태-->0출력
    int num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(input[i][j] == 0){
                num++;
            }
        }
    }
    if(num == 0){//안익은게 없어
        cout<<0<<"\n";
    }

    spread();

    int num_ = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(input[i][j] == 0){
                num_++;
            }
        }
    }
    if(num_ == 0){//다 익었어-->day값 출력(final배열 내림차순으로 정렬해서 [0]값 출력)
        sort(final.begin(), final.end(), greater<int>()); 
        cout<<final[0]<<"\n";
    }else{//안익은게 있어--> -1출력
        cout<<-1<<"\n";
    }
    return 0;
}