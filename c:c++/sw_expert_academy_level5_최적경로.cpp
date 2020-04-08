// 1247. [S/W 문제해결 응용] 3일차 - 최적 경로
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int visited[11] = {0, };
vector<pair<int, int>> customer;
int n, testcase, company_x, company_y, home_x, home_y, customer_x, customer_y;
int final = INT_MAX;

void go(int num, int total, int idx){//이전 집 idx
    if(num==n){
        //마지막 고객집에서 집까지의 거리 더하기
        final = min(final, total+abs(customer[idx].first-home_x)+abs(customer[idx].second-home_y));
        return;
    }
    for(int i=0; i<customer.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            go(num+1, total+abs(customer[i].first-customer[idx].first)+abs(customer[i].second-customer[idx].second), i);
            visited[i] = 0;
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        memset(visited, 0, sizeof(visited));
        customer.clear();
        final = INT_MAX;
        cin>>n;
        cin>>company_x>>company_y;
        cin>>home_x>>home_y;
        for(int j=0; j<n; j++){
            cin>>customer_x>>customer_y;
            customer.push_back(make_pair(customer_x, customer_y));
        }
        for(int j=0; j<customer.size(); j++){
            //처음 시작이어서 회사출발
            if(!visited[j]){
                visited[j] = 1;
                go(1, abs(company_x-customer[j].first)+abs(company_y-customer[j].second), j);
                visited[j] = 0;
            }
        }
        cout<<"#"<<i+1<<" "<<final<<"\n";
    }
}