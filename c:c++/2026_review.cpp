// 소풍
#include <iostream>
using namespace std;
 
int k, n, f, a, b;
int visited[902] = {0, };
int relation[902][902] = {0, };
bool check = false; // 맨 처음 구한 값 후에는 return 하기 위해
 
// 서로 친구인 관계인지 확인
bool Check(int idx)
{
   for(int i=1; i<=n; i++){
       if(visited[i]==true){
           if(relation[i][idx]==0){
               return false;
           }
       }
   }
   return true;
}
 
void combin(int num, int idx)
{
   if(check==true) return;
   if(num==k){
       check = true;
       for(int i=1; i<=n; i++){
           if(visited[i]==true){
               cout<<i<<"\n";
           }
       }
       return;
   }
 
   for(int i=idx+1; i<=n; i++){
       if(!visited[i] && (num+n-i+1)>=k && (relation[idx][i]==1 || relation[i][idx]==1)){
           if(Check(i)==false) continue;
           visited[i] = true;
           combin(num+1, i);
           visited[i] = false;
       }
   }
}
 
int main()
{
   cin>>k>>n>>f;
   for(int i=0; i<f; i++){
       cin>>a>>b;
       relation[a][b] = 1;
       relation[b][a] = 1;
   }
 
   // n개 중 k개를 선택하기 위해 하나의 점 선택
   for(int i=1; i<=n; i++){
       if(check==true) break;
       if(!visited[i] && (n-i+1)>=k){
           visited[i] = true;
           combin(1, i);
           visited[i] = false;
       }
   }
 
   if(check==false){
       cout<<"-1"<<"\n";
   }
 
   return 0;
}
