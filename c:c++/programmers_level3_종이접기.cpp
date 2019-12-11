//종이 접기
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> answer;
int n;

int main() {
    cin>>n;
    for(int i=0; i<n; i++){//n번 반복하는 것
        if(i == 0){
            answer.push_back(0);
        }else{
            vector<int> temp;
            for(int k=0; k<answer.size(); k++){
                temp.push_back(answer[k]);
            }
            temp.push_back(0);
            for(int k=answer.size()-1; k>=0; k--){
                if(answer[k] == 0){
                    temp.push_back(1);
                }else{
                    temp.push_back(0);
                }
            }
            answer.clear();
            for(int k=0; k<temp.size(); k++){
                answer.push_back(temp[k]);
            }
        }
    }
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i];
    }
    cout<<"\n";
}