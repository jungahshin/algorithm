//프린터
#include <string>
#include <vector>
#include <queue>
#include <iostream>

int exist[12] = {0, };

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> final;
    int cnt = 1;

    for(int i=0; i<priorities.size(); i++){
        exist[priorities[i]]++;
        final.push(make_pair(priorities[i], i));
    }
    
    while(!final.empty()){
        int num = final.front().first;
        bool check = false;
        for(int j=num+1; j<=9; j++){
            if(exist[j]>0){ // 우선순위가 더 높은게 있다.
                check = true;
                break;
            }
        }
        if(check==true){
            int a = final.front().first;
            int b = final.front().second;
            final.pop();
            // 뒤로 넣어준다.
            final.push(make_pair(a, b));
        }else{
            if(final.front().second==location){
                answer = cnt;
                break;
            }
            exist[final.front().first]--;
            final.pop();
            cnt++;
        }        
    }


    
    return answer;
}