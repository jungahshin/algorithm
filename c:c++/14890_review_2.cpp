//경사로 복습
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, l;
int map[101][101] = {0, };
int final = 0;

void go(){
    final = 2*n;
    //행 기준
    for(int i=0; i<n; i++){
        int visited[101] = {0, };
        bool check = false;
        for(int j=0; j<n-1; j++){
            if((map[i][j]-map[i][j+1]) == 1){//내려감
                int num = 0;
                for(int k=j+1; k<j+1+l; k++){
                    if(k>=0 && k<=n-1){
                        if(map[i][j+1] == map[i][k] && !visited[k]){
                            visited[k] = 1;
                            num++;
                        }                        
                    }
                }
                if(num != l){
                    check = true;
                }
            }else if((map[i][j]-map[i][j+1]) == -1){//올라감
                int num_1 = 0;
                for(int k=j; k>j-l; k--){
                    if(k>=0 && k<=n-1){
                        if(map[i][j] == map[i][k] && !visited[k]){
                            visited[k] = 1;
                            num_1++;
                        }                           
                    } 
                }
                if(num_1 != l){
                    check = true;
                }
            }else if(abs(map[i][j]-map[i][j+1])>=2){
                check = true;
            }
        }
        if(check == true){
            final--;
        }
    }

    //열 기준
    for(int i=0; i<n; i++){
        int visited[101] = {0, };
        bool check = false;
        for(int j=0; j<n-1; j++){
            if((map[j][i]-map[j+1][i]) == 1){//내려감
                int num = 0;
                for(int k=j+1; k<j+1+l; k++){
                    if(k>=0 && k<=n-1){
                        if(map[j+1][i] == map[k][i] && !visited[k]){
                            visited[k] = 1;
                            num++;
                        }                        
                    }
                }
                if(num != l){
                    check = true;
                }
            }else if((map[j][i]-map[j+1][i]) == -1){//올라감
                int num_1 = 0;
                for(int k=j; k>j-l; k--){
                    if(k>=0 && k<=n-1){
                        if(map[j][i] == map[k][i] && !visited[k]){
                            visited[k] = 1;
                            num_1++;
                        }                           
                    } 
                }
                if(num_1 != l){
                    check = true;
                }
            }else if(abs(map[j][i]-map[j+1][i])>=2){
                check = true;
            }
        }
        if(check == true){
            final--;
        }
    }
}

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    go();
    cout<<final<<"\n";
}