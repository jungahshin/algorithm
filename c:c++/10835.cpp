//카드 게임(DP)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a, b;
vector<int> LEFT;
vector<int> RIGHT;
int DP[2002][2002] = {0, };

int go(int i, int j){
    if(i > LEFT.size()-1 || j > RIGHT.size()-1){
        return 0;
    }
    
    if(DP[i][j] != -1){
        return DP[i][j];
    }
    //left>right인 경우 오른쪽 카드만 버릴 수 있다.
    //언제든지, 왼쪽을 버릴 수 있다.
    //언제든지, 왼쪽과 오른쪽 둘 다 버릴 수 있다.   
    if(LEFT[i] > RIGHT[j]){
        DP[i][j] = max(DP[i][j], RIGHT[j]+go(i, j+1));
    }else{
        DP[i][j] = max(go(i+1, j+1), go(i+1, j));
    }

    return DP[i][j];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        LEFT.push_back(a);
    }
    for(int i=0; i<n; i++){
        cin>>b;
        RIGHT.push_back(b);
    }
    //점수가 아예 0점인 경우가 있을 수 있기 때문에 DP를 0이 아닌 값으로 초기화한다.
    memset(DP, -1, sizeof(DP));
    cout<<go(0, 0)<<"\n";
}

/*
30
5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
*/
//위와 같은 테스트케이스에서는 값이 0이기 때문에 DP가 0이 아닌 경우가 없어 시간초과가 날 수 밖에...