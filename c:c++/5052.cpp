//전화번호 목록
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int testcase, n;
string s;
vector<string> v;

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        v.clear();
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        bool check = false;
        for(int j=1; j<v.size(); j++){
            if(v[j-1] == v[j].substr(0, v[j-1].size())){
                check = true;
                break;
            }
        }
        if(check == true){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
}
