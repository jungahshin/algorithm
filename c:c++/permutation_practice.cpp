//순열 연습(1~10번의 사람에게 1~10사이의 순번 부여하기!)
#include <iostream>
using namespace std;

int seq[10] = {0, };
int visited[10] = {0, };
int num = 0;

void permutation(int person, int num, int sequence){
    if(num == 1){
        seq[sequence] = person;
        if(sequence == 10){
            //출력
            for(int i=1; i<=10; i++){
                cout<<seq[i]<<" ";
            }
            cout<<"\n";
        }
        permutation(1, 0, sequence);
    }

    for(int i=person; i<=10; i++){
        if(visited[i] == 1) continue;
        visited[i] = 1;
        sequence++;

        permutation(i, num+1, sequence);
        visited[i] = 0;
        sequence--;
    }
}

int main(){
    permutation(1, 0, 0);
    cout<<num<<"\n";
}