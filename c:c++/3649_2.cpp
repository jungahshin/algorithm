//로봇 프로젝트(이분 탐색)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int x, n, len;
vector<int> lego;
int size = 10000000;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    while(cin>>x){//예제가 들어오면 시작
        lego.clear();
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>len;
            lego.push_back(len);
        }
        sort(lego.begin(), lego.end());
        bool check = false;

        for(int i=0; i<n; i++){
            int low = i+1;
            int high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if((lego[mid]+lego[i]) == x*size){
                    check = true;
                    cout<<"yes "<<lego[i]<<" "<<lego[mid]<<"\n";
                    break;
                }else if((lego[mid]+lego[i]) < x*size){
                    low = mid+1;
                }else if((lego[mid]+lego[i]) > x*size){
                    high = mid-1;
                }
            }
            if(check == true){
                break;
            }
        }
        if(check == false){
            cout<<"danger"<<"\n";
        }
    }
    return 0;
}