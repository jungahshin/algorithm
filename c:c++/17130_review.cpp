// 토끼가 정보섬에 올라온 이유
#include <cstring>
#include <iostream>
using namespace std;
 
int n, m, startX, startY;
string s;
int dp[1001][1001] = {0, };
char map[1001][1001];
int ans = 0;
bool check = false;
 
void rabbitMove()
{
    for(int j=startY; j<m; j++){
        for(int i=0; i<n; i++){
            if(map[i][j]=='#') continue;
 
            if(i-1>=0 && j-1>=0 && dp[i-1][j-1]!=-1){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            if(j-1>=0 && dp[i][j-1]!=-1){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
            if(i+1<n && j-1>=0 && dp[i+1][j-1]!=-1){
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
            }
 
            if(map[i][j]=='C' && dp[i][j]!=-1){
                dp[i][j]++;
            }
            if(map[i][j]=='O' && dp[i][j]!=-1){
                check = true;
                ans = max(ans, dp[i][j]);
            }
        }
    }
}
 
int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j];
            if(map[i][j]=='R'){
                startX = i;
                startY = j;
                dp[i][j] = 0; // 경로의 시작!
            }
        }
    }
 
    rabbitMove();
 
    if(check){
        cout<<ans<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
    
    return 0;
}