//사다리 조작
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h, a, b;
int A[31][11] = {0, };
int A_copy[31][11] = {0, };
vector<pair<int, int>> v;
bool visited[301];
vector<int> final;
int really_final = 0;

void copy(){
    for(int i=0; i<31; i++){
        for(int j=0; j<11; j++){
            A_copy[i][j] = A[i][j];
        }
    }
}

void dfs(int idx, int n){
    for(int i=n; i<=h; i++){
        if(A_copy[i][idx] == 1){
            idx++;
            dfs(idx, i+1);
            return;
        }else if(A_copy[i][idx-1] == 1){
            idx--;
            dfs(idx, i+1);
            return;
        }
    }
    //여기에 나오면 끝났다는 것!
    really_final = idx;
}

void prepare(int idx){
    int temp = 0; 
    for(int i=1; i<=n; i++){//세로선 기준
        dfs(i, 1);
        if(really_final == i){
            temp++;
        }
    }
    if(temp == n){//성공!
        final.push_back(idx);//사다리 개수 넣기
    }else{
        final.push_back(-1);
    }
}

void put(int idx){
    //가능한 경우의 수를 A_copy배열에 넣기
    copy();
    for(int i=0; i<v.size(); i++){
        if(visited[i] == true){
            A_copy[v[i].first][v[i].second] = 1;
        }
    }
    prepare(idx);
}   

void choose(int idx, int num, int choose_num){
    if(num == choose_num){
        put(choose_num);//dfs진행하기
        return;
    }
    for(int i=idx; i<v.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        
        choose(i, num+1, choose_num);
        visited[i] = false;
    }
}

void go(){//가능한 가로선 위치들 다 벡터에 넣기
    // if(n > 3){
    for(int i=1; i<=h; i++){//가장자리 부분
        for(int j=1; j<n; j++){
            if(A[i][j] == 0 && A[i][j-1] == 0 && A[i][j+1] == 0){
                v.push_back(make_pair(i, j));
            }
        }
    }
    for(int i=0; i<3; i++){//3개까지는 해보기
        for(int j=0; j<301; j++){
            visited[j] = false;
        }
        choose(0, 0, i+1);
    }
}

int main(){
    cin>>n>>m>>h;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        A[a][b] = 1;
    }
    go();
    //만약 모든 값이 -1이면 3보다 큰값이던가, 불가능한 경우이니 -1출력
    bool temp_final;
    for(int i=0; i<final.size(); i++){
        if(final[i] != -1){
            temp_final = true;
        }
    }
    if(m == 0){
        cout<<"0"<<"\n";
    }else{
        if(temp_final == false){//모두 -1값
            cout<<"-1"<<"\n";
        }else if(temp_final == true){//정렬을 했을 때에 맨 마지막 값이 -1이 아니면 -1값을 다 지우고 최소값을 출력한다.
            sort(final.begin(), final.end());
            for(int i=0; i<final.size(); i++){
                if(final[i] != -1){
                    cout<<final[i]<<"\n";
                    break;
                }
            }
        }        
    }

    return 0;
}