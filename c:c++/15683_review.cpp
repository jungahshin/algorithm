//감시 복습
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int area[9][9] = {0, };
int area_copy[9][9] = {0, };
int final = INT_MAX;
vector<pair<int, int>> cctv;
int wall_num = 0;

//1-5는 cctv번호, 0-빈칸, 6-벽
//가능한 방향을 일단 잡고 그 방향으로 번진다.
//0->위, 1->오, 2->아래, 3->왼(dir)
//1번 cctv 1, 2, 3, 4 ->4가지
//2번 cctv (0, 2), (1, 3) ->2가지
//3번 cctv (0, 1), (1, 2), (2, 3), (3, 0) ->4가지
//4번 cctv (0, 1, 3), (0, 1, 2), (1, 2, 3), (0, 2, 3) ->4가지
//감시하고 있는 곳 -1로 표시

void copy(int area_[9][9]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            area_copy[i][j] = area_[i][j];
        }
    }
}

void cal(int x, int y, int dir){
    if(dir == 1){
        //위(열 그대로)
        for(int i=x-1; i>=0; i--){
            if(0<=i && i<n){
                if(area_copy[i][y] == 0){
                    area_copy[i][y] = -1;
                }else if(1<=area_copy[i][y] && area_copy[i][y]<=5){
                    continue;
                }else if(area_copy[i][y] == 6){
                    break;
                }                
            }
        } 
    }else if(dir == 2){
        //오른쪽(행 그대로)
        for(int i=y+1; i<m; i++){
            if(0<=i && i<m){
                if(area_copy[x][i] == 0){
                    area_copy[x][i] = -1;
                }else if(1<=area_copy[x][i] && area_copy[x][i]<=5){
                    continue;
                }else if(area_copy[x][i] == 6){
                    break;
                }                
            }
        } 
    }else if(dir == 3){
        //아래(열 그대로)
        for(int i=x+1; i<n; i++){
            if(0<=i && i<n){
                if(area_copy[i][y] == 0){
                    area_copy[i][y] = -1;
                }else if(1<=area_copy[i][y] && area_copy[i][y]<=5){
                    continue;
                }else if(area_copy[i][y] == 6){
                    break;
                }
            }
        }
    }else if(dir == 4){
        //왼쪽(행 그대로)
        for(int i=y-1; i>=0; i--){
            if(0<=i && i<m){
                if(area_copy[x][i] == 0){
                    area_copy[x][i] = -1;
                }else if(1<=area_copy[x][i] && area_copy[x][i]<=5){
                    continue;
                }else if(area_copy[x][i] == 6){
                    break;
                }
            }
        } 
    }
}

void go(int area_[9][9], int k){
    int area_1[9][9] = {0, };
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            area_1[i][j] = area_[i][j];
        }
    }
    for(int i=k; i<cctv.size(); i++){
        int x = cctv[i].first;
        int y = cctv[i].second;
        if(area_1[x][y] == 1){
            //4가지 경우
            copy(area_1);
            cal(x, y, 1);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 2);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 3);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 4);
            go(area_copy, i+1);
        }else if(area_1[x][y] == 2){
            //2가지 경우
            copy(area_1);
            cal(x, y, 1);
            cal(x, y, 3);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 2);
            cal(x, y, 4);
            go(area_copy, i+1);
        }else if(area_1[x][y] == 3){
            //4가지 경우
            copy(area_1);
            cal(x, y, 1);
            cal(x, y, 2);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 2);
            cal(x, y, 3);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 3);
            cal(x, y, 4);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 4);
            cal(x, y, 1);
            go(area_copy, i+1);
        }else if(area_1[x][y] == 4){
            //4가지 경우
            copy(area_1);
            cal(x, y, 1);
            cal(x, y, 2);
            cal(x, y, 4);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 1);
            cal(x, y, 2);
            cal(x, y, 3);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 2);
            cal(x, y, 3);
            cal(x, y, 4);
            go(area_copy, i+1);
            copy(area_1);
            cal(x, y, 3);
            cal(x, y, 4);
            cal(x, y, 1);
            go(area_copy, i+1);
        }else if(area_1[x][y] == 5){
            //1가지 경우
            copy(area_1);
            cal(x, y, 1);
            cal(x, y, 2);
            cal(x, y, 3);
            cal(x, y, 4);
            go(area_copy, i+1);
        }
    }
    //여기에서 총 사가지대의 수를 계산해준다.
    int num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area_copy[i][j] == 0){
                num++;
            }
        }
    }
    final = min(final, num);
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>area[i][j];
            if(1<=area[i][j] && area[i][j]<=5){
                cctv.push_back(make_pair(i, j));
            }else if(area[i][j] == 6){
                wall_num++;
            }
        }
    }
    if(cctv.size() == 0){
        cout<<n*m-wall_num<<"\n";
        return 0;
    }
    go(area, 0);
    cout<<final<<"\n";
    return 0;
}