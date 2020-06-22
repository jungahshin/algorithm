//도토리 숨기기
#include <iostream>
#include <vector>

using namespace std;

int n, k, d, a, b, gap;
vector<pair<pair<int, int>, int> > v;
int final;

int main()
{
    cin>>n>>k>>d;
    for(int i=0; i<k; i++)
    {
        cin>>a>>b>>gap;
        v.push_back(make_pair(make_pair(a, b), gap));
    }

    int Start = 1;
    int End = n;

    while(Start<=End)
    {
        long long cnt = 0;
        int mid = (Start+End)/2;
        for(int i=0; i<v.size(); i++)
        {
            if (v[i].first.second<mid)//다 구한다.
            {
                cnt += (v[i].first.second - v[i].first.first)/v[i].second+1;
            } else if (v[i].first.first>mid){
                continue;
            } else if (v[i].first.first == mid){
                cnt++;
            } else {
                cnt += (mid-v[i].first.first)/v[i].second+1;
            }
        }

        if (cnt >= d){
            final = mid;
            End = mid-1;
        } else {
            Start = mid+1;
        }
    }

    cout<<final<<"\n";
}