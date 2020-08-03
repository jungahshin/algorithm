// 큐로 스택 구현하기
/*
   입력하려는 수의 총 개수와
   개수만큼의 수를 입력받은 후
 
   큐만을 이용하여 스택처럼 동작하도록 하여 값 출력하기
   ex) 1, 2, 3, 4 -> 4, 3, 2, 1
*/
 
#include <iostream>
#include <queue>
using namespace std;
 
int n, m;
queue<int> a;
queue<int> b;
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>m;
       if(a.empty()){
           a.push(m);
       }else{
           while(!a.empty()){
               b.push(a.front());
               a.pop();
           }
 
           a.push(m);
 
           while(!b.empty()){
               a.push(b.front());
               b.pop();
           }
       }
   }
 
   while(!a.empty()){
       cout<<a.front()<<"\n";
       a.pop();
   }
 
   return 0;
}
