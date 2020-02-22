//섬 연결하기(크루스칼 알고리즘)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int a[101] = {0, };

int find(int node){
    if(node == a[node]) return node;
    else return a[node] = find(a[node]);
}

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        a[i] = i;//자기 자신을 부모노드로 설정한다
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++){
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];
        
        //부모노드가 같지 않다면
        if(start != end){
            a[start] = end;
            answer += cost;
        }
    }
    return answer;
}    