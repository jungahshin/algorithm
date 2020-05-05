//84.8점짜리 코드...
#include <string>
#include <vector>
#include <map>

using namespace std;
map<long, long> room;

long long find(long long a){
    if(room[a] == a){
        return a;
    }
    return room[a] = find(room[a]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0; i<room_number.size(); i++){
        long long wish = room_number[i];
        
        if(room.count(wish) == 0){//아직 배정받지 못한 방->내가 차지
            room[wish] = wish;
            answer.push_back(wish);
        }else{//이미 누군가가 배정받은 방
            long long a = wish;
            long long b = find(wish);
            
            long long temp = b;
            while(1){
                temp++;
                if(room.count(temp) == 0){//배정받지 않은 방이 나올때까지..
                    break;
                }
            }
            room[b] = temp;
            room[temp] = temp;
            answer.push_back(temp);
        }
    }
    return answer;
}