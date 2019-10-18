//이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[101][101] = {0, };
int time_ = 0;
int r, c, k;

void go(){
    int row = 3, col = 3;
    while(a[r][c] != k){
        time_++;//시간 재기
        if(time_>100){
            break;
        }
        vector<pair<int, int>> v[101];//v[i][j].first, v[i][j].second
        if(row>=col){//R연산 수행(행 단위로)
            for(int i=0; i<row; i++){
                int num[101] = {0, };//행마다 등장 횟수 세기
                for(int j=0; j<col; j++){
                    num[a[i][j]]++;//a[i][j]의 값이 1~100가능
                }
                for(int k=1; k<=100; k++){//0은 취급하지 않는다.
                    if(num[k] != 0){//0이면 한 번도 등장하지 않았다는 것
                        //등장했으면 v에 넣어준다.
                        v[i].push_back(make_pair(num[k],k));//행마다 다른 벡터(등장 횟수, 숫자)
                    }
                }
            }
            for(int i=0; i<row; i++){//행마다 벡터를 정렬한다.(first기준)
                sort(v[i].begin(), v[i].end());
            }
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    a[i][j] = 0;//0으로 초기화
                }
            }
            for(int i=0; i<row; i++){
                int temp = 0;
                for(int j=0; j<v[i].size(); j++){
                    a[i][temp++] = v[i][j].second;//숫자 먼저 배열에 넣는다
                    if(temp == 100) break;//a배열의 행과 열은 (0~99) && 100보다 행과 열이 크면 버린다.
                    a[i][temp++] = v[i][j].first;
                    if(temp == 100) break;//100보다 행과 열이 크면 버린다.
                }
                col = max(col,temp);//a배열의 행이 가장 큰 것을 기준으로 바뀐다.
            }
        }else{//C연산 수행(열 단위로)
            for(int i=0; i<col; i++){
                int num[101] = {0, };//행마다 등장 횟수 세기
                for(int j=0; j<row; j++){
                    num[a[j][i]]++;//a[i][j]의 값이 1~100가능
                }
                for(int k=1; k<=100; k++){//0은 취급하지 않는다.
                    if(num[k] != 0){//0이면 한 번도 등장하지 않았다는 것
                        //등장했으면 v에 넣어준다.
                        v[i].push_back(make_pair(num[k],k));//행마다 다른 벡터(등장 횟수, 숫자)
                    }
                }
            }
            for(int i=0; i<col; i++){//행마다 벡터를 정렬한다.(first기준)
                sort(v[i].begin(), v[i].end());
            }
            for(int i=0; i<col; i++){
                for(int j=0; j<row; j++){
                    a[j][i] = 0;//0으로 초기화
                }
            }
            for(int i=0; i<col; i++){
                int temp = 0;
                for(int j=0; j<v[i].size(); j++){
                    a[temp++][i] = v[i][j].second;//숫자 먼저 배열에 넣는다
                    if(temp == 100) break;//a배열의 행과 열은 (0~99) && 100보다 행과 열이 크면 버린다.
                    a[temp++][i] = v[i][j].first;
                    if(temp == 100) break;//100보다 행과 열이 크면 버린다.
                }
                row = max(row,temp);//a배열의 행이 가장 큰 것을 기준으로 바뀐다.
            }
        }
    }
}

int main(){
    cin>>r>>c>>k;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }
    r-=1;
    c-=1;
    go();
    if(time_>100){
        cout<<"-1"<<"\n";
    }else{
        cout<<time_<<"\n";
    }
    return 0;
}