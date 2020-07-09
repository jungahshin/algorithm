//핸드폰 요금
#include <iostream>
 
using namespace std;
 
int n, a;
 
int main()
{
   cin>>n;
   int total_m = 0;
   int total_y = 0;
   for(int i=0; i<n; i++){
       cin>>a;
       int temp_m = 0;
       int temp_y = 0;
       //민식
       while(1){
           temp_m += 60;
           total_m += 15;
           if(temp_m>a){
               break;
           }
       }
       cout<<"temp_m"<<temp_m<<"\n";
       cout<<"totla_m"<<total_m<<"\n";
 
       //영식
       while(1){
           temp_y += 30;
           total_y += 10;
           if(temp_y>a){
               break;
           }
       }
       cout<<"temp_y"<<temp_y<<"\n";
       cout<<"total_y"<<total_y<<"\n";
   }
 
   if(total_m<total_y){
       cout<<"M"<<" "<<total_m;
   }else if(total_m>total_y){
       cout<<"Y"<<" "<<total_y;
   }else{
       cout<<"Y"<<" "<<"M"<<" "<<total_m;
   }
 
   return 0;
}
