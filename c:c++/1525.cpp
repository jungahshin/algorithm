//퍼즐-->최단은 무조건!!!bfs
//visited대신 set사용!!!
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
using namespace std;

char a[4][4];
set<string> visited;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int final = INT_MAX;
string str;

void change(string str){//string 에서 이차원 배열로
    int temp = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            a[i][j] = str[temp];
            temp++;
        }
    }
}

string change_(char A[][4]){
    string str_temp;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            str_temp += A[i][j];
        }
    }
    return str_temp;
}

void go(){//bfs
    queue<pair<string, int>> q;
    q.push(make_pair(str, 0));
    visited.insert(str);

    while(!q.empty()){
        string z = q.front().first;
        int num = q.front().second;
        q.pop();

        if(num > final){
            continue;
        }

        if(z == "123456780"){
            final = min(final, num);
            continue;
        }

        change(z);//z를 a_copy로 변환

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(a[i][j] != 0){
                    for(int k=0; k<4; k++){
                        int final_x = i + dx[k];
                        int final_y = j + dy[k];
                        if(0 <= final_x && final_x < 3 && 0 <= final_y && final_y <3){
                            if(a[final_x][final_y] == '0'){
                                char temp[4][4];
                                for(int c=0; c<3; c++){
                                    for(int b=0; b<3; b++){
                                        temp[c][b] = a[c][b];
                                    }
                                }
                                temp[final_x][final_y] = a[i][j];
                                temp[i][j] = a[final_x][final_y];//0으로 만든다.
                                string str_change = change_(temp);
                                if(visited.find(str_change) == visited.end()){//찾는 값이 없다.
                                    q.push(make_pair(str_change, num+1));      
                                    visited.insert(str_change);                              
                                }
                            }
                        }
                    }                       
                }                        
            }
        }
    }
}

int main(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
            str += a[i][j];
        }
    }
    go();
    if(final == INT_MAX){
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";
    }
}