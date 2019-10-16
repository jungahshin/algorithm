//연산자 끼워넣기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[12] = {0, };
int cal[4] = {0, };
vector<int> place;
vector<int> place_copy;
vector<int> place_copy_1;
vector<int> place_copy_2;
vector<int> place_copy_3;
vector<int> plus_;
vector<int> minus_;
vector<int> multi;
vector<int> division;
vector<pair<int, int>> final;
int n;
bool visited_plus[11];
bool visited_minus[11];
bool visited_multi[11];
bool visited_division[11];
vector<long long> print;

void copy(){
    place_copy.clear();
    for(int i=0; i<place.size(); i++){
        place_copy.push_back(place[i]);
    }
}

void copy_1(){
    place_copy_1.clear();
    for(int i=0; i<place_copy.size(); i++){
        place_copy_1.push_back(place_copy[i]);
    }
}

void copy_2(){
    place_copy_2.clear();
    for(int i=0; i<place_copy_1.size(); i++){
        place_copy_2.push_back(place_copy_1[i]);
    }
}

void copy_3(){
    place_copy_3.clear();
    for(int i=0; i<place_copy_2.size(); i++){
        place_copy_3.push_back(place_copy_2[i]);
    }
}

void go(){
    final.clear();
    long long final_num = 0;
    for(int i=0; i<plus_.size(); i++){
        final.push_back(make_pair(plus_[i], 1));
    }
    for(int i=0; i<minus_.size(); i++){
        final.push_back(make_pair(minus_[i], 2));
    }
    for(int i=0; i<multi.size(); i++){
        final.push_back(make_pair(multi[i], 3));
    }
    for(int i=0; i<division.size(); i++){
        final.push_back(make_pair(division[i], 4));
    }
    sort(final.begin(), final.end());

    for(int i=0; i<final.size(); i++){
        if(i == 0){
            if(final[i].second == 1){//덧셈
                final_num = a[i]+a[i+1];
            }else if(final[i].second == 2){//뺄셈
                final_num = a[i]-a[i+1];
            }else if(final[i].second == 3){//곱셈
                final_num = a[i]*a[i+1];
            }else if(final[i].second == 4){//나눗셈
                final_num = a[i]/a[i+1];
            }
        }else{//final_num에 계산해준다.
            if(final[i].second == 1){//덧셈
                final_num += a[i+1];
            }else if(final[i].second == 2){//뺄셈
                final_num -= a[i+1];
            }else if(final[i].second == 3){//곱셈
                final_num *= a[i+1];
            }else if(final[i].second == 4){//나눗셈
                if(final_num<0){
                    final_num = ((final_num*(-1))/a[i+1])*(-1);
                }else{
                    final_num = final_num/a[i+1];
                }
            }
        }
    }
    print.push_back(final_num);
}

void put_division(){
    copy_3();
    division.clear();
    for(int i=0; i<place_copy_3.size(); i++){
        if(visited_division[i] == true){
            division.push_back(place_copy_3[i]);
        }
    }
    int num_division = 0;
    for(int i=0; i<place_copy_3.size(); i++){
        if(visited_division[i] == true){
            place_copy_3.erase(place_copy_3.begin()+(i-num_division));
            num_division++;
        }
    }
    go();
}

void choose_division(int idx, int num){
    if(num == cal[3]){
        put_division();
        return;
    }
    for(int i=idx; i<place_copy_2.size(); i++){
        if(visited_division[i] == true) continue;
        visited_division[i] = true;

        choose_division(i, num+1);
        visited_division[i] = false;
    }
}

void put_multi(){
    copy_2();
    multi.clear();
    for(int i=0; i<place_copy_2.size(); i++){
        if(visited_multi[i] == true){
            multi.push_back(place_copy_2[i]);
        }
    }
    int num_multi = 0;
    for(int i=0; i<place_copy_2.size(); i++){
        if(visited_multi[i] == true){
            place_copy_2.erase(place_copy_2.begin()+(i-num_multi));
            num_multi++;
        }
    }
    choose_division(0, 0);
}

void choose_multi(int idx, int num){
    if(num == cal[2]){
        put_multi();
        return;
    }
    for(int i=idx; i<place_copy_1.size(); i++){
        if(visited_multi[i] == true) continue;
        visited_multi[i] = true;

        choose_multi(i, num+1);
        visited_multi[i] = false;
    }
}

void put_minus(){
    copy_1();
    minus_.clear();
    for(int i=0; i<place_copy_1.size(); i++){
        if(visited_minus[i] == true){
            minus_.push_back(place_copy_1[i]);
        }
    }
    int num_minus = 0;
    for(int i=0; i<place_copy_1.size(); i++){
        if(visited_minus[i] == true){
            place_copy_1.erase(place_copy_1.begin()+(i-num_minus));
            num_minus++;
        }
    }
    choose_multi(0, 0);
}

void choose_minus(int idx, int num){
    if(num == cal[1]){
        put_minus();
        return;
    }
    for(int i=idx; i<place_copy.size(); i++){
        if(visited_minus[i] == true) continue;
        visited_minus[i] = true;

        choose_minus(i, num+1);
        visited_minus[i] = false;
    }
}

void put_plus(){
    copy();
    plus_.clear();
    for(int i=0; i<place_copy.size(); i++){
        if(visited_plus[i] == true){
            plus_.push_back(place_copy[i]);
        }
    }
    int num_plus = 0;
    for(int i=0; i<place_copy.size(); i++){
        if(visited_plus[i] == true){
            place_copy.erase(place_copy.begin()+(i-num_plus));
            num_plus++;
        }
    }
    choose_minus(0, 0);
}

void choose_plus(int idx, int num){
    if(num == cal[0]){
        put_plus();
        return;
    }
    for(int i=idx; i<place.size(); i++){
        if(visited_plus[i] == true) continue;
        visited_plus[i] = true;

        choose_plus(i, num+1);
        visited_plus[i] = false;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<4; i++){
        cin>>cal[i];
    }
    for(int i=0; i<n-1; i++){
        place.push_back(i+1);
    }
    choose_plus(0, 0);
    sort(print.begin(), print.end());
    cout<<print[print.size()-1]<<"\n";//최대
    cout<<print[0]<<"\n";//최소

    return 0;
}