//2018kakao[1차] 뉴스클러스터링
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> A;
vector<string> B;

int solution(string str1, string str2) {
    int answer = 0;
    float final_a = 0;//교집합
    float final_b = 0;//합집합
    for(int i=0; i<str1.size()-1; i++){
        string temp = "";
        if((('a'<=str1[i] && str1[i]<='z') || ('A'<=str1[i] && str1[i]<='Z')) && (('a'<=str1[i+1] && str1[i+1]<='z') || ('A'<=str1[i+1] && str1[i+1]<='Z'))){
            temp += tolower(str1[i]);
            temp += tolower(str1[i+1]);
            A.push_back(temp);
        }
    }
    for(int i=0; i<str2.size(); i++){
        string temp = "";
        if((('a'<=str2[i] && str2[i]<='z') || ('A'<=str2[i] && str2[i]<='Z')) && (('a'<=str2[i+1] && str2[i+1]<='z') || ('A'<=str2[i+1] && str2[i+1]<='Z'))){
            temp += tolower(str2[i]);
            temp += tolower(str2[i+1]);
            B.push_back(temp);
        }
    }
    if(A.size() == 0 && B.size() == 0){//둘 집합 모두 공집합일 경우, 1을 출력한다.
        answer = 1*65536;
        return answer;
    }else{
        int visited[1000] = {0, };
        for(int i=0; i<A.size(); i++){//A의 원소를 기준을 같은 것을 파악한다.
            if(!visited[i]){
                int a_num = 0;
                int b_num = 0;
                for(int j=i; j<A.size(); j++){
                    if(A[i] == A[j] && !visited[j]){
                        visited[j] = 1;
                        a_num++;
                    }
                }
                for(int j=0; j<B.size(); j++){
                    if(A[i] == B[j]){
                        b_num++;
                    }
                }
                final_a += min(a_num, b_num);
                final_b += max(a_num, b_num);   
            }
        }
        int visited_b[1000] = {0, };
        for(int i=0; i<B.size(); i++){
            if(!visited_b[i]){
                int a_num = 0;
                int b_num = 0;
                bool check = false;
                for(int j=i; j<B.size(); j++){
                    if(B[i] == B[j] && !visited_b[j]){
                        visited_b[j] = 1;
                        b_num++;
                    }
                }
                for(int j=0; j<A.size(); j++){
                    if(B[i] == A[j]){
                        check = true;
                        break;
                    }
                }
                if(check == true){
                    continue;
                }
                final_b += max(b_num, a_num);    
            }
        }
    }
    answer = ((float)final_a/(float)final_b)*65536;
    return answer;
}