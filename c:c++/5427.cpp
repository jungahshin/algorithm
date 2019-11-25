//불(이것도 불이 번질 것 같은 곳에는 이동할 수 없다)
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int testcase, w, h;
char a[1001][1001];
int num[1001][1001] = {0, };
queue<pair<int, int>> sang;
queue<pair<int, int>> fire;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int>> edge;
vector<int> final;

bool check(int x, int y){//가장 자리 부분에 오면
    int temp = false;
    for(int i=0; i<edge.size(); i++){
        if(x == edge[i].first && y == edge[i].second){
            temp = true;
        }
    }
    return temp;
}

int go(){
    while(!sang.empty()){
        //불 확장-->., @일때 이동 가능
        int fireSize = fire.size();
        for(int i=0; i<fireSize; i++){
            int x = fire.front().first;
            int y = fire.front().second;
            fire.pop();

            for(int j=0; j<4; j++){
                int final_x = x + dx[j];
                int final_y = y + dy[j];
                if(0 <= final_x && final_x <h && 0<= final_y && final_y < w){
                    if(a[final_x][final_y] == '.' || a[final_x][final_y] == '@'){
                        a[final_x][final_y] = '*';
                        fire.push(make_pair(final_x, final_y));
                    }
                }
            }
        }
        //상근이 이동
        int sangSize = sang.size();
        for(int i=0; i<sangSize; i++){
            int x = sang.front().first;
            int y = sang.front().second;
            sang.pop();

            //외곽인지 검사, 외곽이면->탈출
            if(check(x, y)){
                return (num[x][y]+1);
            }
            
            for(int j=0; j<4; j++){
                int final_x = x + dx[j];
                int final_y = y + dy[j];
                if(0 <= final_x && final_x < h && 0 <= final_y && final_y < w){
                    if(a[final_x][final_y] == '.' && num[final_x][final_y] == 0){
                        num[final_x][final_y] = num[x][y] + 1;
                        sang.push(make_pair(final_x, final_y));
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        //sang, fire, edge clear하기
        while(!sang.empty()){
            sang.pop();
        }
        while(!fire.empty()){
            fire.pop();
        }
        edge.clear();
        for(int t=0; t<1001; t++){
            for(int u=0; u<1001; u++){
                num[t][u] = 0;
            }
        }
        cin>>w>>h;//열, 행
        bool temp = false;
        for(int j=0; j<h; j++){
            for(int k=0; k<w; k++){
                cin>>a[j][k];
                if(a[j][k] == '@'){//상근이의 위치
                    sang.push(make_pair(j, k));
                }else if(a[j][k] == '*'){//불의 위치
                    fire.push(make_pair(j, k));
                }
                if(j == 0 || j == (h-1) || k == 0 || k == (w-1)){
                    if(a[j][k] == '.'){
                        edge.push_back(make_pair(j, k));                   
                    }
                    if(a[j][k] == '@'){
                        temp = true;
                    }
                }
            }
        }
        if(temp == false){
            int result = go();
            if(result == -1){
                final.push_back(-1);
            }else{
                final.push_back(result);
            }      
        }else{
            final.push_back(1);
        }
    }
    for(int i=0; i<final.size(); i++){
        if(final[i] == -1){
            cout<<"IMPOSSIBLE"<<"\n";
        }else{
            cout<<final[i]<<"\n";
        }
    }
}