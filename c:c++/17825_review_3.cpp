// 주사위 윷놀이
#include <iostream>
using namespace std;
 
int num[11] = {0, };
pair<int, int> horse[5];
int map[22] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0}; // 0번 배열
int map1[9] = {10, 13, 16, 19, 25, 30, 35, 40, 0};
int map2[8] = {20, 22, 24, 25, 30, 35, 40, 0};
int map3[9] = {30, 28, 27, 26, 25, 30, 35, 40, 0}; // 3번 배열
int ans = 0;
 
bool check(int array, int idx, pair<int, int> temp[5]) // 해당 배열의 해당 인덱스에 이미 말이 있는지 확인하기
{
   bool temp2 = false;
   if((array == 0 && idx == 20) || (array == 1 && idx == 7) || (array == 2 && idx == 6) || (array == 3 && idx == 7)){
       for(int j=1; j<=4; j++){
           if((temp[j].first == 1 && temp[j].second == 7) || (temp[j].first == 2 && temp[j].second == 6) || (temp[j].first == 3 && temp[j].second == 7) || (temp[j].first == 0 && temp[j].second == 20)){
               temp2 = true;
           }
       }
   }else if((array == 1 && idx == 4) || (array == 2 && idx == 3) || (array == 3 && idx == 4)){
       for(int j=1; j<=4; j++){
           if((temp[j].first == 1 && temp[j].second == 4) || (temp[j].first == 2 && temp[j].second == 3) || (temp[j].first == 3 && temp[j].second == 4)){
               temp2 = true;
           }
       }
   }else if((array == 1 && idx == 5) || (array == 2 && idx == 4) || (array == 3 && idx == 5)){
       for(int j=1; j<=4; j++){
           if((temp[j].first == 1 && temp[j].second == 5) || (temp[j].first == 2 && temp[j].second == 4) || (temp[j].first == 3 && temp[j].second == 5)){
               temp2 = true;
           }
       }
   }else if((array == 1 && idx == 6) || (array == 2 && idx == 5) || (array == 3 && idx == 6)){
       for(int j=1; j<=4; j++){
           if((temp[j].first == 1 && temp[j].second == 6) || (temp[j].first == 2 && temp[j].second == 5) || (temp[j].first == 3 && temp[j].second == 6)){
               temp2 = true;
           }
       }
   }
 
   for(int i=1; i<=4; i++){
       if(temp[i].first == array && temp[i].second == idx){
           temp2 = true;
       }
   }
 
   return temp2;
}
 
void play(int turn, pair<int, int> horse[5], int score)
{
   if(turn==10){
       ans = max(ans, score);
       return;
   }
 
   pair<int, int> temp[5];
   for(int i=1; i<=4; i++){
       temp[i] = make_pair(horse[i].first, horse[i].second);
   }
 
   // 1~4번 말 이동시킨다.
   // num[turn]만큼 이동한다.
 
   int cnt = num[turn]; // 이동칸 수
 
   for(int i=1; i<=4; i++){
       int arrayNum = temp[i].first;
       int arrayIdx = temp[i].second;
       int nIdx = arrayIdx+cnt;
 
       if((arrayNum==0 && arrayIdx==21) || (arrayNum==1 && arrayIdx==8) || (arrayNum==2 && arrayIdx==7) || (arrayNum==3 && arrayIdx==8)){
           continue;
       }
 
       if(arrayNum==0){
           if(nIdx>=21){ // 도착한것...
               arrayIdx = 21;
           }else{
               if(nIdx==5){ // 0->1
                   arrayNum = 1;
                   arrayIdx = 0;
               }else if(nIdx==10){ // 0->2
                   arrayNum = 2;
                   arrayIdx = 0;
               }else if(nIdx==15){ // 0->3
                   arrayNum= 3;
                   arrayIdx = 0;
               }else{ // 그냥 그대로 0번 배열
                   arrayIdx = nIdx;
               }
           }
       }else if(arrayNum==1){
           if(nIdx>=8){ // 도착했다.
               arrayIdx = 8;
           }else{
               arrayIdx = nIdx;
           }
       }else if(arrayNum==2){
           if(nIdx>=7){
               arrayIdx = 7;
           }else{
               arrayIdx = nIdx;
           }
       }else if(arrayNum==3){
           if(nIdx>=8){
               arrayIdx = 8;
           }else{
               arrayIdx = nIdx;
           }
       }
 
       if((arrayNum==0 && arrayIdx==21) || (arrayNum==1 && arrayIdx==8) || (arrayNum==2 && arrayIdx==7) || (arrayNum==3 && arrayIdx==8)){ // 도착한다면
           temp[i].first = arrayNum;
           temp[i].second = arrayIdx;
           play(turn+1, temp, score);
           temp[i].first = horse[i].first;
           temp[i].second = horse[i].second;               
       }else{
           if(!check(arrayNum, arrayIdx, temp)){
               temp[i].first = arrayNum;
               temp[i].second = arrayIdx;
               int plus = 0;
               if(temp[i].first==0){
                   plus = map[temp[i].second];
               }else if(temp[i].first==1){
                   plus = map1[temp[i].second];
               }else if(temp[i].first==2){
                   plus = map2[temp[i].second];
               }else if(temp[i].first==3){
                   plus = map3[temp[i].second];
               }
 
               play(turn+1, temp, score+plus);
               temp[i].first = horse[i].first;
               temp[i].second = horse[i].second;               
           }
       }
   }
}
 
int main()
{
   for(int i=0; i<10; i++){
       cin>>num[i];
   }
 
   for(int i=1; i<=4; i++){ // 1~4번 말
       horse[i] = make_pair(0, 0); // 맨 처음에는 0번 배열의 0Idx에 위치해있다.
   }
 
   play(0, horse, 0);
 
   cout<<ans<<"\n";
   return 0;
}