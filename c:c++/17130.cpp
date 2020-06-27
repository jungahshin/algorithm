//토끼가 정보섬에 올라온 이유
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, start_x, start_y;
string s;
char island[1001][1001];
int dp[1001][1001];//먹은 당근의 수
int dx[3] = {1, };
int dy[3] = {1, };
int final = 0;
bool temp = false;

int main()
{
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    bool check = false;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        for(int j=0; j<s.size(); j++)
        {
            island[i][j] = s[j];
            if(s[j] == 'R'){
                start_x = i;
                start_y = j;
                dp[start_x][start_y] = 0;
            }else if(s[j] == 'O'){
                check = true;
            }
        }
    }
    if(check == false){//쪽문이 없는 경우
        cout<<"-1"<<"\n";
        return 0;
    }
    for(int j=start_y; j<m; j++){//열 기준
        for(int i=0; i<n; i++){//행
            if(island[i][j] == '#') continue;
            
            if(i-1>=0 && j-1>=0 && dp[i-1][j-1]!=-1){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            if(j-1>=0 && dp[i][j-1]!=-1){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
            if(i+1<n && j-1>=0 && dp[i+1][j-1]!=-1){
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
            }

            if(island[i][j] == 'C' && dp[i][j] != -1){//-1이면 이동할 수 있는 곳이 아니기 때문
                dp[i][j]++;
            }
            if(island[i][j] == 'O' && dp[i][j] != -1){//도착!
                temp = true;
                final = max(final, dp[i][j]);
            }
        }
    }

    if(temp == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}