#include <iostream>
#include <vector>
#include <climits> //INT_MAX
#include <algorithm>
using namespace std;

int a[21][21] = {0, };//인구 수 넣는 배열
int area[21][21] = {0, };//구역 지정하는 배열
int final = INT_MAX;
int n;
int d1, d2, x, y;
vector<int> range;

void cal(){//인구 세기
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(area[i][j] == 1){
                one += a[i][j];
            }else if(area[i][j] == 2){
                two += a[i][j];
            }else if(area[i][j] == 3){
                three += a[i][j];
            }else if(area[i][j] == 4){
                four += a[i][j];
            }else if(area[i][j] == 5){
                five += a[i][j];
            }
        }
    }
    vector<int> v;    
    v.push_back(one);
    v.push_back(two);
    v.push_back(three);
    v.push_back(four);
    v.push_back(five);
    sort(v.begin(), v.end());
    int minus = v[v.size()-1] - v[0];//인구가 가장 많은 곳에서 가장 적은 곳 차이
    final = min(final, minus);
}

void go_3(int x, int y, int d1, int d2){//1,2,3,4구역 설정
    for(int r=1; r<x+d1; r++){//1구역 설정
        for(int c=1; c<=y; c++){
            if(area[r][c] != 5){
                area[r][c] = 1;
            }
        }
    }
    for(int r=1; r<=x+d2; r++){//2구역 설정
        for(int c=y+1; c<=n; c++){
            if(area[r][c] != 5){
                area[r][c] = 2;
            }
        }
    }
    for(int r=x+d1; r<=n; r++){//3구역 설정
        for(int c=1; c<y-d1+d2; c++){
            if(area[r][c] != 5){
                area[r][c] = 3;
            }
        }
    }
    for(int r=x+d2+1; r<=n; r++){//4구역 설정
        for(int c=y-d1+d2; c<=n; c++){
            if(area[r][c] != 5){
                area[r][c] = 4;
            }
        }
    }
    cal();
}

void go_2(int x, int y, int d1, int d2){//기준점, 경계길이 설정완료-->5구역 설정
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            area[i][j] = 0;
        }
    }
    int temp = y;
    for(int i=x; i<=x+d1; i++){
        for(int j=y; j>=y-d1; j--){
            if(temp == j){
                area[i][j] = 5;
            }
        }
        temp--;
    }
    int temp_1 = y;
    for(int i=x; i<=x+d2; i++){
        for(int j=y; j<=y+d2; j++){
            if(temp_1 == j){
                area[i][j] = 5;
            }
        }
        temp_1++;
    }
    int temp_2 = y-d1;
    for(int i=x+d1; i<=x+d1+d2; i++){
        for(int j=y-d1; j<=y-d1+d2; j++){
            if(temp_2 == j){
                area[i][j] = 5;
            }
        }
        temp_2++;
    }
    int temp_3 = y+d2;
    for(int i=x+d2; i<=x+d2+d1; i++){
        for(int j=y+d2; j>=y+d2-d1; j--){
            if(temp_3 == j){
                area[i][j] = 5;
            }
        }
        temp_3--;
    }
    //경계선을 기준으로 5구역 마저 채우기
    for(int i=1; i<=n; i++){//행
        range.clear();
        for(int j=1; j<=n; j++){//열-->5인 구역 idx 찾기
            if(area[i][j] == 5){
                range.push_back(j);
            }
        }
        if(range.size()>1){
            for(int k=range[0]; k<=range[1]; k++){//채우기
                area[i][k] = 5;
            }            
        }
    }
    go_3(x, y, d1, d2);
}

void go(){
    for(int i=1; i<=n; i++){//d1
        for(int j=1; j<=n; j++){//d2
            d1 = i;
            d2 = j;
            for(int k=1; k<=n; k++){
                for(int h=1; h<=n; h++){
                    if(1<=k && k<k+d1+d2 && k+d1+d2<=n && 1<=h-d1 && h-d1<h && h<h+d2 && h+d2<=n){
                        x = k;
                        y = h;
                        go_2(x, y, d1, d2);
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
            cin>>a[i][j];
        }
    }
    go();
    cout<<final<<"\n";
}