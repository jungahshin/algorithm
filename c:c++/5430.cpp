// AC
// 그냥 쉽게 reverse를 사용하려고 하면 매번 최대 10만개를 옮기다보니....당연,,, 시간초과가 난다.(10만*10만)
// 투포인터로 시간을 매우 줄일 수 있다...!
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
 
int testcase, n;
string p, arr;
 
int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>p;
        cin>>n;
        cin>>arr;
        string tmp = "";
        vector<int> dq;
        for(int j=0; j<arr.size(); j++){
            if(arr[j]!='[' && arr[j]!=']' && arr[j]!=','){
                tmp += arr[j];
            }else{
                if(tmp.size()>0){
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }
 
        int Start = 0, End = dq.size()-1;
        bool isAscend = true;
 
        bool isError = false;
        for(int j=0; j<p.size(); j++){
            if(p[j]=='R'){
                isAscend = !isAscend;
                swap(Start, End);
            }else{
                if(isAscend){
                    if(Start>End){
                        isError = true;
                        break;
                    }else{
                        Start++;
                    }
                }else{
                    if(Start<End){
                        isError = true;
                        break;
                    }else{
                        Start--;
                    }
                }
            }
        }
        
        if(isError){
            cout<<"error"<<"\n";
            continue;
        }
 
        if(isAscend){
            if(Start>End) cout<<"[]"<<"\n";
            else{
                string ans = "";
                ans += '[';
                for(int j=Start; j<=End; j++){
                    ans += to_string(dq[j]);
                    ans += ',';
                }
                ans.pop_back();
                ans += ']';
                cout<<ans<<"\n"; 
            }            
        }else{
            if(Start<End) cout<<"[]"<<"\n";
            else{
                string ans = "";
                ans += '[';
                for(int j=Start; j>=End; j--){
                    ans += to_string(dq[j]);
                    ans += ',';
                }
                ans.pop_back();
                ans += ']';
                cout<<ans<<"\n"; 
            }
        }
    }
 
    return 0;
}