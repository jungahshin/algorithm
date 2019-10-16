//스타트와 링크
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int a[21][21] = {0, };
vector<int> v;//모든 참가자 저장
vector<int> s;//스타트팀
vector<int> l;//링크팀
bool visited[21];
bool visited_s[11];
bool visited_l[11];
int final = INT_MAX;
int start;
int link;
vector<int> final_s;
vector<int> final_l;
int n;

void put_s(){
    //계산하기
    final_s.clear();
    for(int i=0; i<s.size(); i++){
        if(visited_s[i] == true){
            final_s.push_back(s[i]);
        }
    }
    start += a[final_s[0]][final_s[1]];
    start += a[final_s[1]][final_s[0]];
}

void choose_s(int idx, int num){
    if(num == 2){
        put_s();//계산하기
        return;
    }
    for(int i=idx; i<s.size(); i++){
        if(visited_s[i] == true) continue;
        visited_s[i] = true;

        choose_s(i, num+1);
        visited_s[i] = false;
    }
}

void put_l(){
    //계산하기
    final_l.clear();
    for(int i=0; i<l.size(); i++){
        if(visited_l[i] == true){
            final_l.push_back(l[i]);
        }
    }
    link += a[final_l[0]][final_l[1]];
    link += a[final_l[1]][final_l[0]];
}

void choose_l(int idx, int num){
    if(num == 2){
        put_l();//계산하기
        return;
    }
    for(int i=idx; i<l.size(); i++){
        if(visited_l[i] == true) continue;
        visited_l[i] = true;

        choose_l(i, num+1);
        visited_l[i] = false;
    }
}

void go(){//각각 팀원들의 능력치를 더해서 차이가 가장 적은 것
    //여기서도 2명씩 조합..진행
    start = 0;
    link = 0;
    choose_s(0, 0);
    choose_l(0, 0);
    final = min(final, abs(start-link));
}

void put(){//스타트팀과 링크팀 벡터에 각각 넣기
    s.clear();
    l.clear();
    for(int i=0; i<v.size(); i++){
        if(visited[i] == true){
            s.push_back(v[i]);
        }else if(visited[i] == false){
            l.push_back(v[i]);
        }
    }
    go();
}

void choose(int idx, int num){
    if(num == n/2){
        put();
        return;
    }

    for(int i=idx; i<v.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        choose(i, num+1);
        visited[i] = false;
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    choose(0, 0);

    cout<<final<<"\n";
    return 0;
}