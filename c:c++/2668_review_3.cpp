//숫자 고르기 복습
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int n, k;
int a[102] = {0, };
int visited[102] = {0, };
vector<int> final;
vector<int> real_final;
map<int, int> check;

bool dfs(int num, int k, int next){
    bool check = false;

    if(!visited[a[next]]){
        visited[a[next]] = true;
        if(dfs(num+1, k, a[next]) == true){
            check = true;
            final.push_back(next);
        }
    }else{
        if(k == next){
            check = true;
        }
    }

    return check;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>k;
        a[i] = k;
    }
    for(int i=1; i<=n; i++){
        memset(visited, 0, sizeof(visited));
        if(i != a[i]){
            if(!visited[a[i]]){
                visited[a[i]] = true;
                if(dfs(1, i, a[i]) == true){
                    final.push_back(i);
                }
            }
        }else{
            final.push_back(i);
        }
    }
    for(int i=0; i<final.size(); i++){
        if(check.count(final[i]) == 0){
            check[final[i]] = 1;
            real_final.push_back(final[i]);
        }
    }
    cout<<real_final.size()<<"\n";
    sort(real_final.begin(), real_final.end());
    for(int i=0; i<real_final.size(); i++){
        cout<<real_final[i]<<"\n";;
    }
    return 0;
}