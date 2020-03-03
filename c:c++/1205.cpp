//등수 구하기
#include <iostream>
using namespace std;

int ranking[51] = {0, };
int n, p, score;

int go(){
    if(p==n){
        if(score<=ranking[n-1]){//유진이가 들어가지 못한다.
            return -1;
        }else{//누군가가 반드시 쫓기고 유진이가 들어간다.
            int temp = 0;
            for(int i=0; i<n; i++){
                if(ranking[i]>score){
                    temp++;
                }else if(ranking[i]<score){
                    return temp+1;
                }
            }
        }
    }else if(p>n){//유진이가 위치 잡고 들어간다
        if(n==0){
            return 1;
        }
        int temp = 0;
        for(int i=0; i<n; i++){
            if(ranking[i]>score){
                temp++;
                if(i==(n-1)){
                    return temp+1;
                }
            }else if(ranking[i]<score){
                return temp+1;
            }else if(ranking[i]==score){
                if(i==(n-1)){
                    return temp+1;
                }
            }
        }
    }
    return 0;
}

int main(){
    cin>>n>>score>>p;
    for(int i=0; i<n; i++){
        cin>>ranking[i];
    }
    int final = go();
    cout<<final<<"\n";
}