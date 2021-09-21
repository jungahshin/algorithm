// 오름세
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> LIS;

int main()
{
    while(cin>>N)
    {
        LIS.clear();
        for(int i=1; i<=N; i++){
            int stock;
            cin>>stock;
            if(LIS.empty() || LIS.back()<stock){
                LIS.push_back(stock);
            }
            else{
                LIS[lower_bound(LIS.begin(), LIS.end(), stock)-LIS.begin()] = stock;
            }
        }

        cout<<LIS.size()<<"\n";
    }

    return 0;
}