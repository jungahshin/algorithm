//게리맨더링 2
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int pop[21][21] = {0, };
int visited[21][21] = {0, };
int final = INT_MAX;

void go(int x, int y, int d1, int d2){
    memset(visited, 0, sizeof(visited));
    //경계선 안 1구역
    int temp_one = 0;
    for(int i=0; i<d1; i++){
        //(x+i, y-i)가 기준점
        for(int j=y-i; j<=y; j++){
            temp_one += pop[x+i][j];
        }
    }
    //경계선 안 2구역
    int temp_two = 0;
    for(int i=1; i<=d2; i++){
        //(x+i, y+i)가 기준점
        for(int j=y+1; j<=y+i; j++){
            temp_two += pop[x+i][j];
        }
    }
    //경계선 안 3구역
    int temp_three = 0;
    for(int i=0; i<d2; i++){
        //(x+d1+i, y-d1+i)가 기준점
        for(int j=y-d1+i; j<y-d1+d2; j++){
            temp_three += pop[x+d1+i][j];
        }
    }
    //경계선 안 4구역
    int temp_four = 0;
    for(int i=1; i<=d1; i++){
        //(x+d2+i, y+d2-i)가 기준점
        for(int j=y+d2-d1; j<=y+d2-i; j++){
            temp_four += pop[x+d2+i][j];
        }
    }
    //1구역
    int one = 0;
    for(int i=1; i<x+d1; i++){
        for(int j=1; j<=y; j++){
            one += pop[i][j];
            visited[i][j] = 1;
        }
    }
    //2구역
    int two = 0;
    for(int i=1; i<=x+d2; i++){
        for(int j=y+1; j<=n; j++){
            two += pop[i][j];
            visited[i][j] = 1;
        }
    }
    //3구역
    int three = 0;
    for(int i=x+d1; i<=n; i++){
        for(int j=1; j<y-d1+d2; j++){
            three += pop[i][j];
            visited[i][j] = 1;
        }
    }
    //4구역
    int four = 0;
    for(int i=x+d2+1; i<=n; i++){
        for(int j=y-d1+d2; j<=n; j++){
            four += pop[i][j];
            visited[i][j] = 1;
        }
    }
    int five = temp_one+temp_two+temp_three+temp_four;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visited[i][j]){
                five += pop[i][j];
            }
        }
    }
    int real_one = abs(one-temp_one);
    int real_two = abs(two-temp_two);
    int real_three = abs(three-temp_three);
    int real_four = abs(four-temp_four);
    vector<int> v;
    v.push_back(real_one);
    v.push_back(real_two);
    v.push_back(real_three);
    v.push_back(real_four);
    v.push_back(five);
    sort(v.begin(), v.end());
    int total = v[v.size()-1] - v[0];//인구가 가장 큰 곳과 가장 작은 곳의 차이
    final = min(final, total);
    v.clear();
}

void check(){
    //기준점(i, j)
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //d1, d2
            for(int k=1; k<=n; k++){//d1
                for(int t=1; t<=n; t++){//d2
                    if((i<i+k+t) && (i+k+t<=n) && (1<=j-k) && (j-k<j) && (j+t<=n)){
                        go(i, j, k, t);
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>pop[i][j];
        }
    }
    check();//기준점(x, y)와 d1, d2를 정하고 그것이 범위에 맞는지 확인한 후 go() 진행
    cout<<final<<"\n";
}