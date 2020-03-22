//신입 사원(풀이 2-> 시간 복잡도▽)
#include <iostream>
using namespace std;

int testcase;
int n, a, b;
int total = 0;
int chart[100001] = {0, };

void go(){
    int temp = chart[1];
    for(int i=2; i<=n; i++){//각 사람 기준
        if(chart[i]>temp){//자신보다 면접 등수도 높아
            total--;
        }else{
            temp = chart[i];
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n;
        total = n;
        for(int j=0; j<n; j++){
            cin>>a>>b;
            chart[a] = b;
        }
        go();
        cout<<total<<"\n";
    }
}