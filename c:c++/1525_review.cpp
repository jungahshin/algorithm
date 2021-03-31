// 퍼즐
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
 
using namespace std;
 
int puzzle[4][4] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
 
string arrayToString()
{
    string tmp = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp += (puzzle[i][j]+'0');
        }
    }
    return tmp;
}
 
int move()
{
    queue<pair<string, int>> q;
    map<string, int> check;
 
    q.push(make_pair(arrayToString(), 0));
    while (!q.empty()) {
        string s = q.front().first;
        int cnt = q.front().second;
        check[s] = 1;
        q.pop();
 
        if (s == "123456780") {
            return cnt;
        }
 
        int idx = s.find('0');
        int x = idx / 3;
        int y = idx % 3;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                string tmp = s;
                swap(tmp[x * 3 + y], tmp[nx * 3 + ny]);
 
                if (check.count(tmp) == 0) {
                    check[tmp] = 1;
                    q.push(make_pair(tmp, cnt + 1));
                }
            }
        }
    }
    return -1;
}
 
int main()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> puzzle[i][j];
        }
    }
 
    cout << move() << "\n";
 
    return 0;
}