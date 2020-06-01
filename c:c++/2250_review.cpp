#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int n, a, b, c, root;
vector<pair<int, int>> v;
int small[10010] = {0, };//각 레벨에서 최소값을 저장하는 배열
int big[10010] = {0, };//각 레벨에서 최대값을 저장하는 배열
int tree[10010][3] = {0, };//각 노드번호의 left[0], right[1] node를 저장하는 배열
int row_num[10010] = {0, };//각 노드번호의 열번호를 저장하는 배열
int num = 0;
int final = 0;
map<int, int> m;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second>b.second;
    }

    return a.first<b.first;
}

void row(int node, int level){
    int left = tree[node][0];
    int right = tree[node][1];

    if(left == -1 && right == -1){
        row_num[node] = num++;
        small[level] = min(small[level], row_num[node]);
        big[level] = max(big[level], row_num[node]);
        return;
    }

    if(left != -1){
        row(left, level+1);
    }

    row_num[node] = num++;
    small[level] = min(small[level], row_num[node]);
    big[level] = max(big[level], row_num[node]);
    
    if(right != -1){
        row(right, level+1);
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>b>>c;
        tree[a][0] = b;//left node
        tree[a][1] = c;//right node
        m[b] = 1;
        m[c] = 1;
    }

    if(n == 1){
        cout<<1<<" "<<1<<"\n";
        return 0;
    }

    for(int i=1; i<=n; i++){
        small[i] = INT_MAX;
    }
    
    //일단, 루트노드를 먼저 찾기...!
    for(int i=1; i<=n; i++){
        if(m.count(i) == 0){
            root = i;
        }
    }

    row(root, 1);
    for(int i=1; i<=n; i++){
        if(big[i] == 0 && small[i] == INT_MAX){
            continue;
        }
        v.push_back(make_pair(big[i]-small[i]+1, i));    
    }
    if(v.size() != 0){
        sort(v.begin(), v.end(), cmp);
        cout<<v[v.size()-1].second<<" "<<v[v.size()-1].first<<"\n";        
    }

    return 0;
}