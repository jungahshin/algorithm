//보물상자 비밀번호
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, k;
string v;
string v_copy;//회전시킬 때 이용
string v_temp = "";
vector<string> final;
int num = 0;
vector<pair<int, string>> print;
vector<int> really_final;

bool compare(const pair<int, string> &a, const pair<int, string> &b){
    return a.first>b.first;
}

void go(){
    while(1){
        //나올 수 있는 문자열 저장
        int temp = 0;
        v_temp = "";
        for(int i=0; i<v.size(); i++){
            v_temp += v[i];
            temp++;
            if(temp == n/4){
                final.push_back(v_temp);
                temp = 0;
                v_temp = "";
            }
        }
        //확인-->몇회전인지(n/4-1)이면 break;
        if(num == (n/4-1)){
            break;
        }
        //회전시킨다.
        v_copy = v;
        v_copy[0] = v[v.size()-1];
        for(int i=0; i<v.size()-1; i++){
            v_copy[i+1] = v[i];
        }
        v = v_copy;
        //회전 시키는 수 ++
        num++;
    }
    //16진수 ->10진수로 변환
    for(int i=0; i<final.size(); i++){
        char ch[100];
        for(int j=0; j<final[i].size(); j++){
            ch[j] = final[i][j];
        }
        int nDec = (int)strtol(ch, NULL, 16);
        print.push_back(make_pair(nDec, final[i]));
    }
    sort(print.begin(),  print.end(), compare);//내림차순
    //같은 수는 거른다.
    int temp__ = 0;
    for(int i=0; i<k; i++){
        if(print[i].first == print[i+1].first){
            temp__++;
        }
    }
    really_final.push_back(print[k-1+temp__].first);
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>k;
        cin>>v;
        go();
        v = "";
        num = 0;
        final.clear();
        print.clear();
    }
    for(int i=0; i<really_final.size(); i++){
        cout<<"#"<<i+1<<" "<<really_final[i]<<"\n";
    }
}