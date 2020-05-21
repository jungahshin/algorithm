//센서
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, k, a;
vector<int> v;
vector<pair<int, int>> v2;
map<int, int> m;
int final = 0;

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size()-1; i++){
        v2.push_back(make_pair(v[i+1]-v[i], i));
    }
    sort(v2.begin(), v2.end());
    int num = 0;
    for(int i=v2.size()-1; i>=0; i--){
        num++;
        if(num == k){
            break;
        }
        m[v2[i].second] = 1;
    }
    int idx = 0;
    for(int i=0; i<v.size(); i++){
        if(m[i] == 1 || i == v.size()-1){
            final += (v[i]-v[idx]);
            idx = i+1;
        }
    }
    cout<<final<<"\n";
    return 0;
}