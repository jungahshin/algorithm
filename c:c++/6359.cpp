//만취한 상범
#include <iostream>
#include <cstring>
using namespace std;

int testcase, n;
int a[101] = {0, };

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        memset(a, 0, sizeof(a));
        cin>>n;
        for(int k=1; k<=n; k++){//1~n번째 라운드 진행(n배수)
            for(int t=1; t<=n; t++){
                if((t%k) == 0){
                    if(a[t] == 0){//닫혀있다->열어
                        a[t] = 1;
                    }else if(a[t] == 1){//열려있다->닫아
                        a[t] = 0;
                    }
                }
            }
        }
        int num = 0;
        for(int k=1; k<=n; k++){
            if(a[k] == 1){//열려있는 것
                num++;
            }
        }
        cout<<num<<"\n";
    }
}