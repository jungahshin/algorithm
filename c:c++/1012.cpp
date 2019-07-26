#include <iostream>
#include <string.h>
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int M,N,K;
int arr[50][50]={0, };
int visited[50][50]={0, };
 
void dfs(int x,int y){
    
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(ny<0 || ny>=N || nx<0 || nx>=M)
            continue;
        
        if(arr[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] =1;
            dfs(nx,ny);
        }
    }
}
int main(){
    int T,x,y;
    cin>>T;
    
    for(int testCase=0;testCase<T;testCase++){
        scanf("%d %d %d",&M,&N,&K);
        
        int ans=0; //지렁이 개수
        
        for(int i=0;i<K;i++){
            scanf("%d %d",&x,&y);
            arr[x][y]=1;
        }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                if(arr[i][j] && !visited[i][j]){
                    
                    ans++;
                    visited[i][j] = 1;
                    dfs(i,j);
                    
                }
        
        cout<<ans<<endl;
    }
    return 0;
}
