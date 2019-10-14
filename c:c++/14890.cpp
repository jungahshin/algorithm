//경사로
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int a[101][101] = {0, };
int a_[101][101] = {0, };
int n, l;

int go(){
    int final = 2*n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_[i][j] = a[i][j];
        }
    }

    for(int i=0; i<n; i++){//행먼저 검사-->a배열 이용
        int visited[101] = {0, };
        int slope = 0;//경사로 개수 세기
        bool check = false;
        for(int j=0; j<n-1; j++){//열
            if((a[i][j] - a[i][j+1]) == 1){//차이가 1나면-->내려가는 중
                int num = 0;
                for(int k=j+1; k<j+1+l; k++){//연속된 l만큼 같으면 경사로 설치 가능
                    if(a[i][j+1] == a[i][k]){
                        num++;
                    }
                }
                if(num == l){//경사로 설치 가능
                    int overlap = 0;
                    for(int k=j+1; k<j+1+l; k++){
                        if(!visited[k]){
                            visited[k] = 1;
                            overlap++;
                        }
                    }
                    if(overlap != l){
                        check = true;
                    }
                }else if(num != l){
                    check = true;
                }
            }else if((a[i][j] - a[i][j+1]) == -1){//올라가는 중
                int num_ = 0;
                for(int k=j; k>j-l; k--){//연속된 l만큼 같으면 경사로 설치 가능
                    if(a[i][j] == a[i][k]){
                        num_++;
                    }
                }
                if(num_ == l){//경사로 설치 가능
                    int overlap_ = 0;
                    for(int k=j; k>j-l; k--){
                        if(!visited[k]){
                            visited[k] = 1;
                            overlap_++;
                        }
                    }
                    if(overlap_ != l){
                        check = true;
                    }
                }else if(num_ != l){
                    check = true;
                }           
            }else if(abs(a[i][j] - a[i][j+1]) >=2){//차이가 아예 1, -1이 아닌 경우
                check = true;
            }
        }
        if(check == true){
            final--;
        }
    }

    for(int i=0; i<n; i++){//열 검사-->a_배열이용
        int visited_[101] = {0, };
        int slope_1 = 0;//경사로 개수 세기    
        bool check_ = false;
        for(int j=0; j<n-1; j++){//행
            if((a_[j][i] - a_[j+1][i]) == 1){//차이가 1나면-->내려가는 중
                int num_1 = 0;
                for(int k=j+1; k<j+1+l; k++){//연속된 l만큼 같으면 경사로 설치 가능
                    if(a_[j+1][i] == a_[k][i]){
                        num_1++;
                    }
                }
                if(num_1 == l){//경사로 설치 가능
                    int overlap_1 = 0;
                    for(int k=j+1; k<j+1+l; k++){
                        if(!visited_[k]){
                            visited_[k] = 1;
                            overlap_1++;
                        }
                    }
                    if(overlap_1 != l){
                        check_ = true;
                    }
                }else if(num_1 != l){
                    check_ = true;
                }
            }else if((a_[j][i] - a_[j+1][i]) == -1){//올라가는 중
                int num_2 = 0;
                for(int k=j; k>j-l; k--){//연속된 l만큼 같으면 경사로 설치 가능
                    if(a_[j][i] == a_[k][i]){
                        num_2++;
                    }
                }
                if(num_2 == l){//경사로 설치 가능
                    int overlap_2 = 0;
                    for(int k=j; k>j-l; k--){
                        if(!visited_[k]){
                            visited_[k] = 1;
                            overlap_2++;
                        }
                    }
                    if(overlap_2 != l){
                        check_ = true;
                    }
                }else if(num_2 != l){
                    check_ = true;
                }          
            }else if(abs(a_[j][i] - a_[j+1][i]) >=2){//차이가 아예 1, -1이 아닌 경우
                check_ = true;
            }
        }
        if(check_ == true){
            final--;
        }
    }
    return final;
}

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    cout<<go()<<"\n";
}