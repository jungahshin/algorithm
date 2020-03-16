//숨바꼭질
#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100002] = {0, };
int dir[2] = {-1, 1};
int final = 0;

int main(){
    cin>>n>>k;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));//수빈이 처음 위치
    
    while(!q.empty()){
        int x = q.front().first;
        int num = q.front().second;
        visited[x] = 1;
        q.pop();

        if(x == k){//수빈이가 동생을 찾았다.
            final = num;
            break;
        }

        //걷기
        for(int i=0; i<2; i++){
            int walk_x = x+dir[i];
            if(0<=walk_x && walk_x <=100000 && !visited[walk_x]){
                visited[walk_x] = 1;
                q.push(make_pair(walk_x, num+1));
            }
        }

        //달리기
        int run_x = 2*x;
        if(0<=run_x && run_x <=100000 && !visited[run_x]){
            visited[run_x] = 1;
            q.push(make_pair(run_x, num+1));
        }
    }

    cout<<final<<"\n";
    return 0;
}