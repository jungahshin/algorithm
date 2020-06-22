//십자카드 문제
#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

int n;
int num = 0;

int clocknum(string v)
{
    int num = INT_MAX;
    for(int i=0; i<4; i++)//시작 idx
    {
        string s;
        int start = i;
        for(int j=0; j<4; j++)
        {
            if(start>3){
                start = 0;
            }
            s += v[start];
            start++;
        }
        int N;
        stringstream ss;
        ss.str(s);
        ss>>N;
        num = min(num, N);
    }

    return num;
}

int main()
{
    string temp;
    for(int i=0; i<4; i++)
    {
        cin>>n;
        temp += to_string(n);
    }

    //시계수 구하기
    int final = clocknum(temp);
    
    for(int i=1111; i<=9999; i++)
    {
        string temp2 = to_string(i);
        bool check = true;
        for(int j=0; j<temp2.size(); j++)
        {
            if(temp2[j] == '0')
            {
                check = false;
            }
        }
        if(check == true)
        {
            if(clocknum(temp2) == i)
            {
                num++;
                if(i == final)
                {
                    break;
                }
            }
        }
    }

    cout<<num<<"\n";
    return 0;
}