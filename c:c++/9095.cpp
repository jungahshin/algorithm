//1, 2, 3 더하기
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> final;
int num, t;
int check[11] = {0, };


int go(int x){//1, 2, 3의 합으로 나타내는 방법 구하기
    if(x == 0){
        return 1;
    }
    if(check[x] != 0){
        return check[x];
    }
    if((x-1) >= 0){//-1하기
        check[x] += go(x-1);
    }

    if((x-2) >= 0){//-2하기
        check[x] += go(x-2);
    }
    if((x-3) >= 0){//-3하기
        check[x] += go(x-3);
    }
    return check[x];
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>num;
        v.push_back(num);
    }
    for(int i=0; i<v.size(); i++){
        int result = go(v[i]);
        final.push_back(result);
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}