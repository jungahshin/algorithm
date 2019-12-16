//30
//3의 배수의 특징
// 1. 끝의 자리수가 0이여야 합니다.
// 2. 각 자리의 수의 합이 3의 배수여야 합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string n;
string final;
bool check;

bool desc(char a, char b){ 
    return a > b;
}

int main(){
    cin>>n;
    long long sum = 0;
    for(int i=0; i<n.size(); i++){
        sum += (n[i]-'0');
    }
    if(sum % 3 == 0){//각 자리수의 합이 3의 배수
        sort(n.begin(), n.end(), desc);//내림차순
        if(n[n.size()-1] == '0'){
            check = true;
            string str;
            long long temp = 0;
            for(int i=0; i<n.size(); i++){
                str += n[i];
            }
            final = str;
        }
    }
    if(check == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}