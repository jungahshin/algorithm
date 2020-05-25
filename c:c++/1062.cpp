//가르침
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
string s;
vector<char> v;
vector<string> words;
int check[30] = {0, };
map<char, int> total;
int ans = 0;
int visited[30] = {0, };

void choose(int final, int num, int idx){
    if(num == final){
        for(int i=0; i<v.size(); i++){
            if(visited[i] == true){
                check[v[i]-'a'] = 1;
            }
        }
        //몇개의 단어를 읽을 수 있는 지 센다.
        int temp_num = 0;
        for(int i=0;  i<words.size(); i++){
            string temp = words[i];
            bool go = true;
            for(int j=0; j<temp.size(); j++){
                if(check[temp[j]-'a'] == 0){//배우지 않은 글자.
                    go = false;
                }
            }
            if(go == true){
                temp_num++;
            }
        }
        ans = max(ans, temp_num);
        for(int i=0; i<v.size(); i++){
            if(visited[i] == true){
                check[v[i]-'a'] = 0;
            }
        }
        return;
    }

    for(int i=idx; i<v.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        choose(final, num+1, i);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>s;
        words.push_back(s);
        for(int j=0; j<s.size(); j++){
            if(s[j] != 'a' && s[j] != 'n' && s[j] != 't' && s[j] != 'i' && s[j] != 'c'){
                if(total.count(s[j]) == 0){
                    v.push_back(s[j]);
                    total[s[j]] = 1;
                }
            }
        }
    }
    check['a'-'a'] = 1;
    check['n'-'a'] = 1;
    check['t'-'a'] = 1;
    check['i'-'a'] = 1;
    check['c'-'a'] = 1;
    if(k < 5){//하나도 읽을 수 없다.
        cout<<"0"<<"\n";
        return 0;
    }else{
        if(k-5>=v.size()){
            cout<<words.size()<<"\n";
            return 0;
        }else{
            choose(k-5, 0, 0);//k-5개를 뽑아야한다.
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}