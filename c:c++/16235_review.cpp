//나무재테크(복습)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int winter_vitamin[11][11] = {0, };//겨울에 줄 양분
vector<int> tree[11][11];//특정 위치에 나무를 여러개 심을 수 있도록(각 위치에 나무의 나이 저장)
int n, m, k, x, y, z;
int year = 0;
int vitamin[11][11] = {0, };//기존의 양분 역할
int summer_vitamin[11][11] = {0, };//봄에 죽은 나무 나이/2만큼이 양분으로(각 위치에 죽은 나무나이/2 저장)
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int num = 0;

//봄
//자신의 나이만큼 양분 섭취->+1살 증가
//같은 위치에 나무가 여러그루일 경우, 나이가 어린 나무부터 양분 섭취
//나이만큼 양분 섭취를 못할시-->즉사...
void spring(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].size()>0){//한 그루라도 들어 있으면
                //정렬(오름차순)
                sort(tree[i][j].begin(), tree[i][j].end());
                //가장 어린 나무부터 양분 섭취
                int temp_idx = 0;
                bool temp = false;
                int size = tree[i][j].size();
                for(int k=0; k<size; k++){
                    if(tree[i][j][k] <= vitamin[i][j]){
                        //양분 섭취
                        vitamin[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                    }else{
                        if(temp == false){
                            //index k이후에는 다 먹지 못하는 즉사
                            temp_idx = k;
                            temp = true;
                        }
                        //양분을 먹지 못하고 즉사
                        summer_vitamin[i][j] += (tree[i][j][k]/2);
                    }
                }
                if(temp == true){
                    //temp_idx이후의 모든 나무들은 다 즉사
                    tree[i][j].erase(tree[i][j].begin()+temp_idx, tree[i][j].end());
                }
            }
        }
    }
}

//여름
//봄에 죽은 나무의 나이/2(소수점 버림)만큼이 나무가 있던 위치에 양분으로 변한다.
void summer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vitamin[i][j] += summer_vitamin[i][j];
        }
    }
    memset(summer_vitamin, 0, sizeof(summer_vitamin));
}

//가을
//나이가 5의 배수인 나무들의 인접한 8개의 곳에 나이가 1인 나무가 번식
void autumn(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int size = tree[i][j].size();
            if(size>0){
                for(int k=0; k<size; k++){
                    if((tree[i][j][k]%5) == 0){//나이가 5의 배수이면
                        //인접한 8칸에 번식
                        for(int t=0; t<8; t++){
                            int final_x = i+dx[t];
                            int final_y = j+dy[t];
                            if(1<=final_x && final_x<=n && 1<=final_y && final_y<=n){
                                tree[final_x][final_y].push_back(1);
                            }
                        }
                    }
                }                
            }
        }
    }
}

//겨울
//땅에 winter_vitamin배열에 있는 수만큼 양분 추가
void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vitamin[i][j] += winter_vitamin[i][j];
        }
    }
}

void go(){
    while(1){
        if(year == k){
            //살아있는 나무의 수를 센다.
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    num += tree[i][j].size();
                }
            }         
            break;   
        }
        spring();
        summer();
        autumn();
        winter();
        year++;        
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>winter_vitamin[i][j];
        }
    }
    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        tree[x][y].push_back(z);
    }
    // memset(vitamin, 5, sizeof(vitamin));//초기 양분 5만큼 들어 있다.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vitamin[i][j] = 5;
        }
    }
    go();
    cout<<num<<"\n";
}