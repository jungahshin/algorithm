#include <iostream>
using namespace std;
int input[101][101];
bool visited[101][101];
int output[101][101] = {0, };
int n;

void go(int top,int x,int y)
{
    output[top][y] = 1;
    visited[top][y] = true;
    for(int i=1; i<=n; i++)
    {
        if(!visited[top][i] && input[y][i])
            go(top,y,i);
    }
    
}


int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&input[i][j]);
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
           if(!visited[i][i] && input[i][j])
               go(i,i,j);
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ",output[i][j]);
        printf("\n");
    }
    
    return 0;
}
