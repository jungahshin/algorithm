//LCS
#include <iostream>
using namespace std;

string s1, s2;
int DP[1002][1002] = {0, };

int main(){
    cin>>s1>>s2;
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                DP[i][j] = DP[i-1][j-1]+1;
            }else{
                DP[i][j] = max(DP[i][j], DP[i-1][j]);
                DP[i][j] = max(DP[i][j], DP[i][j-1]);
            }
        }
    }
    cout<<DP[s1.size()][s2.size()]<<"\n";
}