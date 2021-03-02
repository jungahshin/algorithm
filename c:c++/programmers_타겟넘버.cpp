#include <string>
#include <vector>
 
using namespace std;
 
int answer = 0;
 
void dfs(int num, int idx, int target, vector<int> numbers)
{
    if(idx==numbers.size()){
        if(num==target){
            answer++;
        }
        return;
    }
    
    dfs(num+numbers[idx], idx+1, target, numbers);
    dfs(num-numbers[idx], idx+1, target, numbers);
}
 
int solution(vector<int> numbers, int target) {    
    dfs(0, 0, target, numbers);
    
    return answer;
}