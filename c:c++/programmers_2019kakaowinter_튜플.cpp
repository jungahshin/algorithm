#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
vector<pair<int, vector<int>>> v;//원소들의 개수, 원소들 저장하는 벡터

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    int num = 0;
    string temp_s = "";
    for(int i=1; i<s.size()-1; i++){
        if(s[i] == '}'){
            num++;
            temp.push_back(stoi(temp_s));
            temp_s = "";
            v.push_back(make_pair(num, temp));
            num = 0;
            temp.clear();
        }else if(s[i] == '{'){
            continue;
        }else if(s[i] == ',' ){
            if(temp_s.size() == 0){
                continue;
            }
            num++;
            temp.push_back(stoi(temp_s));
            temp_s = "";
        }else{//숫자
            temp_s += s[i];
        }
    }
    sort(v.begin(), v.end());
    map<int, int> m;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<(v[i].second).size(); j++){
            int temp = (v[i].second)[j];
            if(m.count(temp) == 0){
                m[temp] = 1;
                answer.push_back(temp);
            }
        }
    }
    return answer;
}