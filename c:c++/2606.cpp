//바이러스(유니온 파인드)
#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b;
int connect[101] = {0, };
vector<pair<int, int>> v;//연결된 컴퓨터 저장
int final = 0;

int find(int i){
    if(connect[i] == i){
        return i;
    }else{
        return connect[i] = find(connect[i]);
    }
}

int main(){
    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    //초기 setting
    for(int i=1; i<=n; i++){
        connect[i] = i;
    }
    for(int i=0; i<v.size(); i++){
        int start = find(v[i].first);//각각 루트를 찾는다.
        int end = find(v[i].second);

        
        if(start != end){
            connect[start] = end;
        }
    }
    int temp = find(1);//1의 루트노드를 임시 변수에 넣어놓고 다른 노드의 루트노드를 찾는 과정에서 temp를 만나면 final++해준다.
    for(int i=2; i<=n; i++){
        if(temp == find(i)){
            final++;
        }
    }
    cout<<final<<"\n";
}

/*
1->2->3->5->6, 4->7의 형태로 간선이 이어진다.
*/