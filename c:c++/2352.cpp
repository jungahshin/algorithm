//반도체 설계
#include <iostream>
#include <map>
using namespace std;

int n, m;
int connect[40002] = {0, };
int DP[40002] = {0, };
int DP2[40002] = {0, };
int DP_final[40002] = {0, };
int final = 0;
map<int, int> M;

int go(int temp, int temp2){
    if(DP[temp] != 0){
        return DP[temp];
    }

    for(int j=temp+1; j<=n; j++){
        if(M[j]>temp2){
            temp2 = M[j];
            DP[temp] = max(DP[temp], go(j, temp2)+1);
            break;
        }
    }

    return DP[temp];
}

int go2(int temp, int temp2){
    if(DP2[temp] != 0){
        return DP2[temp];
    }

    for(int j=temp2+1; j<=n; j++){
        if(connect[j]>temp){
            int next = connect[j];
            DP2[temp] = max(DP2[temp], go2(next, j)+1);
            break;
        }
    }

    return DP2[temp];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>m;
        connect[i+1] = m;
        M[m] = i+1;//거꾸로 저장
    }
    for(int i=1; i<=n; i++){//기준
        int temp = connect[i];
        int temp2 = i;
        DP[temp] = max(DP[temp], go(temp, temp2)+1);
        DP2[temp] = max(DP2[temp], go2(temp, temp2)+1);
        DP_final[temp] = max(DP[temp], DP2[temp]);
        final = max(final, DP_final[temp]);
    }
    cout<<final<<"\n";
    return 0;
}