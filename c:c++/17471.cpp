//게리맨더링
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;

int population[100] = {0, };
int a[100][100] = {0, };
int n, near_num, near_region;
int total = 0;
int visited[100] = {0, };
int visited_copy[100] = {0, };
int final = INT_MAX;
int total_pop = 0;
bool possible = false;
vector<int> v;

void copy(){
    for(int i=1; i<n+1; i++){
        visited_copy[i] = visited[i];
    }
}

void check(){
    copy();
    queue<int> q_check;
    for(int i=1; i<n+1; i++){
        if(visited_copy[i] == 0){
            q_check.push(i);
            break;
        }
    }
    while(!q_check.empty()){
        int x = q_check.front();
        visited_copy[x] = 1;
        q_check.pop();

        for(int k=1; k<n+1; k++){
            if(a[x][k] == 1 && !visited_copy[k] && !visited[k]){
                visited_copy[k] = 1;
                q_check.push(k);
            }
        }
    }
    bool temp = false;
    for(int i=1; i<n+1; i++){
        if(visited_copy[i] == 0){
            temp = true;
        }
    }
    if(temp == false){
        possible = true;
        final = min(final, abs(total - (total_pop-total)));
    }
}

void check_non(){
    queue<int> q;
    for(int i=1; i<n+1; i++){
        if(visited[i] == 1){
            q.push(i);
            break;
        }
    }
    int visited_check[100] = {0, };
    while(!q.empty()){
        int x = q.front();
        visited_check[x] = 1;
        q.pop();

        for(int k=1; k<n+1; k++){
            if(a[x][k] == 1 && !visited_check[k] && visited[k]){
                visited_check[k] = 1;
                q.push(k);
            }
        }
    }
    int temp_check = 0;
    for(int i=0; i<v.size(); i++){
        if(visited_check[(v[i])] == 1){
            temp_check++;
        }
    }
    if(temp_check == v.size()){
        int temp_ = 0;
        for(int i=1; i<n+1; i++){
            if(visited[i] == 0){
                temp_++;
            }
        }
        if(temp_ == 1){
            possible = true;
            final = min(final, abs(total - (total_pop-total)));
            return;
        }else{
            check();
        }
    }
}

void go(){
    int temp_ = 0;
    for(int i=1; i<n+1; i++){
        if(visited[i] == 0){
            temp_++;
        }
    }
    if(temp_ == 0){
        return;
    }
    v.clear();
    for(int i=1; i<n+1; i++){
        if(visited[i] == 1){
            v.push_back(i);
        }
    }
    check_non();
}

void go_2(int t, int idx, int num){
    if(num == t){
        go();
        return;
    }

    for(int i=idx; i<n+1; i++){
        if(visited[i] == 1) continue;
        visited[i] = 1;
        total += population[i];

        go_2(t, i, num+1);
        visited[i] = 0;
        total -= population[i];
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>population[i+1];
    }
    for(int i=1; i<n+1; i++){
        cin>>near_num;
        for(int j=0; j<near_num; j++){
            cin>>near_region;
            a[i][near_region] = 1;
        }
    }
    for(int i=1; i<n+1; i++){
        total_pop += population[i];
    }
    for(int i=1; i<n+1; i++){
        go_2(i, 0, 0);
    }

    if(possible == false){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
    return 0;
}