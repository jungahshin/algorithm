// 1244. [S/W 문제해결 응용] 2일차 - 최대 상금
#include <iostream>
#include <vector>
using namespace std;

string a;
vector<char> v;
int testcase, count_;
int final = 0;
vector<int> f;
int visited[1000000][20] = {0, }; 

void go(string num, int count_change){//string, 바뀐 횟수
    if(count_change == count_){
        final = max(final, stoi(num));
        return;
    }
    if(count_change > count_){
        return;
    }
    for(int h=0; h<v.size(); h++){//기준 idx
        for(int i=h+1; i<v.size(); i++){//바뀔 대상
            vector<char> temp;
            for(int k=0; k<num.size(); k++){
                temp.push_back(num[k]);
            }
            temp[h] = num[i];
            temp[i] = num[h];
            string b;
            for(int k=0; k<temp.size(); k++){
                b += temp[k];
            }
            //바뀐 string b로 dfs진행
            if(visited[stoi(b)][count_change+1] == 0){
                visited[stoi(b)][count_change+1] = 1;
                go(b, count_change+1);
            }
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>a;
        final = 0;
        v.clear();
        for(int j=0; j<a.size(); j++){
            v.push_back(a[j]);
        }
        cin>>count_;
        go(a, 0);
        f.push_back(final);
    }
    for(int i=0; i<f.size(); i++){
        cout<<"#"<<i+1<<" "<<f[i]<<"\n";
    }
}