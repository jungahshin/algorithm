//스타트와 링크
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int n;
int a[21][21] = {0, };
int visited[21] = {0, };
int visited_[21] = {0, };
int visited_1[21] = {0, };
int final = 0;
int final_ = 0;
vector<int> v;
vector<int> v_;
vector<int> v_final;
vector<int> v_final_;
int real_final = INT_MAX;
//인원수는 무조건 n/2로 나눠야 한다.

void cal_2(){
    v_final.clear();
    for(int i=0; i<n; i++){
        if(visited_[i] == true){
            v_final.push_back(i);
        }
    }
    final += a[(v_final[0])][(v_final[1])];
    final += a[(v_final[1])][(v_final[0])];
}

void go_2(int num, int idx){//n/2중에서 2개를 뽑는다.
    if(num == 2){
        cal_2();
        return;
    }

    for(int i=idx; i<v.size(); i++){
        if(visited_[v[i]] == true) continue;
        visited_[v[i]] = true;

        go_2(num+1, i);
        visited_[v[i]] = false;
    }
}

void cal_3(){
    v_final_.clear();
    for(int i=0; i<n; i++){
        if(visited_1[i] == true){
            v_final_.push_back(i);
        }
    }
    final_ += a[(v_final_[0])][(v_final_[1])];
    final_ += a[(v_final_[1])][(v_final_[0])];
}

void go_3(int num, int idx){
    if(num == 2){
        cal_3();
        return;
    }

    for(int i=idx; i<v_.size(); i++){
        if(visited_1[v_[i]] == true) continue;
        visited_1[v_[i]] = true;

        go_3(num+1, i);
        visited_1[v_[i]] = false;
    }
}

void cal(){
    v.clear();
    v_.clear();
    for(int i=0; i<n; i++){
        if(visited[i] == true){//스타트팀
            v.push_back(i);
        }else{
            v_.push_back(i);
        }
    }
    memset(visited_1, 0, sizeof(visited_1));
    final_ = 0;
    go_3(0, 0);
    memset(visited_, 0, sizeof(visited_));
    final = 0;
    go_2(0, 0);
    real_final = min(abs(final-final_), real_final);
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