//DSLR
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int testcase, a, b;
int visited[10001] = {0, };
string final;

void go(int start, int end){
    queue<pair<int, string>> q;
    q.push(make_pair(start, ""));

    while(!q.empty()){
        int x = q.front().first;
        string num = q.front().second;
        visited[x] = 1;
        q.pop();

        if(x == end){
            final = num;
            break;
        }

        //D
        if(x*2>9999){
            int temp_d = x*2%10000;
            if(!visited[temp_d]){
                visited[temp_d] = 1;
                q.push(make_pair(temp_d, num+"D"));
            }
        }else{
            int temp_d = x*2;
            if(!visited[temp_d]){
                visited[temp_d] = 1;
                q.push(make_pair(temp_d, num+"D"));
            }
        }
        //S
        if(x==0){
            int temp_s = 9999;
            if(!visited[temp_s]){
                visited[temp_s] = 1;
                q.push(make_pair(temp_s, num+"S"));
            }
        }else{
            int temp_s = x-1;
            if(!visited[temp_s]){
                visited[temp_s] = 1;
                q.push(make_pair(temp_s, num+"S"));
            }
        }
        //L(왼쪽으로 한 칸 이동)
        int one_l = x/1000;
        int two_l = (x-1000*one_l)/100;
        int three_l = (x-1000*one_l-100*two_l)/10;
        int four_l = (x-1000*one_l-100*two_l-10*three_l)/1;
        int temp_l = two_l*1000+three_l*100+four_l*10+one_l;
        if(!visited[temp_l]){
            visited[temp_l] = 1;
            q.push(make_pair(temp_l, num+"L"));
        }
        //R
        int one_r = x/1000;
        int two_r = (x-1000*one_r)/100;
        int three_r = (x-1000*one_r-100*two_r)/10;
        int four_r = (x-1000*one_r-100*two_r-10*three_r)/1;
        int temp_r = four_r*1000+one_r*100+two_r*10+three_r;
        if(!visited[temp_r]){
            visited[temp_r] = 1;
            q.push(make_pair(temp_r, num+"R"));
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>a>>b;
        memset(visited, 0, sizeof(visited));
        go(a, b);
        cout<<final<<"\n";
    }
    return 0;
}