//큐빙(시뮬레이션)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int t, n;
char cube, dir;//면, 도는 방향
vector<pair<char,char>> v;
vector<string> final;
char w[3][3];
char y[3][3];
char r[3][3];
char o[3][3];
char g[3][3];
char b[3][3];

void go(){//돌리기
    for(int i=0; i<v.size(); i++){
        vector<char> temp;
        temp.clear();
        if(v[i].first == 'U'){//위(흰색)
            for(int k=2; k>=0; k--){
                temp.push_back(o[0][k]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(b[0][k]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(r[0][k]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(g[0][k]);
            }
            //temp의 뒤에 3개 요소를 앞으로 끌고온다.-->그래고 오렌지부터 시계방향으로 순서대로 채운다
            char move[12];
            if(v[i].second == '+'){//시계방향
                move[0] = temp[9];
                move[1] = temp[10];
                move[2] = temp[11];
                for(int i=0; i<=8; i++){
                    move[i+3] = temp[i];
                }
            }else if(v[i].second == '-'){
                move[9] = temp[0];
                move[10] = temp[1];
                move[11] = temp[2];
                for(int i=0; i<=8; i++){
                    move[i] = temp[i+3];
                }
            }
            int t=0;
            for(int k=2; k>=0; k--){
                o[0][k] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                b[0][k] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                r[0][k] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                g[0][k] = move[t];
                t++;
            }
            char q[3][3];
            if(v[i].second == '+'){
                for(int i=0; i<3; i++){
                    q[0][2-i] = w[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][2-i] = w[i][1];
                }
                for(int i=0; i<3; i++){
                    q[2][2-i] = w[i][2];
                }   
            }else if(v[i].second == '-'){
                for(int i=0; i<3; i++){
                    q[2][i] = w[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][i] = w[i][1];
                }
                for(int i=0; i<3; i++){
                    q[0][i] = w[i][2];
                }
            }
            for(int t=0; t<3; t++){
                for(int e=0; e<3; e++){
                    w[t][e] = q[t][e];
                }
            }
        }
        if(v[i].first == 'D'){//위(흰색)
            for(int k=0; k<3; k++){
                temp.push_back(r[2][k]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(b[2][k]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(o[2][k]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(g[2][k]);
            }
            //temp의 뒤에 3개 요소를 앞으로 끌고온다.-->그래고 오렌지부터 시계방향으로 순서대로 채운다
            char move[12];
            if(v[i].second == '+'){//시계방향
                move[0] = temp[9];
                move[1] = temp[10];
                move[2] = temp[11];      
                for(int i=0; i<=8; i++){
                    move[i+3] = temp[i];
                }          
            }else if(v[i].second == '-'){
                move[9] = temp[0];
                move[10] = temp[1];
                move[11] = temp[2];
                for(int i=0; i<=8; i++){
                    move[i] = temp[i+3];
                }
            }
            int t=0;
            for(int k=0; k<3; k++){
                r[2][k] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                b[2][k] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                o[2][k] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                g[2][k] = move[t];
                t++;
            }
            char q[3][3];
            if(v[i].second == '+'){
                for(int i=0; i<3; i++){
                    q[0][2-i] = y[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][2-i] = y[i][1];
                }
                for(int i=0; i<3; i++){
                    q[2][2-i] = y[i][2];
                }   
            }else if(v[i].second == '-'){
                for(int i=0; i<3; i++){
                    q[2][i] = y[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][i] = y[i][1];
                }
                for(int i=0; i<3; i++){
                    q[0][i] = y[i][2];
                }
            }
            for(int t=0; t<3; t++){
                for(int e=0; e<3; e++){
                    y[t][e] = q[t][e];
                }
            }
        }
        if(v[i].first == 'F'){//위(흰색)
            for(int k=0; k<3; k++){
                temp.push_back(w[2][k]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(b[k][0]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(y[0][k]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(g[k][2]);
            }
            //temp의 뒤에 3개 요소를 앞으로 끌고온다.-->그래고 오렌지부터 시계방향으로 순서대로 채운다
            char move[12];
            if(v[i].second == '+'){//시계방향
                move[0] = temp[9];
                move[1] = temp[10];
                move[2] = temp[11];           
                for(int i=0; i<=8; i++){
                    move[i+3] = temp[i];
                }     
            }else if(v[i].second == '-'){
                move[9] = temp[0];
                move[10] = temp[1];
                move[11] = temp[2];
                for(int i=0; i<=8; i++){
                    move[i] = temp[i+3];
                }
            }
            int t=0;
            for(int k=0; k<3; k++){
                w[2][k] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                b[k][0] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                y[0][k] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                g[k][2] = move[t];
                t++;
            }
            char q[3][3];
            if(v[i].second == '+'){
                for(int i=0; i<3; i++){
                    q[0][2-i] = r[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][2-i] = r[i][1];
                }
                for(int i=0; i<3; i++){
                    q[2][2-i] = r[i][2];
                }   
            }else if(v[i].second == '-'){
                for(int i=0; i<3; i++){
                    q[2][i] = r[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][i] = r[i][1];
                }
                for(int i=0; i<3; i++){
                    q[0][i] = r[i][2];
                }
            }
            for(int t=0; t<3; t++){
                for(int e=0; e<3; e++){
                    r[t][e] = q[t][e];
                }
            }
        }
        if(v[i].first == 'B'){//위(흰색)
            for(int k=2; k>=0; k--){
                temp.push_back(w[0][k]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(g[k][0]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(y[2][k]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(b[k][2]);
            }
            //temp의 뒤에 3개 요소를 앞으로 끌고온다.-->그래고 오렌지부터 시계방향으로 순서대로 채운다
            char move[12];
            if(v[i].second == '+'){//시계방향
                move[0] = temp[9];
                move[1] = temp[10];
                move[2] = temp[11];           
                for(int i=0; i<=8; i++){
                    move[i+3] = temp[i];
                } 
            }else if(v[i].second == '-'){
                move[9] = temp[0];
                move[10] = temp[1];
                move[11] = temp[2];
                for(int i=0; i<=8; i++){
                    move[i] = temp[i+3];
                }
            }
            int t=0;
            for(int k=2; k>=0; k--){
                w[0][k] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                g[k][0] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                y[2][k] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                b[k][2] = move[t];
                t++;
            }
            char q[3][3];
            if(v[i].second == '+'){
                for(int i=0; i<3; i++){
                    q[0][2-i] = o[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][2-i] = o[i][1];
                }
                for(int i=0; i<3; i++){
                    q[2][2-i] = o[i][2];
                }   
            }else if(v[i].second == '-'){
                for(int i=0; i<3; i++){
                    q[2][i] = o[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][i] = o[i][1];
                }
                for(int i=0; i<3; i++){
                    q[0][i] = o[i][2];
                }
            }
            for(int t=0; t<3; t++){
                for(int e=0; e<3; e++){
                    o[t][e] = q[t][e];
                }
            }
        }
        if(v[i].first == 'L'){//위(흰색)
            for(int k=0; k<3; k++){
                temp.push_back(w[k][0]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(r[k][0]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(y[k][0]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(o[k][2]);
            }
            //temp의 뒤에 3개 요소를 앞으로 끌고온다.-->그래고 오렌지부터 시계방향으로 순서대로 채운다
            char move[12];
            if(v[i].second == '+'){//시계방향
                move[0] = temp[9];
                move[1] = temp[10];
                move[2] = temp[11];            
                for(int i=0; i<=8; i++){
                    move[i+3] = temp[i];
                }    
            }else if(v[i].second == '-'){
                move[9] = temp[0];
                move[10] = temp[1];
                move[11] = temp[2];
                for(int i=0; i<=8; i++){
                    move[i] = temp[i+3];
                }
            }
            int t=0;
            for(int k=0; k<3; k++){
                w[k][0] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                r[k][0] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                y[k][0] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                o[k][2] = move[t];
                t++;
            }
            char q[3][3];
            if(v[i].second == '+'){
                for(int i=0; i<3; i++){
                    q[0][2-i] = g[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][2-i] = g[i][1];
                }
                for(int i=0; i<3; i++){
                    q[2][2-i] = g[i][2];
                }   
            }else if(v[i].second == '-'){
                for(int i=0; i<3; i++){
                    q[2][i] = g[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][i] = g[i][1];
                }
                for(int i=0; i<3; i++){
                    q[0][i] = g[i][2];
                }
            }
            for(int t=0; t<3; t++){
                for(int e=0; e<3; e++){
                    g[t][e] = q[t][e];
                }
            }
        }
        if(v[i].first == 'R'){//위(흰색)
            for(int k=2; k>=0; k--){
                temp.push_back(w[k][2]);
            }
            for(int k=0; k<3; k++){
                temp.push_back(o[k][0]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(y[k][2]);
            }
            for(int k=2; k>=0; k--){
                temp.push_back(r[k][2]);
            }
            //temp의 뒤에 3개 요소를 앞으로 끌고온다.-->그래고 오렌지부터 시계방향으로 순서대로 채운다
            char move[12];
            if(v[i].second == '+'){//시계방향
                move[0] = temp[9];
                move[1] = temp[10];
                move[2] = temp[11];            
                for(int i=0; i<=8; i++){
                    move[i+3] = temp[i];
                }    
            }else if(v[i].second == '-'){
                move[9] = temp[0];
                move[10] = temp[1];
                move[11] = temp[2];
                for(int i=0; i<=8; i++){
                    move[i] = temp[i+3];
                }
            }
            int t=0;
            for(int k=2; k>=0; k--){
                w[k][2] = move[t];
                t++;
            }
            for(int k=0; k<3; k++){
                o[k][0] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                y[k][2] = move[t];
                t++;
            }
            for(int k=2; k>=0; k--){
                r[k][2] = move[t];
                t++;
            }
            char q[3][3];
            if(v[i].second == '+'){
                for(int i=0; i<3; i++){
                    q[0][2-i] = b[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][2-i] = b[i][1];
                }
                for(int i=0; i<3; i++){
                    q[2][2-i] = b[i][2];
                }   
            }else if(v[i].second == '-'){
                for(int i=0; i<3; i++){
                    q[2][i] = b[i][0];
                }
                for(int i=0; i<3; i++){
                    q[1][i] = b[i][1];
                }
                for(int i=0; i<3; i++){
                    q[0][i] = b[i][2];
                }
            }
            for(int t=0; t<3; t++){
                for(int e=0; e<3; e++){
                    b[t][e] = q[t][e];
                }
            }
        }
    }
}

int main(){
    cin>>t;//testcase(1<=t<=100)
    for(int i=0; i<t; i++){
        for(int j=0; j<3; j++){
            memset(w[j], 'w', sizeof(char)*3);
        }
        for(int j=0; j<3; j++){
            memset(y[j], 'y', sizeof(char)*3);
        }
        for(int j=0; j<3; j++){
            memset(r[j], 'r', sizeof(char)*3);
        }
        for(int j=0; j<3; j++){
            memset(o[j], 'o', sizeof(char)*3);
        }
        for(int j=0; j<3; j++){
            memset(g[j], 'g', sizeof(char)*3);
        }
        for(int j=0; j<3; j++){
            memset(b[j], 'b', sizeof(char)*3);
        }
        cin>>n;//돌리는 횟수(1<=n<=1000)
        for(int j=0; j<n; j++){
            cin>>cube>>dir;
            v.push_back(make_pair(cube, dir));
        }

        go();
        //final벡터에 추가
        for(int h=0; h<3; h++){
            string final_string = "";
            for(int k=0; k<3; k++){
                final_string += w[h][k];
            }
            final.push_back(final_string);
        }
        v.clear();
    }
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}