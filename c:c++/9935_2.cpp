//문자열 폭발
#include <iostream>
#include <vector>
using namespace std;

string s, explode, ans;
char result[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s>>explode;
        string S = "";
        for(int i=0; i<s.size(); i++){
            ans += s[i];
            if(ans[ans.size()-1] == explode[explode.size()-1] && i>=explode.size()-1){
                bool check = true;
                for(int j=1; j<explode.size(); j++){
                    if(ans[ans.size()-1-j] != explode[explode.size()-1-j]){
                        check = false;
                        break;
                    }
                }
                if(check == true){
                    for(int k=0; k<explode.size(); k++){
                        ans.pop_back();
                    }
                }
            }
        }
        if(ans == ""){
            cout<<"FRULA"<<"\n";
        }else{
            cout<<ans<<"\n";
        }
    
    return 0;
}