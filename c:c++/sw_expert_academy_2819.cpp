//격자판의 숫자 이어붙이기(bfs)
//시간 초과....
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[5][5] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<string> v;
int t;

void go(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            //격자마다 한 번씩 돈다.
            queue<pair<pair<int, int>, string>> q;
            queue<int> num_q;
            q.push(make_pair(make_pair(i, j), to_string(a[i][j])));
            num_q.push(0);
            
            while(!q.empty() && !num_q.empty()){
                int x = q.front().first.first;
                int y = q.front().first.second;
                string value = q.front().second;
                int num = num_q.front();
                q.pop();
                num_q.pop();

                if(num>6){
                    continue;
                }
                if(num<6){
                    for(int i=0; i<4; i++){
                        int final_x = dx[i] + x;
                        int final_y = dy[i] + y;
                        // cout<<"f"<<final_x<<"/"<<final_y<<"\n";
                        if(0<=final_x && final_x<4 && 0<=final_y && final_y<4){//방문은 했어도 상관 x
                            q.push(make_pair(make_pair(final_x, final_y), value + to_string(a[final_x][final_y])));
                            num_q.push(num+1);
                        }
                    }
                }else if(num == 6){//vector에 저장해놓고, 새로운 애가 vector의 모든 값과 같지 않으면 vector에 추가!
                    if(v.size() == 0){//처음 값이면
                        v.push_back(value);
                    }else{
                        //모든 vector에 있는 값과 비교
                        int num_temp = 0;
                        for(int i=0; i<v.size(); i++){
                            if(v[i] == value){//같으면
                                num_temp++;
                            }
                        }
                        if(num_temp == 0){//같은게 아무것도 x
                            v.push_back(value);
                        }
                    }
                }
            }
        }
    }
}

int main (){
    cin>>t;
    for(int i=0; i<t; i++){//testcase만큼
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cin>>a[j][k];
            }
        }
        //다른 테케 넘어가기 전에 계산해주기!
        v.clear();
        go();
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i]<<"\n";
        // }
        cout<<"#"<<i+1<<" "<<v.size()<<"\n";
    }

}