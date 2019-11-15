//⚾
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int seq[10] = {0, };
int visited[10] = {0, };
int a[51][10] = {0, };//행->n(이닝 수), 열(선수 번호, 타수 x)
int n, sequence;
int final = 0;

void play(){//seq[1] ~ seq[9]에 지정된 선수 번호에 맞게 play진행된다.
    vector<int> v;
    //벡터에 값 넣어주기
    for(int i=1; i<4; i++){
        v.push_back(seq[i]);
    }
    v.push_back(1);
    for(int i=4; i<=8; i++){
        v.push_back(seq[i]);
    }
    int score = 0;
    int k=1;
    queue<int> q;
    q.push(0);
    q.push(0);
    q.push(0);
    for(int i=0; i<n; i++){//이닝 수만큼 반복
        int out = 0;
        while(out<3){//아웃이 3개보다 작으면 계속 이닝을 멈추지 않고 진행한다.
            // int k=1;
            for(int j=k; j<=9; j++){//seq[j]가 선수 번호-->이걸로 a배열에 접근하기
                if(a[i][(v[j-1])] == 0){//아웃
                    out++;
                }else if(a[i][(v[j-1])] == 1){//안타(1루타)
                    int x = q.front();
                    if(x == 1){
                        score++;
                    }
                    q.pop();
                    q.push(1);
                }else if(a[i][(v[j-1])] == 2){//2루타
                    for(int h=0; h<2; h++){
                        int x = q.front();
                        if(x == 1){
                            score++;
                        }
                        q.pop();
                    }
                    q.push(1);
                    q.push(0);
                }else if(a[i][(v[j-1])] == 3){//3루타
                    for(int h=0; h<3; h++){
                        int x = q.front();
                        if(x == 1){
                            score++;
                        }
                        q.pop();
                    }
                    q.push(1);
                    q.push(0);
                    q.push(0);
                }else if(a[i][(v[j-1])] == 4){//홈런
                    for(int h=0; h<3; h++){
                        int x = q.front();
                        if(x == 1){
                            score++;
                        }
                        q.pop();
                    }
                    score++;
                    q.push(0);
                    q.push(0);
                    q.push(0);
                }
                if(out>=3){//3개 이상이면 이닝 끝난다.
                    //몇 타수까지 했는지 저장하기
                    if(j == 9){
                        k = 1;
                    }else{
                        k = j+1;                  
                    }
                    break;
                }
                if(j == 9){
                    k = 1;
                }
            }
        }
        //q비우기
        while(!q.empty()){
            q.pop();
        }
        q.push(0);
        q.push(0);
        q.push(0);
    }
    final = max(final, score);
}

void combin(int idx, int num, int sequence){//타순 정하기(4번 타순 빼고)
    if(num == 1){
        seq[sequence] = idx;//그 순서에 그 idx번의 선수가 지정된다.
        if(sequence == 8){
            play();
        }
        combin(1, 0, sequence);
    }

    for(int i=idx; i<10; i++){//선수 의미
        if(visited[i] == 1) continue;
        visited[i] = 1;
        sequence++;//순서를 의미

        combin(i, num+1, sequence);
        visited[i] = 0;
        sequence--;
    }
}

int main(){
    cin>>n;//이닝 수
    for(int i=0; i<n; i++){
        for(int j=1; j<=9; j++){//9명의 선수(1번~9번), 1번 선수는 이미 4번 타자로 확정
            cin>>a[i][j];
        }
    }
    seq[4] = 1;//4번 타자는 이미 1번 선수로 지정
    visited[1] = 1;
    combin(1, 0, 0);//순열 

    cout<<final<<"\n";
}