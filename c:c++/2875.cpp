//대회 or 인턴
#include <iostream>
using namespace std;

int n, m, k;
int final = 0;

void go(){//여자를 기준으로 진행
    for(int i=0; i<=k; i++){//인턴에 참가하는 여자
        int intern_women = i;
        int intern_men = (k-i);
        int women = n-i;//대회에 참가하는 여자
        int men = m-(k-i);//대회에 참가하는 남자
        if(0 <= women && 0 <= men){
            int gr_women = women/2;
            int gr_men = men/1;

            int team = min(women/2, men/1);
            final = max(final, team);
        }
    }
}

int main(){
    cin>>n>>m>>k;
    go();
    cout<<final<<"\n";
}