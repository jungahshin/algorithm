// 배열돌리기
#include <iostream>
using namespace std;
 
int n, m, r;
int map[301][301] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
 
int main()
{
    cin>>n>>m>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
 
    while(r--){
        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = m-1;
        int x3 = n-1, y3 = m-1;
        int x4 = n-1, y4 = 0;
 
        while(x1<x4 && y1<y2){
            int temp = map[x1][y1];
            for(int i=y1; i<y2; i++){
                map[x1][i] = map[x1][i+1];
            }
            for(int i=x2; i<x3; i++){
                map[i][y2] = map[i+1][y2];
            }
            for(int i=y3; i>y4; i--){
                map[x3][i] = map[x3][i-1];
            }
            for(int i=x4; i>x1; i--){
                map[i][y4] = map[i-1][y4];
            }
            map[x1+1][y4] = temp;
            x1 += 1;
            y1 += 1;
            x2 += 1;
            y2 -= 1;
            x3 -= 1;
            y3 -= 1;
            x4 -= 1;
            y4 += 1;
        }
    }
 
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
 
    return 0;
}