#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//부모->자식 관계(노드 번호로 연결)
vector<vector<int>> tree;//y축 별로 저장
vector<pair<int, int>> v;
map<int, int> m;
map<int, int> m2;
map<int, int> left_;
map<int, int> right_;
int visited[10001] = {0, };
vector<int> pre;
vector<int> pos;

void go(int node){//전위순회
    pre.push_back(node);
    if(left_.count(node) != 0){
        go(left_[node]);            
    }
    if(right_.count(node) != 0){
        go(right_[node]);
    }
}

int go2(int node){//후위순회
    if(left_.count(node) != 0){
        pos.push_back(go2(left_[node]));            
    }
    if(right_.count(node) != 0){
        pos.push_back(go2(right_[node]));
    }
    return node;
}

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    //node관계 열결해주기
    for(int i=0; i<nodeinfo.size(); i++){
        v.push_back(make_pair(nodeinfo[i][1], nodeinfo[i][0]));
        m[nodeinfo[i][0]] = i+1;//x값에 따른 노드 번호 저장
        m2[i+1] = nodeinfo[i][0];//노드 번호에 따른 x값 저장
    }
    
    sort(v.begin(), v.end(), compare);//x축은 증가, y축은 감소순으로
    
    for(int i=0; i<v.size(); i++){
        if(!visited[i]){
            vector<int> temp;
            for(int j=i; j<v.size(); j++){
                if(v[i].first == v[j].first){
                    visited[j] = 1;
                    temp.push_back(m[v[j].second]);
                }
            }
            tree.push_back(temp);
        }
    }
    
    for(int i=0; i<tree.size(); i++){
        for(int j=0; j<tree[i].size(); j++){//기준 노드 tree[i][j]
            int root = tree[0][0];
            for(int t=0; t<=i; t++){//비교하기
                if(m2[root]>m2[tree[i][j]]){//왼쪽
                    if(left_.count(root) == 0){
                        left_[root] = tree[i][j];
                        root = tree[i][j];
                    }else{
                        root = left_[root];
                    }
                }else if(m2[root]<m2[tree[i][j]]){//오른쪽
                    if(right_.count(root) == 0){
                        right_[root] = tree[i][j];
                        root = tree[i][j];
                    }else{
                        root = right_[root];
                    }
                }
            }                           
        }
    }

    //전위 순회(root->left->right), pre벡터
    pre.push_back(tree[0][0]);
    if(left_.count(tree[0][0]) != 0){
        go(left_[tree[0][0]]);            
    }
    if(right_.count(tree[0][0]) != 0){
        go(right_[tree[0][0]]);
    }
    
    
    //후위 순회(left->right->root), pos벡터
    if(left_.count(tree[0][0]) != 0){
        pos.push_back(go2(left_[tree[0][0]]));            
    }
    if(right_.count(tree[0][0]) != 0){
        pos.push_back(go2(right_[tree[0][0]]));
    }
    pos.push_back(tree[0][0]);
    
    
    answer.push_back(pre);
    answer.push_back(pos);
    
    return answer;
}