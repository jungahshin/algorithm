#include <iostream>
using namespace std;
 
string str;
int n;
 
// idx(시작)~n-1(끝)까지의 부분 문자열이 팰린드롬인지 확인 -> 팰린드롬이면 n+idx만큼이 가장 짧은 팰린드롬의 길이이다.
bool isPalin(int idx){
    int half = (n-idx)/2; // 양쪽을 비교할 횟수
    for(int i=0; i<half; i++){
        if(str[idx+i]!=str[(n-1)-i]) return false;
    }
    return true;
}
 
int main()
{
    cin>>str;
    n = str.size();
 
    for(int i=0; i<n; i++){
        if(isPalin(i)){
            cout<<n+i<<"\n";
            return 0;
        }
    }
 
    return 0;
}