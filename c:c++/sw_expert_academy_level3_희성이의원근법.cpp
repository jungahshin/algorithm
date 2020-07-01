// 6718. 희성이의 원근법
#include <iostream>
using namespace std;

int testcase, N;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        cin>>N;
        //1/1000을 해야 km로의 값이 나온다.
        int num;
        if(N<100){
            num = 0;
        }else if(100<=N && N<1000){
            num = 1;
        }else if(1000<=N && N<10000){
            num = 2;
        }else if(10000<=N && N<100000){
            num = 3;
        }else if(100000<=N && N<1000000){
            num = 4;
        }else{
            num = 5;
        }
        cout<<"#"<<i+1<<" "<<num<<"\n";
    }
    return 0;
}