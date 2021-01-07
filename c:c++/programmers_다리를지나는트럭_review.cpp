#include <string>
#include <vector>
#include <queue>
#include <iostream>
 
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> on_bridge;
    int total_weight = 0;
    int i = 0;
    
    while(1){
        answer++;
        // 이미 다리 위에 있는 트력을 뺀다.
        if(on_bridge.size()==bridge_length){å
            if(on_bridge.front()!=-1){
                total_weight -= on_bridge.front();
            }
            on_bridge.pop();
        }
        // 대기 트럭 중 하나를 넣는다.
        if((total_weight+truck_weights[i])>weight){
            on_bridge.push(-1);
        }else{
            on_bridge.push(truck_weights[i]);
            total_weight += truck_weights[i];
            i++;
            if(i>=truck_weights.size()){
                answer += bridge_length;
                break;
            }
        }
    }
    
    return answer;
}