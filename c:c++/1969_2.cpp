//DNA(map 이용)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
string s;
char map_[1001][51];
map<char, int> alphabet;
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
        alphabet.clear();
        alphabet['A'] = 0;
        alphabet['T'] = 0;
        alphabet['G'] = 0;
        alphabet['C'] = 0;
        for(int j=0; j<n; j++){//행
            if(map_[j][i] == 'A'){
                alphabet['A']++;
            }else if(map_[j][i] == 'T'){
                alphabet['T']++;
            }else if(map_[j][i] == 'G'){
                alphabet['G']++;
            }else if(map_[j][i] == 'C'){
                alphabet['C']++;
            }
        }
        v.clear();
        v.push_back(make_pair(alphabet['A'], 'A'));
        v.push_back(make_pair(alphabet['T'], 'T'));
        v.push_back(make_pair(alphabet['G'], 'G'));
        v.push_back(make_pair(alphabet['C'], 'C'));
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