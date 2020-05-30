//문자열
#include <iostream>
#include <climits>
using namespace std;

string a, b;
int final = INT_MAX;

int main(){
    cin>>a>>b;
    for(int i=0; i<b.size(); i++){
        if(i+a.size()-1<b.size()){
            int num = 0;
            int idx = 0;
            for(int j=i; j<i+a.size(); j++){
                if(a[idx++] != b[j]){
                    num++;
                }
            }
            final = min(final, num);
        }
    }

    cout<<final<<"\n";
    return 0;
}