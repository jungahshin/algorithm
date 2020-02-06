//게리맨더링 복습
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

//하나 방문하고 나머지 방문 안한애들이 모두 다 연결되면 두 구역으로 나눌 수 있는 것->이때, 인구 차이 계산
//일단 순열로 1~n-1까지 경우의 수 구하고 (1, n-1), (2, n-2), ...(n-1, 1)의 경우 각각 두 구역으로 나눌 수 있는 지(인접해 있는지 확인)
//두 구역으로 나눌 수 있으면 저장해놓은 인구수 비교 후 저장
int pop[11] = {0, };//각 구역 인구수 저장
int connect[11][11] = {0, };
int visited[11] = {0, };
int final = INT_MAX;
int n, population, num, area;
bool final_check = false;
vector<int> v;
vector<int> v_;

void go_2(){
    int visited_check_2[11] = {0, };
    queue<int> q;
    q.push(v_[0]);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        visited_check_2[x] = 1;

        for(int j=1; j<=n; j++){
            if(connect[x][j] == 1 && !visited_check_2[j] && !visited[j]){
                visited_check_2[j] = 1;
                q.push(j);
            }
        }
    }
    int temp = 0;
    for(int i=1; i<=n; i++){
        if(visited_check_2[i] == 1){
            temp++;
        }
    }
    if(v_.size() == temp){
        final_check = true;
        //2구역 다 인접해있다.
        //여기에서 인구 비교
        int one = 0;
        int two = 0;
        for(int k=1; k<=n; k++){
            if(visited[k] == true){
                one += pop[k];
            }else if(visited[k] == false){
                two += pop[k];
            }
        }
        final = min(final, abs(one-two));
    }
}

void go(){
    int visited_check[11] = {0, };
    queue<int> q;
    q.push(v[0]);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        visited_check[x] = 1;

        for(int j=1; j<=n; j++){
            if(connect[x][j] == 1 && !visited_check[j] && visited[j] == 1){
                q.push(j);
                visited_check[j] = 1;
            }
        }
    }
    int temp = 0;
    for(int i=1; i<=n; i++){
        if(visited_check[i] == 1){
            temp++;
        }
    }
    if(v.size() == temp){
        //1구역 다 인접 하였다.
        go_2();
    }else{
        return;
    }
}

void share(int final, int num, int idx){
    if(final == num){
        v.clear();
        v_.clear();
        for(int j=1; j<=n; j++){
            if(visited[j] == true){
                v.push_back(j);
            }else if(visited[j] == false){
                v_.push_back(j);
            }
        }
        //v벡터에 넣는 구역들이 모두 다 인접해 있는지 확인하기
        //v벡터에 있는 모든 구역들을 큐에 넣고 새로운 visited_check를 만들어서
        //visited_check하지 않았고 visited는 한 인접한 구역을 찾는다.
        //visited_check한 수가 visited한 수와 같다면 
        //이제 visited 안한 구역들이 다 인접한지 확인한다.
        go();
        return;
    }

    for(int i=idx; i<=n; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        share(final, num+1, i);
        visited[i] = false;
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>population;
        pop[i] = population;
    }
    for(int i=1; i<=n; i++){//i구역과 연결된 
        cin>>num;
        for(int j=0; j<num; j++){//j구역
            cin>>area;
            connect[i][area] = 1;
            connect[area][i] = 1;
        }
    }
    for(int i=1; i<n; i++){
        share(i, 0, 1);
    }
    if(final_check == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}