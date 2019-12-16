//부분 수열의 합
#include <iostream>
#include <cstring>
using namespace std;

int n, s;
int a[21] = {0, };
int visited[21] = {0, };
int final = 0;

void check(){
    int num = 0;
    for(int i=0; i<n; i++){
        if(visited[i] == true){
            num += a[i];
        }
    }
    if(num == s){
        final++;
    }
}

void go(int index, int num, int final){
    if(num == final){
        check();
        return;
    }

    for(int i=index; i<n; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        go(i, num+1, final);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){//1개~n개
        memset(visited, 0, sizeof(visited));
        go(0, 0, i);
    }
    cout<<final<<"\n";
}