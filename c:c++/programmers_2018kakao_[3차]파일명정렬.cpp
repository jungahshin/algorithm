#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<pair<pair<string, int>, int>> v;//head, number, filesIdx 저장

bool compare(const pair<pair<string, int>, int> &a, const pair<pair<string, int>, int> &b){
    if(a.first.first == b.first.first){
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    //head부분은 대문자->소문자로 저장
    //number부분은 string에서 int로 변환해서 저장
    for(int i=0; i<files.size(); i++){
        string head = "";
        string number = "";
        int num = 0;
        bool check = false;
        for(int j=0; j<files[i].size(); j++){
            if(('a'<=files[i][j] && files[i][j]<='z') || ('A'<=files[i][j] && files[i][j]<='Z') || files[i][j] == ' ' || files[i][j] == '.' || files[i][j] == '-'){
                if(check == true){
                    break;
                }
                head += tolower(files[i][j]);
            }else{
                num++;
                check = true;
                if(num>5){
                    break;
                }
                number += files[i][j];
            }
        }
        v.push_back(make_pair(make_pair(head, stoi(number)), i));
    }
    stable_sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        answer.push_back(files[v[i].second]);
    }
    return answer;
}