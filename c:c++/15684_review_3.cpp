//사다기 조작 복습
#include <iostream>
#include <climits>
using namespace std;

int ladder[31][11] = {0, };//(h, n)
int n, m, h, a, b;
int final = INT_MAX;

bool check(){
    for(int i=1; i<=n; i++){//각 사다리
        int move = i;//기준 사다리
        for(int j=1; j<=h; j++){//높이
            if(ladder[j][move] == true){
                move++;
            }else if(ladder[j][move-1] == true){
                move--;
            }
        }
        if(i != move){//하나라도 같지 않으면 바로 빠져나온다!!!
            return true;
        }
    }
    return false;
}

void play(int idx, int num){
    if(num>3){//3보다 크다면 -1을 출력(더 이상 할 필요가 없다)
        return;
    }

    if(check() == false){//모든 i가 i로 갔다.->end
        final = min(final, num);
        return;
    }

    for(int i=idx; i<=h; i++){
        for(int j=1; j<n; j++){//n번째는 이을 것이 없기 때문에 생략
            if(ladder[i][j] == true) continue;
            if(ladder[i][j-1] == true) continue;
            if(ladder[i][j+1] == true) continue;

            ladder[i][j] = true;
            play(i, num+1);
            ladder[i][j] = false;
        }
    }

}

int main(){
    cin>>n>>m>>h;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        ladder[a][b] = 1;
    }
    play(1, 0);//일단 사다리를 잇는 조합을 시작
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}
