//수 고르기(투포인터, 정렬)
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m, a, Start, End;
vector<int> v;
int MIN = INT_MAX;

int go()
{
    Start = 0;
    End = 1;
    int size = v.size();

    while (Start<size && End<size)
    {   
        if(v[End]-v[Start]<m)
        {
            End++;
            continue;
        }

        if(v[End]-v[Start]==m){
            return m;
        }

        MIN = min(MIN, v[End]-v[Start]);
        Start++;
    }

    return MIN;
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    
    cout<<go()<<"\n";

    return 0;
}