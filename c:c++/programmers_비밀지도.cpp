#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
int cal(int num){
    int temp = num;
    string s = "";
    while(temp!=0){
        s = to_string(temp%2)+s;
        temp /= 2;
    }
    
    int bitmask = 0;
    int cnt = 0;
    for(int i=s.size()-1; i>=0; i--){
        cnt++;
        if(s[i]=='0') continue;
        bitmask |= (1<<(cnt-1));
    }
    
    return bitmask;
}
 
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // bitmask형태로 만들기
    vector<int> v1;
    for(int i=0; i<n; i++){
        v1.push_back(cal(arr1[i]));
    }
    
    vector<int> v2;
    for(int i=0; i<n; i++){
        v2.push_back(cal(arr2[i]));
    }
    
    // 전체 지도 -> 두 장의 지도를 or연산하기
    for(int i=0; i<n; i++){
        int temp = (v1[i] | v2[i]);
        string s = "";
        for(int j=1; j<=n; j++){
            if((temp & (1<<(j-1))) != 0){
                s = "#"+s;
            }else{
                s = " "+s;
            }
        }
        answer.push_back(s);
    }
    
    return answer;
}