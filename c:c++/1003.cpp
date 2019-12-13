//피보나치 함수
#include <iostream>
#include <vector>
using namespace std;

int testcase, n;
vector<pair<int, int>> final_;//testcase의 최종 값들 넣기
vector<pair<int, int>> num[41];//0과1 저장
int num_zero = 0;
int num_one = 0;

vector<pair<int, int>> fibonacci(int n) {//배열 반환
    if(num[n].size() > 0){//뭐라도 들어 있다면,
        num_zero = num[n][0].first;
        num_one = num[n][0].second;
        vector<pair<int, int>> temp;
        temp.push_back(make_pair(num_zero, num_one));
        return temp;
    }else{
        if (n == 0) {
            num_zero++;
            vector<pair<int, int>> temp_3;
            temp_3.push_back(make_pair(num_zero, 0));
            return temp_3;
        } else if (n == 1) {
            num_one++;
            vector<pair<int, int>> temp_4;
            temp_4.push_back(make_pair(0, num_one));
            return temp_4;
        } else {
            vector<pair<int, int>> temp_2;
            vector<pair<int, int>> temp_5;
            vector<pair<int, int>> final;
            temp_2 = fibonacci(n-1);
            temp_5 = fibonacci(n-2);
            num[n-1].push_back(make_pair(temp_2[0].first, temp_2[0].second));
            num[n-2].push_back(make_pair(temp_5[0].first, temp_5[0].second));
            final.push_back(make_pair(temp_2[0].first+temp_5[0].first, temp_2[0].second+temp_5[0].second));
            return final;
        }
    }
}


int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        cin>>n;
        num_zero = 0;
        num_one = 0;
        vector<pair<int, int>> temp;
        temp = fibonacci(n);
        final_.push_back(make_pair(temp[0].first, temp[0].second));
    }
    for(int i=0; i<final_.size(); i++){
        cout<<final_[i].first<<" "<<final_[i].second<<"\n";
    }
}