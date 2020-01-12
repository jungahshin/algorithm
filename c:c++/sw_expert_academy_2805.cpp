//2805. 농작물 수확하기
#include <iostream>
#include <vector>
using namespace std;

int testcase, n;
int a[50][50] = {0, };
int final = 0;
string b;
vector<int> sum;

void go(int n){
    //증가하는 부분
    int y = 0;//(행++1)
    int x = n/2;//(열-1)
    for(int i=1; i<=n; i+=2){//갯수(1, 3, 5, ..)
        //시작 좌표
        for(int j=x; j<x+i; j++){//좌표(위의 갯수만큼 돌린다)
            final += a[y][j];
        }
        x--;
        y++;
    }
    x++;
    y--;
    //감소하는 부분
    for(int i=n-2; i>=0; i-=2){
        x++;
        y++;
        for(int j=x; j<x+i; j++){
            final += a[y][j];
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>b;
            for(int t=0; t<n; t++){
                a[j][t] = b[t] - '0';
            }
        }
        final = 0;
        go(n);
        sum.push_back(final);
    }
    for(int i=0; i<sum.size(); i++){
        cout<<"#"<<i+1<<" "<<sum[i]<<"\n";
    }
}