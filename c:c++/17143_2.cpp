//낚시왕-->나중에 struct이용해보기
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int R, C, M, r, c, s, d, z;
int a[101][101];
int temp[101][101];
vector<tuple<int, int, int>> v_else;//상어 속력, 방향, 크기 저장(get<0>(v_else[i]))
vector<pair<int, int>> v_location;//상어 위치 저장
vector<int> final;
int final_num = 0;

void go(){
    //낚시왕 이동 & 상어 잡기
    for(int h=0; h<C; h++){//낚시왕 이동
        for(int j=0; j<R; j++){
            if(a[j][h] != -1){//상어가 있다.
                //상어 잡기
                final.push_back(get<2>(v_else[(a[j][h])]));//상어 크기 저장
                a[j][h] = -1;
                break;
            }
        }
        //상어 이동
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                temp[i][j] = -1;
            }
        }
        for(int i=0; i<v_location.size(); i++){//모든 상어에 적용
            if(a[v_location[i].first][v_location[i].second] == i){//상어가 있을 시에 진행
                a[v_location[i].first][v_location[i].second] = -1;//원래 위치 0으로 만들고
                if(get<1>(v_else[i]) <=2){
                    int moving = get<0>(v_else[i])%(2*(R-1));
                    while(moving--){
                        if(get<1>(v_else[i]) == 1){//위
                            if(v_location[i].first == 0){//맨 위
                                get<1>(v_else[i]) = 2;
                                v_location[i].first++;
                            }else{
                                v_location[i].first--;
                            }
                        }else if(get<1>(v_else[i]) == 2){//아래
                            if(v_location[i].first == R-1){//맨 밑
                                get<1>(v_else[i]) = 1;
                                v_location[i].first--;
                            }else{
                                v_location[i].first++;
                            }
                        }
                    }
                }else{
                    int moving = get<0>(v_else[i])%(2*(C-1));
                    while(moving--){
                        if(get<1>(v_else[i]) == 3){//오른쪽
                            if(v_location[i].second == C-1){
                                get<1>(v_else[i]) = 4;
                                v_location[i].second--;
                            }else{
                                v_location[i].second++;
                            }
                        }else if(get<1>(v_else[i]) == 4){//왼쪽
                            if(v_location[i].second == 0){
                                get<1>(v_else[i]) = 3;
                                v_location[i].second++;
                            }else{
                                v_location[i].second--;
                            }
                        }
                    }
                }
                if(temp[v_location[i].first][v_location[i].second] == -1){//새로 바뀐 위치에 아무것도 없으면
                    temp[v_location[i].first][v_location[i].second] = i;
                }else if(temp[v_location[i].first][v_location[i].second] != -1){//이동한 위치에 이미 상어가 있으면(크기 비교해서 큰걸로 저장)
                    //현재 index-->i, 이미 있는 상어의 index --> a[v_location[i].first][v_location[i].second]
                    if(get<2>(v_else[i]) > get<2>(v_else[(temp[v_location[i].first][v_location[i].second])])){
                        temp[v_location[i].first][v_location[i].second] = i;
                    }
                }
            }
        }
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                a[i][j] = temp[i][j];
            }
        }
    }
}

int main(){
    cin>>R>>C>>M;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            a[i][j] = -1;
        }
    }
    for(int i=0; i<M; i++){
        cin>>r>>c>>s>>d>>z;//위치, 속력, 방향, 크기
        a[r-1][c-1] = i;//몇 번째 상어인지를 저장-->벡터 조회할때 사용
        //상어 정보 저장
        v_else.push_back(make_tuple(s, d, z));
        v_location.push_back(make_pair(r-1, c-1));
    }
    //낚시왕 이동->상어 잡기->상어 이동
    go();
    for(int i=0; i<final.size(); i++){
        final_num += final[i];
    }
    cout<<final_num<<"\n";
}