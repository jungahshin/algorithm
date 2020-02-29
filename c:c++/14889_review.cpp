//스타트와 링크
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int n;
int a[21][21] = {0, };
int visited[21] = {0, };
int start[21] = {0, };
int link[21] = {0, };
int start_final = 0;
int link_final = 0;
vector<int> start_v;
vector<int> link_v;
vector<int> start_v_final;
vector<int> link_v_final;
int real_final = INT_MAX;
//인원수는 무조건 n/2로 나눠야 한다.

void cal_2(){
    start_v_final.clear();
    for(int i=0; i<n; i++){
        if(start[i] == true){
            start_v_final.push_back(i);
        }
    }
    start_final += a[(start_v_final[0])][(start_v_final[1])];
    start_final += a[(start_v_final[1])][(start_v_final[0])];
}

void go_2(int num, int idx){//n/2중에서 2개를 뽑는다.
    if(num == 2){
        cal_2();
        return;
    }

    for(int i=idx; i<start_v.size(); i++){
        if(start[start_v[i]] == true) continue;
        start[start_v[i]] = true;

        go_2(num+1, i);
        start[start_v[i]] = false;
    }
}

void cal_3(){
    link_v_final.clear();
    for(int i=0; i<n; i++){
        if(link[i] == true){
            link_v_final.push_back(i);
        }
    }
    link_final += a[(link_v_final[0])][(link_v_final[1])];
    link_final += a[(link_v_final[1])][(link_v_final[0])];
}

void go_3(int num, int idx){
    if(num == 2){
        cal_3();
        return;
    }

    for(int i=idx; i<link_v.size(); i++){
        if(link[link_v[i]] == true) continue;
        link[link_v[i]] = true;

        go_3(num+1, i);
        link[link_v[i]] = false;
    }
}

void cal(){
    start_v.clear();
    link_v.clear();
    for(int i=0; i<n; i++){
        if(visited[i] == true){//스타트팀
            start_v.push_back(i);
        }else{
            link_v.push_back(i);
        }
    }
    memset(link, 0, sizeof(link));
    link_final = 0;
    go_3(0, 0);
    memset(start, 0, sizeof(start));
    start_final = 0;
    go_2(0, 0);
    real_final = min(abs(start_final-link_final), real_final);
}

void go(int num, int idx){
    if(num == (n/2)){
        cal();
        return;
    }

    for(int i=idx; i<n; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        go(num+1, i);
        visited[i] = false;
    }
}

int main(){
    cin>>n;//짝수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    go(0, 0);
    cout<<real_final<<"\n";
}