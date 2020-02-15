//숫자고르기 복습
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[101] = {0, };
int visited[101] = {0, };
int final = 0;
vector<int> total;

void go(){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(i == a[i]){
                final += 1;
                visited[i] = 1;
                total.push_back(i);
                continue;
            }
            int x = i;//출발점
            queue<pair<int, int>> q;//출발점과 num
            vector<int> v;
            q.push(make_pair(x, 0));
            while(!q.empty()){
                int next = q.front().first;
                int num = q.front().second;
                q.pop();

                if(num > n){
                    break;
                }

                if(next == x && num > 1){
                    for(int j=0; j<v.size(); j++){
                        total.push_back(v[j]);
                        visited[v[j]] = 1;
                    }
                    final += num;
                    break;
                }

                v.push_back(next);

                if(!visited[a[next]]){
                    q.push(make_pair(a[next], num+1));
                }
            }
            v.clear();            
        }

    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    go();
    sort(total.begin(), total.end());
    cout<<final<<"\n";
    for(int i=0; i<total.size(); i++){
        cout<<total[i]<<"\n";
    }
}