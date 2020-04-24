//나무 자르기(이분 탐색->시간복잡도 O(logn))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, length;
vector<long long> wood;//10억이하의 높이를 가지고 있기때문에 int로 충분
long long result = 0;

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>length;
        wood.push_back(length);
    }

    sort(wood.begin(), wood.end());

    long long low = 0;
    long long high = wood[wood.size()-1];

    while(low<=high){
        long long mid = (low+high)/2;
        long long total = 0;
        for(int i=0; i<wood.size(); i++){
            if(wood[i]-mid>0){
                total += (wood[i]-mid);
            }
        }
        if(total >= m){
            if(result<mid){
                result = mid;
            }
            //기존의 이분탐색과 다르게 왜 low이냐면, 여기서는 low가 커져야 mid(나무의 높이)가 커지면서 total이 작아진다!!!
            low = mid+1;
        }else{
            //기존의 이분탐색과 다르게 왜 high이냐면, 여기서는 high가 작아져야 mid(나무의 높이)가 작아지면서 total이 커진다!!!
            high = mid-1;
        }
    }

    cout<<result<<"\n";
    return 0;
}