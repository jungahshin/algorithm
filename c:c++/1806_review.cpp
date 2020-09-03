// 부분합
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int n, s;
vector<int> v;
int final = INT_MAX;
 
int main()
{
   cin>>n>>s;
   v.resize(n);
   for(int i=0; i<n; i++){
       cin>>v[i];
   }
 
   int Start = 0;
   int End = 0;
   int Sum = v[0]; // 총 개수
   int Num = 1; // 총 합
 
   while(Start<=End && End<v.size()){
       if(Sum>=s){
           final = min(final, Num);
       }
       if(Sum<s){ // End++
           if(Start<=End && End<v.size()){
               End++;
               Sum += v[End];
               Num++;
           }
       }else if(Sum>=s){ // Start++
           if(Start<=End && End<v.size()){
               Num--;
               Sum -= v[Start];
               Start++;
           }
       }
   }
 
   if(final==INT_MAX){
       cout<<"0"<<"\n";
   }else{
      cout<<final<<"\n";
   }
  
   return 0;
}