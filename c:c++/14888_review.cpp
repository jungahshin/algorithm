//연산자 끼워넣기 복습
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[12] = {0, };//수 저장
int cal[5] = {0, };//연산자 저장
int visited_cal[5] = {0, };
int visited[12] = {0, };//숫자 사이의 연산자 위치
int n, temp;
vector<int> remain;
long final = 0;
vector<long> real_final;

void real_cal_2(){
    int temp = 0;
    for(int i=0; i<n-1; i++){
        if(visited[i] == 0){
            temp++;
        }
    }
    if(temp == 0){//모두 방문했어-->계산 진행
        final = num[0];
        for(int j=0; j<n-1; j++){
            if(visited[j] == 1){//덧셈
                final += num[j+1];
            }else if(visited[j] == 2){//뺄셈
                final -= num[j+1];
            }else if(visited[j] == 3){//곱셈
                final *= num[j+1];
            }else if(visited[j] == 4){//나눗셈
                if(final < 0){
                    int temp = -final;
                    temp /= num[j+1];
                    final = -temp;
                }else{
                    final /= num[j+1];
                }
            }
        }
        real_final.push_back(final);
    }
}

void real_cal(int idx){//남은 자리에 대해 조합 진행
    if(idx > remain.size()-1){
        real_cal_2();
        return;
    }

    for(int i=0; i<n-1; i++){
        if(visited[i] != 0) continue;
        visited[i] = remain[idx];
        real_cal(idx+1);
        visited[i] = 0;
    }        
}

void go(int idx, int num_, int total, int cal_){
    if(num_ == total){
        for(int i=0; i<4; i++){
            if(cal[i] > 1 && !visited_cal[i]){//같은 연산자가 여러번 사용된다면
                visited_cal[i] = 1;
                go(0, 0, cal[i], i+1);
                visited_cal[i] = 0;
            }
        }
        
        if(remain.size() > 0){
            real_cal(0);//진짜 계산하기         
        }else{
            real_cal_2();
        }
    }

    for(int i=idx; i<n-1; i++){
        if(visited[i] != 0) continue;
        visited[i] = cal_;

        go(i, num_+1, total, cal_);
        visited[i] = 0;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    for(int i=0; i<4; i++){
        cin>>cal[i];//덧셈, 뺄셈, 곱셈, 나눗셈
    }
    for(int i=0; i<4; i++){
        if(cal[i] == 1){
            remain.push_back(i+1);
        }
    }
    bool check = false;
    for(int i=0; i<4; i++){
        if(cal[i] > 1 && !visited_cal[i]){//같은 연산자가 여러번 사용된다면
            check = true;
            visited_cal[i] = 1;
            go(0, 0, cal[i], i+1);
            break;
        }
    }
    if(check == false){
        real_cal(0);
    }
    sort(real_final.begin(), real_final.end());
    cout<<real_final[real_final.size()-1]<<"\n";
    cout<<real_final[0]<<"\n";
    return 0;
}