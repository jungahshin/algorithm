//드래곤 커브 복습
#include <iostream>
#include <vector>
using namespace std;

int n, x, y, d, g;
vector<pair<pair<int, int>, pair<int, int>>> curve;
int a[102][102] = {0, };
vector<int> dir[22];//각 드래곤커브 마다 방향 축적된 것 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

//0(오), 1(위), 2(왼), 3(아래)

void go(){
    for(int i=0; i<curve.size(); i++){//각 드래곤커브마다 a배열에 표시한다.
        int size = curve[i].second.second;
        for(int j=0; j<size; j++){//세대만큼 반복한다.
            bool check = false;
            vector<int> temp;//새로운 방향들을 임시로 저장

            int size_temp = dir[i].size();
            if(size_temp>0){
                for(int k=size_temp-1; k>=0; k--){//마지막부터 진행
                    int x = curve[i].first.first;//시작 지점(x, y)
                    int y = curve[i].first.second;
                    int temp_dir = dir[i][k]+1;
                    if(temp_dir > 3){
                        int final_x = x+dx[0];
                        int final_y = y+dy[0];
                        if(0<=final_x && final_x<=100 && 0<=final_y && final_y<=100){
                            curve[i].first.first = final_x;
                            curve[i].first.second = final_y;
                            a[final_x][final_y] = 1;
                            // dir[i].push_back(0);
                            temp.push_back(0);
                        }else{
                            check = true;
                            break;
                        }
                    }else{
                        int final_x = x+dx[temp_dir];
                        int final_y = y+dy[temp_dir];
                        if(0<=final_x && final_x<=100 && 0<=final_y && final_y<=100){
                            curve[i].first.first = final_x;
                            curve[i].first.second = final_y;
                            a[final_x][final_y] = 1;
                            // dir[i].push_back(temp_dir);
                            temp.push_back(temp_dir);
                        }else{
                            check = true;
                            break;
                        }
                    }
                }
                if(check == true){//중간에 나간다.
                    break;
                }
                for(int k=0; k<temp.size(); k++){
                    dir[i].push_back(temp[k]);
                }
                temp.clear();                
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y>>d>>g;//시작점(x, y), 방향(d), 몇 세대(g)
        curve.push_back(make_pair(make_pair(x, y), make_pair(d, g)));
    }
    //처음 setting
    for(int i=0; i<curve.size(); i++){
        int x = curve[i].first.first;
        int y = curve[i].first.second;
        int temp_dir = curve[i].second.first;
        a[x][y] = 1;

        //끝점을 curve에 update
        int final_x = x+dx[temp_dir];
        int final_y = y+dy[temp_dir];
        if(0<=final_x && final_x<=100 && 0<=final_y && final_y<=100){
            curve[i].first.first = final_x;
            curve[i].first.second = final_y;
            a[final_x][final_y] = 1;
        }

        //방향 dir에 넣기
        dir[i].push_back(temp_dir);
    }
    go();
    int num = 0;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(0<=i+1 && i+1<=100 && 0<=j+1 && j+1<=100){
                if(a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1){//네 꼭지점이 모두 드래곤 커브의 일부
                    num++;
                }
            }
        }
    }
    cout<<num<<"\n";
}