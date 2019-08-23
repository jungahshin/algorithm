//숫자가 여러 개 들어있는 배열이 주어짐. 배열에서 숫자를 n개 뽑아서 다 더했을 때 그 합이 x보다 작은 경우의 수를 구하는 코드 작성.
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include <algorithm>

using namespace std;
vector<int> list;
vector<string> semi_final;//n개인 애들을 저장하는 배열
vector<string> final;//n개이면서 합이 x보다 작은 애들을 저장하는 배열
int n,m,x,a;
int num = 0;
int sum = 0;

void dfs(int first, string str){
    if(num == n){
        vector<string> final_split;
        istringstream iss(str);
        for(string str; iss >> str;)
            final_split.push_back(str);

        int sum = 0;
        for(int j=0; j<final_split.size(); j++){
            sum += stoi(final_split[j]);
        }
        if(sum < x){
            final.push_back(str);
        }
    }else{
        for(int i = first+1; i<m; i++){
            num += 1;
            dfs(i, str+to_string(list[i])+" ");
        }
    }
    num -= 1;
}

int main(){
    cin>>m;//숫자 몇개를 입력할건지(배열의 구성 요소)
    for(int i=0; i<m; i++){
        cin>>a;
        list.push_back(a);
    }
    cin>>n;//배열에서 숫자 총 몇개를 뽑을 건지..
    cin>>x;//합이 x보다 작은 경우의 수 구하기
    if(n>m){
        return 0;
    }
    
    for(int i=0; i<m; i++){
        num = 1;//첫 번째 수
        dfs(i, to_string(list[i])+" ");
    }

    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
    return 0;
}
