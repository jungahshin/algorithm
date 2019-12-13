//회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, a, b;
vector<pair<int, int>> v;
int final = 0;
int visited[100001] = {0, };
int num_[26][26] = {0, };//dp

bool check(int y, int b[100001]){
    bool temp;
    for(int i=0; i<v.size(); i++){
        if(!b[i] && y <= v[i].first){
            temp = true;
        }
    }
    return temp;
}

int dfs(int x, int y, int num, int a[100001]){
    if(!check(y, a)){//visited하지 않은 곳에서 더 이상 temp<=v[i].first인 것이 없을 경우
        return 1;
    }
    if(num_[x][y] != 0){
        return num_[x][y];
    }else{
        int temp = y;
        for(int i=0; i<v.size(); i++){
            if(!a[i]){
                if(temp <= v[i].first){//방문하지 않았고 값이 더 큰 애들 중에 가장 차이 값이 작은 애들 
                    a[i] = 1;
                    num_[x][y] = max(num_[x][y], dfs(v[i].first, v[i].second, num+1, a)+1);
                    a[i] = 0;
                }
            }
        }
        return num_[x][y];
    }
}

void go(){
    for(int i=0; i<v.size(); i++){//기준이 되는 회의
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;//기준 회의는 빼고 돈다
        int num = 1;
        if(num_[v[i].first][v[i].second] != 0){
            final = max(final, num_[v[i].first][v[i].second]);
        }else{
            final = max(final, dfs(v[i].first, v[i].second, num, visited));
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    go();
    cout<<final<<"\n";
}