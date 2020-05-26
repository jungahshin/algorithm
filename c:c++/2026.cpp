//소풍
#include <iostream>
#include <vector>
using namespace std;

int k, n, f, a, b;
int relation[902][902] = {0, };
int visited[902] = {0, };
bool check = false;

bool check2(int now){//새로 들어온 애가 기존에 있던 애들과 모두 친구이면 성립
    for(int i=1; i<=n; i++){
        if(visited[i] == true){
            if(relation[i][now] == false){
                return false;
            }
        }
    }
    
    return true;
}

void go(int num, int now){
    if(check == true) return;
    if(num == k){
        check = true;
        for(int i=1; i<=n; i++){
            if(visited[i] == true){
                cout<<i<<"\n";
            }
        }
        return;
    }

    for(int i=now+1; i<=n; i++){
        if(!visited[i] && (num+n-i+1)>=k && (relation[now][i] == 1 || relation[i][now] == 1)){
            if(check2(i) == false) continue;
            visited[i] = 1;
            go(num+1, i);
            visited[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>k>>n>>f;
    for(int i=0; i<f; i++){
        cin>>a>>b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    for(int i=1; i<=n; i++){
        if(check == true){
            break;
        }
        if(!visited[i] && (n-i+1)>=k){
            visited[i] = 1;
            go(1, i);
            visited[i] = 0;            
        }
    }
    if(check == false){
        cout<<"-1"<<"\n";
    }
    return 0;
}