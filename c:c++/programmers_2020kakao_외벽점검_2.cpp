#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int iscovered[16] = {0, };//취약점이 커버되었는지
int isfriend[16] = {0, };//이미 투입된 친구인지
int answer = 9;
int final = 9;

void go(vector<int> weak, vector<int> dist, int Friend){//지금까지 투입된 친구의 수
    //최대 8명이기 때문..!
    if(Friend>8){
        return;
    }
    bool check = true;
    
    for(int i=0; i<weak.size(); i++){
        if(iscovered[i] == 0){//하나라도 커버가 안되면 실패
            check = false;
        }
    }
    
    if(check == true && Friend>0){//모두 커버를 했다.
        final = min(final, Friend);
    }
    
    for(int i=0; i<dist.size(); i++){
        if(isfriend[i] == 0){
            isfriend[i] = 1;
            for(int j=0; j<weak.size(); j++){
                if(iscovered[j] == 0){//아직 커버되지 않은 부분에서 커버 가능한 부분까지 커버.
                    int idx = j;
                    while(1){
                        if(idx>weak.size()-1){
                            break;
                        }
                        if(weak[j]+dist[i]>=weak[idx]){
                            iscovered[idx] = 1;
                            idx++;
                        }else{
                            break;
                        }
                    }
                    break;
                }
            }
            go(weak, dist, Friend+1);
            isfriend[i] = 0;
            memset(iscovered, 0, sizeof(iscovered));
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    //역정렬
    sort(dist.rbegin(), dist.rend());
    for(int i=0; i<weak.size(); i++){
        go(weak, dist, 0);
        // 한 칸씩 이동
        vector<int> temp;
        for(int j=1; j<weak.size(); j++){
            temp.push_back(weak[j]);
        }
        temp.push_back(weak[0]+n);
        weak.clear();
        for(int j=0; j<temp.size(); j++){
            weak.push_back(temp[j]);
        }
    }
    if(final == 9){
        return -1;
    }else{
        return final;
    }
}