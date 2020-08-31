// 공항
#include <iostream>
#include <vector>
using namespace std;
 
int g, p, n;
vector<int> airplane;
int num = 0;
int connect[100001] = {0, }; // 유니온파인드
 
int find(int x){
   if(connect[x] == x){
       return x;
   }else{
       return connect[x] = find(connect[x]);
   }
}
 
int main()
{
   cin>>g>>p;
   for(int i=1; i<=g; i++){
       connect[i] = i;
   }
   for(int i=0; i<p; i++){
       cin>>n;
       airplane.push_back(n);
   }
 
   for(int i=0; i<airplane.size(); i++){
       int a = find(airplane[i]);
       if(1<=a && a<=g){
           // a와 a-1을 연결해준다.
           connect[a] = a-1;
           num++;
       }else{
           break;
       }
   }
  
   cout<<num<<"\n";
   return 0;
}