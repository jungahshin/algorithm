//2018kakao[1차] 프렌즈4블록
#include <iostream>
#include <vector>
using namespace std;

string s;
int m, n;
char game[31][31];
int final = 0;

int main(){
    cin>>m>>n;
    for(int i=0; i<m; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            game[i][j] = s[j];
        }
    }
    int num = n*m;
    while(num != 0){
        num = 0;
        vector<pair<int, int>> v;//없앨 블록 위치 저장
        for(int i=0; i<=m-2; i++){
            for(int j=0; j<=n-2; j++){
                if((game[i][j]==game[i][j+1]) && (game[i][j+1]==game[i+1][j]) && (game[i+1][j]==game[i+1][j+1]) && game[i][j]!='.'){
                    v.push_back(make_pair(i, j));
                    v.push_back(make_pair(i+1, j));
                    v.push_back(make_pair(i, j+1));
                    v.push_back(make_pair(i+1, j+1));
                }
            }
        }
        for(int i=0; i<v.size(); i++){
            if(game[v[i].first][v[i].second] != '.'){
                game[v[i].first][v[i].second] = '.';
                num++;
            }
        }
        int x = 0;
        int y = 0;
        bool check = false;
        for(int i=0; i<n; i++){//열을 기준으로
            vector<pair<int, int>> temp;
            for(int j=m-1; j>=0; j--){
                if(game[j][i]!='.'){
                    temp.push_back(make_pair(j, i));
                }
            }
            if(temp.size() == 0){
                continue;
            }
            int k = 0;
            for(int j=m-1; j>=0; j--){//차례대로 채운다.
                if(k<=temp.size()-1){
                    game[j][i] = game[temp[k].first][temp[k].second];
                    k++;
                }else{
                    game[j][i] = '.';
                    k++;
                }
            }
        }
        final += num;
    }
    cout<<final<<"\n";
    return 0;
}