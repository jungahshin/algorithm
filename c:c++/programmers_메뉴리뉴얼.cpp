#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;
 
int bits[21] = {0, };
map<string, int> kind;
map<string, int> m;
vector<string> v[11];
int visited[11] = {0, };
 
bool cmp(const pair<int, string>&a, const pair<int, string> &b){
    return a.first>b.first;
}
 
// 각 코스요리 주문에서 조합에 해당되는 메뉴가 있는 지 확인
// s = "AB"이면, "ABCDE" 코스요리에서 "AB"가 있는지 확인 (O)
// s = "CD"이면, "BCFG" 코스요리에는 없다. (X)
void cal(vector<string> orders, vector<int> cours, string s) {
    int cnt = 0;
    for(int i=0; i<orders.size(); i++){
        int cmp = bits[i];
        bool check = true;
        for(int j=0; j<s.size(); j++){
            if((cmp & (1<<(s[j]-'A'))) == 0) {
                check = false;
                break;
            }
        }
        
        if(check==true){
            cnt++;
        }
    }
    
    // 각 조합이 몇 번 주문되었는지
    m[s] = cnt;
    // 개수별로 저장
    v[s.size()].push_back(s);
}
 
// 조합 구하기
void combin(string s, int num, int cnt, int idx, vector<string> orders, vector<int> course) {
    if(cnt==num){
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(visited[i]==true){
                temp += s[i];
            }
        }
        
        // "WX"와 "XW"모두 같은 값이기 때문에 sorting한다.
        sort(temp.begin(), temp.end());
        if(kind.count(temp)==0){
            kind[temp] = 1;
            cal(orders, course, temp);
        }
        return;
    }
    
    for(int i=idx; i<s.size(); i++){
        if(visited[i]==true) continue;
        visited[i] = true;
        combin(s, num, cnt+1, i, orders, course);
        visited[i] = false;
    }
}
 
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 각 주문의 bit값을 구하기
    for(int i=0; i<orders.size(); i++){
        int temp = 0;
        for(int j=0; j<orders[i].size(); j++){
            temp |= (1<<(orders[i][j]-'A'));
        }
        bits[i] = temp;
    }
    
    // 각 주문마다 개수에 맞게 조합 구하기
    for(int i=0; i<orders.size(); i++){
        int idx = 0;
        while(1){
            if(idx>=course.size()){
                break;
            }
            if(course[idx]<=orders[i].size()){
                combin(orders[i], course[idx], 0, 0, orders, course);
            }
            idx++;
        }
    }
    
    // 마지막으로, 코스요리가 될 수 있는 구성(개수가 같으면 더 자주 주문된 구성으로)을 선별
    for(int i=0; i<course.size(); i++){
        int level = course[i];
        vector<pair<int, string>> tmp;
        for(int j=0; j<v[level].size(); j++){
            tmp.push_back(make_pair(m[v[level][j]], v[level][j]));
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i].first==tmp[0].first && tmp[i].first>=2){ // 2번이상 주문되어야한다.
                answer.push_back(tmp[i].second);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}