// 스택 구현하기
/*
   일반적인 스택을 구현하시오.
   (push(), pop(), empty() 함수 구현)
   ex) 1, 2, 3, 4 -> 4, 3, 2, 1
*/
#include <iostream>
using namespace std;
 
int n, m;
int stack[10002] = {0, };
int top = -1; // 가장 위에 부분을 가리키고 있는 변수
 
bool empty()
{
   if(top==-1){
       return 1;
   }else{
       return 0;
   }
}
 
void push(int data)
{
   stack[++top] = data; // default값이 -1이기 때문에 ++top
}
 
void pop()
{
   cout<<stack[top]<<"\n";
   stack[top--] = 0; // top을 출력하고 0으로 만들고 top-1해준다.
}
 
int Top()
{
   if(empty()){
       return -1;
   }
 
   return stack[top];  
}
