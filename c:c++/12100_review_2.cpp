//2048(easy) -> dfs(코드 더 간단하게)
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[21][21] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};//우, 좌, 상, 하
int final = 0;

void move(int dir, int total, int temp[21][21]){
    if(total == 5){
        int temp_num = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp_num = max(temp[i][j], temp_num);
            }
        }
        final = max(final, temp_num);
        return;
    }

    for(int i=0; i<4; i++){
        //해당 방향으로 움직인다.
        if(dir == 1){//좌
            int a_temp[21][21] = {0, }; 
            for(int k=0; k<n; k++){//행
                int idx = 0;
                int num = 0;
                for(int t=0; t<n; t++){//열
                    if(temp[k][t] != 0){
                        if(num != temp[k][t]){
                            a_temp[k][idx] = temp[k][t];
                            idx++;
                            num = temp[k][t];
                        }else{
                            a_temp[k][idx-1] = num*2;
                            num = 0;
                        }
                    }
                }
            }
            move(i, total+1, a_temp);
        }else if(dir == 0){//우
            int a_temp[21][21] = {0, }; 
            for(int k=0; k<n; k++){//행
                int idx = n-1;
                int num = 0;
                for(int t=n-1; t>=0; t--){//열
                    if(temp[k][t] != 0){
                        if(num != temp[k][t]){
                            a_temp[k][idx] = temp[k][t];
                            idx--;
                            num = temp[k][t];
                        }else{
                            a_temp[k][idx+1] = num*2;
                            num = 0;
                        }
                    }
                }
            }
            move(i, total+1, a_temp);
        }else if(dir == 2){//상
            int a_temp[21][21] = {0, }; 
            for(int k=0; k<n; k++){//열
                int idx = 0;
                int num = 0;
                for(int t=0; t<n; t++){//행
                    if(temp[t][k] != 0){
                        if(num != temp[t][k]){
                            a_temp[idx][k] = temp[t][k];
                            idx++;
                            num = temp[t][k];
                        }else{
                            a_temp[idx-1][k] = num*2;
                            num = 0;
                        }
                    }
                }
            }
            move(i, total+1, a_temp);
        }else if(dir == 3){//하
            int a_temp[21][21] = {0, }; 
            for(int k=0; k<n; k++){//행
                int idx = n-1;
                int num = 0;
                for(int t=n-1; t>=0; t--){//열
                    if(temp[t][k] != 0){
                        if(num != temp[t][k]){
                            a_temp[idx][k] = temp[t][k];
                            idx--;
                            num = temp[t][k];
                        }else{
                            a_temp[idx+1][k] = num*2;
                            num = 0;
                        }
                    }
                }
            }
            move(i, total+1, a_temp);
        }
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