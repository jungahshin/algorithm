//보석모으기
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, c, a;
vector<int> v;
int dp[1<<13][14][21] = {0, };//사용한 보석의 상태(비트마스크), 사용하고 있는 특정 가방(idx), 특정 가방의 남은 공간
int final = 0;
int all = 0;

int go(int bit, int idx, int remain){
    //모든 보석을 이미 다 사용했거나 모든 가방을 이미 다 사용한 경우
    if(idx == m || bit == all){
        return 0;
    }

    if(dp[bit][idx][remain] != -1){
        return dp[bit][idx][remain];
    }

    dp[bit][idx][remain] = 0;

    for(int i=0; i<n; i++){
        int temp = bit & (1<<i);
        if((temp != 0) || remain<v[i]){//보석을 사용하지 않았거나 남은 공간이 보석의 무게보다 적다면
            continue;
        }

        if(remain-v[i]>0){//또 남았다.->그대로 그 가방을 넘겨
            dp[bit][idx][remain] = max(dp[bit][idx][remain], go(bit | (1<<i), idx, remain-v[i])+1);
        }

        dp[bit][idx][remain] = max(dp[bit][idx][remain], go(bit | (1<<i), idx+1, c)+1);
    }

    return dp[bit][idx][remain];
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n>>m>>c;//보석개수, 가방개수, 최대 한도
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }

    for(int i=1; i<=n; i++){
        all = all | (1<<(i-1));
    }

    final = go(0, 0, c);
    cout<<final<<"\n";
    return 0;
}