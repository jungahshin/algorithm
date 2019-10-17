//낚시왕 복습
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int a[101][101];
int a_copy[101][101];
vector<pair<int, int>> v_1;
vector<tuple<int, int, int>> v_2;
int final_size = 0;
int R, C, M, r, c, s, d, z;

void go(){
    for(int i=0; i<C; i++){//낚시꾼 이동
        //상어 잡기
        for(int j=0; j<R; j++){
            if(a[j][i] != -1){
                final_size += get<2>(v_2[(a[j][i])]);
                a[j][i] = -1;//잡는다.
                break;
            }
        }
        //상어 이동
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                a_copy[i][j] = -1;
            }
        }
        for(int i=0; i<v_1.size(); i++){//상어 개수만큼
            if(a[v_1[i].first][v_1[i].second] == i){//상어가 존재하면 진행
                if(get<1>(v_2[i]) <= 2){
                    int fast = get<0>(v_2[i])%(2*(R-1));
                    while(fast--){
                        if(get<1>(v_2[i]) == 1){//위
                            if(v_1[i].first == 0){
                                get<1>(v_2[i]) = 2;
                                v_1[i].first = 1;
                            }else{
                                v_1[i].first -= 1;
                            }
                        }else if(get<1>(v_2[i]) == 2){//아래
                            if(v_1[i].first == R-1){
                                get<1>(v_2[i]) = 1;
                                v_1[i].first = R-2;
                            }else{
                                v_1[i].first += 1;
                            }
                        }                              
                    }
                }else{
                    int fast_ = get<0>(v_2[i])%(2*(C-1));
                    while(fast_--){
                        if(get<1>(v_2[i]) == 3){//오른
                            if(v_1[i].second == C-1){
                                get<1>(v_2[i]) = 4;
                                v_1[i].second = C-2;
                            }else{
                                v_1[i].second += 1;
                            }
                        }else if(get<1>(v_2[i]) == 4){//왼
                            if(v_1[i].second == 0){
                                get<1>(v_2[i]) = 3;
                                v_1[i].second = 1;
                            }else{
                                v_1[i].second -= 1;
                            }
                        }                           
                    }
                }
                if(a_copy[v_1[i].first][v_1[i].second] == -1){//상어가 없었다.
                    a_copy[v_1[i].first][v_1[i].second] = i;
                }else{
                    if(get<2>(v_2[i]) > get<2>(v_2[(a_copy[v_1[i].first][v_1[i].second])])){
                        a_copy[v_1[i].first][v_1[i].second] = i;
                    }
                }                   
            }
        }
        //a_copy값을 a에 넣어준다.
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                a[i][j] = a_copy[i][j];
            }
        }
    }
}


int main(){
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            a[i][j] = -1;
        }
    }
    cin>>R>>C>>M;
    for(int i=0; i<M; i++){
        cin>>r>>c>>s>>d>>z;
        a[r-1][c-1] = i;//몇 번째 상어인지를 저장하기
        v_1.push_back(make_pair(r-1, c-1));
        v_2.push_back(make_tuple(s, d, z));
    }
    go();
    cout<<final_size<<"\n";
}