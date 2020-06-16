//폰트
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
string s;
vector<string> v;
int total_num = 0;
int arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int a[26] = {0, };
int all = 0;

void dfs(int num, int status)
{
    if(num == n)
    {
        if(status == all)
        {
            total_num++;
        }
        return;
    }

    //넣어
    dfs(num+1, status | a[num]);
    //안넣어
    dfs(num+1, status);
}

int main(){
    cin>>n;

    for(int i=0; i<26; i++)
    {
        all = all | (1<<(arr[i]-'a')) ;
    }

    for(int i=0; i<n; i++)
    {
        cin>>s;
        v.push_back(s);
        for(int j=0; j<s.size(); j++)
        {
            a[i] = a[i] | (1<<(s[j]-'a'));
        }
    }

    dfs(0, 0);

    cout<<total_num<<"\n";

    return 0;
}