// 보석도둑
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bag;
int n, k, m, v, c;
priority_queue<int> q;
vector<pair<int, int>> jewelry;
long long final = 0;

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>m>>v;
        jewelry.push_back(make_pair(m, v));
    }

    for(int i=0; i<k; i++){
        cin>>c;
        bag.push_back(c);
    }

    //bag와 jewelry정렬
    sort(bag.begin(), bag.end());
    sort(jewelry.begin(), jewelry.end());

    int idx = 0;
    for(int i=0; i<k; i++){//가방기준으로 자기가 감당 가능한 무게인 보석들을 다 우선순위큐에 넣는다.
        while(idx<n && jewelry[idx].first<=bag[i]){
            q.push(jewelry[idx++].second);
        }

        //우선순위큐에 들어있는 보석들의 가격중 가장 높은 것이 top에 있다.
        if(!q.empty()){
            final += q.top();
            q.pop();
        }
    }

    cout<<final<<"\n";
    return 0;
}