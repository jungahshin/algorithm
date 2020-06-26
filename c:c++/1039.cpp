//교환
#include <iostream>
#include <cstring>

using namespace std;

int k;
string s;
int final = 0;
int DP[1000001][11];

int go(int num, string s)
{
    if(num == k){
        return stoi(s);
    }

    int &temp = DP[stoi(s)][num];
    if(temp != -1){
        return temp;
    }

    for(int i=0; i<s.size()-1; i++){
        for(int j=i+1; j<s.size(); j++){
            swap(s[i], s[j]);
            if(s[0] != '0'){
                // cout<<"S"<<s<<"num"<<num<<"\n";
                // cout<<"temp"<<temp<<"\n";
                temp = max(temp, go(num+1, s));
            }
            swap(s[i], s[j]);
        }
    }

    return temp;
}

int main()
{   
    cin>>s>>k;
    memset(DP, -1, sizeof(DP));
    cout<<go(0, s)<<"\n";
    return 0;
}