//부분합(투포인터)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, s, a, Start, End;
vector<int> v;
int MIN = INT_MAX;

int go()
{
    Start = 0;
    End = 1;
    int sum = v[Start]+v[End];

    while(Start<v.size() && End<v.size())
    {
        if(sum<s)
        {
            End++;
            sum += v[End];
            continue;
        }

        MIN = min(MIN, End-Start+1);
        sum -= v[Start];
        Start++;
    }

    return MIN;
}

int main()
{
    cin>>n>>s;
    for (int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    
    int temp = go();

    if(temp == INT_MAX){
        cout<<"0"<<"\n";
    }else{
        cout<<temp<<"\n";
    }

    return 0;
}