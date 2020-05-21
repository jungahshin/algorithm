#include <string>
#include <vector>
#include <queue>//다리의 역할
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weights = 0;//다리에 있는(큐에 들어있는 총 원소의 무게)
    int sec = 0;//총 걸린 시간
    int idx = 0;//대기 트럭을 가리키는 idx
    queue<int> on_bridge;//다리위에 있는 트럭들
    while(1){
        sec++;
        if(on_bridge.size() == bridge_length){//다리를 나간다.
            total_weights -= on_bridge.front();
            on_bridge.pop();
        }

        if(total_weights+truck_weights[idx] <= weight){//다리에 트럭들을 더 넣을 수 있다.
            if(idx == truck_weights.size()-1){
                sec += bridge_length;
                break;
            }
            total_weights += truck_weights[idx];
            on_bridge.push(truck_weights[idx]);
            idx++;
        }else{
            on_bridge.push(0);
        }
    }
    answer = sec;
    return answer;
}