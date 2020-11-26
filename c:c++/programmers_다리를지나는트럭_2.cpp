// 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> on_bridge;
    int idx = 0;
    int total_bridge = 0;
    int sec = 0;
    
    while(1){
        sec++;
        if(on_bridge.size()==bridge_length){ // 트럭 나간다.
            total_bridge -= on_bridge.front();
            on_bridge.pop();
        }
        
        if(total_bridge+truck_weights[idx]<=weight){ // 트럭 넣기
            if(idx==truck_weights.size()-1){
                sec += bridge_length;
                break;
            }
            
            total_bridge += truck_weights[idx];
            on_bridge.push(truck_weights[idx]);
            idx++;
        }else{
            on_bridge.push(0);
        }
    }
    
    answer = sec;
    
    return answer;
}