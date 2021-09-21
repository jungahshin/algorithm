// 민균이의 계략
#include <iostream>
#include <vector>
using namespace std;

int N, card;
vector<int> LIS;

int main()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>card;
        if(LIS.empty() || LIS.back()<card){
            LIS.push_back(card);
        }else{
            LIS[lower_bound(LIS.begin(), LIS.end(), card)-LIS.begin()] = card;
        }
    }

    cout<<LIS.size()<<"\n";
    return 0;
}