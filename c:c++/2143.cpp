//두 배열의 합(투포인터, lower_bound, upper_bound)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, a, m, b;
vector<long long> v1;
vector<long long> v2;
vector<int> t1;
vector<int> t2;
long long ans;

int main()
{
    cin>>t;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a;
        t1.push_back(a);
    }
    cin>>m;
    for (int i=0; i<m; i++)
    {
        cin>>b;
        t2.push_back(b);
    }

    for(int i=0; i<t1.size(); i++)
    {
        int sum = t1[i];
        v1.push_back(sum);
        for(int j=i+1; j<t1.size(); j++)
        {
            sum += t1[j];
            v1.push_back(sum);
        }
    }

    for(int i=0; i<t2.size(); i++)
    {
        int sum = t2[i];
        v2.push_back(sum);
        for(int j=i+1; j<t2.size(); j++)
        {
            sum += t2[j];
            v2.push_back(sum);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(int i=0; i<v1.size(); i++)
    {
        int low = lower_bound(v2.begin(), v2.end(), t-v1[i])-v2.begin();
        int upper = upper_bound(v2.begin(), v2.end(), t-v1[i])-v2.begin();

        ans += (upper-low);
    }

    cout<<ans<<"\n";
    return 0;
}