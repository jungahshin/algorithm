//이 문제는 인접 리스트가 훨씬 쉽다...
//11724-3이 제일 소요 시간 적었음!!
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> input[1001];
int visited[1001]={0, };
int connected_component = 0;
int a,b,m,n ;
int sum = 0;
int next = 0;

void dfs(int y){
    for(int i=0; i<input[y].size(); i++){
        int next = input[y][i];
        if(!visited[next]){
            visited[next] = 1;
            dfs(next);
        }
    }
}

int main(){

    cin>>a>>b;

    if(a<1 || a>1000 || b<0 || b>a*(a-1)/2){
        return 0;
    }

    for(int i=1; i<=b; i++){//간선의 개수 b만큼 입력을 받는다

        cin>>m>>n;

        if(m<1 || n>a){
            return 0;
        }
        
        input[m].push_back(n);//무방향 그래프
        input[n].push_back(m);
    }   

    for(int i=1; i<= a; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i);
            connected_component++;
        }
    }

    cout<<connected_component<<"\n";
}

