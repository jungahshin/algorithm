#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

// 5 + 5 + (5 / 5) + (5 / 5) -> 55/5/5+5+5로 대체된다.... 둘다 총 6개 사용
// 55 / 5 + 5 / 5 -> 5/5+55/5로 대체된다.. 둘다 총 5개 사용
//dfs는 예제와 같이 괄호를 고려할 수 없다.. 하지만 그것을 대체할 경우는 항상 존재한다...
//그래서 dfs로도 풀이가 가능한 것이다..!

int a, b;
int final = INT_MAX;
bool check = false;

void dfs(int a, int b, int total_n, int total){
    if(total_n >= 9){
        return;
    }
    if(total == b){
        //가장 최소 사용횟수
        check = true;
        final = min(final, total_n);
    }
    int temp = 0;
    for(int i=0; total_n+i<9; i++){
        //N, NN, NNN...
        //i=0->N1번 사용
        //i=1->N2번 사용...
        temp = temp*10+a;
        dfs(a, b, total_n+i+1, total+temp);
        dfs(a, b, total_n+i+1, total-temp);
        dfs(a, b, total_n+i+1, total*temp);
        dfs(a, b, total_n+i+1, total/temp);
    }
}

int solution(int N, int number) {
    a = N;
    b = number;
    dfs(a, b, 0, 0);//총 n의 수, 총 계산 수
    if(check == true){
        return final;
    }else{//8을 넘었다.
        return -1;
    }
}