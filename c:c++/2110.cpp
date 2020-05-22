//공유기 설치
#include<iostream>
#include <vector>
using namespace std;

int n, c, home;
vector<int> v;
int final = 0;

//거리를 기준으로 이분탐색을 진행!!!

int main(){
    cin>>n>>c;
    for(int i=0; i<n; i++){
        cin>>home;
        v.push_back(home);
    }
    sort(v.begin(), v.end());
    int start = 1;//최소거리
    int end = v[v.size()-1] - v[0];//최대거리

    while(start<=end){
        int mid = (start+end)/2;
        int cnt = 1;//공유기의 개수를 센다.
        int cmp = v[0];

        for(int i=0; i<v.size(); i++){
            if((v[i]-cmp)>=mid){
                cnt++;
                cmp = v[i];
            }
        }
        
        if(cnt >= c){//가능하다.
            final = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<final<<"\n";
    return 0;
}