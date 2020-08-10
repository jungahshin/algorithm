// 삽입 정렬 구현(오름차순)
#include <iostream>
using namespace std;
 
int arr[5] = {8, 5, 6, 2, 4};
 
void insertion_sort(int arr[], int size)
{
   for(int i=1; i<size; i++){
       int cmp = arr[i];
       for(int j=i-1; j>=0; j--){
           if(cmp<arr[j]){ // 뒤로 밀기
               arr[j+1] = arr[j];
               arr[j] = cmp;
           }else{
               break;
           }
       }
   }
}
 
int main()
{
   insertion_sort(arr, 5);
   for(int i=0; i<5; i++){
       cout<<arr[i]<<" ";
   }
   cout<<"\n";
}
