//문자열 자르기
#include <iostream>
#include <map>
using namespace std;

int r, c, Start, End;
string s;
char table[1001][1001];
int row;
int final = 0;

int main()
{
    cin>>r>>c;
    for(int i=0; i<r; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            table[i][j] = s[j];
        }
    }
    
    Start = 0;
    End = r;

    while(Start<=End){
        //구하는 행
        int mid = (Start+End)/2;
        bool check = true;

        //열을 읽어서 문자열을 만든다.
        map<string, int> m;
        for(int i=0; i<c; i++){
            string t = "";
            for(int j=mid; j<r; j++){
                t += table[j][i];
            }
            if(m.count(t) == 0){
                m[t] = 1;
            }else{//중복
                check = false;
            }
            if(check == false){
                break;
            }
        }

        if(check == false){//중복 발생
            End = mid-1;
        }else{
            Start = mid+1;
        }
    }

    cout<<End<<"\n";
    return 0;
}