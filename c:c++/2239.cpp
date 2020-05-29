//스도쿠
#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
int sdoku[10][10] = {0, }; 
map<int, int> m;
int row[10][10] = {0, };
int col[10][10] = {0, };
int group[10][10] = {0, };
#define find_cell(r, c) 3*(r/3)+(c/3) //스도쿠가 어디 그룹에 위치해 있는지

void go(){
    bool total_check = false;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(sdoku[i][j] == 0){
                total_check = true;
                bool check = false;
                for(int k=1; k<=9; k++){
                    if(!row[i][k] && !col[j][k] && !group[find_cell(i, j)][k]){
                        check = true;
                        row[i][k] = 1;
                        col[j][k] = 1;
                        group[find_cell(i, j)][k] = 1;
                        sdoku[i][j] = k;
                        go();
                        check = false;
                        sdoku[i][j] = 0;
                        row[i][k] = 0;
                        col[j][k] = 0;
                        group[find_cell(i, j)][k] = 0;
                    }
                }
                if(check == false){
                    return;
                }
            }
        }
    }

    if(total_check == false){
        for(int i=0; i<9; i++){
            string temp = "";
            for(int j=0; j<9; j++){
                temp += to_string(sdoku[i][j]);
            }
            cout<<temp<<"\n";
        }
        exit(0);
    }
}

int main(){
    for(int i=0; i<9; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            sdoku[i][j] = s[j]-'0';
            row[i][s[j]-'0'] = 1;
            col[j][s[j]-'0'] = 1;
            group[find_cell(i, j)][s[j]-'0'] = 1;
        }
    }
    go();
    return 0;
}