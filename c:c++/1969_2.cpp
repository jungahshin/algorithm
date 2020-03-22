//DNA(map 이용)
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
string s;
char map_[1001][51];
int alphabet[4] = {0, };
vector<pair<int, char>> v;
string final;

bool compare(const pair<int, char>&a, const pair<int, char>&b){
    if(a.first == b.first){
        return a.second>b.second;
    }else{
        return a.first<b.first;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            map_[i][j] = s[j];
        }
    }

    //열을 기준으로 가장 자주 나오는 알파벳을 선정
    for(int i=0; i<m; i++){//열
        memset(alphabet, 0, sizeof(alphabet));
        for(int j=0; j<n; j++){//행
            if(map_[j][i] == 'A'){
                alphabet[0]++;
            }else if(map_[j][i] == 'T'){
                alphabet[1]++;
            }else if(map_[j][i] == 'G'){
                alphabet[2]++;
            }else if(map_[j][i] == 'C'){
                alphabet[3]++;
            }
        }
        v.clear();
        v.push_back(make_pair(alphabet[0], 'A'));
        v.push_back(make_pair(alphabet[1], 'T'));
        v.push_back(make_pair(alphabet[2], 'G'));
        v.push_back(make_pair(alphabet[3], 'C'));
        sort(v.begin(), v.end(), compare);
        final += v[v.size()-1].second;//가장 많은 수 & 알파벳 순 앞
    }

    //Hamming Distance의 합 구하기
    int num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map_[i][j] != final[j]){
                num++;
            }
        }
    }
    cout<<final<<"\n";
    cout<<num<<"\n";
    return 0;
}