//텀 프로젝트(서브 사이클 생각도 못함...ㅋㅋㅋㅋ)
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int testcase, n, mem;
int relation[100001];
int visited[100001] = {0, };
vector<int> temp;
int final = 0;
int start = 0;

void go(int n, int num, vector<int>& v){
    if(visited[n]){//이미 방문한 경로이다.
        int sub_start = 0;
        bool sub_check = false;
        for(int i=0; i<v.size(); i++){
            if(v[i] == n){//서브 사이클 형성
                sub_start = i;
                sub_check = true;
                break;
            }
        }
        if(sub_check == true){  
            for(int j=sub_start; j<v.size(); j++){
                visited[v[j]] = 1;
            }
            final -= (v.size()-1-sub_start)+1;
        }        
        return;
    }

    visited[n] = 1;
    v.push_back(n);
    go(relation[n-1], num+1, v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        memset(visited, 0, sizeof(visited));
        cin>>n;
        final = n;
        for(int j=0; j<n; j++){
            cin>>mem;
            relation[j] = mem;
        }
        for(int j=0; j<n; j++){
            if(!visited[j+1]){//그룹에 있지 않으면 dfs진행한다.
                temp.clear();
                start = j+1;
                go(j+1, 0, temp);
            }
        }
        cout<<final<<"\n";
    }
}