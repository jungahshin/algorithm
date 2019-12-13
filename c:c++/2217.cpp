//로프-->여러 개(k)를 골라서 그 중 가장 작은 값 * k가 최대 들 수 있는 무게가 된다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, weights;
vector<int> rope;
int final = 0;

void go(){
    for(int i=0; i<rope.size(); i++){
        int temp = rope[i]*(rope.size()-i);
        final = max(final, temp);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>weights;
        rope.push_back(weights);
    }    
    for(int i=0; i<rope.size(); i++){
        final = max(final, rope[i]);
    }
    sort(rope.begin(), rope.end());
    go();
    cout<<final<<"\n";
}