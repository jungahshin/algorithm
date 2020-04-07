// 4112. 이상한 피라미드 탐험
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int testcase, a, b, r;
int visited[10100] = {0, };
int DP[200] = {0, };//층에 따른 가장 첫 번째 숫자
int final = 0;

void go(int r, int room){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(r, 0), room));

    while(!q.empty()){
        int hang = q.front().first.first;//행
        int time_ = q.front().first.second;
        int num = q.front().second;
        visited[num] = 1;
        q.pop();

        if(num == b){
            final = time_;
            break;
        }

        //r행과 r-1행 r+1행의 범위? 구하기
        int temp = 1;
        int one, two, three;
        int num_ = 0;
        if(DP[hang] != 0){
            one = DP[hang]-hang;
            two = DP[hang];
            three = DP[hang]+hang+1;
            DP[hang+1] = three;
            if(hang-1>=0){
                DP[hang-1] = one;                
            }
        }
        if(hang == 0){
            one = 0;
        }

        //-r
        int final_hang_1 = num-hang;
        if(one<=final_hang_1 && final_hang_1<=one+hang-1 && final_hang_1<=10000){
            if(!visited[final_hang_1]){
                visited[final_hang_1] = 1;
                q.push(make_pair(make_pair(hang-1, time_+1), final_hang_1));                
            }
        }
        //-(r+1)
        int final_hang_2 = num-(hang+1);
        if(one<=final_hang_2 && final_hang_2<=one+hang-1 && final_hang_2<=10000){
            if(!visited[final_hang_2]){
                visited[final_hang_2] = 1;
                q.push(make_pair(make_pair(hang-1, time_+1), final_hang_2));                
            }
        }
        //-1
        int final_hang_3 = num-1;
        if(two<=final_hang_3 && final_hang_3<=two+hang && final_hang_3<=10000){
            if(!visited[final_hang_3]){
                visited[final_hang_3] = 1;
                q.push(make_pair(make_pair(hang, time_+1), final_hang_3));                
            }
        }
        //+1
        int final_hang_4 = num+1;
        if(two<=final_hang_4 && final_hang_4<=two+hang && final_hang_4<=10000){
            if(!visited[final_hang_4]){
                visited[final_hang_4] = 1;
                q.push(make_pair(make_pair(hang, time_+1), final_hang_4));                
            }
        }
        //+(r+1)
        int final_hang_5 = num+(hang+1);
        if(three<=final_hang_5 && final_hang_5<=three+hang+1 && final_hang_5<=10000){
            if(!visited[final_hang_5]){
                visited[final_hang_5] = 1;
                q.push(make_pair(make_pair(hang+1, time_+1), final_hang_5));
            }
        }
        //+(r+2)
        int final_hang_6 = num+(hang+2);
        if(three<=final_hang_6 && final_hang_6<=three+hang+1 && final_hang_6<=10000){
            if(!visited[final_hang_6]){
                visited[final_hang_6] = 1;
                q.push(make_pair(make_pair(hang+1, time_+1), final_hang_6));                
            }
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        memset(visited, 0, sizeof(visited));
        memset(DP, 0, sizeof(DP));
        cin>>a>>b;//민지와 보물의 위치
        //민지의 행을 찾는다.
        int temp = 1;
        int num = 0;
        while(1){
            DP[num] = temp;
            if(a<temp){
                r = num-1;
                break;
            }
            num++;
            temp += num;
        }
        go(r, a);
        cout<<final<<"\n";
    }
}