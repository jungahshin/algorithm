// 가장 큰 수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[100001] = {0, };

bool cmp(const string &a, const string &b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> final;
    
    // 문자로 정렬하면 앞의 숫자 순으로 정렬된다.
    for(int i=0; i<numbers.size(); i++){
        final.push_back(to_string(numbers[i]));
    }
    
    sort(final.begin(), final.end(), cmp);
    
    bool check = true;
    for(int i=0; i<final.size(); i++){
        if(final[i]!="0"){
            check = false;
        }
        answer += final[i];
    }
    
    if(check==true){
        answer = "0";
    }
    
    return answer;
}