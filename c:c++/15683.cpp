//감시
//조합 4번(1, 2, 3, 4번 cctv)
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n,m;
int a[9][9] = {0, };
int a_[9][9] = {0, };
vector<pair<pair<int, int>, pair<int, int>>> cctv;//위치랑 몇번인지
int one[4] = {1,2,3,4};//위, 오, 아래, 왼
int two[2] = {1,2};//양옆, 위아래
int three[4] = {1,2,3,4};
int four[4] = {1,2,3,4};
int five[1] = {1};
vector<pair<pair<int, int>, pair<int, int>>> final;//위치랑 cctv몇번인지 그중에서도 몇 번인지
int no_cctv = INT_MAX;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_[i][j] = a[i][j];
        }
    }
}

void cal_2(int x,  int y, int num){//위, 오, 아래, 왼 방향 계산
    if(num == 1){//위
        for(int i=x-1; i>=0; i--){//행 감소, 열 그대로
            if(a_[i][y] == 6){//벽
                break;
            }else if(1<=a_[i][y] && a_[i][y]<=5){//cctv
                continue;
            }else{//빈칸이면
                a_[i][y] = -1;//감시할 수 있는 영역
            }
        }
    }else if(num == 2){//오
        for(int i=y+1; i<m; i++){//행 그대로, 열 증가
            if(a_[x][i] == 6){//벽
                break;
            }else if(1<=a_[x][i] && a_[x][i]<=5){//cctv
                continue;
            }else{//빈칸이면
                a_[x][i] = -1;//감시할 수 있는 영역
            }
        }
    }else if(num == 3){//아래
        for(int i=x+1; i<n; i++){//행 증가, 열 그대로
            if(a_[i][y] == 6){//벽
                break;
            }else if(1<=a_[i][y] && a_[i][y]<=5){//cctv
                continue;
            }else{//빈칸이면
                a_[i][y] = -1;//감시할 수 있는 영역
            }
        }
    }else if(num == 4){//왼
        for(int i=y-1; i>=0; i--){//행 그대로, 열 감소
            if(a_[x][i] == 6){//벽
                break;
            }else if(1<=a_[x][i] && a_[x][i]<=5){//cctv
                continue;
            }else{//빈칸이면
                a_[x][i] = -1;//감시할 수 있는 영역
            }
        }
    }

}

void cal(){//사각지대 계산하기-->final에 있는 값들 가지고 (0의 갯수 세기)
    copy();
    int zero_num = 0;//0의 개수
    for(int i=0; i<final.size(); i++){
        int x = final[i].first.first;
        int y = final[i].first.second;
        if(final[i].second.first == 1){//1번 cctv
            if(final[i].second.second == 1){//중에서 위
                cal_2(x, y, 1);
            }else if(final[i].second.second == 2){//오
                cal_2(x, y, 2);
            }else if(final[i].second.second == 3){//아래
                cal_2(x, y, 3);
            }else if(final[i].second.second == 4){//왼
                cal_2(x, y, 4);
            }
        }else if(final[i].second.first == 2){//2번 cctv
            if(final[i].second.second == 1){//위, 아래
                cal_2(x, y, 1);
                cal_2(x, y, 3);
            }else if(final[i].second.second == 2){//왼, 오
                cal_2(x, y, 4);
                cal_2(x, y, 2);
            }
        }else if(final[i].second.first == 3){
            if(final[i].second.second == 1){//위,오
                cal_2(x, y, 1);
                cal_2(x, y, 2);
            }else if(final[i].second.second == 2){//오, 아래
                cal_2(x, y, 2);
                cal_2(x, y, 3);
            }else if(final[i].second.second == 3){//아래, 왼
                cal_2(x, y, 3);
                cal_2(x, y, 4);
            }else if(final[i].second.second == 4){//왼,위
                cal_2(x, y, 4);
                cal_2(x, y, 1);
            }
        }else if(final[i].second.first == 4){
            if(final[i].second.second == 1){//왼, 위, 오
                cal_2(x, y, 4);
                cal_2(x, y, 1);
                cal_2(x, y, 2);
            }else if(final[i].second.second == 2){//위, 오, 아래
                cal_2(x, y, 1);
                cal_2(x, y, 2);
                cal_2(x, y, 3);
            }else if(final[i].second.second == 3){//왼, 아래, 오
                cal_2(x, y, 4);
                cal_2(x, y, 3);
                cal_2(x, y, 2);
            }else if(final[i].second.second == 4){//위, 왼, 아래
                cal_2(x, y, 1);
                cal_2(x, y, 4);
                cal_2(x, y, 3);
            }
        }else if(final[i].second.first == 5){
            if(final[i].second.second == 1){//위, 오, 아래, 왼
                cal_2(x, y, 1);
                cal_2(x, y, 2);
                cal_2(x, y, 3);
                cal_2(x, y, 4);
            }
        }
    }
    //0의 개수 세기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_[i][j] == 0){
                zero_num++;
            }
        }
    }
    no_cctv = min(no_cctv, zero_num);
}


void go(int num, int idx){
    if(num == cctv.size()){
        //cctv 사각지대 계산
        cal();
        return;
    }

    if(cctv[idx].second.first == 1){
        for(int i=0; i<4; i++){
            final.push_back(make_pair(make_pair(cctv[idx].first.first, cctv[idx].first.second), make_pair(cctv[idx].second.first, one[i])));
            go(num+1, idx+1);
            final.erase(final.begin()+idx);
        }
    }else if(cctv[idx].second.first == 2){
        for(int i=0; i<2; i++){
            final.push_back(make_pair(make_pair(cctv[idx].first.first, cctv[idx].first.second), make_pair(cctv[idx].second.first, two[i])));
            go(num+1, idx+1);
            final.erase(final.begin()+idx);   
        }
    }else if(cctv[idx].second.first == 3){
        for(int i=0; i<4; i++){
            final.push_back(make_pair(make_pair(cctv[idx].first.first, cctv[idx].first.second), make_pair(cctv[idx].second.first, three[i])));
            go(num+1, idx+1);
            final.erase(final.begin()+idx);   
        } 
    }else if(cctv[idx].second.first == 4){
        for(int i=0; i<4; i++){
            final.push_back(make_pair(make_pair(cctv[idx].first.first, cctv[idx].first.second), make_pair(cctv[idx].second.first, four[i])));
            go(num+1, idx+1);
            final.erase(final.begin()+idx);   
        } 
    }else if(cctv[idx].second.first == 5){
        for(int i=0; i<1; i++){
            final.push_back(make_pair(make_pair(cctv[idx].first.first, cctv[idx].first.second), make_pair(cctv[idx].second.first, five[i])));
            go(num+1, idx+1);
            final.erase(final.begin()+idx);   
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(1<=a[i][j] && a[i][j]<=5){//cctv위치 저장
                if(a[i][j] == 1 || a[i][j] == 3 || a[i][j] == 4){
                    cctv.push_back(make_pair(make_pair(i, j), make_pair(a[i][j], 4)));
                }else if(a[i][j] == 2){
                    cctv.push_back(make_pair(make_pair(i, j), make_pair(a[i][j], 2)));
                }else if(a[i][j] == 5){
                    cctv.push_back(make_pair(make_pair(i, j), make_pair(a[i][j], 1)));
                }
            }
        }
    }
    go(0,0);
    cout<<no_cctv <<"\n";
}