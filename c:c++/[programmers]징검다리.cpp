// [programmers] 징검 다리
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(int distance, vector<int> rocks, int n) {
   int answer = 0;
   int low = 0;
   int high = distance;
  
   sort(rocks.begin(), rocks.end());
  
   while(low<=high){
       int prev = 0; // 이전의 돌 위치
       int remove_num = 0;
       int mid = (low+high)/2; // '돌사이의 최솟값'을 잠정적으로 잡아놓는다.
      
       for(int i=0; i<rocks.size(); i++){
           if((rocks[i]-prev)<mid){ // 돌을 제거
               remove_num++;
           }else{ // 돌을 그냥 둔다.
               prev = rocks[i];
           }
       }
      
       // 마지막 distance와도 비교해준다.
       if((distance-prev)<mid){
           remove_num++;
       }
      
       if(remove_num<=n){
           // 갱신
           answer = max(answer, mid);
           low = mid+1;
       }else{
           high = mid-1;
       }
   }
  
   return answer;
}