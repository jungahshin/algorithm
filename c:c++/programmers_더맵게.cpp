// 더 맵게
#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
        
    while(!pq.empty() && pq.top()<K){
        if(pq.size()==1){
            answer = -1;
            break;
        }
        answer++;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a+(b*2);
        pq.push(c);
    }
    
    return answer;
}