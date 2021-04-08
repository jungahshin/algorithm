// N-Queen
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int n;
int ans = 0;
int chess[16][16] = { 0, };
int dx[3] = {-1, -1, -1};
int dy[3] = {0, -1, 1};
 
// 어차피, 같은 행과 그 뒤에 좌표들은 검사할 필요가 없기 때문에
// 위, 오르쪽 위 대각선, 왼쪽 위 대각선만 보면 된다.
bool check(int x, int y) {
    for (int i = 0; i < 3; i++) {
        int nx = x;
        int ny = y;
        while (1) {
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                break;
            }
            if (chess[nx][ny] == 1) {
                return false;
            }
        }
    }
 
    return true;
}
 
void choose(int idx)
{
    if (idx == n) {
        ans++;
        return;
    }
 
    for (int i = 0; i < n; i++)
    {
        if (chess[idx][i] == 0 && check(idx, i)) {
            chess[idx][i] = 1;
            choose(idx + 1);
            chess[idx][i] = 0;
        }
    }
}
 
int main()
{
    cin >> n;
    
    choose(0);
    
    cout << ans << "\n";
    return 0;
}