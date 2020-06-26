//수 묶기
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;//합친
vector<int> a;//음수
vector<int> b;//양수
vector<int> final;
int check[10001] = {0, };
int ans = 0;
bool temp = false;
bool temp2 = false;

int main()
{
    cin>>n;
    int num = 0;
    for(int i=0; i<n; i++)
    {
        cin>>m;
        if(m<0)
        {
            a.push_back(m);
        }else{
            b.push_back(m);
        }
        v.push_back(m);
        if(m == 0){
            temp = true;
        }else if(m<0){
            num++;
        }
    }

    if(num%2 != 0){
        if(temp == true){//오름차순
            sort(v.begin(), v.end());
        }else{//내림차순
            v.clear();
            if(a.size()>0){
                sort(a.rbegin(), a.rend());
                for(int i=0; i<a.size(); i++)
                {
                    v.push_back(a[i]);
                }
            }
            if(b.size()>0){
                sort(b.begin(), b.end());
                for(int i=0; i<b.size(); i++)
                {
                    v.push_back(b[i]);
                }
            }            
        }

    }else{
        sort(v.begin(), v.end());
    }

    if(temp == true && (num%2 == 0)){
        temp = true;
    }else{
        temp = false;
    }


    for(int i=v.size()-1; i>=0; i--)
    {
        if(v[i] == 0 && temp == true){//그냥 0을 더하고 넘어가
            check[i] = 1;
            continue;
        }else{
            if(!check[i])
            {
                int a = v[i];
                check[i] = 1;
                if((i-1)>=0 && !check[i-1])
                {
                    check[i-1] = 1;
                    int b = v[i-1];
                    if((a*b)>(a+b))//묶어
                    {
                        final.push_back(a*b);
                    }else{
                        check[i-1] = 0;
                        final.push_back(a);
                    }
                }else{//혼자만 마지막으로 남은 경우
                    final.push_back(a);
                }       
            }            
        }
    }

    for(int i=0; i<final.size(); i++)
    {
        ans += final[i];
    }

    cout<<ans<<"\n";
    return 0;
}