//카드정렬하기(우선순위큐)
#include <iostream>
#include <queue>
using namespace std;

int n, k;
priority_queue<int, vector<int>, greater<int>> q;//우선순위큐를 오름차순으로 정렬..
int final = 0;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        q.push(k);
    }
    if(q.size() == 1){
        final = 0;
    }else{
        while(q.size() != 1){
            int temp = 0;
            temp += q.top();
            q.pop();
            temp += q.top();
            q.pop();
            q.push(temp);
            final += temp;
        }        
    }

    cout<<final<<"\n";
    return 0;
}