//다리 놓기
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

long long sum = 0;
int testcase, n, m;
int visited[31] = {0, };
vector<long long> final;

void go(int num, int idx, int n){
    if(num == n){
        sum++;
        return;
    }

    for(int i=idx; i<m; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        go(num+1, i+1, n);
        visited[i] = false;
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n>>m;//조합으로 해결? -> m개 중에 n개 선택하는 경우의 수 구하기!
        sum = 0;
        memset(visited, 0, sizeof(visited));
        if(m-n > n){
            go(0, 0, n);
        }else{
            go(0, 0, m-n);
        }
        final.push_back(sum);
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}