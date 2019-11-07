#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vitamin_winter[11][11] = {0, };//겨울에 각 칸에 주는 양분 저장
int vitamin[11][11];//처음 default 양분
int vitamin_summer[11][11] = {0, };//여름에 줄 양분 저장
vector<int> tree[11][11];//이차원배열 벡터를 사용하여 나무의 위치에 나무의 나이를 저장
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k, x, y, z;   
int final = 0;

void spring(){//자신의 나이만큼 양분을 먹고 나이+1
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            vitamin_summer[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tree[i][j].size() == 1){//나무가 1개 밖에 없다.
                if(tree[i][j][0] <= vitamin[i][j]){//나이가 양분과 같거나 크다면 나이만큼 양분을 먹는다.
                    vitamin[i][j] -= tree[i][j][0];
                    tree[i][j][0]++;
                }else{//나이가 양분보다 많다면 죽는다.
                    //양분으로 저장한다.
                    vitamin_summer[i][j] = tree[i][j][0]/2;
                    tree[i][j].clear();
                    // tree[i][j].erase(tree[i][j]+0);
                }
            }else if(tree[i][j].size() > 1){//나무가 2개 이상이다.--> 가장 나이가 어린 나무부터 양분 준다.
                sort(tree[i][j].begin(), tree[i][j].end());//나이순으로 정렬
                for(int k=0; k<tree[i][j].size(); k++){//벡터 안에 있는 나무 수만큼 반복한다.(나이 순으로)
                    if(tree[i][j][k] <= vitamin[i][j]){
                        vitamin[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                    }else{
                        //양분으로 저장한다.
                        for(int h=k; h<tree[i][j].size(); h++){
                            vitamin_summer[i][j] += tree[i][j][h]/2;
                        }
                        tree[i][j].erase(tree[i][j].begin()+k, tree[i][j].end());//k부터 마지막 원소까지 삭제하기
                        break;
                    }
                }
            }
        }
    }
}

void summer(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vitamin[i][j] += vitamin_summer[i][j];
        }
    }
}

void fall(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k] % 5 == 0){//5의 배수라면, 번식한다.
                    for(int h=0; h<8; h++){//번식   
                        int final_x = dx[h] + i;
                        int final_y = dy[h] + j;
                        if(0 <= final_x && final_x < n && 0 <= final_y && final_y < n){
                            tree[final_x][final_y].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vitamin[i][j] += vitamin_winter[i][j];
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){//n*n
        for(int j=0; j<n; j++){
            cin>>vitamin_winter[i][j];//양분 저장
        }
    }
    for(int i=0; i<m; i++){//m개의 나무
        cin>>x>>y>>z;
        tree[x-1][y-1].push_back(z);//x,y 나무의 위치의 벡터에 z나이를 저장
    }
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            vitamin[i][j] = 5;
        }
    }
    for(int i=0; i<k; i++){//k년 동안 사계절 반복
        spring();
        summer();
        fall();
        winter();
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            final += tree[i][j].size();
        }
    }
    cout<<final<<"\n";
}