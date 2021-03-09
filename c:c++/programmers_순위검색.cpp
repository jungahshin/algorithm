#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
 
using namespace std;
 
vector<int> db[4][3][3][3]; // 각 상태에 따른 점수를 저장
 
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i=0; i<info.size(); i++){
        string word = "";
        int cnt = 0;
        int a, b, c, d, score = 0;
        for(istringstream is(info[i]); is >> word;)
        {
            if(cnt==0){
                if(word=="cpp"){
                    a = 0;
                }else if(word=="java"){
                    a = 1;
                }else{
                    a = 2;
                }
            }else if(cnt==1){
                if(word=="backend"){
                    b = 0;
                }else{
                    b = 1;
                }
            }else if(cnt==2){
                if(word=="junior"){
                    c = 0;
                }else{
                    c = 1;
                }
            }else if(cnt==3){
                if(word=="chicken"){
                    d = 0;
                }else{
                    d = 1;
                }
            }else{
                score = stoi(word);
            }
            cnt++;
        }
                
        db[a][b][c][d].push_back(score);
    }
    
    // db벡터들을 sorting해준다 -> 뒤에서 lower_bound를 해주기 위해서
    for(int i=0; i<=2; i++){
        for(int j=0; j<=1; j++){
            for(int k=0; k<=1; k++){
                for(int l=0; l<=1; l++){
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end()); 
                }
            }
        }
    }
    
    for(int i=0; i<query.size(); i++){
        string word = "";
        int cnt = 0;
        int a1, a2, b1, b2, c1, c2, d1, d2;
        int score = 0;
        for(istringstream is(query[i]); is >> word;)
        {
            if(word=="and") continue;
            if(cnt==0){
                if(word=="cpp"){
                    a1 = 0, a2 = 0;
                }else if(word=="java"){
                    a1 = 1, a2 = 1;
                }else if(word=="python"){
                    a1 = 2, a2 = 2;
                }else{
                    a1 = 0, a2 = 2;
                }
            }else if(cnt==1){
                if(word=="backend"){
                    b1 = 0, b2 = 0;
                }else if(word=="frontend"){
                    b1 = 1, b2 = 1;
                }else{
                    b1 = 0, b2 = 1;
                }
            }else if(cnt==2){
                if(word=="junior"){
                    c1 = 0, c2 = 0;
                }else if(word=="senior"){
                    c1 = 1, c2 = 1;
                }else{
                    c1 = 0, c2 = 1;
                }
            }else if(cnt==3){
                if(word=="chicken"){
                    d1 = 0, d2 = 0;
                }else if(word=="pizza"){
                    d1 = 1, d2 = 1;
                }else{
                    d1 = 0, d2 = 1;
                }
            }else{
                score = stoi(word);
            }
            cnt++;
        }
        
        int ans = 0;
        for(int i=a1; i<=a2; i++){
            for(int j=b1; j<=b2; j++){
                for(int k=c1; k<=c2; k++){
                    for(int l=d1; l<=d2; l++){
                        int n =  db[i][j][k][l].size();
                        int idx = lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score) - db[i][j][k][l].begin();
                        ans += (n-idx);                         
                    }
                }
            }
        }
 
        answer.push_back(ans);
    }
    
    return answer;
}