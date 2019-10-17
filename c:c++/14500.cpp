//테트로미노
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[501][501] = {0, };
int final = 0;
int n,m;

void go(){ 
    for(int i=0; i<n; i++){//한 줄에 4개짜리(1번 그림)-가로버전
        for(int j=0; j<m-3; j++){
            final = max(final, (a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]));
        }
    }
    for(int i=0; i<n-3; i++){//1번 그림-세로버전
        for(int j=0; j<m; j++){
            final = max(final, (a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]));
        }
    }
    for(int i=0; i<n-1; i++){//2번째 그림
        for(int j=0; j<m-1; j++){
            final = max(final, (a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]));
        }
    }
    for(int i=0; i<n-1; i++){//2*3
        for(int j=0; j<m-2; j++){
            final = max(final, (a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]));
            final = max(final, (a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]));
            final = max(final, (a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]));
            final = max(final, (a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]));
            final = max(final, (a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1]));
            final = max(final, (a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2]));
            final = max(final, (a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]));
            final = max(final, (a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]));
        }
    }
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            final = max(final, (a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1]));
            final = max(final, (a[i][j]+a[i+1][j]+a[i+2][j]+a[i][j+1]));
            final = max(final, (a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+2][j]));
            final = max(final, (a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i][j]));
            final = max(final, (a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1]));
            final = max(final, (a[i][j+1]+a[i+1][j+1]+a[i+1][j]+a[i+2][j]));
            final = max(final, (a[i][j]+a[i+1][j]+a[i+2][j]+a[i+1][j+1]));
            final = max(final, (a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+1][j]));
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    go();
    cout<<final<<"\n";
    return 0;
}