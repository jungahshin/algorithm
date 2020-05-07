#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
int visited2[16] = {0, };
int visited[16] = {0, };
vector<int> v;
vector<int> per;
int N = 0;
int real_final = INT_MAX;

void go(int m[201], int num, int final_num, int idx){//v(고른 weak), per(고른 친구)
    int size = v.size();
    if(num == size){
        //다 수리했는지 체크
        if(final_num == 0){//다 수리완료
            real_final = min(real_final, size);
        }
        return;
    }
        
    for(int i=idx; i<v.size(); i++){
        int a = v[i];//점검할 위치
        int b = per[i];//점검할 수 있는 거리
        
        int temp[201] = {0, };
        for(int j=0; j<200; j++){
            temp[j] = m[j];
        }
        int NUM = final_num;
        int k = a;
        temp[a] = 0;
        NUM--;
        
        //시계방향
        // if(dir == 1){
        for(int j=1; j<=b; j++){
            k++;
            if(k > N-1){
                k = 0;
            }
            if(temp[k] == 1){//아직 수리하지 않았다.
                temp[k] = 0;
                NUM--;
            }
        }
        go(temp, num+1, NUM, i);
    }
}

void choose2(int final, int idx, int num, vector<int> dist, vector<int> weak){//visited2
    if(final == num){
        per.clear();
        for(int i=0; i<dist.size(); i++){
            if(visited2[i] == true){
                per.push_back(dist[i]);
            }
        }
        if(real_final != INT_MAX){
            return;
        }
        int m[201] = {0, };
        for(int i=0; i<weak.size(); i++){
            m[weak[i]] = 1;
        }
        go(m, 0, weak.size(), 0);
        return;
    }
    
    for(int i=idx; i<dist.size(); i++){
        if(visited2[i] == true) continue;
        visited2[i] = true;
        
        choose2(final, i, num+1, dist, weak);
        visited2[i] = false;
    }
}

void choose(int final, int idx, int num, vector<int> weak, vector<int> dist){//visited
    if(final == num){
        v.clear();
        for(int i=0; i<weak.size(); i++){
            if(visited[i] == true){
                v.push_back(weak[i]);
            }
        }
        do{
            choose2(final, 0, 0, dist, weak);//사람 고르기
        }while(next_permutation(v.begin(), v.end()));
        return;
    }
    for(int i=idx; i<weak.size(); i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        
        choose(final, i, num+1, weak, dist);
        visited[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n;
    for(int i=1; i<=weak.size(); i++){
        choose(i, 0, 0, weak, dist);
    }
    
    return real_final;
}