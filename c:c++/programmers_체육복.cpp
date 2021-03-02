#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
bool check[31];
bool check2[31];
 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    for(int i=0; i<lost.size(); i++){
        bool temp = false;
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]==reserve[j]){
                check2[reserve[j]] = true;
                temp = true;
                break;
            }
        }
        if(temp==false){
            check[lost[i]] = true;
            answer--;
        }
    }
        
    for(int i=0; i<reserve.size(); i++){
        if(check2[reserve[i]]) continue;
        int before = reserve[i]-1;
        int after = reserve[i]+1;
        bool temp = false;
        if(1<=before && before<=n){
            if(check[before]==true){
                temp = true;
                check[before] = false;
                answer++;
            }
        }
        if(temp==true) continue;
        if(1<=after && after<=n){
            if(check[after]==true){
                check[after] = false;
                answer++;
            }
        }
    }
    
    return answer;
}