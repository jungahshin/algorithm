// 사이클게임
#include <iostream>
using namespace std;
 
int n, m, a, b;
int connect[500001] = {0, };
 
int find(int a){
    if(a==connect[a]){
        return a;
    }
    return connect[a] = find(connect[a]);
}
 
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        connect[i] = i;
    }
 
    for(int i=0; i<m; i++){
        cin>>a>>b;
        int from = find(a);
        int to = find(b);
        if(from!=to){
            connect[from] = to;
        }else{
            cout<<i+1<<"\n";
            exit(0);
        }
    }
 
    cout<<"0"<<"\n";
    return 0;
}