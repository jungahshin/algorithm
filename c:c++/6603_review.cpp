//로또 복습
#include <iostream>
#include <vector>
using namespace std;

int k;
int a[14] = {0, };
int visited[14] = {0, };
vector<string> v;

void check(){
    string str;
    for(int i=0; i<k; i++){
        if(visited[i] == true){
            str += to_string(a[i]);
            str += " ";
        }
    }
    v.push_back(str);
    v.push_back("\n");
}

void go(int num, int index){
    if(num == 6){
        check();
        return;
    }

    for(int i=index; i<k; i++){
        if(visited[i] == true) continue;
        visited[i] = true;

        go(num+1, i);
        visited[i] = false;
    }
}

int main(){
    while(1){
        cin>>k;
        if(k == 0){
            break;
        }else{
            for(int i=0; i<k; i++){
                cin>>a[i];
            }
            for(int i=0; i<k; i++){
                visited[i] = 0;
            }
            go(0, 0);
            v.push_back("\n");
        }
    }
    //출력
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    return 0;
}