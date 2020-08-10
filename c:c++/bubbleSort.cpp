// 버블 정렬 구현(오름차순)
#include <iostream>
using namespace std;
 
// 초기 배열 상태
int arr[5] = {4, 3, 2, 1, 0};
 
void bubble_sort(int arr[], int size)
{
   for(int i=0; i<size-1; i++){ // 반복(size-1만큼)
       for(int j=0; j<size-1; j++){
           if(arr[j]>arr[j+1]){
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
}
 
int main()
{
   bubble_sort(arr, 5);
   for(int i=0; i<5; i++){
       cout<<arr[i]<<" ";
   }
   cout<<"\n";
}
