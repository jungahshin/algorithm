//공통부분 문자열
#include <iostream>
using namespace std;

string s1, s2;
int DP[4001][4001] = {0, };
int final = 0;

int main()
{
    cin>>s1;
    cin>>s2;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i] == s2[j]){
                if(i == 0 || j == 0){
                    DP[i][j] = 1;
                    final = max(final, DP[i][j]);
                    continue;
                }

                DP[i][j] = DP[i-1][j-1]+1;
                final = max(final, DP[i][j]);
            }
        }
    }

    cout<<final<<"\n";
    return 0;
}