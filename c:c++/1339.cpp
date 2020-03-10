//단어 수학
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string temp;
vector<string> s;//단어 저장
vector<char> c;//알파벳 저장
int score[50] = {0, };
int final = 0;

//알파벳을 next_permutation으로 순열.
//그리고 그 순서에 맞게 9부터 숫자 지정(arr[c[i]-'0'] = 9)
//숫자 지정 후 모든 단어들을 돌면서 점수 산정.

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        s.push_back(temp);
        for(int j=0; j<temp.size(); j++){
            bool check = false;
            for(int k=0; k<c.size(); k++){
                if(c[k] == temp[j]){//이미 있어
                    check = true;
                    break;
                }
            }
            if(check == false){//없으면 저장
                c.push_back(temp[j]);
            }
        }
    }
    //정렬해주기
    sort(c.begin(), c.end());

    do{
        //점수 지정
        for(int i=0; i<c.size(); i++){
            score[c[i]-'0'] = (9-i);
        }

        int final_temp = 0;
        for(int i=0; i<s.size(); i++){
            int score_temp = 0;
            int size = 1;
            for(int k=0; k<s[i].size()-1; k++){
                size *= 10;
            }
            for(int j=0; j<s[i].size(); j++){
                score_temp += (score[s[i][j]-'0']*size);
                size /= 10;
            }
            final_temp += score_temp;
        }

        final = max(final, final_temp);

    }while(next_permutation(c.begin(), c.end()));

    cout<<final<<"\n";
    return 0;
}