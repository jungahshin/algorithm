#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
 
using namespace std;
 
long long solution(int n, vector<int> times) {
 
    sort(times.begin(), times.end());
 
    long long Start = 1;
    long long End = (long long)times[times.size()-1]*n;
    long long answer = End;
    
    while(Start<=End){
        long long mid = (Start+End)/2;
        long long sum = 0;
        for(int i=0; i<times.size(); i++){
            sum += (mid/times[i]);
        }
                
        if(sum>=n){
            answer = min(answer, mid);
            End = mid-1;
        }else if(sum<n){
            Start = mid+1;
        }
        
    }
    
    return answer;
}