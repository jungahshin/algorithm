//가스관
//M->Z로 가스 이동
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char gas[26][26];
vector<pair<int, int>> gas_location;//모든 가스관의 위치 저장
vector<int> gas_dir[26][26];
vector<pair<int, int>> v;//원래 블록이 있었던 위치 저장
int dx[4] = {-1, 1, 0, 0};//상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};
int r, c;

void check(){//gas_dir[v[0].first][v[0].second]에 있는 방향들로 맞는 블록 추정하기!
    if(gas_dir[(v[0].first)][(v[0].second)].size() == 4){
        gas[((v[0].first))][(v[0].second)] = '+';
        return;
    }
    sort(gas_dir[(v[0].first)][(v[0].second)].begin(), gas_dir[(v[0].first)][(v[0].second)].end());//정렬하기
    for(int i=0; i<gas_dir[(v[0].first)][(v[0].second)].size(); i++){
        if(gas_dir[(v[0].first)][(v[0].second)][i] == 0){
            if(gas_dir[(v[0].first)][(v[0].second)][1] == 1){
                gas[((v[0].first))][(v[0].second)] = '|';
                return;
            }else if(gas_dir[(v[0].first)][(v[0].second)][1] == 2){
                gas[((v[0].first))][(v[0].second)] = '3';
                return;
            }else if(gas_dir[(v[0].first)][(v[0].second)][1] == 3){
                gas[((v[0].first))][(v[0].second)] = '2';
                return;
            }
        }else if(gas_dir[(v[0].first)][(v[0].second)][i] == 1){
            if(gas_dir[(v[0].first)][(v[0].second)][1] == 2){
                gas[((v[0].first))][(v[0].second)] = '4';
                return;
            }else if(gas_dir[(v[0].first)][(v[0].second)][1] == 3){
                gas[((v[0].first))][(v[0].second)] = '1';
                return;
            }
        }else if(gas_dir[(v[0].first)][(v[0].second)][i] == 2){
            if(gas_dir[(v[0].first)][(v[0].second)][1] == 3){
                gas[((v[0].first))][(v[0].second)] = '-';
                return;
            }
        }
    }
}

void find(){
    for(int i=0; i<gas_location.size(); i++){//가스관 개수 만큼 진행
        //어디던 M, Z가 아닌 빈칸인 경우 벡터에 따로 그 위치를 저장해둔다(원래 블록이 있었던 위치이기 때문)
        int x = gas_location[i].first;
        int y = gas_location[i].second;
        for(int j=0; j<gas_dir[x][y].size(); j++){//방향의 개수 만큼 진행
            if(gas_dir[x][y][j] == 0){//위
                int final_x = x + dx[0];
                int final_y = y + dy[0];
                if(1 <= final_x && final_x <= r && 1 <= final_y && final_y <= c){
                    if(gas[final_x][final_y] == '.'){//빈칸이면-->원래 블록이 있었던 위치
                        v.push_back(make_pair(final_x, final_y));
                        gas_dir[final_x][final_y].push_back(1);//아래
                    }
                }
            }else if(gas_dir[x][y][j] == 1){//아래
                int final_x = x + dx[1];
                int final_y = y + dy[1];
                if(1 <= final_x && final_x <= r && 1 <= final_y && final_y <= c){
                    if(gas[final_x][final_y] == '.'){//빈칸이면-->원래 블록이 있었던 위치
                        v.push_back(make_pair(final_x, final_y));
                        gas_dir[final_x][final_y].push_back(0);//위
                    }
                }                
            }else if(gas_dir[x][y][j] == 2){//왼
                int final_x = x + dx[2];
                int final_y = y + dy[2];
                if(1 <= final_x && final_x <= r && 1 <= final_y && final_y <= c){
                    if(gas[final_x][final_y] == '.'){//빈칸이면-->원래 블록이 있었던 위치
                        v.push_back(make_pair(final_x, final_y));
                        gas_dir[final_x][final_y].push_back(3);//오른
                    }
                }
            }else if(gas_dir[x][y][j] == 3){//오
                int final_x = x + dx[3];
                int final_y = y + dy[3];
                if(1 <= final_x && final_x <= r && 1 <= final_y && final_y <= c){
                    if(gas[final_x][final_y] == '.'){//빈칸이면-->원래 블록이 있었던 위치
                        v.push_back(make_pair(final_x, final_y));
                        gas_dir[final_x][final_y].push_back(2);//왼
                    }
                }
            }
        }
    }
    check();
}

int main(){
    cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin>>gas[i][j];
            if(gas[i][j] != '.'){//빈칸이 아니라 블록을 나타내면, 그 위치를 저장
                gas_location.push_back(make_pair(i, j));
                if(gas[i][j] == '|'){//0, 1(위, 아래)
                    gas_dir[i][j].push_back(0);
                    gas_dir[i][j].push_back(1);
                }else if(gas[i][j] == '-'){//2, 3(왼, 오)
                    gas_dir[i][j].push_back(2);
                    gas_dir[i][j].push_back(3);
                }else if(gas[i][j] == '+'){
                    gas_dir[i][j].push_back(0);
                    gas_dir[i][j].push_back(1);
                    gas_dir[i][j].push_back(2);
                    gas_dir[i][j].push_back(3);
                }else if(gas[i][j] == '1'){
                    gas_dir[i][j].push_back(1);
                    gas_dir[i][j].push_back(3);
                }else if(gas[i][j] == '2'){
                    gas_dir[i][j].push_back(0);
                    gas_dir[i][j].push_back(3);
                }else if(gas[i][j] == '3'){
                    gas_dir[i][j].push_back(0);
                    gas_dir[i][j].push_back(2);
                }else if(gas[i][j] == '4'){
                    gas_dir[i][j].push_back(1);
                    gas_dir[i][j].push_back(2);
                }
            }
        }
    }
    find();
    cout<<v[0].first<<" "<<v[0].second<<" "<<gas[(v[0].first)][(v[0].second)]<<"\n";
}