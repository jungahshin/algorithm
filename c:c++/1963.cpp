//가장 대표적인 bfs로 풀 수 있는 문제
//자리 수를 기준으로 해서 한 자리수를 바꿔서 나오는 숫자가 1000이상, 소수, 방문한 적 없을 경우 큐에 저장
//맨 처음에 모든 4자리 수의 소수 여부를 먼저 판별해서 소수이면 1, 아니면 0의 값을 벡터에 저장
//맨 처음 큐에는 처음 입력값과 num(몇 번째)인지 0값을 pair로 넣는다.
//q.front().first는 4자리 값
//q.front().second는 num(몇 번째)이다.

//함수는 main, 한 자리수를 바꿔주는 함수
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int testcase, start, finish;
int discrimination[10001] = {0,};
vector<string> final;

int change(int start, int a, int b){//한 자리 수를 바꿔주는 함수,a-몇 번째 자리,b-어떤 숫자로
    if(a == 1){
        start -= (start/1000)*1000;
        start += b*1000;
    }else if(a == 2){
        start -= ((start/100)%10)*100;
        start += b*100;
    }else if(a == 3){
        start -= ((start%100)/10)*10;
        start += b*10;
    }else if(a == 4){
        start -= ((start%100)%10);
        start += b;
    }
    return start;
}

int main(){
    cin>>testcase;

    for(int j=1000; j<10000; j++){//4자리수 전체를 소수 판별
        discrimination[j] = 1;
        for(int i=2; i<j; i++){
            if((j % i ) == 0){//소수
                discrimination[j] = 0;
                break;
            }
        }
    }

    for(int i=0; i<testcase; i++){
        int visited[10001] = {0, };
        bool possible = false;
        cin>>start>>finish;
        
        int num;
        queue<pair<int, int>> q;
        q.push(make_pair(start, 0));
        visited[start] = 1;
    
        while(!q.empty()){
            int c = q.front().first;
            num = q.front().second;

            q.pop();

            if(c == finish){
                // cout<<"\n"<<num<<"\n";
                final.push_back(to_string(num));
                possible = true;
                break;
            }

            int z = 0;
            for(int i=1; i<=4; i++){
                for(int j=0; j<=9; j++){
                    int z = change(c, i, j);
                    
                    if(z<1000 || visited[z] || discrimination[z] == 0){//소수가 아니거나, 4자리수가 아니거나 방문한 적이 있으면 나간다.
                        continue;
                    }

                    visited[z] = 1;
                    q.push(make_pair(z, num+1));
                }
            }
        }
        if(possible == false){//아예 경우의 수가 없는 경우
            final.push_back("Impossible");
        }
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
    
}