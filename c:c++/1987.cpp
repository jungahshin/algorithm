//알파벳
#include <iostream>
#include <vector>
using namespace std;

int r, c;
string s;
int alphabet[50] = {0, };//알파벳을 가지고 있는지 유무를 체크한다(1->소유, 0->미소유)
char a[22][22] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[22][22] = {0, };
int final = 0;

void go(int x, int y, int alphabet[50], int num){
    for(int i=0; i<4; i++){
        int final_x = x+dx[i];
        int final_y = y+dy[i];
        if(0<=final_x && final_x<r && 0<=final_y && final_y<c && !visited[final_x][final_y]){
            if(alphabet[a[final_x][final_y] -'A'] == 0){//없는 알파벳이면
                alphabet[a[final_x][final_y] -'A'] = 1;
                visited[final_x][final_y] = 1;
                go(final_x, final_y, alphabet, num+1);
                visited[final_x][final_y] = 0;
                alphabet[a[final_x][final_y] -'A'] = 0;
            }
        }
    }
    final = max(final, num);
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            a[i][j] = s[j];
        }
    }
    alphabet[a[0][0]-'A'] = 1;
    visited[0][0] = 1;
    go(0, 0, alphabet, 1);
    cout<<final<<"\n";
}