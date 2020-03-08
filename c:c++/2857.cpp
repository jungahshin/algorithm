//FBI
#include <iostream>
#include <vector>
using namespace std;

string s;
vector<int> FBI;

int main(){
    for(int i=0; i<5; i++){
        cin>>s;
        bool check = false;
        for(int j=0; j<s.size(); j++){
            if(s[j] == 'F'){//뒤에 바로 BI가 오는지 확인!
                if(s[j+1] == 'B' && s[j+2] == 'I'){
                    check = true;
                    break;
                }
            }
        }
        if(check == true){//FBI요원
            FBI.push_back(i+1);
        }
    }
    if(FBI.size()>0){
        for(int i=0; i<FBI.size(); i++){
            cout<<FBI[i]<<" ";
        }        
        cout<<"\n";
    }else{
        cout<<"HE GOT AWAY!"<<"\n";
    }
    return 0;
}