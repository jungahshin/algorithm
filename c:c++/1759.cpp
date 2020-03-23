//암호 만들기
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int l, c;
char s;
vector<char> alpha;
map<char, int> vowel;
int visited[16] = {0, };
vector<string> final;

void check(){//최소 1개의 모음과 최소 2개의 자음으로 이루어져 있는지 확인
    int temp_vowel = 0;
    int temp_else = 0;
    for(int i=0; i<alpha.size(); i++){
        if(visited[i] == true){
            if(vowel.count(alpha[i]) == 0){//자음
                temp_else++;
            }else{//모음
                temp_vowel++;
            }
        }
    }
    if(temp_else>=2 && temp_vowel>=1){//가능한 암호
        vector<char> temp;
        for(int i=0; i<alpha.size(); i++){
            if(visited[i] == true){
                temp.push_back(alpha[i]);
            }
        }
        string pw = "";
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++){
            pw += temp[i];
        }
        final.push_back(pw);
    }
}

void go(int idx, int num){
    if(num == l){
        check();
        return;
    }

    for(int i=idx; i<alpha.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        go(i, num+1);
        visited[i] = false;
    }
}

int main(){
    cin>>l>>c;
    for(int i=0; i<c; i++){
        cin>>s;
        alpha.push_back(s);
    }
    vowel['a'] = 0;
    vowel['e'] = 1;
    vowel['i'] = 2;
    vowel['o'] = 3;
    vowel['u'] = 4;
    go(0, 0);

    sort(final.begin(), final.end());
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }

    return 0;
}