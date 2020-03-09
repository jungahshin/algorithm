//토너먼트
#include <iostream>
using namespace std;

int n, kim, lim;
int num = 0;

void go(int kim, int lim){
    while(1){
        num++;
        if(((kim%2 != 0) && (kim+1 == lim)) || ((lim%2 != 0) && (lim+1 == kim))){//kim이 홀수이고
            break;
        }

        if(kim%2 == 0){
            kim /= 2;
        }else if(kim%2 != 0){
            kim = (kim/2)+1;
        }
        if(lim%2 == 0){
            lim /= 2;
        }else if(lim%2 != 0){
            lim = (lim/2)+1;
        }
    }
}

int main(){
    cin>>n>>kim>>lim;
    go(kim, lim);
    cout<<num<<"\n";
    return 0;
}