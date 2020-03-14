//트리
#include <iostream>
using namespace std;

int tree[55][55] = {0, };
int n, node, relation, root;
int final = 0;

void go(int k, int i){//부모노드, 자식노드
    bool temp = false;
    for(int j=0; j<n; j++){
        if((j != k) && (tree[i][j] == 1)){
            if(j == node){
                continue;
            }
            temp = true;
            go(i, j);
        }
    }
    if(temp == false){//연결된 것이 없다.
        final++;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){//i번 노드의 관계 정의
        cin>>relation;
        if(relation == -1){//루트노드
            root = i;
            continue;
        }else{
            tree[i][relation] = 1;
            tree[relation][i] = 1;
        }
    }
    cin>>node;

    if(root == node){
        cout<<final<<"\n";
        return 0;
    }
    
    //루트 노드에서 시작
    bool check = false;
    for(int i=0; i<n; i++){
        if(tree[root][i] == 1){//i와 연결되어 있다.
            if(i == node){
                continue;
            }
            check = true;
            go(root, i);
        }
    }
    if(check == false){//연결된 것이 하나도 없다.
        if(root != node){
            final++;
        }
    }
    
    cout<<final<<"\n";
    return 0;
}