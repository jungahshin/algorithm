//베스트 앨범
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[10001] = {0, };

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //일단 장르별로 나눈다.(장르, 총 재생 수)
    vector<pair<int, string>> a;
    for(int i=0; i<genres.size(); i++){
        if(!visited[i]){
            int total = 0;
            total += plays[i];
            visited[i] = 1;
            for(int j=i+1; j<genres.size(); j++){
                if(!visited[j] && (genres[i] == genres[j])){
                    visited[j] = 1;
                    total += plays[j];
                }
            }
           a.push_back(make_pair(total, genres[i]));
        }
    }
    sort(a.begin(), a.end());//총 재생 수로 정렬
    
    for(int i=a.size()-1; i>=0; i--){
        vector<pair<int, int>> v;
        for(int j=0; j<genres.size(); j++){
            if(a[i].second == genres[j]){
                v.push_back(make_pair(plays[j], j));//오름차순
            }
        }
        sort(v.begin(), v.end(), compare);
        if(v.size() == 1){//1개->1개
            answer.push_back(v[0].second);
        }else{//2개 이상->2개
            answer.push_back(v[0].second);
            answer.push_back(v[1].second);
        }
        v.clear();
    }
    
    return answer;
}