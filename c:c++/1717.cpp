//집합의 표현(map사용-> map이 배열보다 훨씬 메모리도 많이 차지, 느려)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m, kind, a, b;
vector<pair<int, pair<int, int>>> cal;
map<int, int> connect;

int find(int x){
    if(connect[x] == x){
        return x;
    }else{
        return connect[x] = find(connect[x]);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>kind>>a>>b;
        cal.push_back(make_pair(kind, make_pair(a, b)));
    }
    
    for(int i=0; i<=n; i++){
        connect[i] = i;
    }

    for(int i=0; i<cal.size(); i++){
        int what = cal[i].first;
        int x = find(cal[i].second.first);
        int y = find(cal[i].second.second);

        if(what == 0){//합집합 연산
            if(x != y){
                connect[x] = y;
            }
        }else{//같은 집합인지 확인
            if(x==y){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}