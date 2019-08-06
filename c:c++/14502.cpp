#include <iostream>
#include <vector>
using namespace std;

<vector>int zero[100];
int copy_input[9][9] = {0, }
int input[9][9] = {0, };
int visited[9][9] = {0, };
int n,m,a;
int b = 1;
int num,safe = 0;

// 연구소 상황을 입력 받는다.
// 받은 연구소 상황을 다른 배열에 복사한다.
// 복사한 연구소에서 안전구역인 곳에 3개의 벽을 세운다.
// 벽을 세운 상태에서 바이러스를 퍼트린다.
// 다 퍼트린 후, 안전 구역의 수를 센다.
// 구역의 수를 기존의 저장값과 비교하여 최대인지 확인한다.
// 모든 벽을 세울 수 있는 경우를 계산 할 때까지 3번과정부터 반복한다.

//연구소 복사하기
void copy(int a[][9], int b[][9]){//앞의 인자는 복사 연구소, 뒤의 인자는 원본 연구소
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] = b[i][j];
        }
    }
}

//바이러스 퍼뜨리기
int spread(){


//바이러스 퍼뜨리고 0개수(t) 센다음에 더 큰 값을 반환하기 safe = max(t,safe)
}



//0 중에 임의로 3개를 정해서 1로 만들어 주기!(벽 만들기)
void wall(int num){
    //벽 3개가 만들어지면 바이러스를 퍼뜨린다.
    if(num == 3){
        spread();
    }
    else{
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //0을 찾는다
                if(input[i][j] == 0){
                    copy_input[i][j] = 1;//벽 세우기
                    wall(num++);
                    copy_input[i][j] = 0;//복사 연구소 벽세운거 다시 초기화
                    //zero.push_back();
                }
            }
        }  
    }

}

int main(){
    cin>>n>>m;//연구소의 크기 n*m을 입력받는다.
    if(n<3 || m>8){//n과m의 조건
        return 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a;//띄어쓰기?
            input[i][j] = a;
        }
        //cin>>endl; 엔터 해줘야 하나?
    }
    copy(copy_input,input);//연구소 복사
}