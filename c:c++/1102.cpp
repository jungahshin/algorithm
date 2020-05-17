//발전소
#include <iostream>
using namespace std;

int n, p;
string s;
int a[17][17] = {0, };
int DP[1<<16][17] = {0, };
int num;//돌아가는 발전소 수
int bit;
int total = 987654321;

int fix(int bit_temp, int num_temp, int idx){
    if(DP[bit_temp][idx] != -1){
        return DP[bit_temp][idx];
    }

    cout<<"bit"<<bit_temp<<"num"<<num_temp<<"idx"<<idx<<"\n";

    if(num_temp == p){
        //최소비용구하기
        return 0;
    }
    DP[bit_temp][idx] = 987654321;
    
    for(int i=1; i<=n; i++){
        if((bit_temp & (1<<(i-1))) != 0){//이미 고친애들이 다른 것을 고칠 수 있다.
            for(int j=1; j<=n; j++){
                //i가 j를 고친다.
                if((bit_temp & (1<<(j-1))) == 0){//j를 고치지 않았다.
                    int temp = bit_temp | (1<<(j-1));
                    DP[bit_temp][idx] = min(DP[bit_temp][idx], fix(temp, num_temp+1, j)+a[i][j]);   
                }
            }
        }
    }

    return DP[bit_temp][idx];
}

int main(){
    memset(DP, -1, sizeof(DP));
    cin>>n;//총 발전소의 개수
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'Y'){
            bit = bit | (1<<i);//i번째 발전소가 정상
            num++;
        }
    }
    cout<<"bit"<<bit<<"\n";
    cin>>p;
    if(p == 0){
        total = 0;
        cout<<total<<"\n";
        return 0;
    }
    if(num == 0 && p>0){
        total = -1;
        cout<<total<<"\n";
        return 0;
    }
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'Y'){
            total = min(total, fix(bit, num, i+1));            
        }
    }
    cout<<total<<"\n";
    return 0;
}