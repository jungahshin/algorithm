#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[52][52] = {0, };
int a_copy[52][52] = {0, };
int n, m, t, d, b, c;
vector<pair<pair<int, int>, int>> v;//t번 돌릴거 저장
int visited[52][52] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = 0;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
        a_copy[i][m] = a[i][0];
        a[i][m] = a[i][0];
    }
}

bool go_2(){//중복 없애기 1~m까지 돌리기(열)
    bool check = false;
    queue<pair<int, int>> q;
    for(int i=0; i<52; i++){
        for(int j=0; j<52; j++){
            visited[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m+1; j++){
            q.push(make_pair(i, j));
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y] = 1;
                q.pop();

                for(int k=0; k<4; k++){
                    int final_x = x+dx[k];
                    int final_y = y+dy[k];
                    if(0 <= final_x && final_x < n && 0 <= final_y && final_y < m+1){
                        if(a_copy[x][y] != 0 && a_copy[x][y] == a_copy[final_x][final_y] && !visited[final_x][final_y]){
                            check = true;
                            visited[final_x][final_y] = 1;
                            a[x][y] = 0;
                            a[final_x][final_y] = 0;
                            q.push(make_pair(final_x, final_y));
                        }                        
                    }
                }                
            }
        }
    }
    for(int i=0; i<n; i++){
        if(a[i][m] == 0){
            a[i][0] = 0;
        }
    }
    while(!q.empty()){
        q.pop();
    }

    return check;
}

void go(){
    for(int i=0; i<t; i++){
        //원판 돌리기
        for(int j=0; j<n; j++){//원판 번호
            if((j+1) % v[i].first.first == 0){//해당되면 돌린다.
                if(v[i].first.second == 0){//시계방향
                    for(int k=0; k<v[i].second; k++){//칸 수만큼 돌린다.
                        int temp_1[51] = {0, };
                        for(int h=0; h<m-1; h++){
                            temp_1[h+1] = a[j][h]; 
                        }
                        temp_1[0] = a[j][m-1];
                        for(int h=0; h<m; h++){
                            a[j][h] = temp_1[h];
                        }
                    }
                }else if(v[i].first.second == 1){//반시계 방향
                    for(int k=0; k<v[i].second; k++){
                        int temp_2[51] = {0, };
                        for(int h=1; h<m; h++){
                            temp_2[h-1] = a[j][h];
                        }
                        temp_2[m-1] = a[j][0];
                        for(int h=0; h<m; h++){
                            a[j][h] = temp_2[h];
                        }
                    }
                }
            }
        }
        copy();
        //평균 구하기
        if(go_2() == false){//해당 안되면
            int total = 0;//총합
            int num = 0;//수
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    if(a[j][k] != 0){
                        total += a[j][k];
                        num++;
                    }
                }
            }
            if(total != 0){
                float average = (float)total/(float)num;
                for(int j=0; j<n; j++){
                    for(int k=0; k<m; k++){
                        if(a[j][k] > average){
                            a[j][k] -= 1;
                        }else if(a[j][k] < average && a[j][k] != 0){
                            a[j][k] += 1;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>t;
    for(int i=0; i<n; i++){//원판
        for(int j=0; j<m; j++){//원판 안의 수
            cin>>a[i][j];
        }

    }
    for(int i=0; i<t; i++){
        cin>>d>>b>>c;//배수, 방향, 칸 수
        v.push_back(make_pair(make_pair(d, b), c));
    }
    go();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            final += a[i][j];
        }
    }
    cout<<final<<"\n";
}