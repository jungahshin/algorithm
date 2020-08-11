// 힙 정렬 구현(오름차순)
/*
   힙 정렬은 2가지 구현방식이 존재한다.
   1) 데이터들을 힙에 넣었다가 꺼내는 원리로 정렬하는 것
   2) 기존의 배열을 heap으로 만들어주는 과정을 거쳐 꺼내주는 방법
*/
 
#include <iostream>
using namespace std;
 
int arr[8] = {7, 6, 2, 8, 3, 5, 4, 1};
 
int main()
{  
   // 기존의 arr배열을 자식이 부모보다 큰 경우를 1차 정렬해준다.
   // 아래 -> 위
   for(int i=1; i<8; i++){
       int c = i;
       do{
           int root = (c-1)/2;
           if(arr[root]<arr[c]){
               int temp = arr[root];
               arr[root] = arr[c];
               arr[c] = temp;
           }
           c = root;
       }while(c!=0);
   }
 
   // 위 -> 아래
   for(int i=7; i>=0; i--){
       // i번째 원소를 0번(root node)으로 올려주고 heap구조로 재배치한다.
       int temp = arr[0];
       arr[0] = arr[i];
       arr[i] = temp;
       int root = 0;
       int c = 1;
 
       do{
           c = (2*root)+1; // 왼쪽 자식
           // c<i-1인 이유는, 왼쪽 자식이기 때문에 1칸 더 여유가 있어야 한다.
           if(c<i-1 && arr[c]<arr[c+1]){ // 왼쪽자식<오른쪽 자식
               c++;
           }
 
           // 왼쪽 자식과 오른쪽 자식 중 더 큰 값(c)과 바꾼다.
           if(c<i && arr[root]<arr[c]){
               temp = arr[root];
               arr[root] = arr[c];
               arr[c] = temp;
           }
           root = c;
       }while(c<i);
   }
 
   for(int i=0; i<8; i++){
       cout<<arr[i]<<" ";
   }
   cout<<"\n";
 
   return 0;
}
