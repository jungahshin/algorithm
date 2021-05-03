// 단어 뒤집기 2
#include <algorithm>
#include <iostream>
using namespace std;
 
string s;
 
int main()
{
    getline(cin, s);
    string ans = "";
    string tmp = "";
    bool check = false;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='<'){
            if(tmp.size()>0){
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                tmp = "";
            }
            check = true;
        }else if(s[i]=='>'){
            tmp += s[i];
            ans += tmp;
            tmp = "";
            check = false;
            continue;
        }else if(s[i]==' '){
            if(!check){
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                ans += s[i];
                tmp = "";
                continue;
            }
        }
 
        tmp += s[i];
        if(i==s.size()-1){
            reverse(tmp.begin(), tmp.end());
            ans += tmp;
        }
    }
 
    cout<<ans<<"\n";
    return 0;
}