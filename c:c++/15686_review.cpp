//치킨 배달 복습
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int city[51][51] = {0, };
vector<pair<int, int>> chicken;//치킨집의 위치 저장
vector<pair<int, int>> home;//가정집의 위치 저장
vector<pair<int, int>> pick;//선택된 치킨집
int visited[14] = {0, };
int final = INT_MAX;

void go(){
    int final_temp = 0;
    for(int i=0; i<home.size(); i++){
        int x = home[i].first;
        int y = home[i].second;
        //각 가정집에서 치킨집까지의 거리 중 최소값 구한다.
        int temp = INT_MAX;
        for(int j=0; j<pick.size(); j++){
            int c_x = pick[j].first;
            int c_y = pick[j].second;
            temp = min(temp, abs(x-c_x)+abs(y-c_y));
        }
        final_temp += temp;
    }
    final = min(final_temp, final);
}

void choose(int num, int idx){//치킨집 m개를 고른다.
    if(num == m){
        pick.clear();
        for(int i=0; i<chicken.size(); i++){
            if(visited[i] == true){
                pick.push_back(make_pair(chicken[i].first, chicken[i].second));
            }
        }
        go();
        return;
    }

    for(int i=idx; i<chicken.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        choose(num+1, i);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>city[i][j];
            if(city[i][j] == 2){
                chicken.push_back(make_pair(i, j));
            }else if(city[i][j] == 1){
                home.push_back(make_pair(i, j));
            }
        }
    }
    choose(0, 0);
    cout<<final<<"\n";
}