//중앙값 구하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int testcase, n, m;
 
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       priority_queue <int> maxheap;//내림차순(최대힙) ex)98765(루트노트부터 내려올때)
       priority_queue <int, vector<int>, greater<int>> minheap;//오름차순(최소힙) ex)12345(루트노트부터 내려올때)
       vector<int> v;
       cin>>n;
       for(int j=1; j<=n; j++){
           cin>>m;
           //1)maxheap은 minheap의 크기와 같거나 +1많아야 한다.
           if(maxheap.size()>minheap.size()){
               minheap.push(m);
           }else{
               maxheap.push(m);
           }
 
           //2)maxheap의 top이 항상 중간값 역할(짝수이던 홀수이던)을 한다. 그런데 minheap의 top보다 maxheap의 top 값이 더 큰 경우에는
           //두 값을 바꿔준다.
           if(!minheap.empty() && !maxheap.empty() && minheap.top()<maxheap.top()){
               int MIN = minheap.top();
               int MAX = maxheap.top();
               minheap.pop();
               maxheap.pop();
 
               //바꿔서 넣어준다.
               maxheap.push(MIN);
               minheap.push(MAX);
           }
           if(j%2!=0){//홀수일때만 출력
               v.push_back(maxheap.top());
           }
       }
       cout<<v.size()<<"\n";
       for(int k=0; k<v.size(); k++){
           cout<<v[k]<<"\n";
       }
   }
 
   return 0;
}
