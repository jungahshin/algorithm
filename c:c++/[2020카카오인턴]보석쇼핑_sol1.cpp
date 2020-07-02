//2020 카카오인턴 #3번(투포인터) solution#1
//보석 쇼핑
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<pair<int, int>> temp;//구간의 길이와 시작점을 저장
    map<string, int> kind;//각 보석 종류에 대한 수 저장
    int Start = 0;
    int End = 0;
    int kind_num = 0;
    int num = 0;
    
    for(int i=0; i<gems.size(); i++){
        if(kind.count(gems[i]) == 0){
            kind[gems[i]] = 1;
            kind_num++;
        }
    }
    kind.clear();
    
    while(Start<=End && End<gems.size()){
        if(num<kind_num){
            if(End<gems.size()){
                if(kind.count(gems[End]) == 0){
                    kind[gems[End]] = 1;
                    num++;
                }else{
                    kind[gems[End]]++; 
                }
                End++;
            }
        }else if(num>=kind_num){
            if(Start<=End){
                kind[gems[Start]]--;
                if(kind[gems[Start]] == 0){
                    kind.erase(gems[Start]);
                    num--;
                }
                Start++;                
            }
        }
        
        if(num==kind_num){//길이, 시작점 저장
            int a = Start;
            int b = End-1;
            temp.push_back(make_pair(b-a+1, a+1));
        }
    }
    
    sort(temp.begin(), temp.end());
    
    answer.push_back(temp[0].second);
    answer.push_back(temp[0].second+temp[0].first-1);
    
    return answer;
}