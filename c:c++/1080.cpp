//행렬
//3*3의 형태로 나눠서 만약 그곳의 수가 다르다면 그곳을 맨 위, 왼쪾 꼭짓점으로 하고 있는 3*3 부분을 다 바꿔준다.

#include <iostream>
using namespace std;

int a[51][51] = {0, };
int b[51][51] = {0, };
int final = 0;
int n, m;
string x, y;

//3*3행렬
//(i, j), (i, j+1), (i, j+2)
//(i+1, j), (i+1, j+1), (i+1, j+2)
//(i+2, j), (i+2, j+1), (i+2, j+2)

//3*3행렬 부분이 다 범위 안에 해당되는 지 확인
bool check(int i, int j){
    bool temp = false;
    if(0 <= i && i < n && 0 <= j && j < m){
        if(0 <= (i+1) && (i+1) < n && 0 <= (j+1) && (j+1) < m){
            if(0 <= (i+2) && (i+2) < n && 0 <= (j+2) && (j+2) < m){
                temp = true;
            }
        }
    }
    return temp;
}

void go(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //a와 b의 값이 다르면
            if(a[i][j] != b[i][j]){
                if(check(i, j)){//3*3의 모든 값들이 범위 안에 해당되면
                    final++;
                    //3*3의 모든 값들을 1->0, 0->1로 바꾼다.
                    for(int k=i; k<=i+2; k++){
                        for(int t=j; t<=j+2; t++){
                            if(a[k][t] == 1){
                                a[k][t] = 0;
                            }else if(a[k][t] == 0){
                                a[k][t] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>x;
        for(int j=0; j<m; j++){
            a[i][j] = x[j]-'0';
        }
    }
    for(int i=0; i<n; i++){
        cin>>y;
        for(int j=0; j<m; j++){
            b[i][j] = y[j]-'0';
        }
    }
    go();
    //변한 a행렬과 b행렬의 모든 값들이 다 같은 지 확인하기
    bool temp_ = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != b[i][j]){
                temp_ = true;
            }
        }
    }
    if(temp_ == true){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}