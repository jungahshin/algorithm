//숫자고르기
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
vector<int> temp;
int v[102] = {0, };
int visited[101] = {0, };
bool check = false;
map<int, int> M;

void go(int a, int final, int num)//기준이 되는 수-final
{
    if(a == final)
    {
        check = true;
        return;
    }

    if(!visited[a])
    {
        visited[a] = 1;
        go(v[a], final, num+1);
    }

    if(check == true)
    {
        if(M.count(a) == 0)
        {
            temp.push_back(a);
            M[a] = 1;
        }
    }else
    {
        visited[a] = 0; 
    }
    
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>m;
        v[i] = m;
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            check = false;
            visited[i] = 1;
            go(v[i], i, 1);
            if(check == true)
            {
                if(M.count(i) == 0)
                {
                    temp.push_back(i);
                    M[i] = 1;
                }
            }else{
                visited[i] = 0;
            }
        }
    }
    
    sort(temp.begin(), temp.end());
    cout<<temp.size()<<"\n";

    for(int i=0; i<temp.size(); i++)
    {
        cout<<temp[i]<<"\n";
    }

    return 0;
}