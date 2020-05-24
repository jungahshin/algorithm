//트리인가?
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int a, b;
vector<pair<int, int>> tree;
vector<int> node;//트리에 존재하는 노드
map<int, int> m;
map<int, int> in;//들어오는 것
map<int, int> out;//나가는 것
map<int, int> all_check;
int root = 0;//루트 노드 번호

bool check1(){
    bool temp = false;
    for(int i=0; i<tree.size(); i++){
        if(m.count(tree[i].first) == 0){
            m[tree[i].first] = 1;
            node.push_back(tree[i].first);
        }
        if(m.count(tree[i].second) == 0){
            m[tree[i].second] = 1;
            node.push_back(tree[i].second);
        }
        out[tree[i].first]++;
        in[tree[i].second]++;
    }
    int num = 0;
    for(int i=0; i<node.size(); i++){
        if(in[node[i]] == 0){
            num++;
            root = node[i];
        }
    }
    if(num == 1){//단 하나의 루트 노드 존재
        temp = true;
    }

    return temp;
}

bool check2(){
    bool temp = true;
    for(int i=0; i<node.size(); i++){
        if(node[i] != root){
            if(in[node[i]] != 1){//여러개의 들어오는 간선을 가진다.
                temp = false;
            }
        }
    }
    return temp;
}



void check3(int n){
    for(int i=0; i<tree.size(); i++){
        if(tree[i].first == n){
            all_check[tree[i].second]++;
            check3(tree[i].second);
        }
    }
}

bool go(){
    // 1)들어오는 간선이 단 한나도 없는 단 하나의 노드 존재(root)
    if(check1() == false){
        return false;
    }
    // 2)루트 노드를 제외한 모든 노드는 반드시 단 하나의 들어오는 간선이 존재
    if(check2() == false){
        return false;
    }
    // 3)루트 노드에서 다른 노드로 가는 경로는 반드시 가능(유일하게)
    all_check[root] = 1;
    check3(root);
    for(int i=0; i<node.size(); i++){
        if(all_check.count(node[i]) != 1){
            return false;
        }
    }

    return true;
}

int main(){
    int testcase = 0;
    int temp_num = 0;
    while(1){
        temp_num++;
        cin>>a>>b;//a에서 b로
        if(a == -1 && b == -1){
            break;
        }
        if(a == 0 && b == 0){
            testcase++;
            if(temp_num == 1){
                cout<<"Case "<<testcase<<" is a tree."<<"\n";
            }else{
                if(go() == true){
                    cout<<"Case "<<testcase<<" is a tree."<<"\n";
                }else{
                    cout<<"Case "<<testcase<<" is not a tree."<<"\n";
                }                
            }
            temp_num = 0;
            tree.clear();
            node.clear();
            m.clear();
            in.clear();
            out.clear();
            all_check.clear();
        }else{
            tree.push_back(make_pair(a, b));
        }
    }
    return 0;
}