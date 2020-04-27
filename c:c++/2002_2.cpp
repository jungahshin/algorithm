//추월
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string s, s1;
int n;
vector<string> after;
map<string, int> m;
int final = 0;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        m[s] = i+1;
    }
    for(int i=0; i<n; i++){
        cin>>s1;
        after.push_back(s1);
    }
    for(int i=0; i<n; i++){//기준
        for(int j=i+1; j<n; j++){
            if(m[after[i]] > m[after[j]]){
                final++;
                break;
            }
        }
    }
    cout<<final<<"\n";
    return 0;
}