//베스트셀러
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int n;
vector<pair<int, string>> v;

bool compare(const pair<int, string>&a, const pair<int, string>&b){
    if(a.first == b.first){
        return a.second>b.second;
    } 
    return a.first<b.first;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        bool check = false;
        for(int j=0; j<v.size(); j++){
            if(s == v[j].second){//이미 벡터에 저장되어 있으면
                check = true;
                v[j].first++;
                break;
            }
        }
        if(check == false){//벡터에 없으면 넣는다.
            v.push_back(make_pair(1, s));
        }
    }
    sort(v.begin(), v.end(), compare);//숫자순, 다음 알파벳 순으로 정렬
    cout<<v[v.size()-1].second<<"\n";
}