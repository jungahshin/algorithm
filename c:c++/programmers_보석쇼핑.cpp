#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> m;
    int kind = 0;
    
    for(int i=0; i<gems.size(); i++){
        if(m.count(gems[i])==0){
            m[gems[i]] = 1;
            kind++;
        }
    }
    
    m.clear();
    
    int Start = 0;
    int End = 0;
    int tempKind = 0;
    vector<pair<int, int>> v;
    
    // End<=gems.size()인 이유는 End, Start의 경우 미리 계산할 곳을 가르키고 있기 때문에
    // ["A", "B", "B", "C", "A"]의 경우 Start = 1, End = 5를 가르키고 끝나버린다...
    while(Start<=End && End<=gems.size()){
        if(tempKind<kind){
            if(End==gems.size()) break;
            if(m.count(gems[End])==0){
                m[gems[End]] = 1;
                tempKind++;
            }else{
                m[gems[End]]++;
            }
            End++;
        }else{
            m[gems[Start]]--;
            if(m[gems[Start]]==0){
                m.erase(gems[Start]);
                tempKind--;
            }
            Start++;
        }
        
        if(tempKind==kind){
            // Start~End-1
            // Start+1, End(실질 번호->1번 진열대부터 시작)
            v.push_back(make_pair(End-Start, Start+1));   
        }
    }
    
    sort(v.begin(), v.end());
    
    answer.push_back(v[0].second);
    answer.push_back(v[0].first+v[0].second-1);
    
    return answer;
}