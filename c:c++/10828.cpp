// 스택
#include <iostream>
using namespace std;
 
int n, m;
string s;
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
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>s;
       if(s=="push"){
           cin>>m;
           push(m);
       }else if(s=="top"){
           cout<<Top()<<"\n";
       }else if(s=="size"){
           cout<<top+1<<"\n";
       }else if(s=="empty"){
           cout<<empty()<<"\n";
       }else if(s=="pop"){
           if(empty()){
               cout<<"-1"<<"\n";
           }else{
               pop();
           }
       }
   }
}
