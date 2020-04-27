//추월
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string s, s1;
int n;
vector<string> before;
vector<string> after;
map<string, int> m;
int final = 0;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        before.push_back(s);
    }
    for(int i=0; i<n; i++){
        cin>>s1;
        after.push_back(s1);
    }
    int idx1 = 0;//before의 idx
    int idx2 = 0;//after의 idx
    while(idx2 != after.size()){//after기준
        if(before[idx1] == after[idx2]){
            idx1++;
        }else{
            if(m[before[idx1]] == 1){//이미 방문했다.
                idx1++;
                continue;
            }else{
                final++;
            }
        }
        m[after[idx2]] = 1;
        idx2++;
    }

    cout<<final<<"\n";
    return 0;
}