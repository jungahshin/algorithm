#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, op;
char oper[4] = {'+', '-', '*', '/'};
int num[101] = {0, };
vector<int> v;
int MIN = 987654321, MAX = -987654321;
 
int cal(){
    int temp = num[0];
    for(int i=1; i<n; i++){
        char OP = oper[v[i-1]];
        if(OP=='+'){
            temp += num[i];
        }else if(OP=='-'){
            temp -= num[i];
        }else if(OP=='*'){
            temp *= num[i];
        }else{
            temp /= num[i];
        }
    }
 
    return temp;
}
 
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
 
    for(int i=0; i<4; i++){
        cin>>op;
        for(int j=0; j<op; j++){
            v.push_back(i);
        }
    }
 
    do{
        int temp = cal();
        MAX = max(MAX, temp);
        MIN = min(MIN, temp);
    }while(next_permutation(v.begin(),v.end()));
 
    cout<<MAX<<"\n";
    cout<<MIN<<"\n";
 
    return 0;
}