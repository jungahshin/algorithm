// 완전이진트리
#include <iostream>
#include <vector>
 
using namespace std;
 
int k, node;
vector<int> height[11];
int arr[1100] = {0, };
 
void dfs(int Start, int End, int level)
{
    int mid = (Start+End)/2;
    height[level].push_back(arr[mid]);
 
    if(Start==End){
        return;
    }
 
    dfs(Start, mid-1, level+1);
    dfs(mid+1, End, level+1);
}
 
int main()
{
    cin>>k;
    int cnt = 1;
    for(int i=0; i<k; i++){
        cnt *= 2;
    }
    cnt -= 1;
    for(int i=0; i<cnt; i++){
        cin>>node;
        arr[i] = node;
    }
 
    dfs(0, cnt-1, 1);
 
    for(int i=1; i<=k; i++){
        for(int j=0; j<height[i].size(); j++){
            cout<<height[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}