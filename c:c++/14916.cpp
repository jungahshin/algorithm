// 거스름돈
#include <vector>
#include <iostream>
using namespace std;
 
int n;
vector<int> v;
int dp[100001] = {0, };
 
int main()
{
    cin>>n;
    int cnt = 0;
    while(n>0){
        if(n%5==0){
            cout<<(n/5+cnt)<<"\n";
            return 0;
        }
        n -= 2;
        cnt++;
    }
 
    if(n==0){
        cout<<cnt<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
 
    return 0;
}