//최소 힙(오름차순 -> 우선순위큐에서 default가 아니기 때문에 처리 필요)
#include <iostream>
#include <queue>
using namespace std;
 
int n, m;
priority_queue<int, vector<int>, greater<int>> pq; //오름차순처리
 
int main()
{
   scanf("%d", &n);
   for(int i=0; i<n; i++){
       scanf("%d", &m);
       if(m==0){//출력, 삭제
           if(pq.empty()){
               printf("%d\n", 0);
           }else{
               int MIN = pq.top();
               printf("%d\n", MIN);
               pq.pop();
           }
       }else{//우선순위큐에 넣기
           pq.push(m);
       }
   }
 
   return 0;
}
