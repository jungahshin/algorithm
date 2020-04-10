//나무재테크 복습
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> garden[12][12];
int dead[12][12] = {0, };//여름에 땅에 추가할 죽은 나무 양분 저장
int vitamin[12][12] = {0, };//양분 저장소->처음에 5로 초기화
int a[12][12] = {0, };//겨울에 땅에 추가할 양분 저장
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int final_num = 0;
int n, m, k, x, y, z;

void spring(){
    //1)나이만큼 양분 먹고 나이+1    
    //2)어러 그루가 있다면, 어린 나이부터 먹기
    //3)나이만큼 먹지 못하면 즉사->dead배열에 양분 추가해주기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(garden[i][j].size()>0){
                sort(garden[i][j].begin(), garden[i][j].end());
                int temp_size = garden[i][j].size();
                for(int k=0; k<temp_size; k++){
                    if(vitamin[i][j]>=garden[i][j][k]){
                        vitamin[i][j] -= garden[i][j][k];
                        garden[i][j][k]++;
                    }else{
                        //garden에서 k부터 끝까지 없애기..
                        for(int t=k; t<temp_size; t++){
                            dead[i][j] += (garden[i][j][t]/2);
                        }
                        garden[i][j].erase(garden[i][j].begin()+k, garden[i][j].end());
                        final_num -= (temp_size-k);
                        break;
                    }
                }
            }
        }
    }
}

void summer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dead[i][j]>0){
                vitamin[i][j] += dead[i][j];
                dead[i][j] = 0;                
            }
        }
    }
}

void fall(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(garden[i][j].size()>0){
                int temp_size = garden[i][j].size();
                for(int k=0; k<temp_size; k++){
                    if((garden[i][j][k]%5) == 0){
                        int temp = 0;
                        for(int t=0; t<8; t++){
                            int final_x = i+dx[t];
                            int final_y = j+dy[t];
                            if(1<=final_x && final_x<=n && 1<=final_y && final_y<=n){
                                temp++;
                                garden[final_x][final_y].push_back(1);
                            }
                        }
                        final_num += temp;
                    }
                }
            }
        }
    }
}

void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vitamin[i][j] += a[i][j];
        }
    }
}

void season(){
    int num = 0;
    while(1){
        num++;
        if(num>k){
            break;
        }
        spring();
        summer();
        fall();
        winter();
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            vitamin[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        garden[x][y].push_back(z);
    }
    final_num = m;
    season();
    cout<<final_num<<"\n";
    return 0;
}