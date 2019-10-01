//격자판의 숫자 이어붙이기(dfs)
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int a[5][5] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visitednum[10000000];
int t;
int num_final, num;
vector<int> v;

void go(int x, int y, string value, int num){
    if(num<6){
        for(int i=0; i<4; i++){
            int final_x = dx[i] + x;
            int final_y = dy[i] + y;
            if(0<=final_x && final_x<4 && 0<=final_y && final_y<4){//방문은 했어도 상관 x
                go(final_x, final_y, value + to_string(a[final_x][final_y]), num+1);
            }
        }
    }
    if(num == 6){//vector에 저장해놓고, 새로운 애가 vector의 모든 값과 같지 않으면 vector에 추가!
        //모든 vector에 있는 값과 비교
        int temp = stoi(value);
        if(!visitednum[temp]){//같은게 아무것도 x
            visitednum[temp] = 1;
            num_final++;
        }
        return;
    }
}


int main (){
    cin>>t;
    for(int i=0; i<t; i++){//testcase만큼
        num_final = 0;
        for(int i =0; i<10000000; i++){
            visitednum[i] = 0;
        }
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cin>>a[j][k];
            }
        }
        //다른 테케 넘어가기 전에 계산해주기!

        for(int h=0; h<4; h++){
            for(int l=0; l<4; l++){
                go(h,l, to_string(a[h][l]), 0);
            }
        }
        v.push_back(num_final);
    }

    for(int i=0; i<t; i++){//testcase만큼
        cout<<"#"<<i+1<<" "<<v[i]<<"\n";
    }
}