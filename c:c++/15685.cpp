//드래곤 커브
#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> v;//위치 저장
int a[101][101] = {0, };
int final = 0;
int n, x, y, d, g;
vector<int> temp;

void go(){//드래곤 커브 완성하기
    for(int h=0; h<v.size(); h++){
        //x, y, d, g
        //일단 기본적으로 0원소를 넣어준다.
        temp.push_back(v[h].second.first);
        for(int i=0; i<v[h].second.second; i++){//이어 붙이기
            for(int j=temp.size()-1; j>=0; j--){
                if(temp[j]+1>3){
                    temp.push_back(0);
                }else{
                    temp.push_back(temp[j]+1);
                }
            }
        }
        int temp_x = v[h].first.first;
        int temp_y = v[h].first.second;
        a[temp_x][temp_y] = 1;
        for(int i=0; i<temp.size(); i++){
            if(temp[i] == 0){//x+, y0
                a[++temp_x][temp_y] = 1;
            }else if(temp[i] == 1){//x0, y-
                a[temp_x][--temp_y] = 1;
            }else if(temp[i] == 2){//x-, y0
                a[--temp_x][temp_y] = 1;
            }else if(temp[i] == 3){//x0, y+
                a[temp_x][++temp_y] = 1;
            }
        }
        temp.clear();
    }
}

int main(){
    cin>>n;//드래곤 커브의 갯수
    for(int i=0; i<n; i++){
        cin>>x>>y>>d>>g;//좌표, 방향, 세대
        v.push_back(make_pair(make_pair(x, y), make_pair(d, g)));//드래곤 커브 시작점 넣기
    }
    go();
    //정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(a[i][j] == 1 && a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1){
                final++;
            }
        }
    }
    cout<<final<<"\n";
}