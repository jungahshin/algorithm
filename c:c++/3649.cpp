//로봇 프로젝트
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int x, n, len;
vector<int> lego;
vector<int> final;
int visited[1000001] = {0, };
int size = 10000000;

void go(){
    for(int i=0; i<lego.size(); i++){//기준
        if(!visited[i]){
            visited[i] = 1;
            for(int j=i+1; j<lego.size(); j++){
                if(!visited[j]){
                    if((lego[i]+lego[j]) == x*size){
                        visited[j] = 1;
                        if(lego[i]>=lego[j]){
                            final.push_back(lego[j]);
                        }else{
                            final.push_back(lego[i]);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    while(cin>>x){//예제가 들어오면 시작
        lego.clear();
        final.clear();
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>len;
            lego.push_back(len);
        }
        memset(visited, 0, sizeof(visited));
        go();
        sort(final.begin(), final.end());
        if(final.size()>0){
            cout<<"yes "<<final[0]<<" "<<(x*size-final[0])<<"\n";
        }else{
            cout<<"danger"<<"\n";
        }
    }
    return 0;
}