//맞춰봐
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n;
string s;
vector<int> v;
char c[11][11];

bool check(){
    int sum = 0;
    for(int i=v.size()-1; i>=0; i--){
        sum += v[i];
        if(c[i+1][v.size()] == '+' && sum<=0) return false;
        if(c[i+1][v.size()] == '-' && sum>=0) return false;
        if(c[i+1][v.size()] == '0' && (sum>0 || sum<0)) return false;
    }

    return true;
}

void go(int num){
    if(num>n){
        return;
    }

    if(num == n){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        exit(0);
    }

    for(int i=-10; i<=10; i++){
        v.push_back(i);
        if(check() == true){
            go(num+1);            
        }
        v.pop_back();
    }
}


int main(){
    cin>>n;
    cin>>s;
    int idx = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            c[i][j] = s[idx++];
        }
    }

    for(int i=-10; i<=10; i++){
        v.push_back(i);
        if(check() == true){
            go(1);
        }
        v.pop_back();
    }

    return 0;
}