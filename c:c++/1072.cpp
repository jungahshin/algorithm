//게임
#include <iostream>
using namespace std;

long long z = 0;
long long x, y;

int main(){
    cin>>x>>y;
    long long temp = (y*100)/x;//현재의 승률

    long long low = 0;
    long long high = 2000000001;

    if(temp >= 99){//이미 승률이 99이면 100이 될 수 없으므로 -1출력
        cout<<"-1"<<"\n";
        return 0;
    }
    while(low<=high){
        long long mid = (low+high)/2;
        //mid는 그저 이분탐색을 위한 수단일뿐...!
        z = (y+mid)*100/(x+mid);//소수점 버린다.
        if(temp<z){
            high = mid-1;
        }else{//승률이 같을 때에도 계속 더해준다(승률이 달라지는 지점을 찾아야하기 때문)
            low = mid+1;
        }
    }

    cout<<low<<"\n";
    return 0;
}