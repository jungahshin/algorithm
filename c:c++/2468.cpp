//안전영역
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int a[101][101] = {0, };
int temp = 0;//높이 중에 가장 최대값 찾기
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;

void go(){
    for(int i=1; i <= temp; i++){//i이하인 지점은 모두 물에 잠겼다.-->i+1이상인 지점을 모두 찾는다.
        int visited[101][101] = {0, };
        int num = 0;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(a[j][k] > i && !visited[j][k]){
                    num++;
                    visited[j][k] = 1;
                    queue<pair<int, int>> q;
                    q.push(make_pair(j, k));
                    // int num = 0;
                    while(!q.empty()){
                        // num++;
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int h=0; h<4; h++){
                            int final_x = x + dx[h];
                            int final_y = y + dy[h];
                            if(0 <= final_x && final_x <n && 0 <= final_y && final_y < n && !visited[final_x][final_y]){
                                if(a[final_x][final_y] > i){
                                    visited[final_x][final_y] = 1;
                                    q.push(make_pair(final_x, final_y));
                                }
                            }
                        }
                    }
                }
            }
        }
        final = max(final, num);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp = max(temp, a[i][j]);
        }
    }
    go();
    if(final == 0){
        cout<<"1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}