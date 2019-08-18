//c++11-->시간초과
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
//6603번 로또 문제 개념 섞억서 num = 6일때가 아니라 
//for(int i=1; int i<=n; i++)로 num을 n으로 받아서 num=1, num=2, ....num = n일때 까지 쭉 진행
//if(num = n)일때 배열에 넣어 놓았던 입력 받았던 값들이랑 그에 해당하는 index+1의 값들의 집합이 일치하면 --> 일치하는 최대 집합 구하기

// dfs(int first, )
// for(int i=0; i<n; i++){
//     num += 1;
//     list[i]
// }
//final_list에는 입력받은 숫자들 중 num의 수만큼 들어가는 list(선택받은)
//num_array에는 입력받은 숫자들 전부가 들어가는 것(입력받을 때 넣는)
//first_line에는 선택받은 숫자들의 index+1값이 들어가는 것(첫째 줄 값)
vector<vector<string>> final_list;
int num_array[101];
int num = 0;
int num_2 = 0;
string tmp;
int n,m,t;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
    return internal;
}

void dfs(int first, string str, string num_){
    if(num == t){//최종 로또의 개수는 6이기 때문에 num의 수가 6이 되면 출력하고 끝낸다!
        //str의 값을 split을 해서 배열로 다시 넣어서 정렬해서 num도 split해서 배열에 넣어서 두개를 비교
        vector<string> str_split = split(str, '\n');//공백으로 나눈다.
        vector<string> num_split = split(num_, '\n');//어차피 순서대로 되어 있는 상태.

        sort(str_split.begin(), str_split.end());
        
//---------------------------------------------------------------------------------------
        for(int i=0; i<str_split.size(); i++){
            if(str_split[i] == num_split[i]){
                num_2 += 1;
                if(num_2 == str_split.size()){//모든 요소가 다 같아야 저장한다.
                    final_list.push_back(str_split);//일치하는 집합을 저장하는 리스트
                    num_2 = 0;
                    break;
                }
            }
        }
        num_2 = 0;
//-----------------------------------------------------------------------------------------------------

    }
    for(int i=first+1; i<n; i++){
        num += 1;
        dfs(i, str+to_string(num_array[i])+"\n", num_+to_string(i+1)+"\n");//비교하기 위해서 같은 형태로!
    }
    num -= 1;
}

int main(){
    cin>>n;
    
    if (n>100){
        return 0;
    }

    for(int i=0 ;i<n; i++){
        cin>>m;//enter?
        num_array[i] = m;
        if(m>100){
            return 0;
        }
    }

    for(int i=1; i<=n; i++){//겉에는 몇개를 할 건지
        t = i; 
        for(int j=0; j<n; j++){
            num = 1;
            dfs(j, to_string(num_array[j])+"\n", to_string(j+1)+"\n");
        }
    }

    //반드시 final_list에 들어있는 str중에 가장 마지막에 들어 있는 값이 가장 많은 값들을 가진 것이다!!!(n이 오름차순으로 진행되기 때문)
    vector<string> final = final_list[final_list.size()-1];
    cout<<final.size()<<"\n";
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
    return 0;
}

