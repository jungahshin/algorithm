#include <string>
#include <vector>
#include <climits>
 
using namespace std;
 
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // 이분탐색으로 제거할 수를 찾기
    int Min = INT_MAX, Max = 0;
    
    for(int i=0; i<stones.size(); i++){
        Max = max(Max, stones[i]);
        Min = min(Min, stones[i]);
    }
    
    while(Min<=Max){
        int mid = (Min+Max)/2;
        
        int cnt = 0;
        bool check = false;
        for(int i=0; i<stones.size(); i++){
            int num = stones[i]-mid;
            if(num<=0){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt>=k){
                answer = mid;
                check = true;
                Max = mid-1;
                break;
            }
        }
                
        if(check==false){
            Min = mid+1;
        }   
    }
    
    return answer;
}