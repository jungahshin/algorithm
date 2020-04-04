//여행 가자
#include <iostream>
#include <vector>
using namespace std;

int a[201][201] = {0, };
int connect[201] = {0, };
vector<int> travel;//여행갈 도시들
vector<pair<int, int>> relation;
int n, m, connection, city;
bool check = true;

int find(int i){
    if(connect[i] == i){
        return i;
    }else{
        return connect[i] = find(connect[i]);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>connection;
            if(connection == 1){
                relation.push_back(make_pair(i, j));                
            }
        }
    }
    for(int i=0; i<m; i++){
        cin>>city;
        travel.push_back(city);
    }
    //초기 setting
    for(int i=1; i<=n; i++){
        connect[i] = i;
    }
    for(int i=0; i<relation.size(); i++){
        int start = find(relation[i].first);
        int end = find(relation[i].second);

        if(start != end){
            connect[start] = end;
        }
    }

    //이제 모든 여행계획을 수행할 수 있는지 판단하기
    for(int i=0; i<travel.size()-1; i++){
        int city1 = find(travel[i]);
        int city2 = find(travel[i+1]);

        if(city1 != city2){//하나라도 여행할 수 없으면 못한다.
            check = false;
            break;
        }
    }

    if(check == false){
        cout<<"NO"<<"\n";
    }else{
        cout<<"YES"<<"\n";
    }
    return 0;
}