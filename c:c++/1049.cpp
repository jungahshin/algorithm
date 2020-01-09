//기타줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a, b;//지점마다의 패키지 가격과 낱개 가격
vector<int> package;
vector<int> each;
int final = 0;

void go(){
    //일단 낱개*6이랑 패키지 가격을 비교한다.
    if(package[0] >= (each[0] * 6)){
        final += each[0] * 6* (n/6);
    }else{
        final += package[0] * (n/6);
    }
    //그 나머지 값은 낱개의 값 중에 가장 싼 가격과 곱한 것과 패키지 가장 싼 가격과 비교하여 더
    //적은 값으로 더한다.
    if((n%6) > 0){//6으로 나눈 나머지가 존재한다면
        int package_price = package[0];
        int each_price = (n%6) * each[0];
        if(package_price >= each_price){
            final += each_price;
        }else{
            final += package_price;
        }        
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        package.push_back(a);
        each.push_back(b);
    }
    sort(package.begin(), package.end());
    sort(each.begin(), each.end());
    go();
    cout<<final<<"\n";
}