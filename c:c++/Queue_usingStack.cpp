// 스택으로 큐 구현하기
/*
   입력하려는 수의 총 개수와
   개수만큼의 수를 입력받은 후
 
   스택만을 이용하여 큐처럼 동작하도록 하여 값 출력하기
   ex) 1, 2, 3, 4 -> 1, 2, 3, 4
*/
 
#include <iostream>
#include <stack>
using namespace std;
 
int n, m;
stack<int> a;
stack<int> b;
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       a.push(m);
   }
 
   while(!a.empty()){
       b.push(a.top());
       a.pop();
   }
 
   while(!b.empty()){
       cout<<b.top()<<"\n";
       b.pop();
   }
 
   return 0;
}
