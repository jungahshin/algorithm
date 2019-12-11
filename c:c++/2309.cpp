//일곱 난쟁이
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tall[10] = {0, };
int visited[10] = {0, };

void cal(){
    int num = 0;
    for(int i=0; i<9; i++){
        if(visited[i] == false){
            num += tall[i];
        }
    }

    if(num == 100){
        vector<int> v;
        for(int i=0; i<9; i++){
            if(visited[i] == false){
                v.push_back(tall[i]);
            }
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<"\n";
        }
        exit(0);
    }
}

void find(int num, int index){
    if(num == 2){
        cal();//키의 합이 100인지 확인
        return;
    }

    for(int i=index; i<9; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        find(num+1, i);
        visited[i] = false;
    }
}

int main(){
    for(int i=0; i<9; i++){
        cin>>tall[i];
    }
    find(0, 0);
}