// 큐 구현하기
/*
   일반적인 큐를 구현하시오.
   (insert(), del(), empty() 함수 구현)
   ex) 1, 2, 3, 4 -> 1, 2, 3, 4
*/
#include <iostream>
using namespace std;
int queue[100] = {0, };
int n = 100; // 최대 크기
int front = -1, rear = -1;
 
void insert(int data)
{
   if(rear == n-1){ // queue배열이 꽉 찬 경우
       cout<<"queue overflow"<<"\n";
   }else{
       if(front==-1){
           front = 0;
       }
 
       queue[++rear] = data;
   }
}
 
void del()
{
   if(front==-1 || front>rear){ // queue배열이 비어있을 경우
       cout<<"queue underflow"<<"\n";
   }else{
       cout<<queue[front]<<"\n";
       front++;
   }
}
 
void print() // front~rear까지 출력
{
   if(front==-1){
       cout<<"queue is empty"<<"\n";
   }else{
       for(int i=front; i<=rear; i++){
           cout<<queue[i]<<"\n";
       }       
   }
}
 
void empty()
{
   if(front==-1 || front>rear){
       cout<<"queue is empty"<<"\n";
   }else{
       cout<<"queue is not empty"<<"\n";
   }
}
