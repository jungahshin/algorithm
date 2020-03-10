//멀티탭 스케쥴링
#include <iostream>
#include <vector>
using namespace std;

int n, k, name;
vector<int> multi;
int tab[101] = {0, };
int num = 0;

int main(){
    cin>>n>>k;
    for(int i=0; i<k; i++){
        cin>>name;
        multi.push_back(name);
    }
    for(int i=0; i<multi.size(); i++){
        bool check = false;
        for(int k=0; k<n; k++){
            //이미 탭에 꽂혀 있으면 넘어가
            if(tab[k] == multi[i]){
                check = true;
                break;
            }
        }
        if(check == true){
            continue;
        }
        //꽂혀져 있지 않다.
        int final = 0;
        bool check_empty = false;
        int arr[101] = {0, };
        for(int j=0; j<n; j++){
            for(int k=i; k<multi.size(); k++){
                if(multi[k] == tab[j] && arr[(multi[k])] == 0){
                    arr[(multi[k])] = 1;
                    final = max(final, k);
                }
            }
            //멀티 탭이 비어있다.
            if(tab[j] == 0){
                check_empty = true;
                tab[j] = multi[i];
                break;
            }
        }
        if(check_empty == true){
            continue;
        }
        //꽂혀져 있지도 않고 빈 곳도 없다...
        bool check_use = false;
        for(int j=0; j<n; j++){
            if(arr[(tab[j])] == 0){//뒤에서 더 이상 쓰이지 않는다.
                check_use = true;
                tab[j] = multi[i];
                num++;
                break;
            }
        }
        if(check_use == true){
            continue;
        }
        for(int j=0; j<n; j++){
            if(tab[j] == multi[final]){
                tab[j] = multi[i];
                num++;
            }
        }
    }
    cout<<num<<"\n";
}