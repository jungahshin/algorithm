// 숫자 카드
#include <iostream>
#include <algorithm>
using namespace std;
 
int arr1[500001] = {0, };
int arr2[500001] = {0, };
int n, m;
 
void binarysearch(int n, int k)
{
   int low = 0;
   int high = n-1;
 
   while(low<=high){
       int mid = (low+high)/2;
       if(arr1[mid]==k){
           cout<<"1"<<"\n";
           return;
       }else{
           if(arr1[mid]>k){
               high = mid-1;
           }else{
               low = mid+1;
           }
       }
   }
   cout<<"0"<<"\n";
}
 
int main()
{
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>arr1[i];
   }
 
   cin>>m;
   for(int i=0; i<m; i++){
       cin>>arr2[i];
   }
 
   sort(arr1, arr1+n);
 
   for(int i=0; i<m; i++){
       binarysearch(n, arr2[i]);
   }
 
   return 0;
}