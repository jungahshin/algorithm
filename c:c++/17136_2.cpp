//색종이붙이기-->예외 있음..!
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int a[11][11] = {0, };
int num_1 = 5;
int num_2 = 5;
int num_3 = 5;
int num_4 = 5;
int num_5 = 5;
int visited[11][11] = {0, };
int final = 0;
int temp = 0;

void go(){//5*5->4*4->3*3->2*2->1*1
    //5*5
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            //기준    
            if(num_5>0){//5*5색종이가 1개라고 있어야 진행 가능!
                bool temp_5 = true;
                for(int k=0; k<5; k++){
                    for(int h=0; h<5; h++){
                        if(a[i+k][j+h] != 1 || visited[i+k][j+h]){
                            temp_5 = false;
                        }
                    }
                }
                if(temp_5 == true){//모두 1일 경우
                    //모두 visited=1 해주고
                    for(int k=0; k<5; k++){
                        for(int h=0; h<5; h++){
                            visited[i+k][j+h] = 1;
                        }
                    }
                    //num_5--해준다.
                    num_5--;
                    final++;
                }
            }                
        }
    }        
    //4*4
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            //기준    
            if(num_4>0){//4*4색종이가 1개라고 있어야 진행 가능!
                bool temp_4 = true;
                for(int k=0; k<4; k++){
                    for(int h=0; h<4; h++){
                        if(a[i+k][j+h] != 1 || visited[i+k][j+h]){
                            temp_4 = false;
                        }
                    }
                }
                if(temp_4 == true){//모두 1일 경우
                    //모두 visited=1 해주고
                    for(int k=0; k<4; k++){
                        for(int h=0; h<4; h++){
                            visited[i+k][j+h] = 1;
                        }
                    }
                    //num_5--해준다.
                    num_4--;
                    final++;
                }
            }                
        }
    }        
    //3*3
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            //기준    
            if(num_3>0){//5*5색종이가 1개라고 있어야 진행 가능!
                bool temp_3 = true;
                for(int k=0; k<3; k++){
                    for(int h=0; h<3; h++){
                        if(a[i+k][j+h] != 1 || visited[i+k][j+h]){
                            temp_3 = false;
                        }
                    }
                }
                if(temp_3 == true){//모두 1일 경우
                    //모두 visited=1 해주고
                    for(int k=0; k<3; k++){
                        for(int h=0; h<3; h++){
                            visited[i+k][j+h] = 1;
                        }
                    }
                    //num_5--해준다.
                    num_3--;
                    final++;
                }
            }                
        }
    }    
    //2*2
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            //기준    
            if(num_2>0){//5*5색종이가 1개라고 있어야 진행 가능!
                bool temp_2 = true;
                for(int k=0; k<2; k++){
                    for(int h=0; h<2; h++){
                        if(a[i+k][j+h] != 1 || visited[i+k][j+h]){
                            temp_2 = false;
                        }
                    }
                }
                if(temp_2 == true){//모두 1일 경우
                    //모두 visited=1 해주고
                    for(int k=0; k<2; k++){
                        for(int h=0; h<2; h++){
                            visited[i+k][j+h] = 1;
                        }
                    }
                    //num_5--해준다.
                    num_2--;
                    final++;
                }
            }                
        }
    }        
    //1*1
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            //기준    
            if(num_1>0){//5*5색종이가 1개라고 있어야 진행 가능!
                bool temp_1 = true;
                for(int k=0; k<1; k++){
                    for(int h=0; h<1; h++){
                        if(a[i+k][j+h] != 1 || visited[i+k][j+h]){
                            temp_1 = false;
                        }
                    }
                }
                if(temp_1 == true){//모두 1일 경우
                    //모두 visited=1 해주고
                    for(int k=0; k<1; k++){
                        for(int h=0; h<1; h++){
                            visited[i+k][j+h] = 1;
                        }
                    }
                    //num_5--해준다.
                    num_1--;
                    final++;
                }
            }                
        }
    }
}

int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>a[i][j];
        }
    }
    go();

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i][j] == 1 && !visited[i][j]){
                temp++;
            }
        }
    }
    if(temp != 0){//존재하면
        cout<<"-1"<<"\n";
    }else{
        cout<<final<<"\n";        
    }
    
    return 0;
}