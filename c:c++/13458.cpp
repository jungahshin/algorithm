//시험감독
#include <iostream>
#include <vector>
using namespace std;

long long a[1000001] = {0, };//백만
long long n, b, c;
vector<long> v;
long final = 0;

void go(){//총 감독은 1명 반드시 있어야 하고 부감독은 몇명이던 상관 없다(있어도 되고 없어도 됨)
    for(long i=0; i<n; i++){//시험장 수
        long num = 0;
        //총 감독
        if(a[i]<=b){//같거나 작으면
            num = 1;
        }else{//크면
            num += 1;//총 감독 1명
            //부감독
            num += (a[i]-b)/c;
            if((a[i]-b)%c != 0){
                num += 1;
            }
        }
        //각 시험장의 num을 v벡터에 넣어준다.
        v.push_back(num);
    }
}

int main(){
    cin>>n;
    for(long i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>b>>c;
    go();

    for(long i=0; i<v.size(); i++){
        final += v[i];
    }

    cout<<final<<"\n";

    return 0;
}