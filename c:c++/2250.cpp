//트리의 높이와 너비
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> left_;//leftsubtree
map<int, int> right_;//rightsubtree
int n, node, a, b;
int visited[10001] = {0, };
int root;
vector<int> v[10001];//같은 Level일 때 열 저장(level, col)
int num = 0;
map<int, int> check;
int max_level;
vector<pair<int, int>> final;

//left->root->right 순회하면 열을 정할 수 있다. 가장 끝에서부터 +1씩 해주면 된다.
//그와 동시에 행도 체크 가능
//left, right->같은 Level, root->level+1...

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first == b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

void go(int node, int level){
    max_level = max(max_level, level);
    //left subtree
    if(left_[node] != 0){
        go(left_[node], level+1);
    }

    //root node
    if(check.count(node) == 0){
        check[node] = 1;
        num++;
        v[level].push_back(num);
    }

    //right subtree
    if(right_[node] != 0){
        go(right_[node], level+1);
    }

    if(check.count(node) == 0){
        check[node] = 1;
        num++;
        v[level].push_back(num);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>node>>a>>b;
        if(a != -1){
            left_[node] = a;
            visited[left_[node]] = 1;
        }
        if(b != -1){
            right_[node] = b;
            visited[right_[node]] = 1;
        }
    }
    //root노드 찾기
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            root = i;
        }
    }
    go(root, 1);
    for(int i=1; i<=max_level; i++){
        int num = v[i][v[i].size()-1]-v[i][0]+1;
        final.push_back(make_pair(num, i));
    }
    sort(final.begin(), final.end(), compare);
    cout<<final[final.size()-1].second<<" "<<final[final.size()-1].first<<"\n";
}