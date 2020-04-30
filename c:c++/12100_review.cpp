//2048(easy) -> dfs
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[21][21] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};//우, 좌, 상, 하
int final = 0;

void move(int dir, int total, int A[21][21]){
    if(total == 5){
        int temp = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<A[i][j];
                temp = max(A[i][j], temp);
            }
            cout<<"\n";
        }
        final = max(final, temp);
        return;
    }

    for(int i=0; i<4; i++){
        int temp[21][21] = {0, };
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[i][j] = A[i][j];
            }
        }
        //해당 방향으로 움직인다.
        if(dir == 1){//좌
            vector<int> v_[21];//행 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=0; t<n; t++){
                    if(temp[k][t] != 0){
                        v_[k].push_back(temp[k][t]);
                        temp[k][t] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v_[k].size(); t++){
                    temp[k][t] = v_[k][t];
                }
            }
            for(int k=0; k<n; k++){//행
                for(int t=0; t<n-1; t++){//열
                    if(temp[k][t] == temp[k][t+1]){
                        temp[k][t] += temp[k][t+1];
                        temp[k][t+1] = 0;
                    }
                }
            }
            vector<int> v[21];//행 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=0; t<n; t++){
                    if(temp[k][t] != 0){
                        v[k].push_back(temp[k][t]);
                        temp[k][t] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v[k].size(); t++){
                    temp[k][t] = v[k][t];
                }
            }
        }else if(dir == 0){//우
            vector<int> v_[21];//행 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=n-1; t>=0; t--){
                    if(temp[k][t] != 0){
                        v_[k].push_back(temp[k][t]);
                        temp[k][t] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v_[k].size(); t++){
                    temp[k][n-1-t] = v_[k][t];
                }
            }
            for(int k=0; k<n; k++){//행
                for(int t=n-1; t>=1; t--){//열
                    if(temp[k][t] == temp[k][t-1]){
                        temp[k][t] += temp[k][t-1];
                        temp[k][t-1] = 0;
                    }
                }
            }
            vector<int> v[21];//행 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=n-1; t>=0; t--){
                    if(temp[k][t] != 0){
                        v[k].push_back(temp[k][t]);
                        temp[k][t] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v[k].size(); t++){
                    temp[k][n-1-t] = v[k][t];
                }
            }
        }else if(dir == 2){//상
            vector<int> v_[21];//행 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=0; t<n; t++){
                    if(temp[t][k] != 0){
                        v_[k].push_back(temp[t][k]);
                        temp[t][k] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v_[k].size(); t++){
                    temp[t][k] = v_[k][t];
                }
            }
            for(int k=0; k<n; k++){//열
                for(int t=0; t<n-1; t++){//행
                    if(temp[t][k] == temp[t+1][k]){
                        temp[t][k] += temp[t+1][k];
                        temp[t+1][k] = 0;
                    }
                }
            }
            vector<int> v[21];//행 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=0; t<n; t++){
                    if(temp[t][k] != 0){
                        v[k].push_back(temp[t][k]);
                        temp[t][k] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v[k].size(); t++){
                    temp[t][k] = v[k][t];
                }
            }
        }else if(dir == 3){//하
            vector<int> v_[21];//열 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=n-1; t>=0; t--){
                    if(temp[t][k] != 0){
                        v_[k].push_back(temp[t][k]);
                        temp[t][k] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v_[k].size(); t++){
                    temp[n-1-t][k] = v_[k][t];
                }
            }
            for(int k=0; k<n; k++){//열
                for(int t=n-1; t>=1; t--){//행
                    if(temp[t][k] == temp[t-1][k]){
                        temp[t][k] += temp[t-1][k];
                        temp[t-1][k] = 0;
                    }
                }
            }
            vector<int> v[21];//열 기준으로 넣는다.
            for(int k=0; k<n; k++){
                for(int t=n-1; t>=0; t--){
                    if(temp[t][k] != 0){
                        v[k].push_back(temp[t][k]);
                        temp[t][k] = 0;
                    }
                }
            }
            for(int k=0; k<n; k++){
                for(int t=0; t<v[k].size(); t++){
                    temp[n-1-t][k] = v[k][t];
                }
            }
        }
        move(i, total+1, temp);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<4; i++){
        move(i, 0, a);
    }
    cout<<final<<"\n";
    return 0;
}