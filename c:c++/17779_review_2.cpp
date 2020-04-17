//게리맨더링2 복습
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int a[22][22] = {0, };//인구수 저장
int five[22][22] = {0, };//5구역에 속해 있는지 판단
int n;
int final = INT_MAX;

void cal(int x, int y, int d1, int d2){
    vector<int> temp;
    int five_num = 0;
    int one_num = 0;
    int two_num = 0;
    int three_num = 0;
    int four_num = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            bool check = false;
            //1구역
            if(1<=i && i<x+d1 && 1<=j && j<=y){
                check = true;
                if(five[i][j] == 1){
                    five_num += a[i][j];
                }else{
                    one_num += a[i][j];
                }
            }
            //2구역
            if(1<=i && i<=x+d2 && y<j && j<=n){
                check = true;
                if(five[i][j] == 1){
                    five_num += a[i][j];
                }else{
                    two_num += a[i][j];
                }
            } 
            //3구역
            if(x+d1<=i && i<=n && 1<=j && j<y-d1+d2){
                check = true;
                if(five[i][j] == 1){
                    five_num += a[i][j];
                }else{
                    three_num += a[i][j];
                }
            }
            //4구역
            if(x+d2<i && i<=n && y-d1+d2<=j && j<=n){
                check = true;
                if(five[i][j] == 1){
                    five_num += a[i][j];
                }else{
                    four_num += a[i][j];
                }
            }
            if(check == false){//5구역에 넣는다.
                five_num += a[i][j];
            }
        }
    }
    temp.push_back(one_num);
    temp.push_back(two_num);
    temp.push_back(three_num);
    temp.push_back(four_num);
    temp.push_back(five_num);
    sort(temp.begin(), temp.end());
    final = min(final, temp[temp.size()-1]-temp[0]);
}

void go2(int x, int y, int d1, int d2){
    memset(five, 0, sizeof(five));
    int temp_x = x;
    int temp_y = y;
    int temp1_x = x+d2;
    int temp1_y = y+d2;
    int num = -1;
    while(1){
        num++;
        if(num>d1){
            break;
        }
        int final_x = temp_x+num;
        int final_y = temp_y-num;
        int final1_x = temp1_x+num;
        int final1_y = temp1_y-num;
        five[final_x][final_y] = 1;
        five[final1_x][final1_y] = 1;
    }
    temp1_x = x+d1;
    temp1_y = y-d1;
    num = -1;
    while(1){
        num++;
        if(num>d2){
            break;
        }
        int final_x = temp_x+num;
        int final_y = temp_y+num;
        int final1_x = temp1_x+num;
        int final1_y = temp1_y+num;
        five[final_x][final_y] = 1;
        five[final1_x][final1_y] = 1;
    }
    for(int i=1; i<=n; i++){
        if(i==x || i==x+d1+d2){
            continue;
        }
        bool check = false;
        for(int j=1; j<=n; j++){
            if(five[i][j] == 1){
                if(check == false){
                    check = true;
                }else{
                    check = false;
                }
            }else{
                if(check == true){
                    five[i][j] = 1;
                }
            }
        }
    }
}

void go(){
    //(x, y), d1, d2정하기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x = i;
            int y = j;
            for(int k=1; k<=n; k++){//d1
                for(int t=1; t<=n; t++){//d2
                    int d1 = k;
                    int d2 = t;
                    if(x<x+d1+d2 && x+d1+d2<=n && 1<=y-d1 && y-d1<y && d2+y<=n){
                        //5구역 표시하기
                        go2(x, y, d1, d2);
                        cal(x, y, d1, d2);
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
    return 0;
}