//사다리조작
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n,m,h,c,d;
int a[11][31] = {0, };
int final = INT_MAX;
bool game(){//사다리 타기해서 i번이 i번으로 가면 true 반환, 아니면 중간에 false반환
    for(int i=1; i<=n; i++){
        int line = i;//기준이 되는 세로줄
        for(int j=1; j<=h; j++){
            if(a[line][j] == true) line+=1;//오른쪽 이동
            else if(a[line-1][j] == true) line-=1;//왼쪽 이동
        }
        if(line != i) return false;
    }
    return true;
}  

void choose(int idx, int num){//dfs
    if(num > 3){
        return;
    }

    if(game() == true){//여기를 한 번도 거친적이 없으면-->final값은 초기화한 그대로 INT_MAX이다.
        final = min(final, num);//가로선 가장 작은 개수
        return;//어차피 여기서 더 들어가면 num만 커지므로 소용이 없다.
    }

    for(int i=idx; i<=h; i++){
        for(int j=1; j<n; j++){
            if(a[j][i] == true) continue;
            if(a[j-1][i] == true) continue;
            if(a[j+1][i] == true) continue;

            a[j][i] = true;
            choose(i, num+1);
            a[j][i] = false;
        }
    }
}

int main(){
    cin>>n>>m>>h;

    for(int i=0; i<m; i++){//가로선 저장
        cin>>c>>d;
        a[d][c] = 1;
    }

    choose(1, 0);//가로선 조합

    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}