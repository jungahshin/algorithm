// 합병 정렬 구현(오름차순)
#include <iostream>
using namespace std;
 
int sorted[8] = {0, };
int arr[8] = {21, 10, 12, 20, 25, 13, 15, 22};
 
void merge(int arr[], int left, int mid, int right)
{
   int i = left;
   int j = mid+1;
   int k = left;
 
   while(i<=mid && j<=right){
       if(arr[i]<=arr[j]){
           sorted[k++] = arr[i++];
       }else{
           sorted[k++] = arr[j++];
       }
   }
 
   // 남은 부분 채워주기
   if(i>mid){ // i가 mid보다 크면, j를 채워야한다.
       for(int t=j; t<=right; t++){
           sorted[k++] = arr[t];
       }
   }else{ // i가 mid보다 작거나 같으면, i를 채워야한다.
       for(int t=i; t<=mid; t++){
           sorted[k++] = arr[t];
       }
   }
 
   // arr배열을 sorted배열(임시배열)로 매번 갱신해준다.
   for(int i=left; i<=right; i++){
       arr[i] = sorted[i];
   }
}
 
void merge_sort(int arr[], int left, int right)
{
   if(left<right){
       int mid = (left+right)/2;
       merge_sort(arr, left, mid);
       merge_sort(arr, mid+1, right);
       merge(arr, left, mid, right);
   }
}
 
int main()
{
   merge_sort(arr, 0, 7);
   for(int i=0; i<8; i++){
       cout<<arr[i]<<" ";
   }
   cout<<"\n";
}
