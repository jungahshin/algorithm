//조합 연습(1~10까지 중에 3개 뽑는 조합)
#include <iostream>
using namespace std;

int visited[10] = {0, };

void check(){
    for(int i=1; i <= 10; i++){
        if(visited[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}

void combin(int idx, int num){
    if(num == 3){
        check();
        return;
    }

    for(int i=idx; i<=10; i++){
        if(visited[i] == 1) continue;
        visited[i] = 1;

        combin(i, num+1);
        visited[i] = 0;
    }
}

int main(){
    combin(1, 0);
}