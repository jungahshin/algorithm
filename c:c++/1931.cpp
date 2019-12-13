//회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, a, b;
vector<pair<int, int>> v;
vector<pair<int, int>> v_temp;
int final = 0;
int visited[100001] = {0, };
int num = 1;
int temp = 0;

void go(){
    for(int i=1; i<v.size(); i++){//기준이 되는 회의
        if(!visited[i]){
            visited[i] = 1;
            if(temp <= v[i].first){//끝나는 시간보다 크거나 같으면 가능!
                num++;
                temp = v[i].second;
            }
        }
        final = max(final, num);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v_temp.push_back(make_pair(b, a));
    }
    sort(v_temp.begin(), v_temp.end());
    for(int i=0; i<v_temp.size(); i++){
        v.push_back(make_pair(v_temp[i].second, v_temp[i].first));
    }
    temp = v[0].second;
    go();
    cout<<final<<"\n";
}