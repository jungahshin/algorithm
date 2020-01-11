//카드 구매하기
//1개당 얼마인지를 계산을 해서 개당 가격이 가장 높은 것*그 개수만큼
//전체 n개에서 위의 갯수만큼을 뺀 나머지 갯수 >= 해당 개수이고 그 다음으로 개당 가격이 높은 것
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<float, int>> v;
int idx;
int final = 0;
int real_final = 0;
int DP[1001] = {0, };

void go(int n, int idx, int final){
    int a = n;
    int b = idx;
    int c = final;
    if(a == 0){
        real_final = max(real_final, c);
    }
    if(b < 0){
        return;
    }
    if(v[b].second <= a){
        int temp = (n/v[b].second); 
        for(int i=1; i<=temp; i++){
            int temp_2 = c + (v[b].second)*(v[b].first)*i;//final
            int temp_3 = a - (v[b].second)*i;//n
            int temp_4 = b-1;
            go(temp_3, temp_4, temp_2);
        }

    }else{
        int temp_5 = b-1;
        go(a, temp_5, c);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>m;
        v.push_back(make_pair(m, i+1));
    }
    for(int i=0; i<n; i++){
        v[i].first = v[i].first/(i+1);
    }
    sort(v.begin(), v.end());
    idx = n-1;
    go(n, idx, final);
    cout<<real_final<<"\n";
}