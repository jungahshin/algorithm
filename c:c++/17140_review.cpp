//이차원 배열과 연산 복습
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int a[102][102] = {0, };
int col = 3;//초기 행과 열의 크기
int row = 3;//나중에 연산해주면서 
bool check = false;
int cnt = 0;

//그냥 배열의 크기는 항상 100으로 생각하고 
//처음 부터 각 열, 행에 있는 숫자를 배열로 증가시키고 0이 나오면 바로 중단
//열 연산을 하면 무조건 열은 이전의 값으로 고정
//행 연산을 하면 무조건 행은 이전의 값으로 고정
void cal(){
    while(a[r][c] != k){
        cnt++;
        if(cnt > 100){
            check = true;
            break;
        }
        int b[102][102] = {0, };
        if(row >= col){//행 연산(row는 그대로 col만 최대값으로 바꿔준다)
            int col_max = 0;
            for(int i=1; i<=row; i++){//행
                int temp[102] = {0, };//횟수를 세줄 임시 배열
                vector<pair<int, int>> v_row;
                for(int j=1; j<=col; j++){//열
                    if(a[i][j] != 0){
                        temp[(a[i][j])]++;
                    }
                }
                for(int j=1; j<=100; j++){
                    if(temp[j] != 0){
                        v_row.push_back(make_pair(temp[j], j));
                    }
                }
                //정렬하기(횟수>수)
                sort(v_row.begin(), v_row.end());
                int size = v_row.size()*2;
                if(size > 100){
                    col_max = max(col_max, 100);
                }else{
                    col_max = max(col_max, size);
                }
                int idx = 1;
                for(int k=0; k<v_row.size(); k++){
                    if(idx > 100){
                        break;
                    }
                    b[i][idx] = v_row[k].second;//수
                    idx++;
                    if(idx > 100){
                        break;
                    }
                    b[i][idx] = v_row[k].first;//등장 횟수
                    idx++;
                }
                v_row.clear();
            }
            col = col_max;
            //b배열의 값을 a에 복사
            memset(a, 0, sizeof(a));
            for(int i=1; i<=row; i++){
                for(int j=1; j<=col; j++){
                    a[i][j] = b[i][j];
                }
            }
        }else{//열 연산(col은 그대로 row만 최대값으로 바꿔준다)
            int row_max = 0;
            for(int i=1; i<=col; i++){//열
                int temp[102] = {0, };//횟수를 세줄 임시 배열
                vector<pair<int, int>> v_col;
                for(int j=1; j<=row; j++){//행
                    if(a[j][i] != 0){
                        temp[(a[j][i])]++;
                    }
                }
                for(int j=1; j<=100; j++){
                    if(temp[j] != 0){
                        v_col.push_back(make_pair(temp[j], j));
                    }
                }
                //정렬하기(횟수>수)
                sort(v_col.begin(), v_col.end());
                int size = v_col.size()*2;
                if(size > 100){
                    row_max = max(row_max, 100);
                }else{
                    row_max = max(row_max, size);
                }
                int idx = 1;
                for(int k=0; k<v_col.size(); k++){
                    if(idx > 100){
                        break;
                    }
                    b[idx][i] = v_col[k].second;//수
                    idx++;
                    if(idx > 100){
                        break;
                    }
                    b[idx][i] = v_col[k].first;//등장 횟수
                    idx++;
                }
                v_col.clear();
            }
            row = row_max;
            //b배열의 값을 a에 복사
            memset(a, 0, sizeof(a));
            for(int i=1; i<=col; i++){
                for(int j=1; j<=row; j++){
                    a[j][i] = b[j][i];
                }
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
    cal();
    if(check == false){
        cout<<cnt<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
}