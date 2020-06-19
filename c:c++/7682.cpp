//틱택토
#include <iostream>
using namespace std;

string s;
char game[4][4];

bool go1()//O가 잇는 경우
{
    //가로
    for(int i=0; i<3; i++){
        if(game[i][0] == 'O' && game[i][0] == game[i][1] && game[i][1] == game[i][2]){
            return true;
        }
    }
    //세로
    for(int i=0; i<3; i++){
        if(game[0][i] == 'O' && game[0][i] == game[1][i] && game[1][i] == game[2][i]){
            return true;
        }
    }
    //대각선
    if(game[0][0] == 'O' && game[0][0] == game[1][1] && game[1][1] == game[2][2]){
        return true;
    }
    if(game[0][2] == 'O' && game[0][2] == game[1][1] && game[1][1] == game[2][0]){
        return true;
    }

    return false;
}

bool go2()//X가 잇는 경우
{
    //가로
    for(int i=0; i<3; i++){
        if(game[i][0] == 'X' && game[i][0] == game[i][1] && game[i][1] == game[i][2]){
            return true;
        }
    }
    //세로
    for(int i=0; i<3; i++){
        if(game[0][i] == 'X' && game[0][i] == game[1][i] && game[1][i] == game[2][i]){
            return true;
        }
    }
    //대각선
    if(game[0][0] == 'X' && game[0][0] == game[1][1] && game[1][1] == game[2][2]){
        return true;
    }
    if(game[0][2] == 'X' && game[0][2] == game[1][1] && game[1][1] == game[2][0]){
        return true;
    }

    return false;
}

int main()
{
    while(1)
    {
        cin>>s;
        if(s == "end")
        {
            break;
        }
        int x_num = 0;
        int o_num = 0;
        bool check = false;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'X') {
                x_num++;
            } else if(s[i] == 'O') {
                o_num++;
            } else if(s[i] == '.') {
                check = true;
            }
        }

        int temp = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                game[i][j] = s[temp++];
            }
        }

        if(check == true)//.이 하나라도 존재하면
        {
            if(x_num == o_num) {//가로, 세로, 대각선 검사하기
                if(go1() == true) {
                    cout<<"valid"<<"\n";
                } else {
                    cout<<"invalid"<<"\n";
                }
            } else if(x_num == o_num+1) {
                if(go2() == true) {
                    cout<<"valid"<<"\n";
                } else {
                    cout<<"invalid"<<"\n";
                }
            }
            else {//invalid
                cout<<"invalid"<<"\n";
            }
        }else {//다 두었으면
            if(x_num == 5 && o_num == 4) {
                if(go1() == false){
                    cout<<"valid"<<"\n";
                }
                if(go1() == true){
                    cout<<"invalid"<<"\n";
                }
            } else {
                cout<<"invalid"<<"\n";
            }
        }
    }
    return 0;
}