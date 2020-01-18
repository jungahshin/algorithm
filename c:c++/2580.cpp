//스도쿠
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[10][10] = {0, };
vector<pair<int, int>> b;

//행 검사
bool check1(int r, int num){
    for(int i = 0; i < 9; i++){
        if(a[r][i] == num)
            return false;
    }
    return true;
}

//열 검사
bool check2(int c, int num){
    for(int i = 0; i < 9; i++){
        if(a[i][c] == num)
            return false;
    }
    return true;
}

// 3x3 검사  
bool check3(int i, int j, int num){
    if(0<=i && i<=2){
        if(0<=j && j<=2){
            for(int k=0; k<=2; k++){
                for(int t=0; t<=2; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }else if(3<=j && j<=5){
            for(int k=0; k<=2; k++){
                for(int t=3; t<=5; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }else if(6<=j && j<=8){
            for(int k=0; k<=2; k++){
                for(int t=6; t<=8; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }
    }
    else if(3<=i && i<=5){
        if(0<=j && j<=2){
            for(int k=3; k<=5; k++){
                for(int t=0; t<=2; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }else if(3<=j && j<=5){
            for(int k=3; k<=5; k++){
                for(int t=3; t<=5; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }else if(6<=j && j<=8){
            for(int k=3; k<=5; k++){
                for(int t=6; t<=8; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }
    }
    else if(6<=i && i<=8){
        if(0<=j && j<=2){
            for(int k=6; k<=8; k++){
                for(int t=0; t<=2; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }else if(3<=j && j<=5){
            for(int k=6; k<=8; k++){
                for(int t=3; t<=5; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }else if(6<=j && j<=8){
            for(int k=6; k<=8; k++){
                for(int t=6; t<=8; t++){
                    if(a[k][t] == num){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void go(int index){
    if(index == b.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    for(int i=1; i<=9; i++){
        int x = b[index].first;
        int y = b[index].second;
        if(check1(x, i) && check2(y, i) && check3(x, y, i)){
            a[x][y] = i;
            go(index+1);
            a[x][y] = 0;
        }
    }
}

//행, 열, 3*3을 차례대로 검사하고 3번의 경우 모두 겹치는 숫자들을 배열에 넣어서 하나씩 해보는 것?(백트래킹)
int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>a[i][j];
            if(a[i][j] == 0){
                b.push_back(make_pair(i, j));
            }
        }
    }
    go(0);
}