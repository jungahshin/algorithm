//배
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<int> crain;
vector<int> box;
vector<int> temp;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        crain.push_back(a);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>b;
        box.push_back(b);
    }

    //내림차순 정렬
    sort(box.begin(), box.end(), greater<int>());
    sort(crain.begin(), crain.end(), greater<int>());

    int num = 0;

    if(box[0]>crain[0]){
        cout<<"-1"<<"\n";
    }else{
        while(!box.empty()){
            num++;
            int idx = 0;
            for(int i=0; i<box.size(); i++){
                if(idx == crain.size()){
                    break;
                }
                if(box[i]<=crain[idx]){
                    idx++;
                    box.erase(box.begin()+i);
                    i = i-1;
                }
            }
        }        
        cout<<num<<"\n";
    }
    return 0;
}