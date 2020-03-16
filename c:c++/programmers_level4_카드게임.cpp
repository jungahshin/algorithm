//카드 게임(DP)
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int DP[2002][2002] = {0, };//왼쪽, 오른쪽 indx
int i, j = 0;//left, right의 초기 index
vector<int> a;
vector<int> b;

int go(int i, int j){
    if(i > a.size()-1 || j > b.size()-1){
        return 0;
    }
    
    if(DP[i][j] != 0){
        return DP[i][j];
    }
    //left>right인 경우 오른쪽 카드만 버릴 수 있다.
    //언제든지, 왼쪽을 버릴 수 있다.
    //언제든지, 왼쪽과 오른쪽 둘 다 버릴 수 있다.   
    if(a[i] > b[j]){
        DP[i][j] = max(DP[i][j], b[j]+go(i, j+1));
    }else{
        DP[i][j] = max(go(i+1, j+1), go(i+1, j));
    }

    return DP[i][j];
}

int solution(vector<int> left, vector<int> right) {
    a=left;
    b=right;
    int answer = 0;    
    answer = go(0, 0);
    return answer;
}