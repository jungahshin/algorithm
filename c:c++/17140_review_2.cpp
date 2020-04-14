//이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int a[101][101] = {0, };
int row, col;//열과 행의 크기를 저장
bool check = false;
int final = 0;//최소시간

void go(){
    int num = 0;//시간(초)
    while(1){
        //A[r][c]가 k인지 확인
        if(a[r][c] == k){
            final = num;
            break;
        }
        num++;
        if(num>100){
            check = true;
            break;
        }
        //수행된 정렬을 저장
        int a_temp[101][101] = {0, };
        if(row>=col){//R연산
            int max_temp = 0;
            for(int i=1; i<=row; i++){//행 기준
                vector<pair<int, int>> v;//(등장횟수, 수)저장 
                int temp[101] = {0, };//해당 숫자가 나온 횟수를 저장
                for(int j=1; j<=col; j++){
                    temp[a[i][j]]++;
                }
                for(int j=1; j<=100; j++){
                    if(temp[j]>0){
                        v.push_back(make_pair(temp[j], j));
                    }
                }
                sort(v.begin(), v.end());
                int idx = 1;
                for(int j=0; j<v.size(); j++){
                    if(idx>100){
                        break;
                    }
                    a_temp[i][idx++] = v[j].second;//수
                    if(idx>100){
                        break;
                    }
                    a_temp[i][idx++] = v[j].first;//등장횟수
                }
                int size = v.size()*2;
                if(size>100){
                    max_temp = max(max_temp, 100);
                }else{
                    max_temp = max(max_temp, size);
                }
            }
            col = max_temp;
        }else{//C연산
            int max_temp = 0;
            for(int i=1; i<=col; i++){//열 기준
                vector<pair<int, int>> v;//(등장횟수, 수)저장 
                int temp[101] = {0, };//해당 숫자가 나온 횟수를 저장
                for(int j=1; j<=row; j++){
                    temp[a[j][i]]++;
                }
                for(int j=1; j<=100; j++){
                    if(temp[j]>0){
                        v.push_back(make_pair(temp[j], j));
                    }
                }
                sort(v.begin(), v.end());
                int idx = 1;
                for(int j=0; j<v.size(); j++){
                    if(idx>100){
                        break;
                    }
                    a_temp[idx++][i] = v[j].second;//수
                    if(idx>100){
                        break;
                    }
                    a_temp[idx++][i] = v[j].first;//등장횟수
                }
                int size = v.size()*2;
                if(size>100){
                    max_temp = max(max_temp, 100);
                }else{
                    max_temp = max(max_temp, size);
                }
            }
            row = max_temp;
        }
        for(int k=1; k<=100; k++){
            for(int t=1; t<=100; t++){
                a[k][t] = a_temp[k][t];
            }
        }
    }
}

int main(){
    cin>>r>>c>>k;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin>>a[i][j];
        }
    }
    row = 3;
    col = 3;
    go();
    if(check == true){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}