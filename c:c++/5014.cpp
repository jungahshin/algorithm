//스타트링크
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;
int visited[1000002] = {0, };
bool check = false;
int final = 0;

int main(){
    cin>>f>>s>>g>>u>>d;
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));//현재 위치
    
    while(!q.empty()){
        int x = q.front().first;
        int num = q.front().second;
        visited[x] = 1;
        q.pop();

        if(x == g){
            check = true;
            final = num;
            break;
        }

        //올라가
        int up = x+u;
        if(1<=up && up<=f && !visited[up]){
            visited[up] = 1;
            q.push(make_pair(up, num+1));
        }

        //내려가
        int down = x-d;
        if(1<=down && down<=f && !visited[down]){
            visited[down] = 1;
            q.push(make_pair(down, num+1));
        }
    }

    if(check == true){
        cout<<final<<"\n";
    }else{
        cout<<"use the stairs"<<"\n";
    }
    return 0;
}