//최대 힙 -> 내림차순(우선순위큐 default)
#include <iostream>
#include <queue>
using namespace std;
 
int n, m;
priority_queue<int> pq;
 
int main()
{
   scanf("%d", &n);
   for(int i=0; i<n; i++){
       scanf("%d", &m);
       if(m==0){//출력하고 제거하기
           if(pq.empty()){
               printf("%d\n", 0);
           }else{
               int MAX = pq.top();
               printf("%d\n", MAX);
               pq.pop();               
           }
       }else{//우선순위큐에 넣기
           pq.push(m);
       }
   }
 
   return 0;
}
