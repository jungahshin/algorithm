// 6855. 신도시 전기 연결하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int testcase, n, k, home;
vector<int> v;
vector<int> dist;//집 사이의 거리 저장
int final = 0;

int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        v.clear();
        dist.clear();
        final = 0;
        cin>>n>>k;
        for(int j=0; j<n; j++){
            cin>>home;
            v.push_back(home);
        }

        for(int i=0; i<v.size()-1; i++){
            dist.push_back(abs(v[i]-v[i+1]));
        }
        
        sort(dist.begin(), dist.end());

        if(n<=k){
            final = 0;
        }else{
            if(k == 1){
                if(n == 1){//그냥 0
                    final = 0;
                }else{
                    for(int t=0; t<dist.size(); t++){
                        final += dist[t];
                    }             
                }
            }else{
                //k-1만큼 구제할 수 있음
                int num = 0;
                for(int t=dist.size()-1; t>=0; t--){
                    num++;
                    if(num>(k-1)){
                        final += dist[t];
                    }
                }
            }            
        }

        cout<<"#"<<i+1<<" "<<final<<"\n";
    }
}