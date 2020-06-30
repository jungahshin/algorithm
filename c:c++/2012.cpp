//등수 매기기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
long long final = 0;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());
    
    for(int i=1; i<=v.size(); i++){
        //i등 예측
        final += abs(i-v[i-1]);
    }
    
    cout<<final<<"\n";
    return 0;
}