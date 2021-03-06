#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1; // 모두 점검할 수 없으면 -1
    
    int weak_len = weak.size();
    int dist_len = dist.size();
    
    sort(dist.begin(), dist.end());
    for(int i=0; i<weak_len-1; i++){
        weak.push_back(weak[i]+n);
    }
    
    for(int i=1; i<=dist_len; i++){ // 투입될 친구 수
        for(int j=0; j<weak_len; j++){ // 시작할 위치
            
            vector<int> temp; // 외벽점검에 투입될 친구
            for(int k=dist_len-i; k<dist_len; k++){
                temp.push_back(dist[k]);
            }
            
            do {
                int idx = 0;
                for(int k=0; k<temp.size(); k++){
                    int End = weak[j+idx]+temp[k];
                    while(weak[j+idx+1]<=End){
                        idx++;
                    }
                    idx++; // 다음 취약 지점으로 이동
                }
                if(idx>=weak_len){
                    return i;
                }
            } while(next_permutation(temp.begin(), temp.end()));
        }
    }
    
    return answer;
}