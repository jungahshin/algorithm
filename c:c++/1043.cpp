//거짓말
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> lie;//lie[1] = 1이면 1번은 진실을 들은 것, lie[1] = 0이면 거짓을 들은 것
vector<int> party[51];//각 파티마다 참석하는 사람
vector<int> per[51];//각 사람마다 참석하는 파티
int total = 0;
int n, m, k, t, num, z;
int visited[51] = {0, };//각 파티에 방문한 여부
vector<int> real;//진실을 아는 사람들

void go(int person){//진실 말하기 -> total을 줄여나가는 식으로
    for(int i=0; i<per[person].size(); i++){
        int par = per[person][i];
        if(!visited[par]){
            visited[par] = 1;
            total--;
            for(int j=0; j<party[par].size(); j++){
                lie[party[par][j]] = 1;
                go(party[par][j]);
            }            
        }
    }
}

int main(){
    cin>>n>>m;//사람 수, 파티 수
    cin>>k;//진실을 아는 사람 수
    for(int i=0; i<k; i++){
        cin>>t;
        lie[t] = 1;
        real.push_back(t);
    }
    total = m;
    //한 명이라도 진실을 아는 사람이 있다 -> 진실말하기
    //한 명이라도 거짓을 아는 사람이 있다 -> 거짓말하기
    for(int i=0; i<m; i++){
        cin>>num;
        for(int j=0; j<num; j++){
            cin>>z;
            party[i].push_back(z);//파티에 참석한 사람
            per[z].push_back(i);//그 사람이 참석한 파티
        }
    }

    //미리 이미 진실을 아는 사람이 있는 파티에는 진실을 말해놓고 시작
    for(int i=0; i<real.size(); i++){
        int person = real[i];
        for(int j=0; j<per[person].size(); j++){
            int par = per[person][j];//진실을 아는 사람이 참석한 파티
            if(!visited[par]){
                visited[par] = 1;
                total--;
                for(int w=0; w<party[par].size(); w++){
                    lie[party[par][w]] = 1;
                    go(party[par][w]);
                }                
            }
        }
    }

    cout<<total<<"\n";
    return 0;
}