// 구명보트
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int solution(vector<int> people, int limit) {
    int answer = 0;
    int i=0, j=0;
    
    sort(people.begin(), people.end());
    
    // int j로 선언하면 노노.... 뒤에서 i==j인 경우를 따져야하기 때문에 i, j는 전역변수로 선언해야 함!
    for(j=people.size()-1; j>i; j--){
        if(people[j]+people[i]<=limit){
            i++;
            answer++;
        }else{
            answer++;
        }
    }
    
    // ex) [30, 40, 50], limit = 100의 경우 i==j에서 멈춘다. 그래서 i==j일 경우 answer++
    if(i==j){
        answer++;
    }
    
    return answer;
}