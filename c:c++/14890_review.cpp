//경사로 복습
#include <iostream>
using namespace std;

int n, l;
int map[101][101] = {0, };
int possible_row[101] = {0, };//각 길이 가능한지 판별 여부(1-불가능)
int possible_col[101] = {0, };
int final = 0;

void go(){
    //행 기준
    //왼쪽->오른쪽
    for(int i=0; i<n; i++){//행
        int temp = map[i][0];
        int num = 1;
        bool check = false;
        bool check_go = false;
        bool check_2 = false;
        for(int j=1; j<n; j++){//열
            if(temp == map[i][j]){
                num++;
                if(j != n-1){
                    temp = map[i][j];
                    continue;                    
                }
            }

            if(j == n-1){
                if(num<l){
                    if(check_2 == true){//내려온게 마지막이고
                        possible_row[i] = 1;
                        break;
                    }
                }
            }

            if(temp-1 == map[i][j]){//내려가
                check_2 = true;
                if(j == n-1 && check_2 == true){
                    num = 1;
                    if(num<l){
                        possible_row[i] = 1;
                        break;                        
                    }
                }
                if(num == l){
                    num = 1;
                    check_go = true;
                    check = true;
                    temp = map[i][j];
                    continue;
                }else if(num>l){
                    num = 1;
                    check_go = true;
                    check = true;
                    temp = map[i][j];
                    continue;
                }else if(num<l){
                    if(check == false){//처음 시작할때
                        num = 1;
                        check = true;
                        check_go = true;
                        temp = map[i][j];
                        continue;
                    }else{
                        possible_row[i] = 1;
                        break;
                    }
                }
            }

            if(temp+1 == map[i][j]){//올라가
                check_2 = false;
                if(check_go == true){//내려갔다 올라가
                    if(num>=(2*l)){
                        num = 1;
                        check_go = false;
                        temp = map[i][j];
                        continue;
                    }else{
                        possible_row[i] = 1;
                        break;
                    }
                }else{
                    if(num == l){
                        num = 1;
                        temp = map[i][j];
                        continue;
                    }else if(num>l){
                        num = 1;
                        temp = map[i][j];
                        continue;
                    }else if(num<l){
                        possible_row[i] = 1;
                        break;
                    }
                }
            }

            if(temp+1<map[i][j]){//더 높아
                possible_row[i] = 1;
                break;
            }

            if(temp-1>map[i][j]){//더 낮아
                possible_row[i] = 1;
                break;
            }

        }
    }
    
    //열 기준
    //위->아래
    for(int i=0; i<n; i++){//열
        int temp = map[0][i];
        int num = 1;
        bool check = false;
        bool check_go = false;
        bool check_2 = false;
        for(int j=1; j<n; j++){//행
            if(temp == map[j][i]){
                num++;
                if(j != n-1){
                    temp = map[j][i];
                    continue;                    
                }
            }

            if(j == n-1){
                if(num<l){
                    if(check_2 == true){//내려온게 마지막이고
                        possible_col[i] = 1;
                        break;
                    }
                }
            }

            if(temp-1 == map[j][i]){//내려가
                check_2 = true;
                if(j == n-1 && check_2 == true){
                    num = 1;
                    if(num<l){
                        possible_col[i] = 1;
                        break;   
                    }
                }
                if(num == l){
                    num = 1;
                    check_go = true;
                    check = true;
                    temp = map[j][i];
                    continue;
                }else if(num>l){
                    num = 1;
                    check_go = true;
                    check = true;
                    temp = map[j][i];
                    continue;
                }else if(num<l){
                    if(check == false){//처음 시작할때
                        num = 1;
                        check = true;
                        check_go = true;
                        temp = map[j][i];
                        continue;
                    }else{
                        possible_col[i] = 1;
                        break;
                    }
                }
            }

            if(temp+1 == map[j][i]){//올라가
                check_2 = false;
                if(check_go == true){//내려갔다 올라가
                    if(num>=(2*l)){
                        num = 1;
                        check_go = false;
                        temp = map[j][i];
                        continue;
                    }else{
                        possible_col[i] = 1;
                        break;
                    }
                }else{
                    if(num == l){
                        num = 1;
                        temp = map[j][i];
                        continue;
                    }else if(num>l){
                        num = 1;
                        temp = map[j][i];
                        continue;
                    }else if(num<l){
                        possible_col[i] = 1;
                        break;
                    }
                }
            }

            if(temp+1<map[j][i]){//더 높아
                possible_col[i] = 1;
                break;
            }

            if(temp-1>map[j][i]){//더 낮아
                possible_col[i] = 1;
                break;
            }
        }
    }
}

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    go();
    for(int i=0; i<n; i++){
        if(possible_row[i] == 0){
            final++;
        }
        if(possible_col[i] == 0){
            final++;
        }
    }
    cout<<final<<"\n";
    return 0;
}