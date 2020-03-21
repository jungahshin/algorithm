//단지번호 붙이기(DFS)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
int map[26][26] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[26][26] = {0, };
int final = 0;
vector<int> town;

void dfs(int i, int j){
    final++;
    for(int k=0; k<4; k++){
        int final_x = i+dx[k];
        int final_y = j+dy[k];
        if(0<=final_x && final_x<n && 0<=final_y && final_y<n && !visited[final_x][final_y]){
            if(map[final_x][final_y] == '1'){
                visited[final_x][final_y] = 1;
                dfs(final_x, final_y);
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == '1' && !visited[i][j]){
                visited[i][j] = 1;
                final = 0;
                dfs(i, j);
                town.push_back(final);
            }
        }
    }
    sort(town.begin(), town.end());
    cout<<town.size()<<"\n";
    for(int i=0; i<town.size(); i++){
        cout<<town[i]<<"\n";
    }
}