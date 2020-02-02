//미세먼지 안녕! 복습
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[51][51] = {0, };
int a_[51][51] = {0, };//미세먼지 확산에 쓰이는 임시 배열
int up_x, up_y, down_x, down_y;
int r, c, t;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int total = 0;

void clean(){
    int time_cnt = 0;
    while(time_cnt<t){
        memset(a_, 0, sizeof(a_));
        time_cnt++;
        //미세먼지 확산
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(a[i][j] > 0){
                    int num = 0;
                    for(int t=0; t<4; t++){
                        int final_x = i+dx[t];
                        int final_y = j+dy[t];
                        if(0<=final_x && final_x<r && 0<=final_y && final_y<c && a[final_x][final_y] != -1){
                            num++;
                            a_[final_x][final_y] += (a[i][j]/5);
                        }
                    }
                    a[i][j] -= (a[i][j]/5)*num;
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                a[i][j] += a_[i][j];
            }
        }

        //공기청정기 작동
        //윗 부분(반시계방향으로 작동)
        vector<int> v;
        for(int i=up_y+1; i<c; i++){//열 증가
            v.push_back(a[up_x][i]);
        }
        for(int i=up_x-1; i>=0; i--){//행 감소
            v.push_back(a[i][c-1]);
        }
        for(int i=c-2; i>=0; i--){//열 감소
            v.push_back(a[0][i]);
        }
        for(int i=1; i<up_x; i++){//행 증가
            v.push_back(a[i][0]);
        }

        vector<int> temp;
        temp.push_back(0);
        for(int i=0; i<v.size()-1; i++){
            temp.push_back(v[i]);
        }    

        //temp를 다시 a배열에 넣어준다.
        int idx = 0;
        for(int i=up_y+1; i<c; i++){//열 증가
            a[up_x][i] = temp[idx];
            idx++;
        }
        for(int i=up_x-1; i>=0; i--){//행 감소
            a[i][c-1] = temp[idx];
            idx++;
        }
        for(int i=c-2; i>=0; i--){//열 감소
            a[0][i] = temp[idx];
            idx++;
        }
        for(int i=1; i<up_x; i++){//행 증가
            a[i][0] = temp[idx];
            idx++;
        }
        v.clear();
        temp.clear();

        vector<int> v_;
        for(int i=down_y+1; i<c; i++){//열 증가
            v_.push_back(a[down_x][i]);
        }
        for(int i=down_x+1; i<r; i++){//행 증가
            v_.push_back(a[i][c-1]);
        }
        for(int i=c-2; i>=0; i--){//열 감소
            v_.push_back(a[r-1][i]);
        }
        for(int i=r-2; i>=down_x+1; i--){//행 감소
            v_.push_back(a[i][0]);
        }

        vector<int> temp_;
        temp_.push_back(0);
        for(int i=0; i<v_.size()-1; i++){
            temp_.push_back(v_[i]);
        }    

        int idx_ = 0;
        for(int i=down_y+1; i<c; i++){//열 증가
            a[down_x][i] = temp_[idx_];
            idx_++;
        }
        for(int i=down_x+1; i<r; i++){//행 증가
            a[i][c-1] = temp_[idx_];
            idx_++;
        }
        for(int i=c-2; i>=0; i--){//열 감소
            a[r-1][i] = temp_[idx_];
            idx_++;
        }
        for(int i=r-2; i>=down_x+1; i--){//행 감소
            a[i][0] = temp_[idx_];
            idx_++;
        }
        v_.clear();
        temp_.clear();        
    }
    //총 남아있는 미세먼지의 수
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j]>0){
                total += a[i][j];
            }
        }
    }
}   

int main(){
    cin>>r>>c>>t;
    int num = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a[i][j];
            if(a[i][j] == -1){//공기청정기 위치
                if(num == 0){
                    num++;
                    up_x = i;
                    up_y = j;                    
                }else{
                    down_x = i;
                    down_y = j;
                }
            }
        }
    }
    clean();
    cout<<total<<"\n";
}