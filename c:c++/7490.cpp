// 0만들기
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
int testcase, n;
char oper[3] = {'+', ' ', '-'};
vector<int> num;
vector<char> op;
vector<string> ans;
 
string trans()
{
    string s;
    s = to_string(num[0]);
    for(int i=0; i<op.size(); i++){
        s += op[i];
        s += to_string(num[i+1]);
    }
 
    return s;
}
 
int cal()
{
    vector<int> numTemp;
    vector<char> opTemp;
 
    string tmp = to_string(num[0]);
    for(int i=0; i<op.size(); i++){
        if(op[i]==' '){
            tmp += to_string(num[i+1]);
        }else{
            numTemp.push_back(stoi(tmp));
            tmp = "";
            tmp += to_string(num[i+1]);
            opTemp.push_back(op[i]);
        }
 
        if(i==op.size()-1){
            numTemp.push_back(stoi(tmp));
        }
    }
 
    int ans = numTemp[0];
    for(int i=0; i<opTemp.size(); i++){
        if(opTemp[i]=='+'){
            ans += numTemp[i+1];
        }else{
            ans -= numTemp[i+1];
        }
    }
    
    return ans;
}
 
void makeSeq(int n, int cnt)
{  
    if(cnt==n-1){
        if(cal()==0){
            ans.push_back(trans());
        }
        return;
    }
 
    for(int i=0; i<3; i++){
        op.push_back(oper[i]);
        makeSeq(n, cnt+1);
        op.pop_back();
    }
}
 
int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        num.clear();
        op.clear();
        ans.clear();
        cin>>n;
        for(int j=1; j<=n; j++){
            num.push_back(j);
        }
        makeSeq(n, 0);
        sort(ans.begin(), ans.end());
        for(int j=0; j<ans.size(); j++){
            cout<<ans[j]<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}