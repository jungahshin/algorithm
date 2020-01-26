// 1215. [S/W 문제해결 기본] 3일차 - 회문1
#include <iostream>
#include <vector>
using namespace std;

char a[9][9] = {0, };
int final = 0;
int len;
string s;
vector<int> num;

void go(){
    for(int i=0; i<8-(len-1); i++){//세로
        for(int j=0; j<8; j++){
            //(i, j)를 시작점으로
            //열로 len만큼 확인
            int temp_ = 0;
            for(int k=0; k<(len/2); k++){
                if(a[i+k][j] == a[(i+len-1)-k][j]){
                    temp_++;
                }
            }
            if(temp_ == (len/2)){
                final++;
            }
        }
    }
    for(int i=0; i<8; i++){//가로
        for(int j=0; j<8-(len-1); j++){
            //(i, j)를 시작점으로
            //행으로 len만큼 확인
            int temp = 0;
            for(int k=0; k<(len/2); k++){//열 증가
                if(a[i][j+k] == a[i][(j+len-1)-k]){
                    temp++;
                }
            }
            if(temp == (len/2)){//회문에 해당된다.
                final++;
            }
        }
    }
}

int main(){
    for(int t=0; t<10; t++){
        final = 0;
        cin>>len;
        for(int i=0; i<8; i++){
            cin>>s;
            for(int j=0; j<8; j++){
                a[i][j] = s[j];
            }
        }
        go();        
        num.push_back(final);
    }
    for(int i=0; i<num.size(); i++){
        cout<<"#"<<i+1<<" "<<num[i]<<"\n";
    }
}