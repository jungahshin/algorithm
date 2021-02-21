// 뉴스클러스터링
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <iostream>
 
using namespace std;
 
vector<string> s1;
vector<string> s2;
 
int solution(string str1, string str2) {
    int answer = 0;
    int kyo = 0; // 교집합
    int hab = 0; // 합집합
    
    // 두글자씩 끊을 때 모두 영문자로 구성된 쌍만 유효하다.
    for(int i=0; i<str1.size()-1; i++){
        if(('a'<=str1[i] && str1[i]<='z' || 'A'<=str1[i] && str1[i]<='Z') && ('a'<=str1[i+1] && str1[i+1]<='z' || 'A'<=str1[i+1] && str1[i+1]<='Z')){
            string temp = "";
            temp += tolower(str1[i]);
            temp += tolower(str1[i+1]);
            s1.push_back(temp);
        }
    }
        
    for(int i=0; i<str2.size()-1; i++){
        if(('a'<=str2[i] && str2[i]<='z' || 'A'<=str2[i] && str2[i]<='Z') && ('a'<=str2[i+1] && str2[i+1]<='z' || 'A'<=str2[i+1] && str2[i+1]<='Z')){
            string temp = "";
            temp += tolower(str2[i]);
            temp += tolower(str2[i+1]);
            s2.push_back(temp);
        }
    }
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    // 합집합
    vector<string> buff1(s1.size() + s2.size());
    auto iter1 = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), buff1.begin());
    buff1.erase(iter1, buff1.end());
    hab = buff1.size();
    
    // 교집합
    vector<string> buff2(s1.size() + s2.size());
    auto iter2 = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), buff2.begin());
    buff2.erase(iter2, buff2.end());
    kyo = buff2.size();
 
    if(kyo==0 && hab==0){
        return 65536;
    }
    
    float similarity = (float)kyo/hab;
    answer = similarity * 65536;
    
    return answer;
}