//1 ~ 10000 까지의 숫자에 8이 몇 개가 들어있는지 구하는 코드 작성.
#include<iostream>
#include<vector>
using namespace std;
int num=0;
// vector<string> eight;


int main(){
    for(int i=1; i<=10000; i++){
        if(i<10){//1의 자리 수
            if(i == 8){
                num++;
                cout<<num<<"\n";
            }
        }
        if(10<=i && i<100){//10의 자리 수
            int a = i / 10 % 10;//십의 자리
            int b = i % 10; //일의 자리
            if( a == 8 ){
                num++;
            }
            if( b == 8){
                num++;
            }
            cout<<num<<"\n";
        }
        if(100<=i && i<1000){//100의 자리 수 
            int a = i % 10;//일의 자리
            int b = i / 10 % 10; //십의 자리
            int c = i / 100 % 10; //백의 자리
            if(a == 8){
                num++;
            }
            if(b == 8){
                num++;
            }
            if(c == 8){
                num++;
            }
            cout<<num<<"\n";
        }
        if(1000<=i && i<10000){//1000의 자리 수
            int a = i % 10; //일의 자리
            int b = i / 10 % 10; //십의 자리
            int c = i / 100 % 10; //백의 자리
            int d = i / 1000 % 10; //천의 자리
            if(a == 8){
                num++;
            }
            if(b == 8){
                num++;
            }
            if(c == 8){
                num++;
            }
            if(d == 8){
                num++;
            }
            cout<<num<<"\n";
        }
        // string i_string = to_string(i);
        // eight.push_back(i_string);
        // for(int j=0; j<eight.size(); j++){
        //     cout<<eight[j]<<"\n";
            // if(eight[j] == '8'){
            //     num++;
            // }
        // }
        // eight.clear();
    }
    cout<<num<<"\n";
}