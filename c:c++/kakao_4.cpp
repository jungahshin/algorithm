#include <string>
#include <vector>
#include<iostream>
using namespace std;
int question_num;
int count =0;
int queries_string_num = 0;
int words_string_num = 0;
// vector <int> split_string;
vector<int> answer;
vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};

void solution() {
    for(int j=0; j<queries.size(); j++){
        question_num = 0;
        for (int k=0; k<queries[j].size(); k++){//각 queries에 ?가 몇개 있는지
            if(queries[j][k] == '?'){
                question_num++;
            }
        }
        queries_string_num = queries[j].size() - question_num;

        int count = 0;
        for(int i=0; i<words.size(); i++){
            if(queries[j][0] == '?'){//?로 시작하면 뒤에서 부터 세기
                for(int h=(queries[j].size())-1; h>=0; h--){
                    if(words[i][h] == queries[j][h]){
                        words_string_num++;
                    }
                }
            }
            else if(queries[j][(queries[j].size())-1] == '?'){//마지막 부분이 ?이면->처음부터 비교
                for(int h=0; h<queries[j].size(); h++){
                    if(words[i][h] == queries[j][h]){
                        words_string_num++;
                    }
                }
            }
            if(words_string_num == queries_string_num && words[i].size() == queries[j].size()){
                count++;//queries에 대해 해당되는 words만큼 ++
            }
            words_string_num = 0;
        }
        answer.push_back(count);
    }
}



int main(){
    solution();

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<"\n";
    }
    return 0;

}
