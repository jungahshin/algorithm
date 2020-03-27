#include <string>
#include <map>//캐시에 있는 지 없는 지 여부
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> check;
int final = 0;

int solution(int cacheSize, vector<string> cities) {
    queue<string> q;
    int answer = 0;
    if(cacheSize == 0){
        return cities.size()*5;
    }
    for(int i=0; i<cities.size(); i++){
        for(int j=0; j<cities[i].size(); j++){
            cities[i][j] = tolower(cities[i][j]);
        }
        if(q.size()<cacheSize){//캐시에 넣을 수 있는 상태
            if(check.count(cities[i]) == 0){//캐시에 넣는다.+5시간(cache hit)
                q.push(cities[i]);
                check[cities[i]] = 1;
                final += 5;
            }else{
                if(check[cities[i]] == 0){//캐시에 넣는다.+5시간(cache hit)
                    q.push(cities[i]);
                    check[cities[i]] = 1;
                    final += 5;
                }else if(check[cities[i]] == 1){//이미 있다.+1시간(cache miss)
                    //가장 최근 사용한 순서로 변경
                    vector<string> temp;
                    while(!q.empty()){
                        temp.push_back(q.front());
                        q.pop();
                    }
                    for(int k=0; k<temp.size(); k++){
                        if(temp[k] == cities[i]){
                            temp.erase(temp.begin()+k);
                        }
                    }
                    temp.push_back(cities[i]);
                    for(int k=0; k<temp.size(); k++){
                        q.push(temp[k]);
                    }
                    final += 1;
                }
            }
        }else{//캐시에 넣을 수 없는 상태
            if(check[cities[i]] == 0){//캐시에 없으니 pop하고 이것을 넣는다.
                check[q.front()] = 0;
                q.pop();
                q.push(cities[i]);
                check[cities[i]] = 1;
                final += 5;
            }else if(check[cities[i]] == 1){//캐시에 이미 있다.
                //가장 최근 사용한 순서로 변경
                vector<string> temp;
                while(!q.empty()){
                    temp.push_back(q.front());
                    q.pop();
                }
                for(int k=0; k<temp.size(); k++){
                    if(temp[k] == cities[i]){
                        temp.erase(temp.begin()+k);
                    }
                }
                temp.push_back(cities[i]);
                for(int k=0; k<temp.size(); k++){
                    q.push(temp[k]);
                }
                final += 1;
            }
        }
    }
    answer = final;
    return answer;
}