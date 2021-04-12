// 성냥개비
#include <iostream>
#include <climits>
 
using namespace std;
 
int n, testcase;
int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
long long minDP[101] = {0, };
 
void minCal()
{
    for(int i=1; i<=9; i++){
        minDP[i] = num[i];
    }
    minDP[6] = 6; // 처음 시작은 0으로 할 수 없으니, 6으로 시작
    // 또한, 9부터 시작하는 이유는, 8부터 하면 10이 아닌, 08(j=7일 경우) 값을 최소로 인식한다.
    for(int i=9; i<=100; i++){
        minDP[i] = 888888888888888;
        for(int j=2; j<8; j++){
            minDP[i] = min(minDP[i], minDP[i-j]*10+num[j]);
        }
    }
}
 
int main()
{
    cin>>testcase;
    minCal(); 
    while(testcase--){
        cin>>n;
        // 최소
        cout<<minDP[n]<<" ";
 
        // 최대(홀수, 짝수 나누어서)
        while(n){
            if(n % 2 != 0){
                cout << 7;
                n -= 3;
            }
            else{
                cout << 1;
                n -= 2;
            }
        }
        cout << "\n";
    }
 
    return 0;
}