// 선택 정렬 구현(오름차순)
#include <iostream>
#include <climits>
using namespace std;
 
// 초기 배열 상태
int arr[5] = {9, 6, 7, 3, 5};
 
void selection_sort(int arr[], int size)
{
   for(int i=0; i<size-1; i++){
       int MIN = INT_MAX;
       int IDX;
       for(int j=i+1; j<size; j++){
           if(MIN>arr[j]){
               MIN = arr[j];
               IDX = j;
           }
       }
 
       if(arr[i]>MIN){
           // i와 IDX위치의 값을 바꿔준다.
           int temp = arr[i];
           arr[i] = arr[IDX];
           arr[IDX] = temp;
       }
   }
}
 
int main()
{
   selection_sort(arr, 5);
 
   for(int i=0; i<5; i++){
       cout<<arr[i]<<" ";
   }
   cout<<"\n";
}
