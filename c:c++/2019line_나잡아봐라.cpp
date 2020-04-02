//2019 라인 상반기 인턴 기출
#include <iostream>
#include <queue>
using namespace std;

int visited[10000][200000] = {0, };
int final_time = 0;
bool check = false;
int b, c;

void bfs(int c, int b){
    int num = 0;//각 time마다 증가할 수
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(b, 0), make_pair(c, 0)));

    while(!q.empty()){
        int brown = q.front().first.first;//브라운의 위치
        int time_ = q.front().first.second;
        int corney = q.front().second.first;//코니의 위치
        int num = q.front().second.second;//증가하는 수
        q.pop();

        if(corney > 200000){//코니가 범위를 벗어났다..
            check = true;
            break;
        }

        if(corney == brown){
            final_time = time_;
            break;
        }

        //B-1
        int final_x1 = brown-1;
        if(0<=final_x1 && final_x1<=200000 && !visited[time_+1][final_x1]){
            visited[time_+1][final_x1] = 1;
            q.push(make_pair(make_pair(final_x1, time_+1), make_pair(corney+num+1, num+1)));
        }

        //B+1
        int final_x2 = brown+1;
        if(0<=final_x2 && final_x2<=200000 && !visited[time_+1][final_x2]){
            visited[time_+1][final_x2] = 1;
            q.push(make_pair(make_pair(final_x2, time_+1), make_pair(corney+num+1, num+1)));
        }

        //2*B
        int final_x3 = 2*brown;
        if(0<=final_x3 && final_x3<=200000 && !visited[time_+1][final_x3]){
            visited[time_+1][final_x3] = 1;
            q.push(make_pair(make_pair(final_x3, time_+1), make_pair(corney+num+1, num+1)));
        }
    }
}

int main(){
    cin>>c>>b;//코니와 브라운
    bfs(c, b);
    if(check == true){
        cout<<"-1"<<"\n";
    }else{
        cout<<final_time<<"\n";        
    }
    return 0;
}