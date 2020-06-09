//선발 명단
#include <iostream>
#include <cstring>
using namespace std;

int testcase;
int ability[13][13] = {0, };
int visited[13] = {0, };//선수들
int final = 0;

void go(int sum, int num){
    if(num == 11){
        final = max(final, sum);
        return;
    }

    for(int t=0; t<11; t++){
        if(ability[num][t]>0 && !visited[t]){
            visited[t] = 1;
            go(sum+ability[num][t], num+1);
            visited[t] = 0;
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        memset(visited, 0, sizeof(visited));
        memset(ability, 0, sizeof(ability));
        final = 0;
        for(int k=0; k<11; k++){
            for(int t=0; t<11; t++){
                cin>>ability[k][t];
            }
        }

        for(int t=0; t<11; t++){
            if(ability[0][t]>0 && !visited[t]){
                visited[t] = 1;
                go(ability[0][t], 1);
                visited[t] = 0;
            }
        }
        cout<<final<<"\n";
    }
}