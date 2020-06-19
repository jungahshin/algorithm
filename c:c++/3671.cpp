//산업스파이의 편지
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int testcase;
string s;
int visited[10] = {0, };
int final = 0;
set<int> S;
vector<char> v;

bool check(int data){
    if (data < 2) return false;
    for (int i = 2; i * i <= data; i++)
    {
        if (data % i == 0) return false;
    }
    return true;
}

void choose(int num)
{
    if(num>s.size()){
        return;
    }

    if(v.size() != 0){
        string temp = "";
        for(int i=0; i<v.size(); i++){
            temp += v[i];
        }
        stringstream ss(temp);
        int n;
        ss >> n;
        if(S.find(n) == S.end()){//존재하지 않음
            S.insert(n);
            if(check(n) == true){//소수
                final++;
            }
        }
    }

    for(int i=0; i<s.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true; 
        v.push_back(s[i]);

        choose(num+1);
        visited[i] = false;
        v.pop_back();
    }
}

int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        final = 0;
        S.clear();
        memset(visited, 0, sizeof(visited));
        cin>>s;
        choose(0);
        cout<<final<<"\n";
    }
    return 0;
}