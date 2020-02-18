//디스크 컨트롤러
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int visited[501] = {0, };

int solution(vector<vector<int>> jobs) {
    int answer = 0;//가장 작은 평균 출력
    sort(jobs.begin(), jobs.end());//요청 시점순으로 정렬
    int start = jobs[0][0] + jobs[0][1];
    answer += jobs[0][1];
    visited[0] = 1;
    if(jobs.size() > 1){
        while(1){
            //모든 작업이 끝났는지 확인
            bool temp = false;
            for(int k=0; k<jobs.size(); k++){
                if(!visited[k]){
                    temp = true;
                }
            }
            if(temp == false){
                break;
            }
            bool check = false;
            vector<pair<int, int>> v;
            for(int i=1; i<jobs.size(); i++){
                //start>jobs[i].first이면 v에 넣어주고
                //v벡터에 있는 것들 중에 가장 작업시간이 작은 것 먼저 실행
                if(start >= jobs[i][0] && !visited[i]){
                    v.push_back(make_pair(jobs[i][1], jobs[i][0]));
                    check = true;
                }
            }      
            if(check == true){
                sort(v.begin(), v.end());
                start += v[0].first;
                answer += (start - v[0].second);
                for(int i=0; i<jobs.size(); i++){
                    if(jobs[i][0] == v[0].second && jobs[i][1] == v[0].first){
                        visited[i] = 1;
                    }
                }
                v.clear();
                continue;
            }
            start++;
        }
    }else{
        //딱 작업 소요시간만큼 걸린다.
        answer = jobs[0][1];
    }
    
    return answer/jobs.size();
}