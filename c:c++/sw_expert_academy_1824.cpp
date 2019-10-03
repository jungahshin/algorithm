//혁진이의 프로그램 검증
//혁쎔블리어
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <tuple>
using namespace std;

int t, n, m;
char a[21][21];
// int num[] = {0,1,2,3,4,5,6,7,8,9};
int memory = 0;
bool visited[21][21][16][4];
string final;
vector<string> v;

bool hyuksembly(){
    memory = 0;
    queue<tuple<int, int, int>> q;//큐에 다음에 갈 위치 저장하기!
    q.push(make_tuple(0,0,3));//맨 처음 위치 넣기
    visited[0][0][0][3] = true;
    
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int dist = get<2>(q.front());
        // cout<<x<<"/"<<y<<"/"<<dist<<"\n";
        q.pop();

        //dir-0(상), 1(하), 2(좌), 3(우)
        //이동방향<,>,^, v, _, |, ?는 다음 위치를 큐에 푸시하고 나머지들을 그냥 다음(오른쪽 방향) 위치를 푸시
        // for(int number : num){//숫자
        if(a[x][y] == '0' || a[x][y] == '1' || a[x][y] == '2'|| a[x][y] == '3' || a[x][y] == '4' || a[x][y] == '5'|| a[x][y] == '6' || a[x][y] == '7' || a[x][y] == '8'|| a[x][y] == '9'){//0~9사이의 값이라면
            //메모리에 값을 넣는다.
            // cout<<"숫자"<<"\n";
            memory = a[x][y] - '0';
            if(y == m-1 && !visited[x][0][memory][dist]){//맨 오른쪽
                q.push(make_tuple(x, 0, dist));
                visited[x][0][memory][dist] = true;
            }else if(!visited[x][y+1][memory][dist]){
                q.push(make_tuple(x, y+1, dist));
                visited[x][y+1][memory][dist] = true;
            }
        }
        // }
        if(a[x][y] == '<'){//왼쪽 방향이동
            // cout<<"<"<<"\n";
            dist = 2;
            if(y == 0 && !visited[x][m-1][memory][dist]){//맨 왼쪽
                q.push(make_tuple(x, m-1, dist));
                visited[x][m-1][memory][dist] = true;
            }else if(!visited[x][y-1][memory][dist]){//맨 왼쪽이 아니라면
                q.push(make_tuple(x, y-1, dist));
                visited[x][y-1][memory][dist] = true;
            }
        }
        if(a[x][y] == '>'){//오른쪽 방향이동
            // cout<<">"<<"\n";
            dist = 3;
            if(y == m-1 && !visited[x][0][memory][dist]){//맨 오른쪽
                q.push(make_tuple(x, 0, dist));
                visited[x][0][memory][dist] = true;
            }else if(!visited[x][y+1][memory][dist]){
                q.push(make_tuple(x, y+1, dist));
                visited[x][y+1][memory][dist] = true;
            }
        }
        if(a[x][y] == '^'){//위쪽 방향이동
            // cout<<"^"<<"\n";
            dist = 0;
            if(x == 0 && !visited[n-1][y][memory][dist]){//맨 위쪽
                q.push(make_tuple(n-1, y, dist));
                visited[n-1][y][memory][dist] = true;
            }else if(!visited[x-1][y][memory][dist]){
                q.push(make_tuple(x-1, y, dist));
                visited[x-1][y][memory][dist] = true;
            }
        }
        if(a[x][y] == 'v'){//아래쪽 방향이동
            // cout<<"v"<<"\n";
            dist = 1;
            if(x == n-1 && !visited[0][y][memory][dist]){//맨 아래쪽
                q.push(make_tuple(0, y, dist));
                visited[0][y][memory][dist] = true;
            }else if(!visited[x+1][y][memory][dist]){
                q.push(make_tuple(x+1, y, dist));
                visited[x+1][y][memory][dist] = true;
            }
        }
        if(a[x][y] == '_'){//메모리에 0이 저장되어 있으면 이동 방향을 오른쪽으로 바꾸고, 아니면 왼쪽으로 바꾼다.
            // cout<<"___"<<"\n";
            if(memory == 0){
                //이동방향 오른쪽으로
                dist = 3;
                if(y == m-1 && !visited[x][0][memory][dist]){//맨 오른쪽
                    q.push(make_tuple(x, 0, dist));
                    visited[x][0][memory][dist] = true;
                }else if(!visited[x][y+1][memory][dist]){
                    q.push(make_tuple(x, y+1, dist));
                    visited[x][y+1][memory][dist] = true;
                }
            }else{//이동방향 왼쪽으로
                dist = 2;
                if(y == 0 && !visited[x][m-1][memory][dist]){//맨 왼쪽
                    q.push(make_tuple(x, m-1, dist));
                    visited[x][m-1][memory][dist] = true;
                }else if(!visited[x][y-1][memory][dist]){//맨 왼쪽이 아니라면
                    q.push(make_tuple(x, y-1, dist));
                    visited[x][y-1][memory][dist] = true;
                }
            }
        }
        if(a[x][y] == '|'){//메모리에 0이 저장되어 있으면 이동 방향을 아래쪽으로 바꾸고, 아니면 위쪽으로 바꾼다.
            // cout<<"|"<<"\n";
            if(memory == 0){
                //이동방향 아래쪽으로
                dist = 1;
                if(x == n-1 && !visited[0][y][memory][dist]){//맨 아래쪽
                    q.push(make_tuple(0, y, dist));
                    visited[0][y][memory][dist] = true;
                }else if(!visited[x+1][y][memory][dist]){
                    q.push(make_tuple(x+1, y, dist));
                    visited[x+1][y][memory][dist] = true;
                }
            }else{//이동방향 위쪽으로
                dist = 0;
                if(x == 0 && !visited[n-1][y][memory][dist]){//맨 위쪽
                    q.push(make_tuple(n-1, y, dist));
                    visited[n-1][y][memory][dist] = true;
                }else if(!visited[x-1][y][memory][dist]){
                    q.push(make_tuple(x-1, y, dist));
                    visited[x-1][y][memory][dist] = true;
                }
            }
        }
        if(a[x][y] == '?'){//이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
            // cout<<"?"<<"\n";
            for(int temp=0; temp<4; temp++){
                if(temp == 0){//상
                    if(x == 0 && !visited[n-1][y][memory][0]){//맨 위쪽
                        q.push(make_tuple(n-1, y, 0));
                        visited[n-1][y][memory][0] = true;
                    }else if(!visited[x-1][y][memory][0]){
                        q.push(make_tuple(x-1, y, 0));
                        visited[x-1][y][memory][0] = true;
                    }
                }else if(temp == 1){//하
                    if(x == n-1 && !visited[0][y][memory][1]){//맨 아래쪽
                        q.push(make_tuple(0, y, 1));
                        visited[0][y][memory][1] = true;
                    }else if(!visited[x+1][y][memory][1]){
                        q.push(make_tuple(x+1, y, 1));
                        visited[x+1][y][memory][1] = true;
                    }
                }else if(temp == 2){//좌
                    if(y == 0 && !visited[x][m-1][memory][2]){//맨 왼쪽
                        q.push(make_tuple(x, m-1, 2));
                        visited[x][m-1][memory][2] = true;
                    }else if(!visited[x][y-1][memory][2]){//맨 왼쪽이 아니라면
                        q.push(make_tuple(x, y-1, 2));
                        visited[x][y-1][memory][2] = true;
                    }
                }else{//우
                    if(y == m-1 && !visited[x][0][memory][3]){//맨 오른쪽
                        q.push(make_tuple(x, 0, 3));
                        visited[x][0][memory][3] = true;
                    }else if(!visited[x][y+1][memory][3]){
                        q.push(make_tuple(x, y+1, 3));
                        visited[x][y+1][memory][3] = true;
                    }
                }
            }
        }
        if(a[x][y] == '.'){//아무것도 하지 않는다.
            // cout<<"."<<"\n";
            if(y == m-1 && !visited[x][0][memory][dist]){//맨 오른쪽
                q.push(make_tuple(x, 0, dist));
                visited[x][0][memory][dist] = true;
            }else if(!visited[x][y+1][memory][dist]){
                q.push(make_tuple(x, y+1, dist));
                visited[x][y+1][memory][dist] = true;
            }
        }
        if(a[x][y] == '@'){//프로그램 실행 정지!
            // cout<<"@"<<"\n";
            return true;
        }
        if(a[x][y] == '+'){//메모리에 저장된 값에 1을 더한다. 만약 더하기 전 값이 15이라면 0으로 바꾼다.
            // cout<<"+"<<"\n";
            if(memory == 15){
                memory = 0;
                // if(dist ==)
                // if(y == m-1 && !visited[x][0][memory][dist]){//맨 오른쪽
                //     q.push(make_tuple(x, 0, dist));
                //     visited[x][0][memory][dist] = true;
                // }else if(!visited[x][y+1][memory][dist]){
                //     q.push(make_tuple(x, y+1, dist));
                //     visited[x][y+1][memory][dist] = true;
                // }
                if(dist == 0){//상
                    if(x == 0 && !visited[n-1][y][memory][0]){//맨 위쪽
                        q.push(make_tuple(n-1, y, 0));
                        visited[n-1][y][memory][0] = true;
                    }else if(!visited[x-1][y][memory][0]){
                        q.push(make_tuple(x-1, y, 0));
                        visited[x-1][y][memory][0] = true;
                    }
                }else if(dist == 1){//하
                    if(x == n-1 && !visited[0][y][memory][1]){//맨 아래쪽
                        q.push(make_tuple(0, y, 1));
                        visited[0][y][memory][1] = true;
                    }else if(!visited[x+1][y][memory][1]){
                        q.push(make_tuple(x+1, y, 1));
                        visited[x+1][y][memory][1] = true;
                    }
                }else if(dist == 2){//좌
                    if(y == 0 && !visited[x][m-1][memory][2]){//맨 왼쪽
                        q.push(make_tuple(x, m-1, 2));
                        visited[x][m-1][memory][2] = true;
                    }else if(!visited[x][y-1][memory][2]){//맨 왼쪽이 아니라면
                        q.push(make_tuple(x, y-1, 2));
                        visited[x][y-1][memory][2] = true;
                    }
                }else{//우
                    if(y == m-1 && !visited[x][0][memory][3]){//맨 오른쪽
                        q.push(make_tuple(x, 0, 3));
                        visited[x][0][memory][3] = true;
                    }else if(!visited[x][y+1][memory][3]){
                        q.push(make_tuple(x, y+1, 3));
                        visited[x][y+1][memory][3] = true;
                    }
                }
            }else{
                memory++;
                if(dist == 0){//상
                    if(x == 0 && !visited[n-1][y][memory][0]){//맨 위쪽
                        q.push(make_tuple(n-1, y, 0));
                        visited[n-1][y][memory][0] = true;
                    }else if(!visited[x-1][y][memory][0]){
                        q.push(make_tuple(x-1, y, 0));
                        visited[x-1][y][memory][0] = true;
                    }
                }else if(dist == 1){//하
                    if(x == n-1 && !visited[0][y][memory][1]){//맨 아래쪽
                        q.push(make_tuple(0, y, 1));
                        visited[0][y][memory][1] = true;
                    }else if(!visited[x+1][y][memory][1]){
                        q.push(make_tuple(x+1, y, 1));
                        visited[x+1][y][memory][1] = true;
                    }
                }else if(dist == 2){//좌
                    if(y == 0 && !visited[x][m-1][memory][2]){//맨 왼쪽
                        q.push(make_tuple(x, m-1, 2));
                        visited[x][m-1][memory][2] = true;
                    }else if(!visited[x][y-1][memory][2]){//맨 왼쪽이 아니라면
                        q.push(make_tuple(x, y-1, 2));
                        visited[x][y-1][memory][2] = true;
                    }
                }else{//우
                    if(y == m-1 && !visited[x][0][memory][3]){//맨 오른쪽
                        q.push(make_tuple(x, 0, 3));
                        visited[x][0][memory][3] = true;
                    }else if(!visited[x][y+1][memory][3]){
                        q.push(make_tuple(x, y+1, 3));
                        visited[x][y+1][memory][3] = true;
                    }
                }
            }
        }
        if(a[x][y] == '-'){//메모리에 저장된 값에 1을 뺀다. 만약 빼기 전 값이 0이라면 15로 바꾼다.
            // cout<<"-"<<"\n";
            if(memory == 0){
                memory = 15;
                if(dist == 0){//상
                    if(x == 0 && !visited[n-1][y][memory][0]){//맨 위쪽
                        q.push(make_tuple(n-1, y, 0));
                        visited[n-1][y][memory][0] = true;
                    }else if(!visited[x-1][y][memory][0]){
                        q.push(make_tuple(x-1, y, 0));
                        visited[x-1][y][memory][0] = true;
                    }
                }else if(dist == 1){//하
                    if(x == n-1 && !visited[0][y][memory][1]){//맨 아래쪽
                        q.push(make_tuple(0, y, 1));
                        visited[0][y][memory][1] = true;
                    }else if(!visited[x+1][y][memory][1]){
                        q.push(make_tuple(x+1, y, 1));
                        visited[x+1][y][memory][1] = true;
                    }
                }else if(dist == 2){//좌
                    if(y == 0 && !visited[x][m-1][memory][2]){//맨 왼쪽
                        q.push(make_tuple(x, m-1, 2));
                        visited[x][m-1][memory][2] = true;
                    }else if(!visited[x][y-1][memory][2]){//맨 왼쪽이 아니라면
                        q.push(make_tuple(x, y-1, 2));
                        visited[x][y-1][memory][2] = true;
                    }
                }else{//우
                    if(y == m-1 && !visited[x][0][memory][3]){//맨 오른쪽
                        q.push(make_tuple(x, 0, 3));
                        visited[x][0][memory][3] = true;
                    }else if(!visited[x][y+1][memory][3]){
                        q.push(make_tuple(x, y+1, 3));
                        visited[x][y+1][memory][3] = true;
                    }
                }
            }else{
                memory--;
                if(dist == 0){//상
                    if(x == 0 && !visited[n-1][y][memory][0]){//맨 위쪽
                        q.push(make_tuple(n-1, y, 0));
                        visited[n-1][y][memory][0] = true;
                    }else if(!visited[x-1][y][memory][0]){
                        q.push(make_tuple(x-1, y, 0));
                        visited[x-1][y][memory][0] = true;
                    }
                }else if(dist == 1){//하
                    if(x == n-1 && !visited[0][y][memory][1]){//맨 아래쪽
                        q.push(make_tuple(0, y, 1));
                        visited[0][y][memory][1] = true;
                    }else if(!visited[x+1][y][memory][1]){
                        q.push(make_tuple(x+1, y, 1));
                        visited[x+1][y][memory][1] = true;
                    }
                }else if(dist == 2){//좌
                    if(y == 0 && !visited[x][m-1][memory][2]){//맨 왼쪽
                        q.push(make_tuple(x, m-1, 2));
                        visited[x][m-1][memory][2] = true;
                    }else if(!visited[x][y-1][memory][2]){//맨 왼쪽이 아니라면
                        q.push(make_tuple(x, y-1, 2));
                        visited[x][y-1][memory][2] = true;
                    }
                }else{//우
                    if(y == m-1 && !visited[x][0][memory][3]){//맨 오른쪽
                        q.push(make_tuple(x, 0, 3));
                        visited[x][0][memory][3] = true;
                    }else if(!visited[x][y+1][memory][3]){
                        q.push(make_tuple(x, y+1, 3));
                        visited[x][y+1][memory][3] = true;
                    }
                }
            }
        }
    }
    return false;//계속 돌아가면
}


int main(){
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>m;
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>a[j][k];
            }
        }
        //혁쎔블리어 작동
        memset(visited, false, sizeof(visited));
        if(hyuksembly() == false){
            final = "NO";
        }else{
            final = "YES";
        }
        v.push_back(final);
    }

    for(int i=0; i<v.size(); i++){
        cout<<"#"<<i+1<<" "<<v[i]<<"\n";
    }
    return 0;
}