//프린터 큐
#include <iostream>
#include <queue>
using namespace std;

int testcase;
int n, m, t;
queue<pair<int, int>> important;
vector<int> final;

void go(){//큐에 들어있는 중요도 순으로 출력하기
    int seq = 0;//순서
    while(!important.empty()){
        int temp = important.front().first;//중요도
        int index = important.front().second;//index
        important.pop();

        //벡터에 넣기(탐색하기 위해)
        vector<pair<int, int>> v;
        while(!important.empty()){
            v.push_back(make_pair(important.front().first, important.front().second));
            important.pop();
        }
        //탐색해서 temp보다 큰 중요도를 가진 것이 있으면 벡터 값들을 다시 important에 넣어주고 맨 마지막에 temp를 넣어준다.
        //없으면, 그냥 벡터 값들 그대로를 important에 넣어주면 된다.
        bool check = false;
        for(int i=0; i<v.size(); i++){
            if(temp < v[i].first){
                check = true;
            }
        }
        for(int i=0; i<v.size(); i++){
            important.push(make_pair(v[i].first, v[i].second));
        }
        if(check == true){//더 큰 중요도가 있다
            important.push(make_pair(temp, index));
        }else{//더 큰 중요도가 없다
            seq++;
            if(index == m){
                final.push_back(seq);
            }
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n>>m;//몇 개의 문서, 구하고자하는 문서의 위치(index)
        for(int j=0; j<n; j++){
            cin>>t;
            important.push(make_pair(t, j));
        }
        go();
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}