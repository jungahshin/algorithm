//수들의 합2(투포인터 사용)
#include <iostream>
#include <vector>
using namespace std;

int n, m, a;
vector<int> v;
int ans = 0;

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }

    int Start = 0;
    int End = 0;
    int sum = 0;

    while(1){
        if(sum>=m){
            if(Start<=End){
                sum -= v[Start++];
            }
        }
        else if(End==v.size()){
            break;
        }
        else if(sum<m){
            if(End<v.size()){
                sum += v[End++];
            }
        }
        if(sum==m){
            ans++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}