// 양념 반 후라이드 반
#include <iostream>
using namespace std;
 
int a, b, c, x, y;
int total = 0;
 
int main()
{
   cin>>a>>b>>c>>x>>y;
 
   while(1){
       if(x==0 && y==0){ // 둘 다 소진되면 끝난다.
           break;
       }
 
       if(x>=1 && y>=1){
           if(a+b>2*c){ // 반반 2개로 주문한다.
               total += (2*c);
           }else{ // 따로 주문한다.
               total += (a+b);
           }
           x--;
           y--;
       }
       if(x>=1 && y==0){ // 양념만 주문
           if(a>2*c){
               total += 2*c;
           }else{
               total += a;
           }
           x--;
       }
       if(x==0 && y>=1){ // 후라이드만 주문
           if(b>2*c){
               total += 2*c;
           }else{
               total += b;
           }
           y--;
       }
   }
 
   cout<<total<<"\n";
   return 0;
}
