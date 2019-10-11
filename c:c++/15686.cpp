//치킨배달
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

int n,m;
int a[51][51] = {0, };//전체 값
bool check[14];
vector<pair<int, int>> chicken;
vector<pair<int, int>> chicken_final;//뽑힌 치킨 집
vector<pair<int, int>> home;
vector<int> final;//각 집의 치킨거리 저장
vector<int> really_final;
// int final_chicken = 0;//도시의 치킨 거리 값

void go(){//벡터에 넣은 치킨 집으로 도시의 치킨거리 값 구하기
    final.clear();
    for(int i=0; i<home.size(); i++){
        int home_chicken = INT_MAX;
        for(int j=0; j<chicken_final.size(); j++){
            int temp = abs(home[i].first-chicken_final[j].first) + abs(home[i].second-chicken_final[j].second);
            home_chicken = min(home_chicken, temp);
        }
        final.push_back(home_chicken);//도시의 치킨거리
    }
}

void save(){//m개 고른 치킨집 위치 큐에 저장하기
    chicken_final.clear();
    for(int i=0; i<chicken.size(); i++){
        if(check[i] == true){
            chicken_final.push_back(make_pair(chicken[i].first, chicken[i].second));
        }
    }
    go();
    int temp_ = 0;
    for(int i=0; i<final.size(); i++){//도시의 치킨 거리 값
        temp_ += final[i];
    }
    really_final.push_back(temp_);
}

void choose(int idx, int num){//m개 고르기
    if(num == m){
        save();//큐에 치킨집 위치 넣기
        return;
    }
    for(int i=idx; i<chicken.size(); i++){
        if(check[i] == true) continue;
        check[i] = true;
        choose(i, num+1);
        check[i] = false;
    }
}

int main(){
    cin>>n>>m;//살아남을 치킨집 m개 선택
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j] == 1){
                home.push_back(make_pair(i, j));
            }
            if(a[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    choose(0,0);
    sort(really_final.begin(), really_final.end());
    cout<<really_final[0]<<"\n";
}