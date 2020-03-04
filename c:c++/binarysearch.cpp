//이진 탐색(시간복잡도 - O(logn))
//배열에서 원하는 수가 몇 번째에 있는지 찾는 문제
#include <iostream>
#include <algorithm>
using namespace std;

int a[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
int result = 0;
int x;

int main(){
    cin>>x;
    int low = 0;//맨 처음 idx
    int high = 9;//맨 마지막 idx
    
    sort(a, a+10);//항상 이분탐색을 하려면 배열이 오름차순으로 정렬이 되어 있어야 한다.

    while(low<=high){
        int mid = (high+low)/2;
        if(a[mid] == x){
            result = mid+1;
            break;
        }else if(a[mid] > x){//구하려는 수보다 크니까 high를 줄여
            high = mid-1;
        }else if(a[mid] < x){//구하려는 수보다 작으니까 low를 늘여
            low = mid+1;
        }
    }
    cout<<result<<"번 째"<<"\n";
    return 0;
}