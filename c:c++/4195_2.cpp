//친구 네트워크
#include <map>
#include <iostream>
using namespace std;

int testcase, f;
string s1, s2;
int a[200010] = {0, };
int num[200010] = {0, };

int find(int i){
    if(a[i] == i){
        return i;
    }else{
        return a[i] = find(a[i]);
    }
}

int go(int x, int y){
    int start = find(x);
    int end = find(y);

    if(start != end){
        a[start] = end;
        num[end] += num[start];
    }

    return num[end];
}

int main(){
    //시간을 줄여준다..!
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>testcase;
    
    for(int i=0; i<testcase; i++){
        cin>>f;

        map<string, int> relation;//map에 각 string(사람)마다 고유한 int(숫자)를 부여한다.

        //초기화
        int idx = 0;
        for(int j=0; j<(f*2); j++){
            a[j] = j;
            num[j] = 1;
        }

        for(int j=0; j<f; j++){
            cin>>s1>>s2;
            if(relation.count(s1) == 0){//없으면 추가
                relation[s1] = idx;
                idx++;
            }         
            if(relation.count(s2) == 0){
                relation[s2] = idx;
                idx++;
            }   
            cout<<go(relation[s1], relation[s2])<<"\n";
        }
    }
}