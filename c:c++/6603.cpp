#include<iostream>
#include<vector>
#include<string>
using namespace std;

int testcase = 1,t;
int num = 0;
int lotto_array[13] = {0, };//(6 < testcase < 13)
vector<string> final_array;

void dfs(int first, string str){
    if(num == 6){//최종 로또의 개수는 6이기 때문에 num의 수가 6이 되면 출력하고 끝낸다!
        final_array.push_back(str+"\n");//최종 완성된 로또 6개를 final_array에 넣는다.
    }
    for(int i=first+1; i<testcase; i++){
        num += 1;
        dfs(i, (str+to_string(lotto_array[i])+" "));//(str+space bar)값이 계속 쌓인다.
    }
    num -= 1;
}

int main(){

    while((testcase) != 0){// testcase가 0을 입력받으면 프로그램 끝!
        cin>>testcase;//엔터키 쳐야하나?-->no!
        for(int i=0; i<testcase; i++){
            cin>>t;//testcase의 크기 만큼 로또수를 입력받는다. (0 < t < 50)
            lotto_array[i] = t;
        }
        for(int i=0; i<testcase; i++){
            num = 1;
            dfs(i, (to_string(lotto_array[i])+" "));//lotto_array[i]가 string인지 확인하기!
        }
        //하나의 testcase가 끝나면 final_array에 enter값을 포함시킨다.
        final_array.push_back("\n");
    }
    //testcase를 0을 입력을 하면 이제 모든 final_array에 들어있던 값들을 출력한다.

    for(int i=0; i<final_array.size(); i++){
        cout<<final_array[i];
    }

    return 0;
}