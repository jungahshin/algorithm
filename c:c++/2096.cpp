//내려가기
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int a[3] = {0, };
int DP_MAX[3] = {0, };
int DP_MIN[3] = {0, };
int final_max = 0;
int final_min = INT_MAX;
int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){//행마다 바로바로 계산
        for(int j=0; j<3; j++){
            cin>>a[j];
        }
        if(i == 0){//맨 첫줄
            for(int j=0; j<3; j++){
                DP_MAX[j] = a[j];
                DP_MIN[j] = a[j];
            }            
        }else{
            int max_left = DP_MAX[0];
            int max_mid = DP_MAX[1];
            int max_right = DP_MAX[2];
            int min_left = DP_MIN[0];
            int min_mid = DP_MIN[1];
            int min_right = DP_MIN[2];
            //최댓값
            DP_MAX[0] = max(max_left+a[0], DP_MAX[0]);
            DP_MAX[0] = max(max_mid+a[0], DP_MAX[0]);
            DP_MAX[1] = max(max_left+a[1], DP_MAX[1]);
            DP_MAX[1] = max(max_mid+a[1], DP_MAX[1]);
            DP_MAX[1] = max(max_right+a[1], DP_MAX[1]);
            DP_MAX[2] = max(max_mid+a[2], DP_MAX[2]);
            DP_MAX[2] = max(max_right+a[2], DP_MAX[2]);
            //최솟값
            DP_MIN[0] = min(min_left+a[0], INT_MAX);
            DP_MIN[0] = min(min_mid+a[0], DP_MIN[0]);
            DP_MIN[1] = min(min_left+a[1], INT_MAX);
            DP_MIN[1] = min(min_mid+a[1], DP_MIN[1]);
            DP_MIN[1] = min(min_right+a[1], DP_MIN[1]);
            DP_MIN[2] = min(min_mid+a[2], INT_MAX);
            DP_MIN[2] = min(min_right+a[2], DP_MIN[2]);
        }
        if(i == n-1){//최댓값, 최솟값
            for(int k=0; k<3; k++){
                final_max = max(final_max, DP_MAX[k]);
                final_min = min(final_min, DP_MIN[k]);
            }
        }
    }
    
    cout<<final_max<<" "<<final_min<<"\n";
}