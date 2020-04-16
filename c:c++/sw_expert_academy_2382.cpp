//2382. [모의 SW 역량테스트] 미생물 격리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int testcase, n, m, k, a, b, c, d;
vector<pair<int, int>> microbe[101][101];
vector<pair<int, int>> temp[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int go(){
    int final = 0;
    int hour = 0;
    while(1){
        hour++;
        if(hour>m){
            break;
        }
        final = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(microbe[i][j].size()>0){
                    //이동
                    int num = microbe[i][j][0].first;
                    int dir = microbe[i][j][0].second;
                    int x = i+dx[dir-1];
                    int y = j+dy[dir-1];
                    if(x==0 || x==n-1 || y==0 || y==n-1){//약품이 칠해진 셀
                        num /= 2;
                        if(dir == 1){
                            dir = 2;
                        }else if(dir == 2){
                            dir = 1;
                        }else if(dir == 3){
                            dir = 4;
                        }else if(dir == 4){
                            dir = 3;
                        }
                    }
                    //새로운 곳에 넣기
                    temp[x][y].push_back(make_pair(num, dir));
                }
            }
        }
        //원래 microbe배열로 옮기면서 확인
        //칸에 여러개의 미생물이 있는 지 확인 후 정리
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(microbe[i][j].size()>0){
                    microbe[i][j].clear();
                }
                if(temp[i][j].size()>0){
                    if(temp[i][j].size() == 1){
                        microbe[i][j].push_back(make_pair(temp[i][j][0].first, temp[i][j][0].second));
                        final += temp[i][j][0].first;
                    }else{
                        sort(temp[i][j].begin(), temp[i][j].end());
                        int idx = temp[i][j].size()-1;
                        int dir = temp[i][j][idx].second;//가장 미생물 수가 많은 군집 방향
                        int num = 0;
                        for(int k=0; k<temp[i][j].size(); k++){
                            num += temp[i][j][k].first;
                        }
                        microbe[i][j].push_back(make_pair(num, dir));
                        final += num;
                    }
                    temp[i][j].clear();
                }
            }
        }
    }
    return final;
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n>>m>>k;
        for(int k=0; k<n; k++){
            for(int t=0; t<n; t++){
                microbe[k][t].clear();
            }
        }
        for(int j=0; j<k; j++){
            cin>>a>>b>>c>>d;
            microbe[a][b].push_back(make_pair(c, d));
        }
        cout<<"#"<<i+1<<" "<<go()<<"\n";
    }
    return 0;
}