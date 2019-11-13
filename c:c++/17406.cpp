//배열 돌리기4
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int a[52][52] = {0, };
int a_copy[52][52] = {0, };
vector<pair<pair<int, int>, int>> v;//r, c, s저장
int visited[7] = {0, };
int n, m, k, r, c, s;
int seq[7] = {0, };
int final = INT_MAX;

void copy(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
}

void play(){
    //seq에 들어있는 idx순으로 진행한다.
    for(int h=0; h<v.size(); h++){
        int idx = seq[h];
        int x = v[idx].first.first - v[idx].second;
        int y = v[idx].first.second - v[idx].second;
        int e = v[idx].first.first + v[idx].second;
        int f = v[idx].first.second + v[idx].second;
        int z = (v[idx].second * 2)+1;//정사각형의 크기
        int num = (z/2);
        for(int i=0; i<num; i++){
            vector<int> put;
            queue<int> put_temp;
            put.clear();
            for(int j=0; j<z-1; j++){//위(열++)
                put.push_back(a_copy[x][y+j]);
            }
            for(int j=0; j<z-1; j++){//오 (행++)
                put.push_back(a_copy[x+j][f]);
            }
            for(int j=f; j>=y+1; j--){
                put.push_back(a_copy[e][j]);
            }
            for(int j=e; j>=x+1; j--){
                put.push_back(a_copy[j][y]);
            }
            //한 칸씩 시계방향으로 이동
            put_temp.push(put[put.size()-1]);
            for(int j=0; j<put.size()-1; j++){
                put_temp.push(put[j]);
            }
            //put_temp의 값들을 차례대로 넣는다. ------------------------------>여기 부터!!!!
            for(int j=0; j<z-1; j++){//위(열++)
                a_copy[x][y+j] = put_temp.front();
                put_temp.pop();
            }
            for(int j=0; j<z-1; j++){//오 (행++)
                a_copy[x+j][f] = put_temp.front();
                put_temp.pop();
            }
            for(int j=f; j>=y+1; j--){
                a_copy[e][j] = put_temp.front();
                put_temp.pop();
            }
            for(int j=e; j>=x+1; j--){
                a_copy[j][y] = put_temp.front();
                put_temp.pop();
            }
            z -= 2;//정사각형의 크기 -2
            x += 1;//가장 왼쪽 위 부분 행 +1
            y += 1;//가장 왼쪽 위 부분 열 +1
            e -= 1;
            f -= 1;
        }        
    }
    //A값 계산하기!
    int temp_final = INT_MAX;
    for(int i=1; i<=n; i++){
        int temp = 0;
        for(int j=1; j<=m; j++){
            temp += a_copy[i][j];
        }
        temp_final = min(temp_final, temp);
    }
    final = min(final, temp_final);
}

void combin(int idx, int num, int sequence){//v.size()만큼 진행
    if(num == 1){
        seq[sequence-1] = idx;
        if(sequence == v.size()){
            copy();
            play();
        }
        combin(0, 0, sequence);
        return;
    }
    for(int i=idx; i<v.size(); i++){
        if(visited[i] == 1) continue;
        sequence++;
        visited[i] = 1;

        combin(i, num+1, sequence);
        sequence--;
        visited[i] = 0;
    }
    
}

int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>r>>c>>s;
        v.push_back(make_pair(make_pair(r, c), s));
    }
    combin(0, 0, 0);
    cout<<final<<"\n";
}