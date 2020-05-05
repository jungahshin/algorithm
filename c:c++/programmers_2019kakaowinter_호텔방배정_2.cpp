//100점짜리 코드...
#include <string>
#include <vector>
#include <map>

using namespace std;
map<long long, long long> room;

long long find(long long a){
    if(room[a] == 0){//비어있는 방이면 리턴
        return a;
    }
    return room[a] = find(room[a]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0; i<room_number.size(); i++){
        long long real = find(room_number[i]);
        answer.push_back(real);
        room[real] = real+1;
    }
    return answer;
}