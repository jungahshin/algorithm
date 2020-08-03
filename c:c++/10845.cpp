// 큐
#include <iostream>
using namespace std;
 
int queue[10001] = {0, };
int front = -1, rear = -1;
int n, m;
string s;
 
void insert(int data)
{
   if(front==-1){
       front = 0;
   }
   queue[++rear] = data;
}
 
void del()
{
   cout<<queue[front]<<"\n";
   front++;
}
 
void print() // front~rear까지 출력
{
   if(front==-1 || front>rear){
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
       cout<<"1"<<"\n";
   }else{
       cout<<"0"<<"\n";
   }
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>s;
       if(s=="push"){
           cin>>m;
           insert(m);
       }else if(s=="front"){
           if(front==-1 || front>rear){
               cout<<"-1"<<"\n";
           }else{
               cout<<queue[front]<<"\n";
           }
       }else if(s=="back"){
           if(front==-1 || front>rear){
               cout<<"-1"<<"\n";
           }else{
               cout<<queue[rear]<<"\n";
           }
       }else if(s=="size"){
           if(front==-1 || front>rear){
               cout<<"0"<<"\n";
           }else{
               cout<<rear-front+1<<"\n";
           }
       }else if(s=="empty"){
           empty();
       }else if(s=="pop"){
           if(front==-1 || front>rear){
               cout<<"-1"<<"\n";
           }else{
               del();
           }
       }
   }
 
   return 0;
}
