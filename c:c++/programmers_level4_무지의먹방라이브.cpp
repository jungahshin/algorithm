//무지의 먹방 라이브
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long time = 0;//시간(1초 단위)
    int index = -1;//food_times 배열의 idx
    bool check = false;
    bool check_2 = false;
    while(1){
        if(check_2 == false){
            time++;            
        }else{
            bool go = false;
            for(int i=0; i<food_times.size(); i++){
                if(food_times[i] != 0){
                    go = true;
                }
            }
            if(go == false){//모두 다 0이면 더 이상 먹을 것이 없어서 종료
                answer = -1;
                break;
            }            
        }
        
        index++;
        if(index > food_times.size()-1){
            index = 0;
        }
        if(time>k){
            int start = index;//네트워크 장애후 먹을 음식 번호
            if(food_times[index] == 0){
                for(int i=0; i<food_times.size(); i++){
                    int temp = start+i;
                    if(temp > food_times.size()-1){
                        temp -= food_times.size();
                    }
                    if(food_times[temp] != 0){
                        answer = temp+1;
                        check = true;
                        break;
                    }
                }
            }else{
                answer = index+1;
                break;
            }
            if(check == true){
                break;                
            }else{
                answer = -1;
                break;
            }
        }
        if(food_times[index] == 0){
            check_2 = true;
        }else{
            food_times[index] -= 1;
            check_2 = false;
        }
    }
    return answer;
}